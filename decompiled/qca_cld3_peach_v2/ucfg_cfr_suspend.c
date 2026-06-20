__int64 __fastcall ucfg_cfr_suspend(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
    return cfr_allow_suspend(comp_private_obj, v2, v3, v4, v5, v6, v7, v8, v9);
  qdf_trace_msg(0x6Au, 2u, "%s: null pcfr", v2, v3, v4, v5, v6, v7, v8, v9, "ucfg_cfr_suspend");
  return 4;
}
