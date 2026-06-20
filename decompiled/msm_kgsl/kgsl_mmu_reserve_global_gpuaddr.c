__int64 __fastcall kgsl_mmu_reserve_global_gpuaddr(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _DWORD *v3; // x8
  __int64 v4; // x0

  v2 = *(_QWORD *)(a1 + 88);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_DWORD **)(v2 + 96);
  if ( !v3 )
    return 4294967274LL;
  v4 = a1 + 56;
  if ( *(v3 - 1) != 306362912 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v3)(v4, a2, 0);
}
