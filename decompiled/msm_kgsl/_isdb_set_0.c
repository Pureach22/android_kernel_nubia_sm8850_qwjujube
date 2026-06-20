__int64 __fastcall isdb_set_0(__int64 a1)
{
  if ( (*(_QWORD *)(a1 + 14240) & 0x1000) != 0 )
    return 0;
  else
    return adreno_power_cycle(a1, (void (__fastcall *)(__int64, __int64))set_isdb, 0);
}
