__int64 __fastcall target_p2p_mac_rx_filter_event_handler(
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
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 (__fastcall *v33)(__int64, __int64 *); // x8
  unsigned int v34; // w0
  __int64 v35; // [xsp+0h] [xbp-10h] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
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
      "target_p2p_mac_rx_filter_event_handler",
      a1,
      a2,
      v35,
      v36);
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
  if ( (unsigned int)wmi_extract_mac_addr_rx_filter_evt_param(v20, v11, v12, v13, v14, v15, v16, v17, v18) )
  {
    v22 = "%s: failed to extract wmi p2p noa event";
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
      "target_p2p_mac_rx_filter_event_handler",
      v35,
      v36);
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: vdev_id %d status %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "target_p2p_mac_rx_filter_event_handler",
    (unsigned int)v35,
    HIDWORD(v35));
  v32 = *(_QWORD *)(v21 + 2136);
  if ( v32 == -128 || (v33 = *(__int64 (__fastcall **)(__int64, __int64 *))(v32 + 144)) == nullptr )
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: no add mac addr filter event handler",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "target_p2p_mac_rx_filter_event_handler",
      v35,
      v36);
    v34 = 16;
  }
  else
  {
    if ( *((_DWORD *)v33 - 1) != -963366421 )
      __break(0x8228u);
    v34 = v33(v21, &v35);
  }
  result = qdf_status_to_os_return(v34);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
