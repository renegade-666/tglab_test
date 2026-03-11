import serial

# Open the serial port
with serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=1) as ser:
    while True:
        # Read a line from the serial port
        gpgga_data = ser.readline().decode('ascii', errors='replace').strip()
        
        # Check if the string starts with $GPGGA
        if gpgga_data.startswith('$GPGGA'):
            fields = gpgga_data.split(',')

            # Extracting relevant data
            time = fields[1]
            latitude = fields[2] + fields[3]
            longitude = fields[4] + fields[5]
            
            print(f"Time: {time}, Latitude: {latitude}, Longitude: {longitude}")
