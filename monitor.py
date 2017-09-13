import serial
arduino = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=0.7)
print("Welcome to arduino-serialpy")
while True:
    try:
        line = arduino.readline()
        print(line)
    except KeyboardInterrupt:
        print("Exiting")
        break
