__int64 init_module()
{
  _platform_driver_register(lpass_cdc_drv, &_this_module);
  lpass_cdc_clk_rsc_mgr_init();
  return 0;
}
