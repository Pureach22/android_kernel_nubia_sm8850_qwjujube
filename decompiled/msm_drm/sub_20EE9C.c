__int64 __fastcall sub_20EE9C(int a1, int a2, int a3, int a4)
{
  __int64 v4; // x30

  if ( (v4 & 0x200000000000LL) == 0 )
    JUMPOUT(0x2149B8);
  return msm_smmu_fault_handler(a1, a2, a3, a4);
}
