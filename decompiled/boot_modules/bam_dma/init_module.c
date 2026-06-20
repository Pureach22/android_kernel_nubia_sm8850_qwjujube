__int64 init_module()
{
  return _platform_driver_register(bam_dma_driver, &_this_module);
}
