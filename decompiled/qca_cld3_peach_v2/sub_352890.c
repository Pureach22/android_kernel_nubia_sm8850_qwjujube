__int64 __fastcall sub_352890(long double a1, __int64 a2, __int64 a3)
{
  __int128 v3; // q31

  *(_OWORD *)(a3 - 800) = v3;
  *(long double *)(a3 - 784) = a1;
  return hdd_update_smps_antenna_mode();
}
