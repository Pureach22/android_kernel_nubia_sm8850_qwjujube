__int64 __fastcall lm_store(__int64 a1, char a2)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 8) == 0 )
    return 0;
  if ( *(_BYTE *)(a1 + 20432) == (a2 & 1) )
    return 0;
  return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20432), a2 & 1);
}
