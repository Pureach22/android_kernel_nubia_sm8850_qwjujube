__int64 msm_hdcp_register()
{
  return _platform_driver_register(msm_hdcp_driver, &_this_module);
}
