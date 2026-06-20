__int64 sub_133938()
{
  __int64 v0; // x30

  if ( (v0 & 0x200000000000LL) == 0 )
    JUMPOUT(0x139454);
  return kgsl_iommu_default_fault_handler();
}
