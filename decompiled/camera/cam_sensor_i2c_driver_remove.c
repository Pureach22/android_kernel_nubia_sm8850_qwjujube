__int64 __fastcall cam_sensor_i2c_driver_remove(__int64 a1)
{
  component_del(a1 + 32, cam_sensor_i2c_component_ops);
  return cam_soc_util_uninitialize_power_domain(a1 + 32);
}
