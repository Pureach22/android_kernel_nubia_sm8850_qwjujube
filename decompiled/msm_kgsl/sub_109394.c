__int64 __fastcall sub_109394(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x21

  if ( (v5 & 0x40000000000000LL) != 0 )
    JUMPOUT(0x10BADC);
  return kgsl_mmu_find_svm_region(a1, a2, a3, a4, a5);
}
