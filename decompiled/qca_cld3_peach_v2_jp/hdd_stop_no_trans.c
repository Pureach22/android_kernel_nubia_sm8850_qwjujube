__int64 __fastcall hdd_stop_no_trans(
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
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x21
  int v29; // w23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int conparam; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w21
  const char *v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned __int64 v88; // x10

  v10 = *(_QWORD *)(a1 + 2712);
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_stop_no_trans", a1 + 296);
  qdf_mtrace(51, 51, 1u, *(_BYTE *)(*(_QWORD *)(a1 + 55512) + 8LL), *(_DWORD *)(a1 + 2728));
  result = _wlan_hdd_validate_context(v10, (__int64)"hdd_stop_no_trans", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( (_DWORD)result )
    return result;
  if ( (*(_QWORD *)(a1 + 4312) & 4) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NETDEV Interface is not OPENED",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_stop_no_trans");
    return 4294967277LL;
  }
  v28 = *(_QWORD *)(v10 + 16);
  v29 = *(unsigned __int8 *)(a1 + 2728);
  if ( !_cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", v20, v21, v22, v23, v24, v25, v26, v27) )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: HDD context is NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_hdd_is_session_type_monitor");
    goto LABEL_9;
  }
  conparam = cds_get_conparam();
  if ( v29 != 6 || conparam == 4 )
  {
LABEL_9:
    if ( *(_DWORD *)(a1 + 2728) != 4 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Disabling Auto Power save timer",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "hdd_stop_no_trans");
      ((void (__fastcall *)(__int64, _QWORD))sme_ps_disable_auto_ps_timer)(
        v28,
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 55512) + 8LL));
    }
  }
  v47 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 55512) + 8LL);
  v48 = qdf_opmode_str(*(_DWORD *)(a1 + 2728));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d Disabling queues, adapter device mode: %s(%d)",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "hdd_stop_no_trans",
    v47,
    v48,
    *(unsigned int *)(a1 + 2728));
  wlan_hdd_netif_queue_control(a1 + 2688, 4, 1);
  v57 = *(_DWORD *)(a1 + 2728);
  if ( !v57 )
  {
    hdd_lpass_notify_stop(v10);
    v57 = *(_DWORD *)(a1 + 2728);
  }
  if ( v57 != 11 )
  {
    hdd_stop_adapter(v10, a1 + 2688);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "hdd_deinit_adapter",
      *(_QWORD *)(a1 + 2720) + 296LL);
    hdd_deinit_session(a1 + 2688);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v66, v67, v68, v69, v70, v71, v72, v73, "hdd_deinit_adapter");
  }
  _X8 = (unsigned __int64 *)(a1 + 4312);
  __asm { PRFM            #0x11, [X8] }
  do
    v88 = __ldxr(_X8);
  while ( __stxr(v88 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  if ( (hdd_is_any_interface_open(v10) & 1) == 0 )
    hdd_psoc_idle_timer_start(v10);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v74, v75, v76, v77, v78, v79, v80, v81, "hdd_stop_no_trans");
  return 0;
}
