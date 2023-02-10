import serial # import Serial Library
import requests
import numpy # Import numpy
import matplotlib.pyplot as plt
from drawnow import *

dweetIO= "https://dweet.io/dweet/for/"
myname= "sensorDHT22"
my_key= "measure_temp"

tempF= []
pressure=[]
arduinoData = serial.Serial('com7', 9600) #Creating our serial object named arduinoData
plt.ion() #Tell matplotlib you want interactive mode to plot live data
cnt=0

def makeFig(): #Create a function that makes our desired plot
    plt.ylim(20,40)                                 #Set y min and max values
    plt.title('My Live Streaming Sensor Data')      #Plot the title
    plt.grid(True)                                  #Turn the grid on
    plt.ylabel('Temp (c)')                            #Set ylabels
    plt.plot(tempF, 'ro-', label='Degrees C')       #plot the temperature
    plt.legend(loc='upper left')                    #plot the legend
    plt2= plt.twinx()                                #Create a second y axis
    plt.ylim(70,90)                           #Set limits of second y axis- adjust to readings you are getting
    plt2.plot(pressure, 'b^-', label='Degrees F') #plot pressure data
    plt2.set_ylabel('Temp (f)')                    #label second y axis
    plt2.ticklabel_format(useOffset=False)           #Force matplotlib to NOT autoscale y axis
    plt2.legend(loc='upper right')                  #plot the legend


while True: # While loop that loops forever
    while (arduinoData.inWaiting()==0): #Wait here until there is data
        pass #do nothing
    arduinoString = arduinoData.readline() #read the line of text from the serial port
    arduinoString = arduinoString.decode('ascii')
    #print(arduinoString)
    dataArray = arduinoString.split(',')  #Split it into an array called dataArray
    #print(dataArray)
    temp = float( dataArray[0])            #Convert first element to floating number and put in temp
    P =    float( dataArray[1])            #Convert second element to floating number and put in P
    tempF.append(temp)                     #Build our tempF array by appending temp readings
    pressure.append(P)                     #Building our pressure array by appending P readings
    drawnow(makeFig)                       #Call drawnow to update our live graph
    plt.pause(.000001)                     #Pause Briefly. Important to keep drawnow from crashing
    cnt=cnt+1
    if(cnt>50000):                            #If you have 50 or more points, delete the first one from the array
        tempF.pop(0)                       #This allows us to just see the last 50 data points
        pressure.pop(0)
    rqsString = dweetIO+myname+'?'+my_key+'='+str(temp) #send data to cloud
    print(rqsString)
    rqs = requests.get(rqsString)
    print(rqs.status_code)
    print(rqs.headers)
    print(rqs.content)        
#please visit this site to view online data https://dweet.io/follow/sensorDHT22
