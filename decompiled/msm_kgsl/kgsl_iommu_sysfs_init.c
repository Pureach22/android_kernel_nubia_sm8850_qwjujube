__int64 __fastcall kgsl_iommu_sysfs_init(__int64 a1)
{
  __int64 result; // x0

  result = sysfs_create_files(*(_QWORD *)(a1 - 56), iommu_sysfs_attr_list);
  if ( (_DWORD)result )
    __break(0x800u);
  return result;
}
