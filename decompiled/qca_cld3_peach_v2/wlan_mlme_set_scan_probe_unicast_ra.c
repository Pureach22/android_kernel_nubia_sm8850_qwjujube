__int64 __fastcall wlan_mlme_set_scan_probe_unicast_ra(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  __int64 v13; // x19

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v12 = a2 & 1;
  v13 = psoc_ext_obj_fl;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: scan_probe_unicast_ra %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_mlme_set_scan_probe_unicast_ra",
    v12);
  *(_BYTE *)(v13 + 3545) = v12;
  return 0;
}
