__int64 __fastcall wlan_cfg80211_store_link_key(
        __int64 a1,
        unsigned int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7)
{
  int v14; // w0
  int v15; // w4
  unsigned int v16; // w0
  __int64 ml_sta_link_key; // x26
  __int64 v19; // x0
  int v20; // w19

  if ( a1 )
  {
    if ( !a5 )
    {
      qdf_trace_msg(72, 2, "%s: Key params is NULL", "wlan_cfg80211_store_link_key");
      return 4294967274LL;
    }
    v14 = osif_nl_to_crypto_cipher_len(*(unsigned int *)(a5 + 28));
    v15 = *(_DWORD *)(a5 + 16);
    if ( v14 < 0 || v15 < v14 )
    {
      qdf_trace_msg(72, 2, "%s: cipher length %d less than reqd len %d", "wlan_cfg80211_store_link_key", v15, v14);
    }
    else
    {
      v16 = osif_nl_to_crypto_cipher_type(*(unsigned int *)(a5 + 28));
      if ( (v16 > 0x10 || ((1 << v16) & 0x18001) == 0) && !a3 && !a4 )
      {
        qdf_trace_msg(72, 2, "%s: mac_addr is NULL for pairwise Key", "wlan_cfg80211_store_link_key");
        return 4294967274LL;
      }
      if ( (unsigned int)wlan_crypto_validate_key_params() )
      {
        qdf_trace_msg(72, 2, "%s: Invalid key params", "wlan_cfg80211_store_link_key");
      }
      else
      {
        wlan_crypto_aquire_lock();
        ml_sta_link_key = wlan_crypto_get_ml_sta_link_key(a1, a2, a6, a7);
        if ( !ml_sta_link_key )
        {
          wlan_crypto_release_lock();
          v19 = _qdf_mem_malloc(432, "wlan_cfg80211_store_link_key", 167);
          if ( !v19 )
            return 4294967274LL;
          ml_sta_link_key = v19;
          wlan_crypto_aquire_lock();
        }
        wlan_cfg80211_translate_ml_sta_key(a2, a3, a4, a5, ml_sta_link_key);
        v20 = wlan_crypto_save_ml_sta_key(a1, a2, ml_sta_link_key, a6, a7);
        wlan_crypto_release_lock();
        if ( !v20 )
          return 0;
        qdf_trace_msg(72, 2, "%s: Failed to save key", "wlan_cfg80211_store_link_key");
        _qdf_mem_free(ml_sta_link_key);
      }
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: psoc is NULL", "wlan_cfg80211_store_link_key");
  }
  return 4294967274LL;
}
