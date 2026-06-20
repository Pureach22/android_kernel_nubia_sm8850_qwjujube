__int64 __fastcall cfg_p2p_is_go_ignore_non_p2p_probe_req(__int64 a1)
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

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( comp_private_obj )
    return (*(unsigned __int8 *)(comp_private_obj + 272) >> 3) & 1;
  qdf_trace_msg(
    0x4Eu,
    2u,
    "%s: p2p psoc null",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "cfg_p2p_is_go_ignore_non_p2p_probe_req");
  return 0;
}
