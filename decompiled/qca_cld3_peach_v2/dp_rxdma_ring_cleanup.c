__int64 __fastcall dp_rxdma_ring_cleanup(
        _QWORD *a1,
        __int64 a2,
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
  __int64 v17; // x1
  __int64 *v18; // x21
  void (*v19)(void); // x8
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x1
  __int64 *v33; // x20
  __int64 v34; // t1
  _DWORD *v35; // x8
  __int64 v36; // x8
  __int64 v37; // x8
  __int64 (__fastcall *v38)(_QWORD); // x8
  const char *v40; // x2
  __int64 v41; // t1

  if ( *(_BYTE *)a2 )
    goto LABEL_13;
  v18 = (__int64 *)(a2 + 112);
  v17 = *(_QWORD *)(a2 + 112);
  if ( v17 )
  {
    v19 = (void (*)(void))a1[219];
    if ( v19 )
    {
      if ( *((_DWORD *)v19 - 1) != -1607343988 )
        __break(0x8228u);
      v19();
      v17 = *v18;
    }
    hal_srng_cleanup(a1[141], v17, 0, a12, a13, a14, a15);
    *v18 = 0;
    v34 = *(_QWORD *)(a2 + 192);
    v33 = (__int64 *)(a2 + 192);
    v32 = v34;
    if ( v34 )
      goto LABEL_8;
LABEL_21:
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: Ring type: %d, num:%d not setup",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_srng_deinit",
      a1,
      14,
      1);
    v36 = a1[2514];
    if ( v36 )
      goto LABEL_14;
LABEL_22:
    v40 = "%s: monitor soc is NULL";
    return qdf_trace_msg(0x92u, 8u, v40, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_reap_timer_deinit");
  }
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
    1);
  v41 = *(_QWORD *)(a2 + 192);
  v33 = (__int64 *)(a2 + 192);
  v32 = v41;
  if ( !v41 )
    goto LABEL_21;
LABEL_8:
  v35 = (_DWORD *)a1[219];
  if ( v35 )
  {
    if ( *(v35 - 1) != -1607343988 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64 *, __int64, __int64))v35)(a1, v33, 14, 1);
    v32 = *v33;
  }
  hal_srng_cleanup(a1[141], v32, 0, v20, v21, v22, v23);
  *v33 = 0;
LABEL_13:
  v36 = a1[2514];
  if ( !v36 )
    goto LABEL_22;
LABEL_14:
  v37 = *(_QWORD *)(v36 + 416);
  if ( !v37 || (v38 = *(__int64 (__fastcall **)(_QWORD))(v37 + 544)) == nullptr )
  {
    v40 = "%s: callback not registered";
    return qdf_trace_msg(0x92u, 8u, v40, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_reap_timer_deinit");
  }
  if ( *((_DWORD *)v38 - 1) != -1093861181 )
    __break(0x8228u);
  return v38(a1);
}
