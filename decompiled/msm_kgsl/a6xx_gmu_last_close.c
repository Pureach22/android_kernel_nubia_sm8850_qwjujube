__int64 __fastcall a6xx_gmu_last_close(__int64 a1, __int64 a2)
{
  if ( (*(_QWORD *)(a1 - 352) & 2) != 0 )
    return a6xx_power_off(a1, a2);
  else
    return 0;
}
