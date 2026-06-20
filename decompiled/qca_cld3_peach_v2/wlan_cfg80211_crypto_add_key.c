__int64 __fastcall wlan_cfg80211_crypto_add_key(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, char a5)
{
  __int64 key; // x23
  __int64 comp_private_obj; // x0
  __int64 v12; // x19
  __int64 v13; // x0
  __int64 v14; // x20
  unsigned int v15; // w21
  __int64 v16; // x0
  _DWORD *v18; // x0

  wlan_crypto_aquire_lock();
  key = wlan_crypto_get_key(a1, a2, a4);
  wlan_crypto_release_lock();
  if ( !key )
  {
    qdf_trace_msg(72, 2, "%s: Crypto KEY is NULL", "wlan_cfg80211_crypto_add_key");
    return 4294967274LL;
  }
  if ( (a5 & 1) == 0 )
  {
    v16 = ucfg_crypto_set_key_req(a1, key, a3);
    return qdf_status_to_os_return(v16);
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(72, 2, "%s: Invalid crypto_priv", "wlan_cfg80211_crypto_add_key");
    return 4294967274LL;
  }
  v12 = comp_private_obj;
  v13 = osif_request_alloc(&wlan_cfg80211_crypto_add_key_params);
  if ( !v13 )
  {
    qdf_trace_msg(72, 2, "%s: Request allocation failure", "wlan_cfg80211_crypto_add_key");
    return 4294967284LL;
  }
  v14 = v13;
  *(_QWORD *)(v12 + 432) = osif_request_cookie();
  *(_QWORD *)(v12 + 440) = wlan_cfg80211_crypto_add_key_cb;
  v15 = ucfg_crypto_set_key_req(a1, key, a3);
  if ( !v15 )
  {
    if ( (unsigned int)osif_request_wait_for_response(v14) )
    {
      qdf_trace_msg(72, 2, "%s: Target response timed out", "wlan_cfg80211_crypto_add_key");
    }
    else
    {
      v18 = (_DWORD *)osif_request_priv(v14);
      qdf_trace_msg(
        72,
        8,
        "%s: complete, vdev_id %u, ix: %u, flags: %u, status: %u",
        "wlan_cfg80211_crypto_add_key",
        *v18,
        v18[1],
        v18[2],
        v18[3]);
    }
  }
  *(_QWORD *)(v12 + 432) = 0;
  *(_QWORD *)(v12 + 440) = 0;
  osif_request_put(v14);
  v16 = v15;
  return qdf_status_to_os_return(v16);
}
