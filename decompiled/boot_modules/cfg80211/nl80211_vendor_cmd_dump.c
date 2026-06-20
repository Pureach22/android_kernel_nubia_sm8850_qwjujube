__int64 __fastcall nl80211_vendor_cmd_dump(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x9
  unsigned __int64 v7; // x21
  __int64 v8; // x10
  __int64 v9; // x9
  unsigned __int64 v10; // x22
  _QWORD *v11; // x23
  _DWORD *v12; // x8
  unsigned int v13; // w25
  __int64 v14; // x23
  unsigned int v15; // w24
  __int64 v16; // x28
  int v17; // w8
  __int64 v18; // x8
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x0
  __int64 v21; // x27
  __int64 v22; // x25
  __int64 v23; // x26
  _WORD *v24; // x26
  _DWORD *v25; // x8
  _DWORD *v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 *v28; // x9
  unsigned __int64 v29; // x10
  unsigned __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x26
  __int64 v33; // x10
  __int16 *v34; // x24
  __int16 v35; // w27
  _WORD *v36; // x9
  __int64 v37; // x8
  __int64 v38; // x10
  unsigned __int64 StatusReg; // x21
  __int64 v40; // x22
  _QWORD v42[2]; // [xsp+0h] [xbp-10h] BYREF

  v42[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  rtnl_lock(a1);
  v4 = *(_QWORD *)(a2 + 80);
  if ( !v4 )
  {
    v5 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
    v11 = (_QWORD *)v5;
    if ( v5 )
      goto LABEL_9;
LABEL_81:
    v13 = -12;
    goto LABEL_82;
  }
  v5 = (__int64)wiphy_idx_to_wiphy((unsigned int)(v4 - 1));
  if ( !v5 )
  {
    v13 = -19;
    goto LABEL_82;
  }
  v6 = *(_QWORD *)(a2 + 88);
  v7 = v5 - 992;
  if ( !v6 )
  {
LABEL_11:
    v10 = 0;
    goto LABEL_12;
  }
  v8 = v6 - 1;
  v9 = v5 + 1336;
  do
  {
    v9 = *(_QWORD *)v9;
    if ( v9 == v5 + 1336 )
      goto LABEL_11;
  }
  while ( v8 != *(_DWORD *)(v9 + 24) );
  v10 = v9 - 16;
LABEL_12:
  v14 = *(_QWORD *)(a2 + 104);
  v15 = *(_DWORD *)(a2 + 112);
  v16 = *(_QWORD *)(v7 + 2360) + 56LL * *(unsigned int *)(a2 + 96);
  v17 = *(_DWORD *)(v16 + 8);
  if ( (v17 & 3) != 0 )
  {
    if ( !v10 || (v17 & 2) != 0 && !*(_QWORD *)(v10 + 32) )
    {
      v13 = -22;
      goto LABEL_82;
    }
    if ( (v17 & 4) != 0 )
    {
      v18 = *(_QWORD *)(v10 + 32);
      if ( v18 )
      {
        if ( (*(_QWORD *)(v18 + 168) & 1) == 0 )
          goto LABEL_19;
      }
      else if ( *(_BYTE *)(v10 + 66) != 1 )
      {
LABEL_19:
        v13 = -100;
        goto LABEL_82;
      }
    }
  }
  v5 = genlmsg_put(
         a1,
         *(unsigned int *)(*(_QWORD *)a2 + 52LL),
         *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
         &nl80211_fam,
         2,
         103);
  if ( !v5 )
  {
LABEL_58:
    v13 = *(_DWORD *)(a1 + 112);
    goto LABEL_82;
  }
  v21 = v5;
  while ( 1 )
  {
    LODWORD(v42[0]) = *(_DWORD *)(v7 + 100);
    v5 = nla_put(a1, 1, 4, v42);
    if ( (_DWORD)v5 )
    {
LABEL_52:
      v27 = v21 - 20;
      if ( v21 == 20 )
        goto LABEL_58;
      v28 = (unsigned __int64 *)(a1 + 224);
      v29 = *(_QWORD *)(a1 + 224);
      if ( v29 <= v27 )
        goto LABEL_57;
      goto LABEL_79;
    }
    if ( v10 )
    {
      if ( !*(_QWORD *)v10 )
      {
        __break(0x800u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v40 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &nl80211_prepare_vendor_dump__alloc_tag;
        v5 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
        v11 = (_QWORD *)v5;
        *(_QWORD *)(StatusReg + 80) = v40;
        if ( !v5 )
          goto LABEL_81;
LABEL_9:
        v12 = *(_DWORD **)(a2 + 8);
        if ( *v12 < (unsigned int)(nl80211_fam + 20) )
        {
          do_trace_netlink_extack("Invalid header length");
          v13 = -22;
LABEL_32:
          v5 = kfree(v11);
          goto LABEL_82;
        }
        v13 = _nla_parse(
                v11,
                (unsigned int)dword_BF568,
                (char *)v12 + ((nl80211_fam + 7) & 0xFFFFFFFC) + 16,
                *v12 - ((nl80211_fam + 7) & 0xFFFFFFFC) - 16,
                &nl80211_policy,
                0,
                0);
        if ( v13 )
          goto LABEL_32;
        if ( !v11[195] || !v11[196] )
        {
          v13 = -22;
          goto LABEL_32;
        }
        v19 = _cfg80211_wdev_from_attrs(0, *(void **)(*(_QWORD *)(a1 + 24) + 48LL), (__int64)v11);
        if ( v19 <= 0xFFFFFFFFFFFFF000LL )
          v10 = v19;
        else
          v10 = 0;
        v20 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))_cfg80211_rdev_from_attrs)(
                *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL),
                v11);
        v7 = v20;
        if ( v20 <= 0xFFFFFFFFFFFFF000LL )
        {
          v31 = *(unsigned int *)(v20 + 2376);
          if ( !(_DWORD)v31 )
          {
            v13 = -95;
            goto LABEL_32;
          }
          v32 = 0;
          v13 = -95;
          v33 = *(_QWORD *)(v20 + 2360);
          while ( *(_DWORD *)v33 != *(_DWORD *)(v11[195] + 4LL) || *(_DWORD *)(v33 + 4) != *(_DWORD *)(v11[196] + 4LL) )
          {
            ++v32;
            v33 += 56;
            if ( v31 == v32 )
              goto LABEL_32;
          }
          v13 = -95;
          if ( (v32 & 0x80000000) != 0 || !*(_QWORD *)(v33 + 24) )
            goto LABEL_32;
          v34 = (__int16 *)v11[197];
          if ( v34 )
          {
            v35 = *v34;
            v13 = nl80211_vendor_check_policy(
                    *(_QWORD *)(v20 + 2360) + 56 * (v32 & 0x7FFFFFFF),
                    v11[197],
                    *(_QWORD *)(a2 + 48));
            if ( v13 )
              goto LABEL_32;
            v36 = v34 + 2;
            v37 = (unsigned __int16)(v35 - 4);
          }
          else
          {
            v36 = nullptr;
            v37 = 0;
          }
          *(_QWORD *)(a2 + 80) = *(_DWORD *)(v7 + 100) + 1;
          if ( v10 )
            v38 = (unsigned int)(*(_DWORD *)(v10 + 40) + 1);
          else
            v38 = 0;
          *(_QWORD *)(a2 + 104) = v36;
          *(_QWORD *)(a2 + 112) = v37;
          *(_QWORD *)(a2 + 88) = v38;
          *(_QWORD *)(a2 + 96) = v32 & 0x7FFFFFFF;
          v5 = kfree(v11);
        }
        else
        {
          v5 = kfree(v11);
          v13 = v7;
          if ( (_DWORD)v7 )
            goto LABEL_82;
        }
        goto LABEL_12;
      }
      v42[0] = *(unsigned int *)(v10 + 40) | ((unsigned __int64)*(unsigned int *)(*(_QWORD *)v10 - 892LL) << 32);
      v5 = nla_put_64bit(a1, 153, 8, v42, 229);
      if ( (_DWORD)v5 )
        goto LABEL_52;
    }
    v22 = *(_QWORD *)(a1 + 216);
    v23 = *(unsigned int *)(a1 + 208);
    v5 = nla_put(a1, 197, 0, 0);
    if ( (v5 & 0x80000000) != 0 || (v24 = (_WORD *)(v22 + v23)) == nullptr )
    {
      v27 = v21 - 20;
      if ( v21 == 20 )
        goto LABEL_58;
      v28 = (unsigned __int64 *)(a1 + 224);
      v29 = *(_QWORD *)(a1 + 224);
      if ( v29 <= v27 )
        goto LABEL_57;
LABEL_79:
      __break(0x800u);
      v29 = *v28;
      goto LABEL_57;
    }
    v25 = *(_DWORD **)(v16 + 24);
    if ( *(v25 - 1) != 111105142 )
      __break(0x8228u);
    v5 = ((__int64 (__fastcall *)(unsigned __int64, unsigned __int64, __int64, __int64, _QWORD, __int64))v25)(
           v7 + 992,
           v10,
           a1,
           v14,
           v15,
           a2 + 120);
    *v24 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v24;
    if ( (_DWORD)v5 == -2 || (v13 = v5, (_DWORD)v5 == -105) )
    {
      v27 = v21 - 20;
      if ( v21 == 20 )
        goto LABEL_58;
      v28 = (unsigned __int64 *)(a1 + 224);
      v29 = *(_QWORD *)(a1 + 224);
      if ( v29 > v27 )
        goto LABEL_79;
LABEL_57:
      v5 = skb_trim(a1, (unsigned int)(v27 - v29));
      goto LABEL_58;
    }
    v26 = (_DWORD *)(v21 - 20);
    if ( (int)v5 <= 0 )
      break;
    *v26 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_DWORD)v26;
    v5 = genlmsg_put(
           a1,
           *(unsigned int *)(*(_QWORD *)a2 + 52LL),
           *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL),
           &nl80211_fam,
           2,
           103);
    v21 = v5;
    if ( !v5 )
      goto LABEL_58;
  }
  if ( v21 != 20 )
  {
    v30 = *(_QWORD *)(a1 + 224);
    if ( v30 > (unsigned __int64)v26 )
    {
      __break(0x800u);
      v30 = *(_QWORD *)(a1 + 224);
    }
    v5 = skb_trim(a1, (unsigned int)((_DWORD)v26 - v30));
  }
LABEL_82:
  rtnl_unlock(v5);
  _ReadStatusReg(SP_EL0);
  return v13;
}
