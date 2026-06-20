__int64 __fastcall usesgmem_store(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = a1 + 20480;
  if ( *(_BYTE *)(a1 + 24024) == 1 )
    return adreno_power_cycle_bool(a1, (_BYTE *)(a1 + 20581), a2 != 0);
  *(_BYTE *)(v2 + 101) = a2 != 0;
  return 0;
}
