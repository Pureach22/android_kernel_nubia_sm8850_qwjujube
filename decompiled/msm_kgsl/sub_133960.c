__int64 sub_133960()
{
  __int64 v0; // x30

  if ( (v0 & 0x200000000000LL) == 0 )
    JUMPOUT(0x13947C);
  return kgsl_iommu_lpac_fault_handler();
}
