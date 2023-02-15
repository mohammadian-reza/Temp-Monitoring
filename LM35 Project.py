import serial # import Serial Library
import requests
import numpy # Import numpy
import matplotlib.pyplot as plt
from drawnow import *
%load_ext sql                                       # Use sql magic for convenient coding
%sql mysql+pymysql://root:@localhost/hr             # Connect local or online server for storing data

dweetIO= "https://dweet.io/dweet/for/"
myname= "sensorDHT22"
my_key= "measure_temp"

tempF= []
humidity=[]
arduinoData = serial.Serial('com7', 9600)            #Creating our serial object named arduinoData
plt.ion()                                            #Tell matplotlib you want interactive mode to plot live data
cnt=0


%sql CREATE TABLE PARAMETERS ( Temperature(C) FLOAT, Humidity(RH) FLOAT)

def makeFig():                                     #Create a function that makes our desired plot
    plt.ylim(20,40)                                  #Set y min and max values
    plt.title('My Live Streaming Sensor Data')       #Plot the title
    plt.grid(True)                                   #Turn the grid on
    plt.ylabel('Temp (c)')                           #Set ylabels
    plt.plot(tempF, 'ro-', label='Degrees C')        #plot the temperature
    plt.legend(loc='upper left')                     #plot the legend
    plt2= plt.twinx()                                #Create a second y axis
    plt.ylim(50,90)                                  #Set limits of second y axis- adjust to readings you are getting
    plt2.plot(humidity, 'b^-', label='Relative H')   #plot humidity data
    plt2.set_ylabel('RH(%)')                         #label second y axis
    plt2.ticklabel_format(useOffset=False)           #Force matplotlib to NOT autoscale y axis
    plt2.legend(loc='upper right')                   #plot the legend


while True:                                          # While loop that loops forever
    while (arduinoData.inWaiting()==0):              # Wait here until there is data
        pass                                         # do nothing
    arduinoString = arduinoData.readline()           # read the line of text from the serial port
    arduinoString = arduinoString.decode('ascii')
    dataArray = arduinoString.split(',')             #Split it into an array called dataArray
    temp = float( dataArray[0])                      #Convert first element to floating number and put in temp
    H = float( dataArray[1])                         #Convert second element to floating number and put in H
    tempF.append(temp)                               #Build our tempF array by appending temp readings
    humidity.append(H)                               #Building our humidity array by appending H readings
    %sql INSERT INTO PARAMETERS(Temperature(C), Humidity(RH)) VALUES (temp, H)  #insert data to table in aql server
    drawnow(makeFig)                                 #Call drawnow to update our live graph
    plt.pause(.000001)                               #Pause Briefly. Important to keep drawnow from crashing
    cnt=cnt+1
    if(cnt>50000):                                   #If you have 50 or more points, delete the first one from the array
        tempF.pop(0)                                 #This allows us to just see the last 50 data points
        humidity.pop(0)
    rqsString = dweetIO+myname+'?'+my_key+'='+str(temp)  #send data to cloud
    rqsString_h = dweetIO+myname+'?'+my_key+'='+str(H)   #send data to cloud
    print(rqsString, rqsString_h)
    rqs = requests.get(rqsString)
    rqs_h = requests.get(rqsString_h)
    print(rqs.status_code, rqs_h.status_code)
    print(rqs.headers, rqs_h.headers)
    print(rqs.content, rqs_h.content)        
#please visit this site to view online data https://dweet.io/follow/sensorDHT22
