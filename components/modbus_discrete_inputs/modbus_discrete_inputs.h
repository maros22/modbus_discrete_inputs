#pragma once

#include "esphome/core/component.h"
#include "esphome/components/modbus_controller/modbus_controller.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace modbus_discrete_inputs {

class ModbusDiscreteInputReader : public PollingComponent, public sensor::Sensor {
 public:
  ModbusDiscreteInputReader(modbus_controller::ModbusController *modbus, uint8_t address)
      : PollingComponent(3000), modbus_(modbus), address_(address) {}

  void update() override;

 protected:
  modbus_controller::ModbusController *modbus_;
  uint8_t address_;
};

}  // namespace modbus_discrete_inputs
}  // namespace esphome
