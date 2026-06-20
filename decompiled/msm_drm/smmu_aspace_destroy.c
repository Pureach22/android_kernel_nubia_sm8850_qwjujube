__int64 __fastcall smmu_aspace_destroy(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8

  result = *(_QWORD *)(a1 + 256);
  if ( result )
  {
    v2 = *(__int64 (**)(void))(*(_QWORD *)result + 64LL);
    if ( *((_DWORD *)v2 - 1) != -1262402125 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
