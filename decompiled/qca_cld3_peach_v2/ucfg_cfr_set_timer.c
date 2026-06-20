__int64 __fastcall ucfg_cfr_set_timer(__int64 a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2

  if ( (wlan_cfr_is_feature_disabled(a1) & 1) != 0 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: cfr is disabled", v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_cfr_set_timer");
    return 11;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
  {
    if ( *(_BYTE *)(comp_private_obj + 8) )
      return tgt_cfr_enable_cfr_timer(a1, a2, v14, v15, v16, v17, v18, v19, v20, v21);
    v22 = "%s: cfr is not supported on this chip";
  }
  else
  {
    v22 = "%s: PDEV cfr object is NULL!";
  }
  qdf_trace_msg(0x6Au, 2u, v22, v14, v15, v16, v17, v18, v19, v20, v21, "ucfg_cfr_set_timer");
  return 4294967274LL;
}
