__int64 __fastcall wlan_is_sae_auth_log_present_for_bssid(__int64 a1, unsigned int *a2, unsigned __int8 *a3)
{
  return wlan_is_log_record_present_for_bssid(a1, a2, *a3) & 1;
}
