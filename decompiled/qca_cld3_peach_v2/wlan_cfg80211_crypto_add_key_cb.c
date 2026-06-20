__int64 __fastcall wlan_cfg80211_crypto_add_key_cb(__int64 a1, int a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  int v5; // w0

  v3 = osif_request_get();
  if ( !v3 )
    return qdf_trace_msg(72, 2, "%s: Obsolete request", "wlan_cfg80211_crypto_add_key_cb");
  v4 = v3;
  v5 = osif_request_priv(v3);
  qdf_mem_copy(v5, a2, 0x18u);
  osif_request_complete(v4);
  return osif_request_put(v4);
}
