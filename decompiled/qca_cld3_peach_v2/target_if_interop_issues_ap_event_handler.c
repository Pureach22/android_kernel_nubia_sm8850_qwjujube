__int64 __fastcall target_if_interop_issues_ap_event_handler(
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
  __int64 v20; // x8
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  const char *v31; // x2
  __int64 v32; // [xsp+8h] [xbp-28h] BYREF
  __int64 v33; // [xsp+10h] [xbp-20h]
  __int64 v34; // [xsp+18h] [xbp-18h]
  __int64 v35; // [xsp+20h] [xbp-10h]
  __int64 v36; // [xsp+28h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  qdf_trace_msg(0x49u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_interop_issues_ap_event_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v31 = "%s: psoc ptr is NULL";
    goto LABEL_8;
  }
  v19 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  v33 = psoc_from_scn_hdl;
  if ( !v19 || (v20 = *(_QWORD *)(v19 + 16)) == 0 )
  {
    v31 = "%s: wmi_handle is null.";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v31, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_interop_issues_ap_event_handler");
    goto LABEL_9;
  }
  v21 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_interop_issues_ap_ev_param(v20) )
  {
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: interop issues ap macaddr: %02x:%02x:%02x:**:**:%02x",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "target_if_interop_issues_ap_event_handler",
    BYTE4(v34),
    BYTE5(v34),
    BYTE6(v34),
    BYTE1(v35));
  result = tgt_interop_issues_ap_info_callback(v21, &v32);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
