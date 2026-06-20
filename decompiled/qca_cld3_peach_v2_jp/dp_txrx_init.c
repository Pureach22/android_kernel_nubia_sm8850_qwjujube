__int64 __fastcall dp_txrx_init(
        __int64 **a1,
        char a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v11; // x22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  void (__fastcall *v33)(__int64 **, __int64); // x8
  const char *v34; // x2
  __int64 result; // x0
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19
  __int64 *v46; // x8
  __int64 *v47; // x8
  __int64 v48; // x8
  __int64 (__fastcall *v49)(_QWORD); // x8
  unsigned __int8 v50; // w21
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w20

  if ( !a1 )
  {
    v34 = "%s: soc is NULL";
    goto LABEL_12;
  }
  if ( a2 || (v11 = a1[9]) == nullptr )
  {
    v34 = "%s: pdev is NULL";
LABEL_12:
    qdf_trace_msg(0x45u, 2u, v34, a4, a5, a6, a7, a8, a9, a10, a11, "dp_txrx_init");
    return 0;
  }
  v14 = _qdf_mem_malloc(0x120u, "dp_txrx_init", 1639);
  if ( !v14 )
    return 2;
  v23 = v14;
  qdf_trace_msg(0x45u, 5u, "%s: dp_txrx_handle allocated", v15, v16, v17, v18, v19, v20, v21, v22, "dp_txrx_init");
  *(_QWORD *)v23 = a1;
  *(_QWORD *)(v23 + 8) = v11;
  if ( *a1 )
  {
    v32 = **a1;
    if ( v32 )
    {
      v33 = *(void (__fastcall **)(__int64 **, __int64))(v32 + 632);
      if ( v33 )
      {
        if ( *((_DWORD *)v33 - 1) != -72667692 )
          __break(0x8228u);
        v33(a1, v23);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "cdp_soc_set_dp_txrx_handle");
  }
  qdf_mem_copy((void *)(v23 + 280), a3, 1u);
  *(_QWORD *)(v23 + 24) = v23;
  *(_QWORD *)(v23 + 264) = a1;
  v36 = dp_rx_refill_thread_init(v23 + 56);
  if ( v36 )
  {
    v45 = v36;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to initialize RX refill thread status:%d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "dp_txrx_init",
      v36);
    _qdf_mem_free(v23);
    return v45;
  }
  *(_BYTE *)(v23 + 256) = 1;
  v46 = a1[1];
  if ( v46 )
  {
    v46[40] = (__int64)dp_rx_refill_thread_schedule;
    v47 = *a1;
    if ( !*a1 )
      goto LABEL_28;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "cdp_register_rx_refill_thread_sched_handler");
    v47 = *a1;
    if ( !*a1 )
    {
LABEL_28:
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v37, v38, v39, v40, v41, v42, v43, v44, "cdp_get_num_rx_contexts");
      goto LABEL_29;
    }
  }
  v48 = v47[8];
  if ( !v48 )
    goto LABEL_28;
  v49 = *(__int64 (__fastcall **)(_QWORD))(v48 + 176);
  if ( !v49 )
  {
LABEL_29:
    v50 = 0;
    goto LABEL_30;
  }
  if ( *((_DWORD *)v49 - 1) != 639071501 )
    __break(0x8228u);
  v50 = v49(a1);
LABEL_30:
  qdf_trace_msg(0x45u, 5u, "%s: %d RX threads in use", v37, v38, v39, v40, v41, v42, v43, v44, "dp_txrx_init", v50);
  if ( *(_BYTE *)(v23 + 280) != 1 )
    return 0;
  result = dp_rx_tm_init((unsigned __int8 *)(v23 + 16), v50, v51, v52, v53, v54, v55, v56, v57, v58);
  if ( (_DWORD)result )
  {
    v59 = result;
    dp_txrx_deinit(a1);
    return v59;
  }
  return result;
}
