__int64 __fastcall wlan_cm_roam_set_full_scan_6ghz_on_disc(__int64 a1, char a2)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    *(_BYTE *)(result + 2559) = a2;
  return result;
}
