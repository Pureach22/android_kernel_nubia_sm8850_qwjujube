__int64 __fastcall ucfg_tdls_psoc_enable(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  qdf_trace_msg(0, 8u, "%s: psoc tdls enable: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_psoc_enable", a1);
  if ( !a1 )
  {
    qdf_trace_msg(0, 2u, "%s: NULL psoc", v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_tdls_psoc_enable");
    return 16;
  }
  result = tgt_tdls_register_ev_handler(a1);
  if ( (_DWORD)result )
    return result;
  v19 = wlan_serialization_register_comp_info_cb(a1, 0xAu, 0, (__int64)tdls_scan_serialization_comp_info_cb);
  if ( v19 )
  {
    v28 = v19;
    qdf_trace_msg(
      0,
      2u,
      "%s: Serialize scan cmd register failed ",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "ucfg_tdls_psoc_enable");
  }
  else
  {
    result = tdls_mgmt_rx_ops(a1, 1, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( !(_DWORD)result )
      return result;
    v28 = result;
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to register mgmt rx callback, status:%d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "ucfg_tdls_psoc_enable",
      (unsigned int)result);
  }
  return v28;
}
