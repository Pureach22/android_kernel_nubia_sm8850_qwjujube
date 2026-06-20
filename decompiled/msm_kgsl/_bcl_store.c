__int64 __fastcall bcl_store(__int64 a1, char a2)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x10) == 0 )
    return 0;
  if ( *(_BYTE *)(a1 + 20437) == (a2 & 1) )
    return 0;
  return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20437), a2 & 1);
}
