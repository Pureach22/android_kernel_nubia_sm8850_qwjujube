__int64 __fastcall adreno_smmu_is_stalled(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 14264);
  if ( !(*(_DWORD *)v1 >> 19) )
  {
    if ( *(_DWORD *)(**(_QWORD **)(v1 + 40) + 60LL) <= 0xFFFFFFFD )
      return ((unsigned int)kgsl_regmap_read(a1 + 13200) >> 24) & 1;
    return 0;
  }
  __dmb(9u);
  if ( (*(_DWORD *)(a1 + 24448) & 8) == 0 )
    return 0;
  return (*(_QWORD *)(a1 + 112) >> 1) & 1LL;
}
