__int64 cam_smmu_init_module()
{
  return _platform_driver_register(cam_smmu_driver, &_this_module);
}
