__int64 __fastcall target_p2p_lo_event_handler(
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x2
  __int64 (__fastcall *v53)(__int64, __int64); // x8
  unsigned int v54; // w19
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7

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
    "target_p2p_lo_event_handler",
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
      "target_p2p_lo_event_handler",
      a1,
      a2);
    return 4294967274LL;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v51 = "%s: null psoc";
    goto LABEL_12;
  }
  v30 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 16)) == 0 )
  {
    v51 = "%s: null wmi handle";
LABEL_12:
    qdf_trace_msg(0x49u, 2u, v51, v22, v23, v24, v25, v26, v27, v28, v29, "target_p2p_lo_event_handler");
    return 4294967274LL;
  }
  v32 = psoc_from_scn_hdl;
  v33 = _qdf_mem_malloc(8u, "target_p2p_lo_event_handler", 90);
  if ( !v33 )
    return 4294967284LL;
  v42 = v33;
  if ( (unsigned int)wmi_extract_p2p_lo_stop_ev_param(v31, v34, v35, v36, v37, v38, v39, v40, v41) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to extract wmi p2p lo stop event",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "target_p2p_lo_event_handler");
    _qdf_mem_free(v42);
    return 4294967274LL;
  }
  v53 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v32 + 2136) + 128LL);
  if ( v53 )
  {
    if ( *((_DWORD *)v53 - 1) != 582246767 )
      __break(0x8228u);
    v54 = v53(v32, v42);
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: call lo event handler, status:%d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "target_p2p_lo_event_handler",
      v54);
  }
  else
  {
    _qdf_mem_free(v42);
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: no valid lo event handler",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "target_p2p_lo_event_handler");
    v54 = 16;
  }
  return qdf_status_to_os_return(v54);
}
