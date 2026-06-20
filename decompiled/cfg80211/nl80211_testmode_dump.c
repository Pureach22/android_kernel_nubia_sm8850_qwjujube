__int64 __fastcall nl80211_testmode_dump(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x22
  _UNKNOWN **v6; // x0
  __int64 v7; // x19
  _UNKNOWN **v8; // x23
  __int16 *v9; // x24
  __int16 v10; // t1
  unsigned int v11; // w25
  __int64 v12; // x0
  _DWORD *v13; // x8
  unsigned int v14; // w28
  __int64 v15; // x0
  __int64 v16; // x26
  __int64 v17; // x27
  __int64 v18; // x28
  _WORD *v19; // x27
  _DWORD *v20; // x8
  unsigned int v21; // w0
  unsigned __int64 v22; // x8
  unsigned __int64 *v23; // x9
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x0
  int v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  rtnl_lock(a1);
  v4 = a2[10];
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = cfg80211_rdev_by_wiphy_idx((int)v4 - 1);
    v7 = 0;
    if ( !v6 )
    {
      v14 = -2;
      goto LABEL_47;
    }
    v8 = v6;
  }
  else
  {
    v12 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
    v7 = v12;
    if ( !v12 )
    {
      v14 = -12;
      goto LABEL_47;
    }
    v13 = (_DWORD *)a2[1];
    if ( *v13 < (unsigned int)(nl80211_fam + 20) )
    {
      do_trace_netlink_extack("Invalid header length");
      v14 = -22;
      goto LABEL_47;
    }
    v21 = _nla_parse(
            v12,
            (unsigned int)dword_BF568,
            (char *)v13 + ((nl80211_fam + 7) & 0xFFFFFFFC) + 16,
            *v13 - ((nl80211_fam + 7) & 0xFFFFFFFC) - 16,
            &nl80211_policy,
            0,
            0);
    if ( v21 )
    {
      v14 = v21;
      goto LABEL_47;
    }
    v25 = ((__int64 (__fastcall *)(_QWORD, __int64))_cfg80211_rdev_from_attrs)(
            *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL),
            v7);
    v8 = (_UNKNOWN **)v25;
    if ( v25 >= 0xFFFFFFFFFFFFF001LL )
    {
      v14 = v25;
      goto LABEL_47;
    }
    v28 = *(_QWORD *)(v7 + 552);
    v5 = *(int *)(v25 + 100);
    if ( v28 )
      a2[11] = v28;
  }
  v9 = (__int16 *)a2[11];
  if ( v9 )
  {
    v10 = *v9;
    v9 += 2;
    v11 = (unsigned __int16)(v10 - 4);
  }
  else
  {
    v11 = 0;
  }
  if ( !*((_QWORD *)*v8 + 57) )
  {
    v14 = -95;
    goto LABEL_47;
  }
  v15 = genlmsg_put(a1, *(unsigned int *)(*a2 + 52LL), *(unsigned int *)(a2[1] + 8LL), &nl80211_fam, 2, 45);
  if ( !v15 )
  {
LABEL_38:
    v14 = *(_DWORD *)(a1 + 112);
    a2[10] = v5 + 1;
    goto LABEL_47;
  }
  v16 = v15;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v31 = v5;
    if ( (unsigned int)nla_put(a1, 1, 4, &v31) )
    {
      v22 = v16 - 20;
      if ( v16 == 20 )
        goto LABEL_38;
      v23 = (unsigned __int64 *)(a1 + 224);
      v24 = *(_QWORD *)(a1 + 224);
      if ( v24 <= v22 )
        goto LABEL_37;
      goto LABEL_45;
    }
    v17 = *(_QWORD *)(a1 + 216);
    v18 = *(unsigned int *)(a1 + 208);
    if ( (nla_put(a1, 69, 0, 0) & 0x80000000) != 0 || (v19 = (_WORD *)(v17 + v18)) == nullptr )
    {
      v22 = v16 - 20;
      if ( v16 == 20 )
        goto LABEL_38;
      v23 = (unsigned __int64 *)(a1 + 224);
      v24 = *(_QWORD *)(a1 + 224);
      if ( v24 <= v22 )
        goto LABEL_37;
LABEL_45:
      __break(0x800u);
      v24 = *v23;
      goto LABEL_37;
    }
    v20 = *((_DWORD **)*v8 + 57);
    if ( *(v20 - 1) != -1609587216 )
      __break(0x8228u);
    v14 = ((__int64 (__fastcall *)(_UNKNOWN **, __int64, _QWORD *, __int16 *, _QWORD))v20)(v8 + 124, a1, a2, v9, v11);
    *v19 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v19;
    if ( v14 )
      break;
    *(_DWORD *)(v16 - 20) = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (v16 - 20);
    v16 = genlmsg_put(a1, *(unsigned int *)(*a2 + 52LL), *(unsigned int *)(a2[1] + 8LL), &nl80211_fam, 2, 45);
    if ( !v16 )
      goto LABEL_38;
  }
  if ( v14 == -2 || v14 == -105 )
  {
    v22 = v16 - 20;
    if ( v16 == 20 )
      goto LABEL_38;
    v23 = (unsigned __int64 *)(a1 + 224);
    v24 = *(_QWORD *)(a1 + 224);
    if ( v24 > v22 )
      goto LABEL_45;
LABEL_37:
    skb_trim(a1, (unsigned int)(v22 - v24));
    goto LABEL_38;
  }
  v26 = v16 - 20;
  if ( v16 != 20 )
  {
    v27 = *(_QWORD *)(a1 + 224);
    if ( v27 > v26 )
    {
      __break(0x800u);
      v27 = *(_QWORD *)(a1 + 224);
    }
    skb_trim(a1, (unsigned int)(v26 - v27));
  }
LABEL_47:
  v29 = kfree(v7);
  rtnl_unlock(v29);
  _ReadStatusReg(SP_EL0);
  return v14;
}
