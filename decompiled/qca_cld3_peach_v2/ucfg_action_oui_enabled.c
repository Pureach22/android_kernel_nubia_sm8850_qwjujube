bool __fastcall ucfg_action_oui_enabled(__int64 a1)
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

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( comp_private_obj )
    return *(_BYTE *)(comp_private_obj + 8) != 0;
  qdf_trace_msg(0x63u, 2u, "%s: psoc priv is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "ucfg_action_oui_enabled");
  return 0;
}
