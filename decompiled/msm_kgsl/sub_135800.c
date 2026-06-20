__int64 sub_135800()
{
  __int64 v0; // x30

  if ( (v0 & 0x200000000000LL) == 0 )
    JUMPOUT(0x13B31C);
  return kgsl_iommu_secure_fault_handler();
}
