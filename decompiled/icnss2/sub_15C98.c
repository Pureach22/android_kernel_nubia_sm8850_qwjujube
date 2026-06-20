__int64 sub_15C98()
{
  __int64 v0; // x30

  if ( (v0 & 0x200000000000LL) == 0 )
    JUMPOUT(0x1B7B4);
  return icnss_smmu_fault_handler();
}
