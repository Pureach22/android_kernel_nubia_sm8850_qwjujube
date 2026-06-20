__int64 __fastcall lm_limit_set(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x8
  int v3; // w2

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 8) == 0 || *(_BYTE *)(a1 + 20432) != 1 )
    return 0;
  v2 = 3000;
  if ( a2 > 0xBB8 )
    v2 = a2;
  if ( v2 >= 0x2710 )
    v3 = 10000;
  else
    v3 = v2;
  return adreno_power_cycle_u32(a1, (_DWORD *)(a1 + 20636), v3);
}
