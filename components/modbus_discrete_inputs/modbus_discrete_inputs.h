#pragma once

#include "esphome/core/component.h"
#include "esphome/components/modbus_controller/modbus_controller.h"

namespace esphome {
namespace modbus_discrete_inputs {

class ModbusDiscreteInputReader : public Component {
 public:
  ModbusDiscreteInputReader(modbus_controller::ModbusController *modbus, uint8_t address)
      : modbus_(modbus), address_(address) {}

  void setup() override;
  void loop() override;

 protected:
  modbus_controller::ModbusController *modbus_;
  uint8_t address_;
};

}  // namespace modbus_discrete_inputs
}  // namespace esphome
