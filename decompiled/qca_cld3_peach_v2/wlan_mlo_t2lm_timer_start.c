__int64 __fastcall wlan_mlo_t2lm_timer_start(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  unsigned int v11; // w19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w8
  bool v30; // cf
  unsigned int v31; // w8
  __int64 result; // x0
  __int64 v33; // x3

  if ( !a2 )
  {
    qdf_trace_msg(0x99u, 8u, "%s: Timer interval is 0", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_t2lm_timer_start");
    return 29;
  }
  if ( !a1 )
    return 29;
  v10 = *(_QWORD *)(a1 + 1360);
  if ( !v10 )
    return 29;
  v11 = (a2 << 10) / 0x3E8u;
  v12 = jiffies_to_msecs(jiffies) + v11;
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: earlier timer @%u ms out, new @%u ms out",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_mlo_t2lm_timer_start",
    *(unsigned int *)(v10 + 2444),
    v12);
  v29 = *(_DWORD *)(v10 + 2444);
  if ( !v29 || (v30 = v29 >= v12, v31 = v29 - v12, result = 29, v30) && v31 >= 0x62 )
  {
    if ( *(_BYTE *)(v10 + 2448) == 1 )
      hrtimer_cancel(v10 + 2352);
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: t2lm timer started with interval %d ms",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_mlo_t2lm_timer_start",
      v11);
    if ( *(_DWORD *)(v10 + 2416) == 1 )
      v33 = 5;
    else
      v33 = 1;
    *(_DWORD *)(v10 + 2440) = v11;
    *(_BYTE *)(v10 + 2448) = 1;
    *(_DWORD *)(v10 + 2444) = v12;
    hrtimer_start_range_ns(v10 + 2352, 1000000LL * v11, 0, v33);
    return 0;
  }
  return result;
}
