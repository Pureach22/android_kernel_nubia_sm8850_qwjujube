__int64 __fastcall wlan_ipa_uc_stat_query(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  *a2 = 0;
  *a3 = 0;
  qdf_mutex_acquire(a1 + 7224);
  if ( wlan_ipa_is_fw_wdi_activated(a1) && (*(_BYTE *)(a1 + 3720) & 1) == 0 )
  {
    *a2 = *(_DWORD *)(a1 + 4104);
    *a3 = *(_DWORD *)(a1 + 4108);
  }
  return qdf_mutex_release(a1 + 7224);
}
