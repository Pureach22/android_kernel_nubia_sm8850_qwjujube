__int64 cam_jpeg_dma_init_module()
{
  return _platform_driver_register(cam_jpeg_dma_driver, &_this_module);
}
