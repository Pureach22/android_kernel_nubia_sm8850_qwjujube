__int64 init_module()
{
  _platform_driver_register(lpass_bt_swr_drv, &_this_module);
  return 0;
}
