__int64 __fastcall sub_18456C(double a1, double a2, long double a3)
{
  __int64 v3; // x21
  __int128 v4; // q27

  *(_OWORD *)v3 = v4;
  *(long double *)(v3 + 16) = a3;
  return sde_hw_ctl_update_output_fence();
}
