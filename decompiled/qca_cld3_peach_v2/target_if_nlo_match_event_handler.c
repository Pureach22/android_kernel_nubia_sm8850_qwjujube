__int64 __fastcall target_if_nlo_match_event_handler(
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
  __int64 v20; // x8
  __int64 v21; // x21
  __int64 v22; // x22
  __int64 v23; // x0
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  __int64 (__fastcall *v44)(__int64, __int64); // x8

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
      "target_if_nlo_match_event_handler",
      a1,
      a2);
    return 4294967274LL;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v33 = "%s: null psoc";
    goto LABEL_13;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    v33 = "%s: wmi_handle is NULL";
LABEL_13:
    qdf_trace_msg(0x49u, 2u, v33, v12, v13, v14, v15, v16, v17, v18, v19, "target_if_nlo_match_event_handler");
    return 4294967274LL;
  }
  v22 = psoc_from_scn_hdl;
  v23 = _qdf_mem_malloc(0x38u, "target_if_nlo_match_event_handler", 218);
  if ( !v23 )
    return 4294967284LL;
  v24 = v23;
  if ( (unsigned int)wmi_extract_nlo_match_ev_param(v21, a2, v23 + 8) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to extract WMI PNO match event",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "target_if_nlo_match_event_handler");
LABEL_9:
    _qdf_mem_free(v24);
    return 4294967274LL;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: PNO match event received for vdev %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "target_if_nlo_match_event_handler",
    *(unsigned int *)(v24 + 8));
  v43 = *(_QWORD *)(v22 + 2136);
  if ( !v43 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", v35, v36, v37, v38, v39, v40, v41, v42, "target_if_scan_get_rx_ops");
    v33 = "%s: scan_rx_ops is NULL";
    goto LABEL_13;
  }
  v44 = *(__int64 (__fastcall **)(__int64, __int64))(v43 + 56);
  if ( !v44 )
    goto LABEL_9;
  if ( *((_DWORD *)v44 - 1) != -351425983 )
    __break(0x8228u);
  result = v44(v22, v24);
  if ( (_DWORD)result )
    goto LABEL_9;
  return result;
}
