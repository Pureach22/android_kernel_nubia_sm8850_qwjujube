__int64 __fastcall nl80211_remain_on_channel(__int64 a1, unsigned int *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  unsigned int v4; // w22
  __int64 v5; // x19
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 result; // x0
  unsigned int v9; // w21
  __int64 v11; // x2
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x22
  __int64 v15; // x0
  __int64 v16; // x24
  int v17; // w0
  unsigned int v18; // w19
  int v19; // w0
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v21[4]; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v22[2]; // [xsp+30h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD **)a2 + 4);
  v3 = v2[313];
  if ( v3 )
    v4 = *(unsigned __int8 *)(v3 + 4);
  else
    v4 = 0;
  v5 = *((_QWORD *)a2 + 6);
  v6 = *((_QWORD *)a2 + 7);
  memset(v21, 0, sizeof(v21));
  v20 = 0;
  if ( !v2[38] )
    goto LABEL_11;
  v7 = v2[87];
  if ( !v7 )
    goto LABEL_11;
  if ( *(_QWORD *)(*(_QWORD *)v5 + 504LL) && (*(_BYTE *)(v5 + 1094) & 0x20) != 0 )
  {
    v9 = *(_DWORD *)(v7 + 4);
    if ( v9 < 0xA || v9 > *(unsigned __int16 *)(v5 + 1256) )
    {
LABEL_11:
      result = 4294967274LL;
      goto LABEL_12;
    }
    result = nl80211_parse_chandef(v5, (__int64)a2, 0, (__int64)v21);
    if ( (_DWORD)result )
      goto LABEL_12;
    if ( (cfg80211_off_channel_oper_allowed(v6, v21[0]) & 1) == 0 )
    {
      v12 = wdev_chandef(v6, v4, v11);
      if ( !v12 )
      {
        __break(0x800u);
        __break(0x800u);
        result = 4294967280LL;
        goto LABEL_12;
      }
      if ( (_QWORD *)cfg80211_chandef_compatible((unsigned __int64)v21, v12) != v21 )
      {
        result = 4294967280LL;
        goto LABEL_12;
      }
    }
    v13 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
    if ( !v13 )
    {
      result = 4294967284LL;
      goto LABEL_12;
    }
    v14 = v13;
    v15 = genlmsg_put(v13, a2[1], *a2, &nl80211_fam, 0, 55);
    if ( v15 )
    {
      v16 = v15;
      v17 = rdev_remain_on_channel(v5, v6, v21[0], v9, &v20);
      if ( v17 )
      {
LABEL_23:
        v18 = v17;
        sk_skb_reason_drop(0, v14, 2);
        result = v18;
        goto LABEL_12;
      }
      v22[0] = v20;
      if ( !(unsigned int)nla_put_64bit(v14, 88, 8, v22, 229) )
      {
        *(_DWORD *)(v16 - 20) = *(_DWORD *)(v14 + 216) + *(_DWORD *)(v14 + 208) - (v16 - 20);
        v19 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v14, a2[1], 64);
        result = v19 & (unsigned int)(v19 >> 31);
        goto LABEL_12;
      }
    }
    v17 = -105;
    goto LABEL_23;
  }
  result = 4294967201LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
