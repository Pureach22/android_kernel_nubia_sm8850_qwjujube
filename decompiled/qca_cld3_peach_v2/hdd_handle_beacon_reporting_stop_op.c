__int64 __fastcall hdd_handle_beacon_reporting_stop_op(
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
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w21
  const char *v30; // x2
  unsigned int v31; // w0
  unsigned int v32; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  sme_stop_beacon_report(
    *(_QWORD *)(a1 + 16),
    *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL),
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10);
  v20 = sme_register_bcn_report_pe_cb(*(_QWORD *)(a1 + 16), 0, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( v20 )
  {
    v29 = v20;
    v30 = "%s: Callback de-registration failed = %d";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v30, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_handle_beacon_reporting_stop_op", v29);
    v32 = v29;
    return qdf_status_to_os_return(v32);
  }
  v31 = sme_register_bcn_recv_pause_ind_cb(*(_QWORD *)(a1 + 16), 0, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( v31 )
  {
    v29 = v31;
    v30 = "%s: scan even deregister failed = %d";
    goto LABEL_5;
  }
  if ( hdd_cm_is_vdev_associated(*(_DWORD **)(a2 + 52832))
    && (unsigned int)hdd_add_beacon_filter(a1, *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL)) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Beacon filter addition failed",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "hdd_handle_beacon_reporting_stop_op");
    return 4294967274LL;
  }
  v32 = 0;
  return qdf_status_to_os_return(v32);
}
