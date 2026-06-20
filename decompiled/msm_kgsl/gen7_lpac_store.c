__int64 __fastcall gen7_lpac_store(__int64 a1, char a2)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) == 0 )
    return 4294967274LL;
  if ( *(_BYTE *)(a1 + 20440) == (a2 & 1) )
    return 0;
  return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20440), a2 & 1);
}
