__int64 __fastcall nl80211_send_ap_started(__int64 *a1, char a2)
{
  __int64 v2; // x23
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x22
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  if ( *a1 )
  {
    result = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    if ( !result )
    {
LABEL_9:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v6 = result;
    v7 = genlmsg_put(result, 0, 0, &nl80211_fam, 0, 15);
    if ( !v7
      || (v8 = v7, LODWORD(v9[0]) = *(_DWORD *)(v2 - 892), (unsigned int)nla_put(v6, 1, 4, v9))
      || (LODWORD(v9[0]) = *(_DWORD *)(a1[4] + 224), (unsigned int)nla_put(v6, 3, 4, v9)) )
    {
LABEL_8:
      result = sk_skb_reason_drop(0, v6, 2);
      goto LABEL_9;
    }
    if ( *a1 )
    {
      v9[0] = *((unsigned int *)a1 + 10) | ((unsigned __int64)*(unsigned int *)(*a1 - 892) << 32);
      if ( !(unsigned int)nla_put_64bit(v6, 153, 8, v9, 229)
        && (!*((_BYTE *)a1 + 344) || !(unsigned int)nla_put(v6, 52, *((unsigned __int8 *)a1 + 344), a1 + 39)) )
      {
        if ( !*((_WORD *)a1 + 736) || (LOBYTE(v9[0]) = a2, !(unsigned int)nla_put(v6, 313, 1, v9)) )
        {
          *(_DWORD *)(v8 - 20) = *(_DWORD *)(v6 + 216) + *(_DWORD *)(v6 + 208) - (v8 - 20);
          result = genlmsg_multicast_netns(*(_QWORD *)(v2 + 1352), v6, 3u, 0xCC0u);
          goto LABEL_9;
        }
      }
      goto LABEL_8;
    }
  }
  else
  {
    __break(0x800u);
  }
  __break(0x800u);
  return validate_pae_over_nl80211();
}
