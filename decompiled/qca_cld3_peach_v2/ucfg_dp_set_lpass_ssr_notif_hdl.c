__int64 __fastcall ucfg_dp_set_lpass_ssr_notif_hdl(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj && (v12 = *(_QWORD *)(comp_private_obj + 1472)) != 0 )
  {
    *(_QWORD *)(v12 + 32) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Invalid DP or DP direct link context",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_dp_set_lpass_ssr_notif_hdl");
    return 16;
  }
}
