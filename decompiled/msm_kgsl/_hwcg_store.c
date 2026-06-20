__int64 __fastcall hwcg_store(__int64 a1, char a2)
{
  int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w9

  if ( *(_BYTE *)(a1 + 20434) == (a2 & 1) )
    return 0;
  v3 = **(_DWORD **)(a1 + 14264);
  v4 = v3 & 0xFFFF0000;
  v5 = v3 & 0xFFFFFFFE;
  if ( v4 != 0x80000 && v5 != 461056 )
    *(_BYTE *)(a1 + 23984) = 0;
  return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20434), a2 & 1);
}
