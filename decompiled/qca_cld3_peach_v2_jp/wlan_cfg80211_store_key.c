__int64 __fastcall wlan_cfg80211_store_key(__int64 a1, unsigned int a2, int a3, __int64 a4, __int64 a5)
{
  int v10; // w0
  int v11; // w4
  unsigned int v12; // w0
  __int64 key; // x24
  __int64 v15; // x0
  int v16; // w19

  if ( a1 )
  {
    if ( !a5 )
    {
      qdf_trace_msg(72, 2, "%s: Key params is NULL", "wlan_cfg80211_store_key");
      return 4294967274LL;
    }
    v10 = osif_nl_to_crypto_cipher_len(*(unsigned int *)(a5 + 28));
    v11 = *(_DWORD *)(a5 + 16);
    if ( v10 < 0 || v11 < v10 )
    {
      qdf_trace_msg(72, 2, "%s: cipher length %d less than reqd len %d", "wlan_cfg80211_store_key", v11, v10);
    }
    else
    {
      v12 = osif_nl_to_crypto_cipher_type(*(unsigned int *)(a5 + 28));
      if ( (v12 > 0x10 || ((1 << v12) & 0x18001) == 0) && !a3 && !a4 )
      {
        qdf_trace_msg(72, 2, "%s: mac_addr is NULL for pairwise Key", "wlan_cfg80211_store_key");
        return 4294967274LL;
      }
      if ( (unsigned int)wlan_crypto_validate_key_params() )
      {
        qdf_trace_msg(72, 2, "%s: Invalid key params", "wlan_cfg80211_store_key");
      }
      else
      {
        wlan_crypto_aquire_lock();
        key = wlan_crypto_get_key(a1, a4, a2);
        if ( !key )
        {
          wlan_crypto_release_lock();
          v15 = _qdf_mem_malloc(432, "wlan_cfg80211_store_key", 236);
          if ( !v15 )
            return 4294967274LL;
          key = v15;
          wlan_crypto_aquire_lock();
        }
        wlan_cfg80211_translate_key(a1, a2, a3, a4, a5, key);
        v16 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))wlan_crypto_save_key)(a1, a4, a2, key);
        wlan_crypto_release_lock();
        if ( !v16 )
          return 0;
        qdf_trace_msg(72, 2, "%s: Failed to save key", "wlan_cfg80211_store_key");
        _qdf_mem_free(key);
      }
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: vdev is NULL", "wlan_cfg80211_store_key");
  }
  return 4294967274LL;
}
