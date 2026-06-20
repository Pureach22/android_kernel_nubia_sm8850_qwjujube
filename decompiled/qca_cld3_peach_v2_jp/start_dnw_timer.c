__int64 __fastcall start_dnw_timer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 10) == 1 )
    {
      qdf_trace_msg(0x98u, 8u, "%s: dnw timer started", a2, a3, a4, a5, a6, a7, a8, a9, "start_dnw_timer");
      return 16;
    }
    else
    {
      qdf_trace_msg(
        0x98u,
        8u,
        "%s: DFS no wait timer start on freq %d, duration %d sec",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "start_dnw_timer",
        *(unsigned int *)(a1 + 12),
        *(unsigned int *)(a1 + 24) / 0x3E8uLL);
      qdf_mc_timer_init(a1 + 32, 0, (__int64)wlan_dnw_timer_callback, a1);
      result = qdf_mc_timer_start(a1 + 32, *(_DWORD *)(a1 + 24));
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x98u,
          2u,
          "%s: failed to start cac timer",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "start_dnw_timer");
        *(_BYTE *)(a1 + 10) = 0;
        qdf_mc_timer_destroy(a1 + 32);
        return 16;
      }
      else
      {
        *(_BYTE *)(a1 + 10) = 1;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s: null dnw_pdev_info", a2, a3, a4, a5, a6, a7, a8, a9, "start_dnw_timer");
    return 4;
  }
  return result;
}
