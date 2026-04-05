import serial

NUM_GPGGA_FIELDS = 15

def dumb_parse(fields):
    time = fields[1]

    lat_deg = int(fields[2][:2])
    lat_min = float(fields[2][2:])
    latitude = lat_deg + (lat_min / 60)
    latitude_type = fields[3]

    lon_deg = int(fields[4][:2])
    lon_min = float(fields[4][2:])
    longitude = lon_deg + (lon_min / 60)
    longitude_type = fields[5]

    num_satellites = int(fields[7])
    return (time, latitude, latitude_type, longitude, longitude_type, num_satellites)

# Open the serial port
with serial.Serial('/dev/ttyUSB0', baudrate=9600, timeout=1) as ser:
    while True:
        # Read a line from the serial port
        gpgga_data = ser.readline().decode('ascii', errors='replace').strip()

        # Check if the string starts with $GPGGA
        if gpgga_data.startswith('$GPGGA'):
            fields = gpgga_data.split(',')

            if (len(fields) == NUM_GPGGA_FIELDS):

                # Extracting relevant data
                time, latitude, latitude_type, longitude, longitude_type, num_satellites = dumb_parse(fields)
                if latitude < 0.0 or latitude > 90.0 or latitude_type != "N" and latitude_type != "S":
                    print("Error: Invalid latitude")
                    continue
                if longitude < 0.0 or longitude > 180.0 or longitude_type != "E" and longitude_type != "W":
                    print("Error: Invalid longitude")
                    continue
                if num_satellites <= 0:
                    print("Error: Invalid number of satellites")
                    continue

                print(f"GPS: {latitude:.4f}° {latitude_type}, {longitude:.4f}° {longitude_type} | Супутники: {num_satellites}")
            else:
                print("Error: Incorrect number of fields in GPS data")
        else:
            print("Error: Not a NMEA GPGGA data format")
