__int64 __fastcall gen8_gmu_ifpc_store(__int64 a1, int a2)
{
  int v3; // w2

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x40) == 0 )
    return 4294967274LL;
  if ( a2 )
  {
    if ( *(_BYTE *)(a1 + 20442) )
      v3 = 6;
    else
      v3 = 3;
  }
  else
  {
    v3 = 0;
  }
  if ( *(_DWORD *)(a1 - 816) == v3 )
    return 0;
  else
    return adreno_power_cycle_u32(a1, (_DWORD *)(a1 - 816), v3);
}
