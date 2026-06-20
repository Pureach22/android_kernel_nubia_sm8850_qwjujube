__int64 __fastcall kgsl_mmu_set_svm_region(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( !a1 )
    return 4294967284LL;
  v1 = *(_QWORD *)(a1 + 96);
  if ( !v1 )
    return 4294967284LL;
  v2 = *(__int64 (**)(void))(v1 + 96);
  if ( !v2 )
    return 4294967284LL;
  if ( *((_DWORD *)v2 - 1) != 1466385866 )
    __break(0x8228u);
  return v2();
}
