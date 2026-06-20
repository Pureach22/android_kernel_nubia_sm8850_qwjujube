__int64 __fastcall wlan_cm_get_roam_scan_high_rssi_offset(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return *(unsigned __int8 *)(result + 1552);
  return result;
}
