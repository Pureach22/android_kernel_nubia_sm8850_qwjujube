__int64 __fastcall pmo_core_enhanced_mc_filter_disable(
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
  unsigned int ref; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  unsigned int *v28; // x8
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_enhanced_mc_filter_disable");
  ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( !ref )
  {
    v27 = pmo_tgt_send_enhance_multicast_offload_req(a1, 0);
    wlan_objmgr_vdev_release_ref(a1, 0xAu, v28, v27, v29, v30, v31, v32, v33, v34, v35);
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_core_enhanced_mc_filter_disable");
  return ref;
}
