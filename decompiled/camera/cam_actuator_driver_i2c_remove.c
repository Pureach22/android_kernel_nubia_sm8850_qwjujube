__int64 __fastcall cam_actuator_driver_i2c_remove(__int64 a1)
{
  component_del(a1 + 32, cam_actuator_i2c_component_ops);
  return cam_soc_util_uninitialize_power_domain(a1 + 32);
}
