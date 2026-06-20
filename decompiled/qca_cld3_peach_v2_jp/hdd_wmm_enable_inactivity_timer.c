__int64 __fastcall hdd_wmm_enable_inactivity_timer(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w20
  __int64 v3; // x23
  __int64 v5; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  int v33; // w9
  __int64 v34; // x11
  __int64 v35; // x12
  int v36; // w12

  v2 = *(_DWORD *)(a1 + 32);
  if ( v2 >= 5 )
  {
LABEL_12:
    __break(0x5512u);
    return hdd_wmm_enable_tl_uapsd();
  }
  v3 = *(_QWORD *)(a1 + 24);
  v5 = v3 + 280LL * v2;
  if ( (unsigned int)qdf_mc_timer_init(v5 + 1992, 0, (__int64)hdd_wmm_inactivity_timer_cb, a1) )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Initializing inactivity timer failed on AC %d",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "hdd_wmm_enable_inactivity_timer",
             v2);
  result = qdf_mc_timer_start(v5 + 1992, a2);
  if ( !(_DWORD)result )
  {
    v32 = 0;
    *(_DWORD *)(v5 + 1980) = a2;
    *(_DWORD *)(v5 + 1984) = 0;
    v33 = 0;
    v34 = *(_QWORD *)(v3 + 52824) + 2684LL;
    while ( 1 )
    {
      v35 = *(unsigned int *)(a1 + 32);
      if ( (unsigned int)v35 > 3 )
        break;
      v36 = *(_DWORD *)(v34 + 4 * v35 + v32);
      v32 += 48;
      v33 += v36;
      *(_DWORD *)(v5 + 1984) = v33;
      if ( v32 == 1536 )
      {
        *(_BYTE *)(a1 + 76) = 1;
        return result;
      }
    }
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Starting inactivity timer failed on AC %d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "hdd_wmm_enable_inactivity_timer",
    v2);
  result = qdf_mc_timer_destroy(v5 + 1992);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Failed to destroy inactivity timer",
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             "hdd_wmm_enable_inactivity_timer");
  return result;
}
