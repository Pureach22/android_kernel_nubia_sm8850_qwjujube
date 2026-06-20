__int64 cleanup_module()
{
  platform_driver_unregister(dwc3_msm_driver);
  return dwc3_msm_kretprobe_exit();
}
