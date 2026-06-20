__int64 cleanup_module()
{
  return platform_driver_unregister(msm_show_resume_dev_driver);
}
