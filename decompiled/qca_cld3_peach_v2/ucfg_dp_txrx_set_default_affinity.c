__int64 __fastcall ucfg_dp_txrx_set_default_affinity(__int64 a1)
{
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  if ( wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu) )
    return wlan_dp_lb_set_default_affinity();
  else
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: DP context not found",
             v1,
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             "ucfg_dp_txrx_set_default_affinity");
}
