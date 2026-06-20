__int64 __fastcall target_if_mc_cp_stats_big_data_stats_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x20
  unsigned int big_data_stats_param; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  unsigned int v34; // w0
  const char *v35; // x2
  __int64 result; // x0
  _DWORD *v37; // x8
  _QWORD v38[5]; // [xsp+8h] [xbp-28h] BYREF

  v38[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v38, 0, 32);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_mc_cp_stats_big_data_stats_event_handler",
      a1,
      a2);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v35 = "%s: null psoc";
LABEL_15:
    qdf_trace_msg(
      0x62u,
      2u,
      v35,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_mc_cp_stats_big_data_stats_event_handler");
    goto LABEL_16;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: rx_ops is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_cp_stats_get_rx_ops");
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(v20 + 192) )
  {
LABEL_13:
    v35 = "%s: callback not registered";
    goto LABEL_15;
  }
  v21 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v21 || (v22 = *(_QWORD *)(v21 + 16)) == 0 )
  {
    v35 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  v23 = psoc_from_scn_hdl;
  big_data_stats_param = wmi_extract_big_data_stats_param(v22, a2, v38);
  if ( big_data_stats_param )
  {
    v33 = big_data_stats_param;
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: extract event failed",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "target_if_mc_cp_stats_big_data_stats_event_handler");
    v34 = v33;
  }
  else
  {
    v37 = *(_DWORD **)(v20 + 192);
    if ( *(v37 - 1) != -615971336 )
      __break(0x8228u);
    v34 = ((__int64 (__fastcall *)(__int64, _QWORD *))v37)(v23, v38);
  }
  result = qdf_status_to_os_return(v34);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
