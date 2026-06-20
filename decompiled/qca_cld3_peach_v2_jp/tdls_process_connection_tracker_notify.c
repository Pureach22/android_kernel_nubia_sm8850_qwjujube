__int64 __fastcall tdls_process_connection_tracker_notify(
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
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x19
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x5
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x6

  v10 = *(unsigned __int16 *)(a2 + 8);
  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 152);
    if ( v11 && (v13 = *(_QWORD *)(v11 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
      comp_private_obj = 0;
    }
    v15 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
    v24 = v15;
    if ( comp_private_obj && v15 )
      return 0;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    qdf_trace_msg(0, 2u, "%s: NULL vdev", v26, v27, v28, v29, v30, v31, v32, v33, "wlan_vdev_get_tdls_vdev_obj");
    v24 = 0;
    comp_private_obj = 0;
  }
  if ( (unsigned int)v10 > 3 )
    v34 = "INVALID_TYPE";
  else
    v34 = off_A2B9E8[v10];
  qdf_trace_msg(
    0,
    2u,
    "%s: soc_obj: %pK, vdev_obj: %pK, ignore %s",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "tdls_process_connection_tracker_notify",
    comp_private_obj,
    v24,
    v34);
  return 29;
}
