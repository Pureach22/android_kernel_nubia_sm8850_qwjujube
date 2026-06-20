__int64 __fastcall nl80211_get_station(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x22
  int v9; // w0
  __int64 s[34]; // [xsp+10h] [xbp-110h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 48);
  v4 = *(_QWORD *)(a2 + 56);
  memset(s, 0, 0x108u);
  v5 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 48LL);
  if ( v5 )
  {
    if ( *(_QWORD *)(*(_QWORD *)v3 + 160LL) )
    {
      result = rdev_get_station(v3, v4, v5 + 4, s);
      if ( !(_DWORD)result )
      {
        v7 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
        if ( v7 )
        {
          v8 = v7;
          if ( (nl80211_send_station(v7, 0x13u, *(_DWORD *)(a2 + 4), *(_DWORD *)a2, 0, v3, v4, v5 + 4, s) & 0x80000000) != 0 )
          {
            sk_skb_reason_drop(0, v8, 2);
            result = 4294967191LL;
          }
          else
          {
            v9 = netlink_unicast(*(_QWORD *)(*(_QWORD *)(a2 + 40) + 288LL), v8, *(unsigned int *)(a2 + 4), 64);
            result = v9 & (unsigned int)(v9 >> 31);
          }
        }
        else
        {
          kfree(s[25]);
          result = 4294967284LL;
        }
      }
    }
    else
    {
      result = 4294967201LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
