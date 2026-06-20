__int64 __fastcall dp_destroy_direct_link_refill_ring(
        _QWORD *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  __int64 v15; // x20
  __int64 v17; // x1
  __int64 *v18; // x20
  __int64 v19; // t1
  void (*v20)(void); // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a2 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: DP pdev is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_destroy_direct_link_refill_ring");
  v15 = a1[9];
  if ( !v15 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: DP pdev is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_destroy_direct_link_refill_ring");
  v19 = *(_QWORD *)(v15 + 32);
  v18 = (__int64 *)(v15 + 32);
  v17 = v19;
  if ( v19 )
  {
    v20 = (void (*)(void))a1[219];
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != -1607343988 )
        __break(0x8228u);
      v20();
      v17 = *v18;
    }
    hal_srng_cleanup(a1[141], v17, 0, a12, a13, a14, a15);
    *v18 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: Ring type: %d, num:%d not setup",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_srng_deinit",
      a1,
      14,
      0);
  }
  return dp_srng_free((__int64)a1, (__int64)v18, v21, v22, v23, v24, v25, v26, v27, v28);
}
