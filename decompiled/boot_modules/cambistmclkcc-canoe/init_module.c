__int64 init_module()
{
  return _platform_driver_register(&cam_bist_mclk_cc_canoe_driver, &_this_module);
}
