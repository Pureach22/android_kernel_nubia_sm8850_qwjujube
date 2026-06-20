__int64 init_module()
{
  __int64 v1; // x0

  if ( modeset != 1 )
    return 4294967274LL;
  _drm_dev_dbg(0, 0, 1, "init\n");
  v1 = sde_cesta_register();
  msm_smmu_driver_init(v1);
  sde_wb_register();
  _platform_driver_register(msm_platform_driver, &_this_module);
  dsi_display_register();
  msm_hdcp_register();
  dp_display_register();
  nubia_usb_switch_dp_init();
  nubia_dp_preference_init();
  return 0;
}
