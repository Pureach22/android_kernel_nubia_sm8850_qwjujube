__int64 cleanup_module()
{
  return platform_driver_unregister(lpass_bt_swr_drv);
}
