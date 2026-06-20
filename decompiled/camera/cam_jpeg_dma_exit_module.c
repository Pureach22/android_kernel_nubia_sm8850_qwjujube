__int64 cam_jpeg_dma_exit_module()
{
  return platform_driver_unregister(cam_jpeg_dma_driver);
}
