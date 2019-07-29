#라즈베리파이에서 AWS Dynamodb로 측정한 압력값 저장
import time, json, ssl
import paho.mqtt.client as mqtt
import serial
import os
import datetime
import calendar
from time import gmtime, strftime
port = '/dev/ttyACM0'
arduinoData = serial.Serial(port, 9600)
arduinoData.flushInput()
print(os.getcwd())
ENDPOINT = 'akah2xtfqvmie-ats.iot.ap-northeast-1.amazonaws.com'
THING_NAME = 'myPSP'

def on_connect(mqttc, obj, flags, rc):
 print('CONNECTED!!')
def on_message(mqttc, obj, msg):
 if msg.topic == 'myPSP':
 payload = msg.payload.decode('utf-8')
 j = json.loads(payload)
 print(j['message'])
mqtt_client = mqtt.Client(client_id=THING_NAME)
mqtt_client.on_connect = on_connect
mqtt_client.on_message = on_message
rootca = os.path.join(os.getcwd(), "root-CA.crt")
cert = os.path.join(os.getcwd(), "myPSP.cert.pem")
privatekey = os.path.join(os.getcwd(), "myPSP.private.key")
mqtt_client.tls_set(rootca,certfile = cert,
 keyfile=privatekey, tls_version=ssl.PROTOCOL_TLSv1_2, ciphers=None)
mqtt_client.connect(ENDPOINT, port=8883)
mqtt_client.loop_start() # threaded network loop
index = 1
while True:
 input = arduinoData.readline().decode('utf-8')
 pressed = input[:-2].split(',')
 pressure=[0,0,0,0,0,0,0,0,0,0]


 key_no = 1
 for key_no in range(9) :
 pressure[key_no-1] = int(pressed[key_no-1])

 ts = strftime("%Y-%m-%d %H:%M:%S", gmtime())
 payload = {}
 payload["idx"]= index
 payload["timestamp"] = ts
 payload["user_id"] = "uid_1"
 payload["pressure1"] = pressure[0]
 payload["pressure2"] = pressure[1]
 payload["pressure3"] = pressure[2]
 payload["pressure4"] = pressure[3]
 payload["pressure5"] = pressure[4]
 payload["pressure6"] = pressure[5]
 payload["pressure7"] = pressure[6]
 payload["pressure8"] = pressure[7]
 payload["pressure9"] = pressure[8]
 payload["pressure10"] = pressure[9]
 data = json.dumps(payload)
 mqtt_client.publish('myPSP', data, qos=1)
 print("PUBLISHED : " + data)
 index += 1
