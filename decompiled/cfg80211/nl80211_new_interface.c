__int64 __fastcall nl80211_new_interface(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x19
  _QWORD *v4; // x8
  _BYTE *v5; // x21
  __int64 v6; // x9
  unsigned int v7; // w22
  __int64 v8; // x1
  __int64 v9; // x8
  int v10; // w8
  __int64 v11; // x24
  int v12; // w0
  __int64 v13; // x8
  int v14; // w8
  __int64 v15; // x9
  int v17; // w25
  __int64 v18; // x0
  __int64 v19; // x23
  __int64 v20; // x1
  _DWORD *v21; // x8
  unsigned __int64 v22; // x0
  _WORD *v23; // x8
  __int16 v24; // w8
  size_t v25; // x2
  int v26; // w0
  size_t v27; // x22
  __int64 v28; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v29[4]; // [xsp+10h] [xbp-20h] BYREF

  v29[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *((_QWORD *)a2 + 6);
  cfg80211_destroy_ifaces(v3);
  mutex_lock(v3 + 992);
  v4 = *((_QWORD **)a2 + 4);
  v5 = *((_BYTE **)a2 + 6);
  v28 = 0;
  memset(v29, 0, 24);
  if ( !v4[4] )
    goto LABEL_27;
  v6 = v4[5];
  if ( v6 )
    v7 = *(_DWORD *)(v6 + 4);
  else
    v7 = 0;
  if ( !*(_QWORD *)(*(_QWORD *)v5 + 24LL) )
    goto LABEL_28;
  if ( v7 == 10 || v7 == 12 || (v5[1103] & 8) != 0 )
  {
    v8 = v4[6];
    if ( v8 )
    {
      nla_memcpy(v29, v8, 6);
      if ( (v29[0] & 1) != 0 || !(LODWORD(v29[0]) | WORD2(v29[0])) )
      {
        LODWORD(v11) = -99;
        goto LABEL_29;
      }
      v4 = *((_QWORD **)a2 + 4);
    }
  }
  v9 = v4[83];
  if ( v9 )
  {
    v10 = *(unsigned __int8 *)(v9 + 4);
    HIDWORD(v28) = v10 != 0;
    if ( v10 )
    {
      if ( v7 == 2 )
      {
        if ( (v5[1092] & 0x40) == 0 )
        {
LABEL_28:
          LODWORD(v11) = -95;
          goto LABEL_29;
        }
      }
      else if ( v7 != 4 || (v5[1092] & 0x20) == 0 )
      {
        goto LABEL_28;
      }
      v10 = 1;
    }
  }
  else
  {
    v10 = HIDWORD(v28);
  }
  if ( (cfg80211_iftype_allowed(v5 + 992, v7, v10 != 0, 0) & 1) == 0 )
    goto LABEL_28;
  v12 = nl80211_parse_mon_options(v5, v7, a2, &v28);
  if ( v12 < 0 )
  {
    LODWORD(v11) = v12;
    goto LABEL_29;
  }
  v13 = *(_QWORD *)(*((_QWORD *)a2 + 4) + 2664LL);
  if ( v13 )
  {
    v14 = *(_DWORD *)(v13 + 4);
    v15 = -1LL << *(_DWORD *)(*((_QWORD *)a2 + 6) + 2488LL);
    if ( (v14 & (unsigned int)v15) != 0 )
    {
LABEL_27:
      LODWORD(v11) = -22;
      goto LABEL_29;
    }
    if ( v14 )
      v17 = v14;
    else
      v17 = ~(_DWORD)v15;
  }
  else
  {
    v17 = 0;
  }
  v18 = _alloc_skb(3712, 3264, 0, 0xFFFFFFFFLL);
  if ( v18 )
  {
    v19 = v18;
    v20 = *(_QWORD *)(*((_QWORD *)a2 + 4) + 32LL) + 4LL;
    v21 = *(_DWORD **)(*(_QWORD *)v5 + 24LL);
    if ( *(v21 - 1) != -271372553 )
      __break(0x8228u);
    v22 = ((__int64 (__fastcall *)(_BYTE *, __int64, __int64, _QWORD, __int64 *))v21)(v5 + 992, v20, 3, v7, &v28);
    v11 = v22;
    if ( v22 )
    {
      if ( v22 < 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_QWORD *)(*((_QWORD *)a2 + 4) + 1632LL) )
          *(_DWORD *)(v22 + 176) = a2[1];
        if ( v7 == 12 || v7 == 10 )
        {
          cfg80211_init_wdev((__int64 *)v22);
          cfg80211_register_wdev((__int64)v5, v11);
        }
        else if ( v7 == 7 )
        {
          v23 = *(_WORD **)(*((_QWORD *)a2 + 4) + 192LL);
          if ( v23 )
          {
            v24 = *v23 - 4;
            v25 = (unsigned __int8)v24;
            *(_BYTE *)(v22 + 385) = v24;
            if ( (unsigned __int8)v24 >= 0x21u && (nl80211_new_interface___already_done & 1) == 0 )
            {
              nl80211_new_interface___already_done = 1;
              v27 = (unsigned __int8)v24;
              _warn_printk(
                "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                (unsigned __int8)v24,
                "field \"wdev->u.mesh.id\" at ../soc-repo/net/wireless/nl80211.c:4513",
                0x20u);
              v25 = v27;
              __break(0x800u);
            }
            memcpy((void *)(v11 + 352), (const void *)(*(_QWORD *)(*((_QWORD *)a2 + 4) + 192LL) + 4LL), v25);
          }
        }
        if ( v17 )
          *(_DWORD *)(v11 + 1476) = v17;
        if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _BYTE *, __int64, __int64))nl80211_send_iface)(
                v19,
                a2[1],
                *a2,
                0,
                v5,
                v11,
                7)
            & 0x80000000) != 0 )
        {
          sk_skb_reason_drop(0, v19, 2);
          LODWORD(v11) = -105;
        }
        else
        {
          v26 = netlink_unicast(*(_QWORD *)(*((_QWORD *)a2 + 5) + 288LL), v19, a2[1], 64);
          LODWORD(v11) = v26 & (v26 >> 31);
        }
      }
      else
      {
        sk_skb_reason_drop(0, v19, 2);
      }
    }
    else
    {
      __break(0x800u);
      sk_skb_reason_drop(0, v19, 2);
      LODWORD(v11) = -71;
    }
  }
  else
  {
    LODWORD(v11) = -12;
  }
LABEL_29:
  mutex_unlock(v3 + 992);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v11;
}
