# Arduino Clock

## Configurando los puertos en Ubuntu
  * Habilitar el puerto para poder usarlo :`$ sudo chmod 777 /dev/ttyACM0`
  ### Si deseas utilizar el minitor serial con python
    * Necesitaras instalar el modulo de python `$ pip install pyserial`
    * Si deseas modificar el archivo de python que establece la comununicación serial encontraras mas información aquí [monitor.py](https://pybonacci.es/2014/01/19/leer-datos-de-arduino-desde-python/ "Title")

  ```python
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
```

## Libreria time para arduino
  ##### [TimeLib](https://github.com/PaulStoffregen/Time)

    :::cpp
        hour();            // the hour now  (0-23)
        minute();          // the minute now (0-59)
        second();          // the second now (0-59)
        day();             // the day now (1-31)
        weekday();         // day of the week (1-7), Sunday is day 1
        month();           // the month now (1-12)
        year();            // the full four digit year: (2009, 2010 etc)
