__int64 __fastcall mlo_is_sta_in_quiet_status(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 *v20; // x8
  __int64 v21; // x9
  unsigned __int8 v22; // w20

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 1656);
    v20 = *(unsigned __int8 **)(a1 + 2224);
    if ( v20 )
    {
      if ( (v20[194] & 1) != 0 && v20[192] == a2 )
      {
        v21 = 192;
      }
      else
      {
        if ( v20[197] != 1 || v20[195] != a2 )
        {
          v22 = 0;
          goto LABEL_13;
        }
        v21 = 195;
      }
      v22 = v20[v21 + 1];
LABEL_13:
      qdf_mutex_release(a1 + 1656);
      return v22 & 1;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid sta_ctx",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "mlo_is_sta_in_quiet_status");
    qdf_mutex_release(a1 + 1656);
    v22 = 0;
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: invalid mlo_dev_ctx", a3, a4, a5, a6, a7, a8, a9, a10, "mlo_is_sta_in_quiet_status");
    v22 = 0;
  }
  return v22 & 1;
}
