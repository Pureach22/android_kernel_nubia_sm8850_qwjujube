__int64 __fastcall target_if_dbam_response_event_handler(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 psoc_from_scn_hdl; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 v33; // x20
  const char *v34; // x2
  __int64 result; // x0
  _DWORD *v36; // x8

  _ReadStatusReg(SP_EL0);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: scn:%pK, data:%pK, datalen:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "target_if_dbam_response_event_handler",
    a1,
    a2,
    a3);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_dbam_response_event_handler",
      a1,
      a2);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v34 = "%s: psoc is Null";
    goto LABEL_15;
  }
  v30 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v30 )
  {
    qdf_trace_msg(0x70u, 2u, "%s: rx_ops is NULL", v22, v23, v24, v25, v26, v27, v28, v29, "wlan_psoc_get_dbam_rx_ops");
    goto LABEL_13;
  }
  if ( !*(_QWORD *)(v30 + 1384) )
  {
LABEL_13:
    v34 = "%s: callback not registered";
    goto LABEL_15;
  }
  v31 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v31 || (v32 = *(_QWORD *)(v31 + 16)) == 0 )
  {
    v34 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  v33 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_dbam_config_response(v32) )
  {
    v34 = "%s: Failed to extract dbam config response";
LABEL_15:
    qdf_trace_msg(0x49u, 2u, v34, v22, v23, v24, v25, v26, v27, v28, v29, "target_if_dbam_response_event_handler");
    goto LABEL_16;
  }
  v36 = *(_DWORD **)(v30 + 1384);
  if ( *(v36 - 1) != -921119303 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v36)(v33, 0);
  if ( (_DWORD)result )
  {
    v34 = "%s: process dbam response event failed";
    goto LABEL_15;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
