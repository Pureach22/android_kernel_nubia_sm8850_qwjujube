__int64 init_module()
{
  return _platform_driver_register(qpnp_vibrator_ldo_driver, &_this_module);
}
