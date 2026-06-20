__int64 cleanup_module()
{
  return platform_driver_unregister(qpnp_vibrator_ldo_driver);
}
