__int64 __fastcall psoc_mlme_ext_hdl_disable(__int64 a1)
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

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  wlan_scan_unregister_requester(a1, *(unsigned __int16 *)(psoc_ext_obj_fl + 7608), v3, v4, v5, v6, v7, v8, v9, v10);
  return 0;
}
