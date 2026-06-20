__int64 __fastcall nl80211_michael_mic_failure(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        int a5,
        __int64 a6,
        unsigned int a7)
{
  __int64 result; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 v17; // x27
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, a7, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v15 = result;
    v16 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 41);
    if ( v16 )
    {
      v17 = v16;
      v18 = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(v15, 1, 4, &v18) )
      {
        v18 = *(_DWORD *)(a2 + 224);
        if ( !(unsigned int)nla_put(v15, 3, 4, &v18) && (!a3 || !(unsigned int)nla_put(v15, 6, 6, a3)) )
        {
          v18 = a4;
          if ( !(unsigned int)nla_put(v15, 55, 4, &v18) )
          {
            if ( a5 == -1 || (LOBYTE(v18) = a5, !(unsigned int)nla_put(v15, 8, 1, &v18)) )
            {
              if ( !a6 || !(unsigned int)nla_put(v15, 10, 6, a6) )
              {
                *(_DWORD *)(v17 - 20) = *(_DWORD *)(v15 + 216) + *(_DWORD *)(v15 + 208) - (v17 - 20);
                result = genlmsg_multicast_netns(*(_QWORD *)(a1 + 2344), v15, 3u, a7);
                goto LABEL_7;
              }
            }
          }
        }
      }
      v16 = 0;
    }
    result = sk_skb_reason_drop(v16, v15, 2);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
