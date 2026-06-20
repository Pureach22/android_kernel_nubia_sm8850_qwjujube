__int64 __fastcall target_if_direct_buf_rx_module_unregister(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  const char *v12; // x2
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  __int64 v25; // x8
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w19
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v52; // x2

  if ( !a1 )
  {
    v12 = "%s: pdev context passed is null";
    goto LABEL_5;
  }
  v10 = a2;
  if ( a2 >= 4u )
  {
    v12 = "%s: Invalid module id";
LABEL_5:
    qdf_trace_msg(0x5Bu, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_direct_buf_rx_module_unregister");
    return 4;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 8u);
  if ( !comp_private_obj )
  {
    v52 = "%s: dir buf rx object is null";
LABEL_12:
    qdf_trace_msg(0x5Bu, 2u, v52, v16, v17, v18, v19, v20, v21, v22, v23, "target_if_direct_buf_rx_module_unregister");
    return 16;
  }
  v24 = comp_private_obj;
  qdf_trace_msg(
    0x5Bu,
    8u,
    "%s: Dbr pdev obj %pK",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "target_if_direct_buf_rx_module_unregister",
    comp_private_obj);
  v25 = *(_QWORD *)(v24 + 8);
  if ( !v25 )
  {
    v52 = "%s: dbr_pdev_obj->dbr_mod_param is NULL";
    goto LABEL_12;
  }
  if ( *(_BYTE *)(v25 + 112LL * a2 + 49) == 1 )
  {
    v26 = target_if_deinit_dbr_ring(a1, v24, v10, 0, v16, v17, v18, v19, v20, v21, v22, v23);
    qdf_trace_msg(
      0x5Bu,
      4u,
      "%s: status %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "target_if_direct_buf_rx_module_unregister",
      v26);
    v43 = target_if_deinit_dbr_ring(a1, v24, v10, 1u, v35, v36, v37, v38, v39, v40, v41, v42);
    qdf_trace_msg(
      0x5Bu,
      4u,
      "%s: status %d",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "target_if_direct_buf_rx_module_unregister",
      v43);
    return v43;
  }
  else
  {
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: Module %d not supported in target",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_direct_buf_rx_module_unregister",
      v10);
    return 11;
  }
}
