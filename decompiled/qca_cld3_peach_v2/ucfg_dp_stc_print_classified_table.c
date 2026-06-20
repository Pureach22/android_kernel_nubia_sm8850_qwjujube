__int64 __fastcall ucfg_dp_stc_print_classified_table(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj )
    return wlan_dp_stc_print_classified_table(comp_private_obj, v2);
  else
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DP context",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "ucfg_dp_stc_print_classified_table");
}
