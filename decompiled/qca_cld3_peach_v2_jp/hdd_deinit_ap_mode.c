__int64 __fastcall hdd_deinit_ap_mode(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int64 v34; // x10

  v9 = *(_QWORD *)a1;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_deinit_ap_mode",
    *(_QWORD *)(*(_QWORD *)a1 + 32LL) + 296LL);
  if ( (*(_QWORD *)(v9 + 1624) & 2) != 0 )
  {
    hdd_wmm_adapter_close(v9);
    _X8 = (unsigned __int64 *)(v9 + 1624);
    __asm { PRFM            #0x11, [X8] }
    do
      v34 = __ldxr(_X8);
    while ( __stxr(v34 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  }
  a1[586] = 0;
  if ( a1[587] )
  {
    a1[587] = 0;
    policy_mgr_set_chan_switch_complete_evt(**(_QWORD **)(v9 + 24));
    v11 = wlan_hdd_set_roaming_state(a1, 8, 1);
  }
  a1[592] = 0;
  if ( (unsigned int)hdd_hostapd_deinit_sap_session((__int64)a1, v11, v12, v13, v14, v15, v16, v17, v18) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed:hdd_hostapd_deinit_sap_session",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_deinit_ap_mode");
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "hdd_deinit_ap_mode");
}
