__int64 __fastcall wlan_roam_update_cfg(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v4; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v4 = a2;
  if ( (unsigned int)mlme_get_roam_state(a1, a2) == 2 )
    return cm_roam_send_rso_cmd(a1, v4, 4u, a3);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Update cfg received while ROAM RSO not started",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wlan_roam_update_cfg");
  return 4;
}
