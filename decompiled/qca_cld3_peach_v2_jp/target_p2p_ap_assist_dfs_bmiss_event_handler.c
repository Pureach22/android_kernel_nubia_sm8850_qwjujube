__int64 __fastcall target_p2p_ap_assist_dfs_bmiss_event_handler(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x20
  const char *v22; // x2
  __int64 result; // x0
  __int64 (__fastcall *v24)(_QWORD); // x8
  unsigned int v25; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  _ReadStatusReg(SP_EL0);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
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
      "target_p2p_ap_assist_dfs_bmiss_event_handler",
      a1,
      a2);
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v22 = "%s: null psoc";
    goto LABEL_11;
  }
  v19 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v19 || (v20 = *(_QWORD *)(v19 + 16)) == 0 )
  {
    v22 = "%s: null wmi handle";
    goto LABEL_11;
  }
  v21 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_p2p_ap_assist_dfs_group_bmiss(v20, v11, v12, v13, v14, v15, v16, v17, v18) )
  {
    v22 = "%s: Failed to extract event";
LABEL_11:
    qdf_trace_msg(
      0x49u,
      2u,
      v22,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_p2p_ap_assist_dfs_bmiss_event_handler");
    goto LABEL_12;
  }
  v24 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v21 + 2136) + 152LL);
  if ( v24 )
  {
    if ( *((_DWORD *)v24 - 1) != -132374536 )
      __break(0x8228u);
    v25 = v24(v21);
    if ( v25 )
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: p2p ap assist bmiss handler error %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "target_p2p_ap_assist_dfs_bmiss_event_handler",
        v25);
  }
  else
  {
    v25 = 0;
  }
  result = qdf_status_to_os_return(v25);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
