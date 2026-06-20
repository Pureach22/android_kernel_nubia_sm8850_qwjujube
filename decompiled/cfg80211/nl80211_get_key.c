__int64 __fastcall nl80211_get_key(__int64 a1, unsigned int *a2)
{
  _QWORD *v2; // x8
  _BYTE *v3; // x19
  __int64 v4; // x20
  __int64 v5; // x9
  unsigned int v6; // w21
  __int64 v7; // x22
  char v8; // w9
  int v9; // w10
  __int64 v11; // x9
  __int64 v12; // x10
  unsigned int v13; // w23
  _QWORD *v14; // x20
  __int64 result; // x0
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x25
  _BOOL4 v19; // w26
  unsigned int v20; // w8
  __int64 v22; // x0
  __int64 v23; // x24
  __int64 v24; // x0
  int v25; // w8
  __int64 v26; // x28
  int key; // w0
  unsigned int v28; // w19
  int v29; // w0
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h]
  int v32; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_QWORD **)a2 + 4);
  v30 = 0;
  v31 = 0;
  v3 = *((_BYTE **)a2 + 6);
  v4 = *((_QWORD *)a2 + 7);
  v5 = v2[313];
  if ( v5 )
    v6 = *(unsigned __int8 *)(v5 + 4);
  else
    v6 = -1;
  v7 = *(_QWORD *)(v4 + 992);
  v8 = v3[1109];
  v9 = *(_DWORD *)(v7 + 8);
  if ( v9 == 8 || v9 == 2 )
  {
    v11 = v8 & 0x42;
    v12 = v2[8];
    if ( !v12 )
    {
LABEL_15:
      v13 = 0;
LABEL_16:
      v16 = v2[6];
      v17 = v2[55];
      if ( v16 )
        v18 = v16 + 4;
      else
        v18 = 0;
      v19 = v18 != 0;
      if ( !v17 || (v20 = *(_DWORD *)(v17 + 4), v19 = v20 == 1, v20 <= 1) )
      {
        if ( !*(_QWORD *)(*(_QWORD *)v3 + 72LL) )
        {
          result = 4294967201LL;
          goto LABEL_35;
        }
        if ( !v19 && v18 && (v3[1093] & 1) == 0 )
        {
          result = 4294967294LL;
          goto LABEL_35;
        }
        v22 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
        if ( !v22 )
        {
          result = 4294967284LL;
          goto LABEL_35;
        }
        v23 = v22;
        v24 = genlmsg_put(v22, a2[1], *a2, &nl80211_fam, 0, 11);
        if ( v24 )
        {
          v25 = *(_DWORD *)(v4 + 224);
          v26 = v24;
          v30 = v23;
          HIDWORD(v31) = v13;
          v32 = v25;
          if ( !(unsigned int)nla_put(v23, 3, 4, &v32) )
          {
            LOBYTE(v32) = v13;
            if ( !(unsigned int)nla_put(v23, 8, 1, &v32) && (!v18 || !(unsigned int)nla_put(v23, 6, 6, v18)) )
            {
              key = nl80211_validate_key_link_id(a2, v7, v6, v19);
              if ( key )
                goto LABEL_32;
              key = rdev_get_key(v3, v4, v6, v13, v19, v18, &v30);
              if ( key )
                goto LABEL_32;
              if ( !(_DWORD)v31 )
              {
                *(_DWORD *)(v26 - 20) = *(_DWORD *)(v23 + 216) + *(_DWORD *)(v23 + 208) - (v26 - 20);
                v29 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v23, a2[1], 64);
                result = v29 & (unsigned int)(v29 >> 31);
                goto LABEL_35;
              }
            }
          }
        }
        key = -105;
LABEL_32:
        v28 = key;
        sk_skb_reason_drop(0, v23, 2);
        result = v28;
        goto LABEL_35;
      }
LABEL_26:
      result = 4294967274LL;
      goto LABEL_35;
    }
  }
  else
  {
    v11 = v8 & 2;
    v12 = v2[8];
    if ( !v12 )
      goto LABEL_15;
  }
  v13 = *(unsigned __int8 *)(v12 + 4);
  if ( (v13 & 0xFE) != 6 || v11 )
    goto LABEL_16;
  v14 = *((_QWORD **)a2 + 8);
  do_trace_netlink_extack("BIGTK not supported");
  if ( !v14 )
    goto LABEL_26;
  *v14 = "BIGTK not supported";
  result = 4294967274LL;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
