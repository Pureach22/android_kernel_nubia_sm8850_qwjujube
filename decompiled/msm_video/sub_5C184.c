__int64 sub_5C184()
{
  __int64 v0; // x30

  if ( (v0 & 0x200000000000LL) == 0 )
    JUMPOUT(0x61CA0);
  return msm_vidc_smmu_fault_handler();
}
