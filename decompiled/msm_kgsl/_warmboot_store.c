__int64 __fastcall warmboot_store(__int64 a1, __int64 a2)
{
  if ( *(unsigned __int8 *)(a1 + 8284) == a2 )
    return 0;
  else
    return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 8284), a2 != 0);
}
