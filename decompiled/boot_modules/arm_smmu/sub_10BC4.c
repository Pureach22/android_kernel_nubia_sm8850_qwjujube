__int64 __fastcall sub_10BC4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  if ( !a6 )
    JUMPOUT(0xFFFFFFFFFFFE13ECLL);
  return arm_smmu_attach_dev_blocked();
}
