__int64 __fastcall wlan_cfg80211_coap_cache_get_cbk(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x0

  if ( result )
  {
    if ( a2 )
    {
      result = osif_request_get(result);
      if ( result )
      {
        v3 = result;
        v4 = osif_request_priv(result);
        if ( *(_DWORD *)(a2 + 4) == *(_DWORD *)(v4 + 4) )
        {
          qdf_list_join(v4 + 16, (__int64 *)(a2 + 16));
          if ( (*(_BYTE *)(a2 + 8) & 1) == 0 )
            osif_request_complete(v3);
        }
        return osif_request_put(v3);
      }
    }
  }
  return result;
}
