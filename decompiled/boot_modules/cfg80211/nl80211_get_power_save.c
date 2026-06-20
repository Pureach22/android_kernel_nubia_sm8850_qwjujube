__int64 __fastcall nl80211_get_power_save(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 result; // x0
  int v9; // w0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(**((_QWORD **)a2 + 6) + 536LL) )
  {
    v3 = *(_QWORD *)(*((_QWORD *)a2 + 7) + 992LL);
    v4 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    if ( v4 )
    {
      v5 = v4;
      v6 = genlmsg_put(v4, a2[1], *a2, &nl80211_fam, 0, 62);
      if ( v6 && (v7 = v6, v10 = *(unsigned __int8 *)(v3 + 165), !(unsigned int)nla_put(v5, 93, 4, &v10)) )
      {
        *(_DWORD *)(v7 - 20) = *(_DWORD *)(v5 + 216) + *(_DWORD *)(v5 + 208) - (v7 - 20);
        v9 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v5, a2[1], 64);
        result = v9 & (unsigned int)(v9 >> 31);
      }
      else
      {
        sk_skb_reason_drop(0, v5, 2);
        result = 4294967191LL;
      }
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967201LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
