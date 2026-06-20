__int64 __fastcall wlan_cm_set_roam_scan_high_rssi_offset(__int64 a1, char a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_BYTE *)(result + 1552) = a2;
  return result;
}
