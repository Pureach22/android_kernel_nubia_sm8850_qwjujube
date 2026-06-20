__int64 init_module()
{
  dwc3_msm_kretprobe_init();
  return _platform_driver_register(dwc3_msm_driver, &_this_module);
}
