__int64 cleanup_module()
{
  __int64 v0; // x0

  _drm_dev_dbg(0, 0, 1, "fini\n");
  v0 = sde_wb_unregister();
  msm_smmu_driver_cleanup(v0);
  msm_hdcp_unregister();
  dp_display_unregister();
  dsi_display_unregister();
  sde_cesta_unregister();
  nubia_usb_switch_dp_exit();
  nubia_dp_preference_exit();
  return platform_driver_unregister(msm_platform_driver);
}
