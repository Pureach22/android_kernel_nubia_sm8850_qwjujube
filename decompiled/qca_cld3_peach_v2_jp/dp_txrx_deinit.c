__int64 __fastcall dp_txrx_deinit(
        __int64 **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 (*v9)(void); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 v22; // x1
  __int64 v23; // x1
  __int64 v24; // x1
  __int64 v25; // x1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x8
  _DWORD *v43; // x8

  if ( !a1 )
    return 4;
  if ( !*a1 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_soc_get_dp_txrx_handle");
    return 5;
  }
  v9 = *(__int64 (**)(void))(**a1 + 624);
  if ( !v9 )
    return 5;
  if ( *((_DWORD *)v9 - 1) != -1355198606 )
    __break(0x8228u);
  v11 = v9();
  if ( !v11 )
    return 5;
  v21 = v11;
  if ( *(_BYTE *)(v11 + 256) == 1 )
  {
    wlan_dp_resource_mgr_notify_refill_thread_deinit();
    *(_QWORD *)(v21 + 224) |= 0x12uLL;
    _wake_up(v21 + 232, 1, 1, 0);
    qdf_wait_single_event(v21 + 184, 0);
    qdf_event_destroy(v21 + 64, v22);
    qdf_event_destroy(v21 + 104, v23);
    qdf_event_destroy(v21 + 144, v24);
    qdf_event_destroy(v21 + 184, v25);
    *(_DWORD *)(v21 + 272) = 0;
    *(_QWORD *)(v21 + 264) = 0;
    *(_BYTE *)(v21 + 256) = 0;
  }
  if ( *(_BYTE *)(v21 + 280) == 1 )
    dp_rx_tm_deinit((unsigned __int8 *)(v21 + 16), v12, v13, v14, v15, v16, v17, v18, v19, v20);
  _qdf_mem_free(v21);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: dp_txrx_handle_t de-allocated",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "dp_txrx_deinit");
  if ( *a1 )
  {
    v42 = **a1;
    if ( v42 )
    {
      v43 = *(_DWORD **)(v42 + 632);
      if ( v43 )
      {
        if ( *(v43 - 1) != -72667692 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 **, _QWORD))v43)(a1, 0);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "cdp_soc_set_dp_txrx_handle");
  }
  return 0;
}
