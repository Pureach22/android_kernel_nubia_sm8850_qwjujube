__int64 __fastcall sub_428E28(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        long double a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int128 v9; // q11

  *(long double *)(a9 - 1008) = a5;
  *(_OWORD *)(a9 - 992) = v9;
  return lim_obss_send_detection_cfg(a1, a2, a3);
}
