__int64 __fastcall gen7_9_0_lpac_store(__int64 a1, char a2)
{
  _BYTE *v4; // x1

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) == 0 )
    return 4294967274LL;
  v4 = (_BYTE *)(a1 + 20440);
  if ( (*(_BYTE *)(a1 + 24028) & 2) == 0 )
    return 0;
  if ( *v4 == (a2 & 1) )
    return 0;
  return adreno_power_cycle_bool(a1, v4, a2 & 1);
}
