__int64 __fastcall target_if_pmo_gtk_offload_status_event(
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
  __int64 v19; // x22
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  unsigned __int8 *v30; // x19
  __int64 v31; // x0
  const char *v32; // x2
  unsigned int v33; // w20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  qdf_trace_msg(0x49u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_pmo_gtk_offload_status_event");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( psoc_from_scn_hdl )
  {
    v19 = psoc_from_scn_hdl;
    v20 = _qdf_mem_malloc(0x48u, "target_if_pmo_gtk_offload_status_event", 124);
    if ( !v20 )
    {
      v33 = -12;
      goto LABEL_11;
    }
    v29 = *(_QWORD *)(v19 + 2800);
    v30 = (unsigned __int8 *)v20;
    if ( !v29 || (v31 = *(_QWORD *)(v29 + 16)) == 0 )
    {
      v32 = "%s: Invalid wmi handle";
      goto LABEL_9;
    }
    if ( (unsigned int)wmi_extract_gtk_rsp_event(v31) )
    {
      v32 = "%s: Extraction of gtk rsp event failed";
LABEL_9:
      qdf_trace_msg(0x49u, 2u, v32, v21, v22, v23, v24, v25, v26, v27, v28, "target_if_pmo_gtk_offload_status_event");
      _qdf_mem_free((__int64)v30);
      v33 = -22;
      goto LABEL_11;
    }
    if ( (unsigned int)pmo_tgt_gtk_rsp_evt(v19, v30, v21, v22, v23, v24, v25, v26, v27, v28) )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Failed to rx_gtk_rsp_event",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "target_if_pmo_gtk_offload_status_event");
      v33 = -22;
    }
    else
    {
      v33 = 0;
    }
    _qdf_mem_free((__int64)v30);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc ptr is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_pmo_gtk_offload_status_event");
    v33 = -22;
  }
LABEL_11:
  qdf_trace_msg(0x49u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "target_if_pmo_gtk_offload_status_event");
  return v33;
}
