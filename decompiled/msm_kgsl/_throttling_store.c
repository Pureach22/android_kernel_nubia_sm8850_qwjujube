__int64 __fastcall throttling_store(__int64 a1, char a2)
{
  if ( **(_DWORD **)(a1 + 14264) == 540 && *(_BYTE *)(a1 + 20435) != (a2 & 1) )
    return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20435), a2 & 1);
  else
    return 0;
}
