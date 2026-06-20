__int64 init_module()
{
  return _platform_driver_register(&cam_cc_canoe_driver, &_this_module);
}
