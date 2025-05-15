
# modbus_discrete_inputs
ESPHome external component for reading Modbus Discrete Inputs (FC02) as sensors.

## Usage in ESPHome YAML

external_components:
  - source: github://TVOJE_UZIVATELSKE_MENO/modbus_discrete_inputs
    components: [modbus_discrete_inputs]

sensor:
  - platform: modbus_discrete_inputs
    modbus_id: mrpure
    address: 0x30
    name: "Discrete Input 0x0030"

## Add more sensors for more inputs as needed!
