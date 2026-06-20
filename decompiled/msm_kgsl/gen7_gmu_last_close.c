__int64 __fastcall gen7_gmu_last_close(__int64 a1, __int64 a2)
{
  if ( (*(_QWORD *)(a1 - 680) & 2) != 0 )
    return gen7_power_off(a1, a2);
  else
    return 0;
}
