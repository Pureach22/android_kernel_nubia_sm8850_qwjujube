__int64 __fastcall nl80211_send_ibss_bssid(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  _DWORD *v9; // x20
  __int64 v10; // x0
  __int64 v11; // x24
  __int64 v12; // x0
  __int64 v13; // x3
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _alloc_skb(3712, a4, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v9 = (_DWORD *)result;
    v10 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 43);
    if ( !v10 )
    {
LABEL_7:
      result = sk_skb_reason_drop(v10, v9, 2);
      goto LABEL_8;
    }
    v11 = v10;
    v14 = *(_DWORD *)(a1 + 100);
    if ( (unsigned int)nla_put(v9, 1, 4, &v14)
      || (v14 = *(_DWORD *)(a2 + 224), (unsigned int)nla_put(v9, 3, 4, &v14))
      || (result = nla_put(v9, 6, 6, a3), (_DWORD)result) )
    {
      v10 = 0;
      goto LABEL_7;
    }
    *(_DWORD *)(v11 - 20) = v9[54] + v9[52] - (v11 - 20);
    if ( (unsigned __int8)byte_BF570 <= 3u )
    {
      __break(0x800u);
    }
    else
    {
      v12 = *(_QWORD *)(*(_QWORD *)(a1 + 2344) + 288LL);
      v13 = (unsigned int)(dword_BF5E4 + 3);
      v9[14] = v13;
      result = netlink_broadcast_filtered(v12, v9, 0, v13, a4, 0, 0);
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
