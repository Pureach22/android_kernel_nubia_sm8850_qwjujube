__int64 __fastcall a6xx_gmu_ifpc_store(__int64 a1, int a2)
{
  int v3; // w2
  unsigned int v4; // w8

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x40) == 0 )
    return 4294967274LL;
  if ( a2 )
    v3 = 3;
  else
    v3 = 0;
  v4 = 0;
  if ( *(_DWORD *)(a1 - 448) != v3 )
    return (unsigned int)adreno_power_cycle_u32(a1, (_DWORD *)(a1 - 448), v3);
  return v4;
}
