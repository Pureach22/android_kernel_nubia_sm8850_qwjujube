__int64 __fastcall dispatcher_psoc_close(__int64 a1)
{
  mlme_psoc_close();
  wlan_coex_psoc_close(a1);
  dispatcher_ftm_psoc_close(a1);
  regulatory_psoc_close(a1);
  wlan_cp_stats_close(a1);
  ucfg_scan_psoc_close(a1);
  wlan_mgmt_txrx_psoc_close(a1);
  wlan_spectral_psoc_close(a1);
  return 0;
}
