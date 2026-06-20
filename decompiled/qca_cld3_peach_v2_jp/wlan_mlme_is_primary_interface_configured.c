__int64 __fastcall wlan_mlme_is_primary_interface_configured(__int64 a1)
{
  return wlan_cm_same_band_sta_allowed(a1) & 1;
}
