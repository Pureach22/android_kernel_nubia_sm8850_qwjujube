__int64 __fastcall hdd_start_ap_link(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int inited; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  v9 = a1[34];
  if ( !v9 && !hdd_sap_create_ctx((__int64)a1, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    qdf_trace_msg(0x33u, 2u, "%s: sap creation failed", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_start_ap_link");
    return 16;
  }
  v11 = hdd_vdev_create((__int64)a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v11 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to create vdev, ret:%d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_start_ap_link",
      v11);
    inited = 16;
LABEL_7:
    hdd_sap_destroy_ctx((__int64)a1, v20, v21, v22, v23, v24, v25, v26, v27);
    return inited;
  }
  inited = hdd_init_ap_mode(a1, v9 != 0, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( inited )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error Initializing the AP mode: %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "hdd_start_ap_link",
      inited);
    hdd_vdev_destroy((__int64)a1, v37, v38, v39, v40, v41, v42, v43, v44);
    goto LABEL_7;
  }
  return inited;
}
