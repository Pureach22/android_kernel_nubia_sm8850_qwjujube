__int64 __fastcall ucfg_p2p_cleanup_tx_by_psoc(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
    if ( comp_private_obj )
    {
      v19 = comp_private_obj;
      p2p_del_all_rand_mac_soc(a1, v11, v12, v13, v14, v15, v16, v17, v18);
      return p2p_cleanup_tx_sync(v19, 0, v20, v21, v22, v23, v24, v25, v26, v27);
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: null p2p soc obj",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "ucfg_p2p_cleanup_tx_by_psoc");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: null psoc", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_p2p_cleanup_tx_by_psoc");
    return 4;
  }
}
