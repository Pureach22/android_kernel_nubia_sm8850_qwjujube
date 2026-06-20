__int64 __fastcall ucfg_p2p_cleanup_tx_by_vdev(
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
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v31; // x2
  unsigned int v32; // w1

  if ( !a1 )
  {
    v31 = "%s: null vdev";
    v32 = 8;
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v31 = "%s: null psoc";
    v32 = 2;
LABEL_8:
    qdf_trace_msg(0x4Eu, v32, v31, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_p2p_cleanup_tx_by_vdev");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 5u);
  if ( comp_private_obj )
  {
    v21 = comp_private_obj;
    p2p_del_all_rand_mac_vdev(a1);
    return p2p_cleanup_tx_sync(v21, a1, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: null p2p soc obj",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ucfg_p2p_cleanup_tx_by_vdev");
    return 16;
  }
}
