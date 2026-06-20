__int64 __fastcall perfcounter_store(__int64 a1, char a2)
{
  if ( *(_BYTE *)(a1 + 23968) == (a2 & 1) )
    return 0;
  else
    return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 23968), a2 & 1);
}
