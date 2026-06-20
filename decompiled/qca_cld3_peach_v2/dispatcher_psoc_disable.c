__int64 __fastcall dispatcher_psoc_disable(__int64 a1)
{
  __int64 v2; // x8
  void (__fastcall *v3)(_QWORD); // x8

  wlan_coap_disable();
  wlan_dbam_psoc_disable(a1);
  twt_psoc_disable(a1);
  wlan_mlo_mgr_psoc_disable(a1);
  wlan_mgmt_txrx_psoc_disable(a1);
  wlan_mlme_psoc_disable(a1);
  wlan_crypto_psoc_disable(a1);
  if ( a1 && (v2 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v3 = *(void (__fastcall **)(_QWORD))(v2 + 1784);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != -770124015 )
        __break(0x8228u);
      v3(a1);
    }
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: tx_ops is NULL", "dispatcher_dbr_psoc_disable");
  }
  wifi_dfs_psoc_disable(a1);
  wifi_pos_psoc_disable(a1);
  wlan_cp_stats_disable(a1);
  ucfg_scan_psoc_disable(a1);
  wlan_serialization_psoc_disable(a1);
  wlan_spectral_psoc_disable(a1);
  return 0;
}
