##############
## Script listens to serial port and writes contents into a file
##############
## requires pySerial to be installed 
import serial

serial_port = '/dev/cu.usbserial-A603U1XE';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "Datos_arduinoSeral2.txt";
#write_to_file_path = "/Users/franciscofuentesschreiber/Documents/Arduino/test_Cadena/output.txt";

output_file = open(write_to_file_path, "a+");
ser = serial.Serial(serial_port, baud_rate)
while True:
    line = ser.readline();
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    print(line);
    output_file.write(line);

output_file.close()    