__int64 cleanup_module()
{
  lpass_cdc_clk_rsc_mgr_exit();
  return platform_driver_unregister(lpass_cdc_drv);
}
