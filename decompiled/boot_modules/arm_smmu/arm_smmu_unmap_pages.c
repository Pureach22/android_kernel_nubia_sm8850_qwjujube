__int64 __fastcall arm_smmu_unmap_pages(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8

  result = *(_QWORD *)(a1 - 168);
  if ( result )
  {
    v2 = *(__int64 (**)(void))(result + 8);
    if ( *((_DWORD *)v2 - 1) != -345622939 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
