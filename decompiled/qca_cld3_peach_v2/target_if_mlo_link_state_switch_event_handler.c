__int64 __fastcall target_if_mlo_link_state_switch_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_from_scn_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x22
  __int64 v25; // x21
  unsigned int mlo_link_state_switch_evt; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w19
  unsigned int v36; // w0
  const char *v37; // x2
  __int64 result; // x0
  _DWORD *v39; // x8
  _QWORD v40[15]; // [xsp+8h] [xbp-88h] BYREF
  int v41; // [xsp+80h] [xbp-10h]
  __int64 v42; // [xsp+88h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  memset(v40, 0, sizeof(v40));
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_mlo_link_state_switch_event_handler",
      a1,
      a2);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v37 = "%s: null psoc";
    goto LABEL_15;
  }
  v22 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v22 || (v23 = *(_QWORD *)(v22 + 16)) == 0 )
  {
    v37 = "%s: wmi_handle is null";
LABEL_15:
    qdf_trace_msg(
      0x49u,
      2u,
      v37,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_mlo_link_state_switch_event_handler");
    goto LABEL_16;
  }
  v24 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v24 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "target_if_mlo_get_rx_ops");
    goto LABEL_14;
  }
  if ( !*(_QWORD *)(v24 + 1280) )
  {
LABEL_14:
    v37 = "%s: callback not registered";
    goto LABEL_15;
  }
  v25 = psoc_from_scn_hdl;
  mlo_link_state_switch_evt = wmi_extract_mlo_link_state_switch_evt(v23, a2, a3, v40);
  if ( mlo_link_state_switch_evt )
  {
    v35 = mlo_link_state_switch_evt;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Unable to extract link state switch params",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "target_if_mlo_link_state_switch_event_handler");
    v36 = v35;
  }
  else
  {
    v39 = *(_DWORD **)(v24 + 1280);
    if ( *(v39 - 1) != -929714912 )
      __break(0x8228u);
    v36 = ((__int64 (__fastcall *)(__int64, _QWORD *))v39)(v25, v40);
  }
  result = qdf_status_to_os_return(v36);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
