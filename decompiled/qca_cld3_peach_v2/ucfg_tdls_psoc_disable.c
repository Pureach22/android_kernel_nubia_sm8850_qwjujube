__int64 __fastcall ucfg_tdls_psoc_disable(
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
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 comp_private_obj; // x0
  const char *v37; // x2

  qdf_trace_msg(0, 8u, "%s: psoc tdls disable: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_psoc_disable", a1);
  if ( a1 )
  {
    if ( (unsigned int)tgt_tdls_unregister_ev_handler(a1) )
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to unregister tdls event handler",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "ucfg_tdls_psoc_disable");
    v26 = tdls_mgmt_rx_ops(a1, 0, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v26 )
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to unregister mgmt rx callback",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "ucfg_tdls_psoc_disable");
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
    if ( comp_private_obj )
    {
      *(_QWORD *)(comp_private_obj + 264) = 0;
      *(_QWORD *)(comp_private_obj + 272) = 0;
      return v26;
    }
    v37 = "%s: Failed to get tdls psoc component";
  }
  else
  {
    v37 = "%s: NULL psoc";
  }
  qdf_trace_msg(0, 2u, v37, v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_tdls_psoc_disable");
  return 16;
}
