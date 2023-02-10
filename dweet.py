import requests

dweetIO= "https://dweet.io/dweet/for/"
myname= "sensorDHT22"
my_key= "measure_temp"

rqsString = dweetIO+myname+'?'+my_key+'='+str(temp)
print(rqsString)
rqs = request.get(rqsString)
print(rqs.status_code)
print(rqs.headers)
print(rqs.content)


