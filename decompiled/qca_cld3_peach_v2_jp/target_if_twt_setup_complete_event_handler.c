__int64 __fastcall target_if_twt_setup_complete_event_handler(
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
  __int64 v20; // x23
  __int64 v21; // x22
  __int64 rx_ops; // x0
  __int64 v23; // x25
  __int64 v24; // x0
  __int64 v25; // x21
  unsigned int twt_add_dialog_comp_event; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int twt_add_dialog_comp_additional_params; // w24
  const char *v36; // x2
  __int64 (__fastcall *v38)(__int64, __int64); // x8

  qdf_trace_msg(0x49u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_twt_setup_complete_event_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v36 = "%s: psoc is null";
    goto LABEL_12;
  }
  v19 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v19 || (v20 = *(_QWORD *)(v19 + 16)) == 0 )
  {
    v36 = "%s: wmi_handle is null";
LABEL_12:
    qdf_trace_msg(0x49u, 2u, v36, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_twt_setup_complete_event_handler");
    return 4294967274LL;
  }
  v21 = psoc_from_scn_hdl;
  rx_ops = wlan_twt_get_rx_ops(psoc_from_scn_hdl, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !rx_ops || !*(_QWORD *)(rx_ops + 16) )
  {
    v36 = "%s: No valid twt setup complete rx ops";
    goto LABEL_12;
  }
  v23 = rx_ops;
  v24 = _qdf_mem_malloc(0x30u, "target_if_twt_setup_complete_event_handler", 59);
  if ( !v24 )
    return 4294967284LL;
  v25 = v24;
  twt_add_dialog_comp_event = wmi_extract_twt_add_dialog_comp_event(v20);
  if ( twt_add_dialog_comp_event )
  {
    twt_add_dialog_comp_additional_params = twt_add_dialog_comp_event;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: extract twt add dialog event failed (status=%d)",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "target_if_twt_setup_complete_event_handler",
      twt_add_dialog_comp_event);
  }
  else if ( !*(_DWORD *)(v25 + 20)
         || (twt_add_dialog_comp_additional_params = wmi_extract_twt_add_dialog_comp_additional_params(v20)) == 0 )
  {
    v38 = *(__int64 (__fastcall **)(__int64, __int64))(v23 + 16);
    if ( *((_DWORD *)v38 - 1) != -1016068838 )
      __break(0x8228u);
    twt_add_dialog_comp_additional_params = v38(v21, v25);
  }
  _qdf_mem_free(v25);
  return qdf_status_to_os_return(twt_add_dialog_comp_additional_params);
}
