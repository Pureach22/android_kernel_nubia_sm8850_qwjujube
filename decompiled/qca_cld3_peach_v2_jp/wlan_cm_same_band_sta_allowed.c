bool __fastcall wlan_cm_same_band_sta_allowed(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  _BOOL8 result; // x0

  result = true;
  if ( (wlan_mlme_get_dual_sta_roaming_enabled(a1) & 1) != 0 )
  {
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
    if ( psoc_ext_obj_fl )
    {
      if ( *(unsigned __int8 *)(psoc_ext_obj_fl + 1105) == 255 || *(_BYTE *)(psoc_ext_obj_fl + 1104) )
        return false;
    }
  }
  return result;
}
