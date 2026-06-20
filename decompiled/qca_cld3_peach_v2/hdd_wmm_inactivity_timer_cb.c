__int64 __fastcall hdd_wmm_inactivity_timer_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  __int64 v12; // x19
  __int64 v14; // x20
  _DWORD *v15; // x8
  __int64 v16; // x14
  unsigned int *v17; // x23
  unsigned int v18; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  unsigned int v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: invalid user data",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "hdd_wmm_inactivity_timer_cb");
  v11 = *(_QWORD *)(a1 + 24);
  if ( !v11 || *(_DWORD *)v11 != 1885692259 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: invalid adapter: %pK",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "hdd_wmm_inactivity_timer_cb");
  v12 = *(unsigned int *)(a1 + 32);
  if ( (unsigned int)v12 >= 4 )
  {
    __break(0x5512u);
    return hdd_get_handle_from_ts_id(a1, a2, a3);
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 24);
    v15 = (_DWORD *)(*(_QWORD *)(v11 + 52832) + 4 * v12);
    v16 = v11 + 280LL * (unsigned int)v12;
    v17 = (unsigned int *)(v16 + 1880);
    v18 = v15[1111]
        + v15[1099]
        + v15[1087]
        + v15[1075]
        + v15[1063]
        + v15[1051]
        + v15[1039]
        + v15[1027]
        + v15[1015]
        + v15[1003]
        + v15[991]
        + v15[979]
        + v15[967]
        + v15[955]
        + v15[943]
        + v15[931]
        + v15[919]
        + v15[907]
        + v15[895]
        + v15[883]
        + v15[871]
        + v15[859]
        + v15[847]
        + v15[835]
        + v15[823]
        + v15[811]
        + v15[799]
        + v15[787]
        + v15[775]
        + v15[763]
        + v15[751]
        + v15[739];
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: WMM inactivity check for AC=%d, count=%u, last=%u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_wmm_inactivity_timer_cb",
      (unsigned int)v12,
      v18,
      *(unsigned int *)(v16 + 1984));
    if ( v17[26] == v18 )
    {
      v27 = hdd_wmm_delts(v14, *(_DWORD *)(a1 + 16), v19, v20, v21, v22, v23, v24, v25, v26);
      return qdf_trace_msg(
               0x33u,
               3u,
               "%s: Deleted TS on AC %d, due to inactivity with status = %d!!!",
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               "hdd_wmm_inactivity_timer_cb",
               (unsigned int)v12,
               v27);
    }
    else
    {
      v37 = v17[65];
      v17[26] = v18;
      if ( v37 == 19 )
      {
        result = qdf_mc_timer_start((__int64)(v17 + 28), v17[25]);
        if ( (_DWORD)result )
          return qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Restarting inactivity timer failed on AC %d",
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   "hdd_wmm_inactivity_timer_cb",
                   (unsigned int)v12);
      }
      else
      {
        return qdf_mc_timer_get_current_state((__int64)(v17 + 28));
      }
    }
  }
  return result;
}
