__int64 __fastcall iommu_debug_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  debugfs_remove(*(_QWORD *)(v1 + 24));
  result = *(_QWORD *)(v1 + 32);
  if ( result )
    return of_platform_device_destroy(result, 0);
  return result;
}
