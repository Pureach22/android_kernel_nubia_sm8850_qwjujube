__int64 __fastcall wlan_p2p_cleanup_roc_by_vdev(
        __int64 a1,
        char a2,
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
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 comp_private_obj; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v32; // x2
  unsigned int v33; // w1

  qdf_trace_msg(0x4Eu, 8u, "%s: vdev:%pK", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_p2p_cleanup_roc_by_vdev", a1);
  if ( !a1 )
  {
    v32 = "%s: null vdev";
    v33 = 8;
    goto LABEL_8;
  }
  v20 = *(_QWORD *)(a1 + 216);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 80)) == 0 )
  {
    v32 = "%s: null psoc";
    v33 = 2;
LABEL_8:
    qdf_trace_msg(0x4Eu, v33, v32, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_p2p_cleanup_roc_by_vdev");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v21, 5u);
  if ( comp_private_obj )
    return p2p_cleanup_roc(comp_private_obj, a1, a2 & 1, v23, v24, v25, v26, v27, v28, v29, v30);
  qdf_trace_msg(
    0x4Eu,
    2u,
    "%s: p2p soc context is NULL",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wlan_p2p_cleanup_roc_by_vdev");
  return 16;
}
