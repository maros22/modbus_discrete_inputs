import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import modbus_controller
from esphome.const import CONF_ID, CONF_ADDRESS

modbus_discrete_ns = cg.esphome_ns.namespace("modbus_discrete_inputs")
ModbusDiscreteInputReader = modbus_discrete_ns.class_("ModbusDiscreteInputReader", cg.PollingComponent, cg.sensor.Sensor)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ModbusDiscreteInputReader),
    cv.Required("modbus_id"): cv.use_id(modbus_controller.ModbusController),
    cv.Required(CONF_ADDRESS): cv.uint16_t,
})

async def to_code(config):
    parent = await cg.get_variable(config["modbus_id"])
    var = cg.new_Pvariable(config[CONF_ID], parent, config[CONF_ADDRESS])
    await cg.register_component(var, config)
