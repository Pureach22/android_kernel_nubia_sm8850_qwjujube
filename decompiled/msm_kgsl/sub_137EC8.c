__int64 sub_137EC8()
{
  __int64 v0; // x21

  if ( (v0 & 0x40000000000000LL) != 0 )
    JUMPOUT(0x13A610);
  return kgsl_iommu_find_svm_region();
}
