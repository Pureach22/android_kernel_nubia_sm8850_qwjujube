__int64 init_module()
{
  return _platform_driver_register(msm_show_resume_dev_driver, &_this_module);
}
