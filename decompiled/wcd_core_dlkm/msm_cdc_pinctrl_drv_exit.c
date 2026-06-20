__int64 msm_cdc_pinctrl_drv_exit()
{
  return platform_driver_unregister(msm_cdc_pinctrl_driver);
}
