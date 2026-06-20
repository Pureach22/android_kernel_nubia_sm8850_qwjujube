__int64 __fastcall gmu_ab_store(__int64 a1, char a2)
{
  if ( (*(_QWORD *)(a1 + 14240) & 0x8000) == 0 )
    return 0;
  if ( *(_BYTE *)(a1 + 24032) == (a2 & 1) )
    return 0;
  return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 24032), a2 & 1);
}
