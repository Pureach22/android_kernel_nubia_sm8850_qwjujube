__int64 cam_ife_csid_init_module()
{
  return _platform_driver_register(cam_ife_csid_driver, &_this_module);
}
