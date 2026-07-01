import serial
import time

arduino = serial.Serial('COM4',9600) 
time.sleep(2) #espera o arduino reiniciar

arduino.write(b'1')
time.sleep(5)
arduino.write(b'0')

