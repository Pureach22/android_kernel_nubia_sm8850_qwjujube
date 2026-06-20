__int64 __fastcall wlan_mlme_set_primary_interface(__int64 a1, unsigned __int8 a2)
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

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  *(_BYTE *)(psoc_ext_obj_fl + 1105) = a2;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Set primary iface to :%d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_mlme_set_primary_interface",
    a2);
  return 0;
}
