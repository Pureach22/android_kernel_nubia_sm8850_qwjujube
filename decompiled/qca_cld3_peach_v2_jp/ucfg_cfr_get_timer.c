__int64 __fastcall ucfg_cfr_get_timer(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2

  if ( (wlan_cfr_is_feature_disabled(a1) & 1) != 0 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: cfr is disabled", v2, v3, v4, v5, v6, v7, v8, v9, "ucfg_cfr_get_timer");
    return 11;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
  {
    if ( *(_BYTE *)(comp_private_obj + 8) )
      return *(unsigned __int8 *)(comp_private_obj + 9);
    v20 = "%s: cfr is not supported on this chip";
  }
  else
  {
    v20 = "%s: PDEV cfr object is NULL!";
  }
  qdf_trace_msg(0x6Au, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "ucfg_cfr_get_timer");
  return 4294967274LL;
}
