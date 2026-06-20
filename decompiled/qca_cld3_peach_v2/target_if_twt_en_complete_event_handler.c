__int64 __fastcall target_if_twt_en_complete_event_handler(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 psoc_from_scn_hdl; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x20
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  const char *v43; // x2
  __int64 result; // x0
  __int64 (__fastcall *v45)(__int64, __int64 *); // x8
  __int64 v46; // [xsp+0h] [xbp-10h] BYREF

  qdf_trace_msg(
    0x49u,
    8u,
    "%s: enter",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_twt_en_complete_event_handler",
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_twt_en_complete_event_handler",
      a1,
      a2);
LABEL_16:
    result = 4294967274LL;
    goto LABEL_17;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v43 = "%s: psoc is null";
LABEL_15:
    qdf_trace_msg(0x49u, 2u, v43, v21, v22, v23, v24, v25, v26, v27, v28, "target_if_twt_en_complete_event_handler");
    goto LABEL_16;
  }
  v29 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v29 )
  {
    v43 = "%s: rx_ops is NULL";
    goto LABEL_15;
  }
  if ( !*(_QWORD *)(v29 + 1312) )
  {
    v43 = "%s: TWT rx_ops comp_cb is NULL";
    goto LABEL_15;
  }
  v30 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 16)) == 0 )
  {
    v43 = "%s: wmi_handle is null";
    goto LABEL_15;
  }
  v32 = psoc_from_scn_hdl;
  v33 = wmi_extract_twt_enable_comp_event(v31, a2, &v46);
  if ( v33 )
  {
    v42 = v33;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: TWT enable extract event failed(status=%d)",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "target_if_twt_en_complete_event_handler",
      v33);
  }
  else
  {
    v45 = *(__int64 (__fastcall **)(__int64, __int64 *))(v29 + 1312);
    if ( *((_DWORD *)v45 - 1) != 1962600890 )
      __break(0x8228u);
    v42 = v45(v32, &v46);
  }
  result = qdf_status_to_os_return(v42);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
