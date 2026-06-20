__int64 __fastcall wlan_cfg80211_ftm_rx_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  _QWORD *v6; // x8
  __int64 v8; // x0
  __int64 v9; // x21
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  result = 4;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( a3 )
    {
      v6 = *(_QWORD **)(a1 + 24);
      if ( v6 )
      {
        v8 = _cfg80211_alloc_event_skb(*v6, 0, 45, 69, 0, 0xFFFFFFFFLL, a3, 2080);
        if ( v8 )
        {
          v9 = v8;
          v10 = 0;
          if ( (unsigned int)nla_put(v8, 1, 4, &v10) || (unsigned int)nla_put(v9, 2, a3, a2) )
          {
            _qdf_nbuf_free(v9);
            result = 4;
          }
          else
          {
            _cfg80211_send_event_skb(v9, 2080);
            result = 0;
          }
        }
        else
        {
          result = 2;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
