__int64 init_module()
{
  __int64 result; // x0
  unsigned int v1; // w19

  result = _platform_driver_register(iommu_debug_driver, &_this_module);
  if ( !(_DWORD)result )
  {
    result = _platform_driver_register(&iommu_debug_usecase_driver, &_this_module);
    if ( (_DWORD)result )
    {
      v1 = result;
      platform_driver_unregister(iommu_debug_driver);
      return v1;
    }
  }
  return result;
}
