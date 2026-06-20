__int64 *__fastcall dp_setup_direct_link_refill_ring(
        _QWORD *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v12; // x19
  const char *v13; // x2
  _DWORD *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x1
  _DWORD *v45; // x8

  if ( a2 || (v10 = a1[9]) == 0 )
  {
    v13 = "%s: DP pdev is NULL";
    goto LABEL_6;
  }
  v12 = (__int64 *)(v10 + 32);
  if ( (unsigned int)dp_srng_alloc(a1, v10 + 32, 0xEu, 0x280u, 0) )
  {
    v13 = "%s: SRNG alloc failed for rx_refill_buf_ring4";
LABEL_6:
    qdf_trace_msg(0x45u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "dp_setup_direct_link_refill_ring");
    return nullptr;
  }
  v14 = (_DWORD *)a1[224];
  if ( *(v14 - 1) != -386661336 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, __int64 *, __int64, __int64, _QWORD))v14)(a1, v12, 14, 3, 0) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: SRNG init failed for rx_refill_buf_ring4",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_setup_direct_link_refill_ring");
  }
  else
  {
    if ( !(unsigned int)htt_srng_setup(a1[6], 0, *v12, 14) )
      return v12;
    v44 = *v12;
    if ( *v12 )
    {
      v45 = (_DWORD *)a1[219];
      if ( v45 )
      {
        if ( *(v45 - 1) != -1607343988 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, __int64 *, __int64, __int64))v45)(a1, v12, 14, 3);
        v44 = *v12;
      }
      hal_srng_cleanup(a1[141], v44, 0, v32, v33, v34, v35);
      *v12 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x7Cu,
        2u,
        "%s: %pK: Ring type: %d, num:%d not setup",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "dp_srng_deinit",
        a1,
        14,
        3);
    }
  }
  dp_srng_free((__int64)a1, (__int64)v12, v23, v24, v25, v26, v27, v28, v29, v30);
  return nullptr;
}
