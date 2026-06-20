__int64 __fastcall nl80211_get_wowlan(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  _DWORD *v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x22
  __int64 v11; // x23
  __int64 v12; // x24
  _WORD *v13; // x23
  _BYTE *v14; // x8
  int v16; // w0

  v2 = *((_QWORD *)a2 + 6);
  if ( !*(_QWORD *)(v2 + 1240) )
    return 4294967201LL;
  v3 = *(_QWORD *)(v2 + 1248);
  if ( v3 && (v5 = *(_DWORD **)(v3 + 16)) != nullptr )
    v6 = (v5[20] + v5[7] + v5[14] + (v5[14] >> 3) + 3715) & 0xFFFFFFFC;
  else
    v6 = 3712;
  v7 = _alloc_skb(v6, 3264, 0, 0xFFFFFFFFLL);
  if ( !v7 )
    return 4294967284LL;
  v8 = v7;
  v9 = genlmsg_put(v7, a2[1], *a2, &nl80211_fam, 0, 73);
  if ( !v9 )
    goto LABEL_34;
  v10 = v9;
  if ( *(_QWORD *)(v2 + 1248) )
  {
    v11 = *(_QWORD *)(v8 + 216);
    v12 = *(unsigned int *)(v8 + 208);
    if ( (nla_put(v8, 117, 0, 0) & 0x80000000) != 0 )
      goto LABEL_34;
    v13 = (_WORD *)(v11 + v12);
    if ( !v13 )
      goto LABEL_34;
    v14 = *(_BYTE **)(v2 + 1248);
    if ( *v14 == 1 )
    {
      if ( (unsigned int)nla_put(v8, 1, 0, 0) )
        goto LABEL_34;
      v14 = *(_BYTE **)(v2 + 1248);
    }
    if ( v14[1] == 1 )
    {
      if ( (unsigned int)nla_put(v8, 2, 0, 0) )
        goto LABEL_34;
      v14 = *(_BYTE **)(v2 + 1248);
    }
    if ( v14[2] == 1 )
    {
      if ( (unsigned int)nla_put(v8, 3, 0, 0) )
        goto LABEL_34;
      v14 = *(_BYTE **)(v2 + 1248);
    }
    if ( v14[3] == 1 )
    {
      if ( (unsigned int)nla_put(v8, 6, 0, 0) )
        goto LABEL_34;
      v14 = *(_BYTE **)(v2 + 1248);
    }
    if ( v14[4] == 1 )
    {
      if ( (unsigned int)nla_put(v8, 7, 0, 0) )
        goto LABEL_34;
      v14 = *(_BYTE **)(v2 + 1248);
    }
    if ( v14[5] != 1 )
    {
LABEL_29:
      if ( v14[6] == 1 && (unsigned int)nla_put(v8, 9, 0, 0)
        || (unsigned int)nl80211_send_wowlan_patterns(v8, v2)
        || (unsigned int)nl80211_send_wowlan_tcp(v8, *(_QWORD *)(*(_QWORD *)(v2 + 1248) + 16LL))
        || (unsigned int)nl80211_send_wowlan_nd(v8, *(_QWORD *)(*(_QWORD *)(v2 + 1248) + 32LL)) )
      {
        goto LABEL_34;
      }
      *v13 = *(_WORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (_WORD)v13;
      goto LABEL_38;
    }
    if ( !(unsigned int)nla_put(v8, 8, 0, 0) )
    {
      v14 = *(_BYTE **)(v2 + 1248);
      goto LABEL_29;
    }
LABEL_34:
    sk_skb_reason_drop(0, v8, 2);
    return 4294967191LL;
  }
LABEL_38:
  *(_DWORD *)(v10 - 20) = *(_DWORD *)(v8 + 216) + *(_DWORD *)(v8 + 208) - (v10 - 20);
  v16 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v8, a2[1], 64);
  return v16 & (unsigned int)(v16 >> 31);
}
