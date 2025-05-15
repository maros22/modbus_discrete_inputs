#include "modbus_discrete_inputs.h"
#include "esphome/core/log.h"

namespace esphome {
namespace modbus_discrete_inputs {

static const char *const TAG = "modbus_discrete_inputs";

void ModbusDiscreteInputReader::update() {
  if (modbus_ == nullptr) return;

  uint16_t start_address = this->address_;
  uint16_t num_bits = 1;
  modbus_->send_read_discrete_inputs(start_address, num_bits, [this](std::vector<uint8_t> data) {
    if (data.size() >= 1) {
      bool bit = data[0] & 0x01;
      ESP_LOGI(TAG, "FC02: input @0x%02X = %d", this->address_, bit);
      this->publish_state(bit ? 1 : 0);
    }
  });
}

}  // namespace modbus_discrete_inputs
}  // namespace esphome
