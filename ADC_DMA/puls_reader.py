import serial
import time

# Konfiguracja portu szeregowego
ser = serial.Serial('COM4', 115200, timeout=1)
ser.flush()

with open("C:/Users/Legion/Desktop/pulse_data.csv", "w") as file:
    file.write("Timestamp,Pulse\n")  # Nagłówek pliku CSV

    # Zbieraj dane przez 2 minuty
    start_time = time.time()
    while time.time() - start_time < 120:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            file.write(line + "\n")
            print(line)  # Wyświetl dane w terminalu