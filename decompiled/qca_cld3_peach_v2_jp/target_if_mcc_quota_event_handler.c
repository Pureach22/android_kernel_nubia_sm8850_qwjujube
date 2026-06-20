__int64 __fastcall target_if_mcc_quota_event_handler(
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
  __int64 v30; // x8
  __int64 v31; // x21
  __int64 v32; // x22
  __int64 v33; // x0
  __int64 v34; // x19
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  const char *v44; // x2
  __int64 v46; // x8
  __int64 (__fastcall *v47)(__int64, __int64); // x8
  unsigned int v48; // w20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7

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
    "target_if_mcc_quota_event_handler",
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
      "target_if_mcc_quota_event_handler",
      a1,
      a2);
    return 4294967274LL;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v44 = "%s: null psoc";
    goto LABEL_13;
  }
  v30 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 16)) == 0 )
  {
    v44 = "%s: null wmi handle";
LABEL_13:
    qdf_trace_msg(0x49u, 2u, v44, v22, v23, v24, v25, v26, v27, v28, v29, "target_if_mcc_quota_event_handler");
    return 4294967274LL;
  }
  v32 = psoc_from_scn_hdl;
  v33 = _qdf_mem_malloc(0x28u, "target_if_mcc_quota_event_handler", 69);
  if ( !v33 )
    return 4294967284LL;
  v34 = v33;
  if ( (unsigned int)wmi_extract_mcc_quota_ev_param(v31, a2, v33) )
  {
    v43 = "%s: failed to extract mcc quota event";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v43, v35, v36, v37, v38, v39, v40, v41, v42, "target_if_mcc_quota_event_handler");
    _qdf_mem_free(v34);
    return 4294967274LL;
  }
  v46 = *(_QWORD *)(v32 + 2136);
  if ( !v46 )
  {
    v43 = "%s: failed to get soc rx ops";
    goto LABEL_9;
  }
  v47 = *(__int64 (__fastcall **)(__int64, __int64))(v46 + 160);
  if ( v47 )
  {
    if ( *((_DWORD *)v47 - 1) != 1824194349 )
      __break(0x8228u);
    v48 = v47(v32, v34);
    if ( v48 )
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: quota event handler, status:%d",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "target_if_mcc_quota_event_handler",
        v48);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: no valid mcc quota event handler",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "target_if_mcc_quota_event_handler");
    v48 = 16;
  }
  _qdf_mem_free(v34);
  return qdf_status_to_os_return(v48);
}
