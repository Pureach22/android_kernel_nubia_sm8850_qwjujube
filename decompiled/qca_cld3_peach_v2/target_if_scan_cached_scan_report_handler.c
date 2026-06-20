__int64 __fastcall target_if_scan_cached_scan_report_handler(
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
  __int64 pdev_from_scn_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x22
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x21
  __int64 cached_scan_report_ev_params; // x0
  __int64 v28; // x19
  void (__fastcall *v29)(__int64, __int64); // x8
  const char *v31; // x2

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
      "target_if_scan_cached_scan_report_handler",
      a1,
      a2);
    return 4294967274LL;
  }
  pdev_from_scn_hdl = target_if_get_pdev_from_scn_hdl(a1);
  if ( !pdev_from_scn_hdl )
  {
    v31 = "%s: null pdev";
LABEL_19:
    qdf_trace_msg(0x49u, 2u, v31, v14, v15, v16, v17, v18, v19, v20, v21, "target_if_scan_cached_scan_report_handler");
    return 4294967274LL;
  }
  v22 = *(_QWORD *)(pdev_from_scn_hdl + 80);
  if ( !v22 )
  {
    v31 = "%s: null psoc";
    goto LABEL_19;
  }
  v23 = *(_QWORD *)(v22 + 2136);
  if ( !v23 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "target_if_scan_get_rx_ops");
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(v23 + 72) )
  {
LABEL_17:
    v31 = "%s: scan_rx_ops or handler is NULL";
    goto LABEL_19;
  }
  v24 = *(_QWORD *)(v22 + 2800);
  if ( !v24 || (v25 = *(_QWORD *)(v24 + 16)) == 0 )
  {
    v31 = "%s: wmi_handle is NULL";
    goto LABEL_19;
  }
  v26 = pdev_from_scn_hdl;
  cached_scan_report_ev_params = wmi_extract_cached_scan_report_ev_params(v25, a2, a3);
  if ( !cached_scan_report_ev_params )
    return 4294967274LL;
  v28 = cached_scan_report_ev_params;
  v29 = *(void (__fastcall **)(__int64, __int64))(v23 + 72);
  if ( *((_DWORD *)v29 - 1) != 223207110 )
    __break(0x8228u);
  v29(v26, cached_scan_report_ev_params);
  _qdf_mem_free(*(_QWORD *)(v28 + 16));
  _qdf_mem_free(*(_QWORD *)(v28 + 24));
  _qdf_mem_free(v28);
  return 0;
}
