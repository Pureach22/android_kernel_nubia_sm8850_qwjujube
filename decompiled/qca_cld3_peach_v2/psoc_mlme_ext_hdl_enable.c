__int64 __fastcall psoc_mlme_ext_hdl_enable(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int16 v12; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v11 = psoc_ext_obj_fl;
  v12 = wlan_scan_register_requester(
          a1,
          "MLME_EXT",
          (__int64)wlan_mlme_chan_stats_scan_event_cb,
          0,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10);
  *(_WORD *)(v11 + 7832) = v12;
  return 0;
}
