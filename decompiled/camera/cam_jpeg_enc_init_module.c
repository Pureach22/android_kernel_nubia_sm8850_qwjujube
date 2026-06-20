__int64 cam_jpeg_enc_init_module()
{
  return _platform_driver_register(cam_jpeg_enc_driver, &_this_module);
}
