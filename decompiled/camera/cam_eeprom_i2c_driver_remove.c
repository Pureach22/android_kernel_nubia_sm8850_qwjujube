__int64 __fastcall cam_eeprom_i2c_driver_remove(__int64 a1)
{
  cam_soc_util_uninitialize_power_domain(a1 + 32);
  return component_del(a1 + 32, cam_eeprom_i2c_component_ops);
}
