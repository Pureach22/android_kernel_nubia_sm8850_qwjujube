__int64 msm_cdc_pinctrl_drv_init()
{
  return _platform_driver_register(msm_cdc_pinctrl_driver, &_this_module);
}
