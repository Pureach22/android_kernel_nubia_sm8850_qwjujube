__int64 __fastcall restore_regulatory_settings(__int64 a1, char a2)
{
  char v3; // w20
  char *v4; // x8
  int v5; // w9
  char *v6; // x8
  void *v7; // x8
  _QWORD *v8; // x9
  _QWORD *v9; // x10
  _QWORD *v10; // x0
  _QWORD *v11; // x8
  _QWORD *v12; // x23
  _QWORD *v13; // x9
  _QWORD *v14; // x0
  _QWORD *v15; // x8
  _QWORD *v16; // x23
  _QWORD *v17; // x9
  char v18; // w20
  char v19; // w26
  _UNKNOWN **v20; // x8
  int *v21; // x10
  __int64 v22; // x11
  __int64 v23; // x12
  __int64 v24; // x13
  __int64 v25; // x14
  int v26; // w15
  int *v27; // x10
  __int64 v28; // x11
  __int64 v29; // x12
  __int64 v30; // x13
  __int64 v31; // x14
  int v32; // w15
  int *v33; // x10
  __int64 v34; // x11
  __int64 v35; // x12
  __int64 v36; // x13
  __int64 v37; // x14
  int v38; // w15
  int *v39; // x10
  __int64 v40; // x11
  __int64 v41; // x12
  __int64 v42; // x13
  __int64 v43; // x14
  int v44; // w15
  int *v45; // x10
  __int64 v46; // x11
  __int64 v47; // x12
  __int64 v48; // x13
  __int64 v49; // x14
  int v50; // w15
  int *v51; // x10
  __int64 v52; // x11
  __int64 v53; // x12
  __int64 v54; // x13
  __int64 v55; // x14
  int v56; // w15
  __int64 v57; // x0
  __int64 v58; // x19
  _UNKNOWN **v59; // x27
  _UNKNOWN **v60; // x20
  _QWORD *v61; // x8
  __int64 v62; // x9
  _UNKNOWN **v63; // x21
  __int64 v64; // x0
  _UNKNOWN **i; // x24
  __int64 v66; // x0
  _DWORD *v67; // x8
  __int64 v68; // x0
  _QWORD *v69; // x9
  _QWORD *v70; // x10
  _UNKNOWN **v71; // x11
  __int64 result; // x0
  _QWORD *v73; // [xsp+0h] [xbp-20h] BYREF
  _QWORD **v74; // [xsp+8h] [xbp-18h]
  char v75[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v76; // [xsp+18h] [xbp-8h]

  v3 = a1;
  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)v75 = 0;
  v73 = &v73;
  v74 = &v73;
  if ( !(unsigned int)rtnl_is_locked(a1) && (restore_regulatory_settings___already_done & 1) == 0 )
  {
    restore_regulatory_settings___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 3502);
    __break(0x800u);
  }
  raw_spin_lock(&reg_indoor_lock);
  if ( reg_is_indoor == 1 && !reg_is_indoor_portid )
  {
    reg_is_indoor = 0;
    mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
  }
  raw_spin_unlock(&reg_indoor_lock);
  reset_regdomains(1, &world_regdom);
  *(_WORD *)v75 = 14137;
  if ( (unsigned __int8)user_alpha2 == 57 && HIBYTE(user_alpha2) == 55 )
  {
LABEL_20:
    v4 = ieee80211_regdom;
    v5 = (unsigned __int8)*ieee80211_regdom;
    if ( !ieee80211_regdom )
      goto LABEL_23;
    goto LABEL_21;
  }
  if ( (unsigned __int8)user_alpha2 == 48 )
  {
    if ( HIBYTE(user_alpha2) == 48 )
      goto LABEL_16;
  }
  else if ( (user_alpha2 & 0x80) != 0 )
  {
LABEL_19:
    _warn_printk("Unexpected user alpha2: %c%c\n", (unsigned __int8)user_alpha2, HIBYTE(user_alpha2));
    __break(0x800u);
    goto LABEL_20;
  }
  if ( (*((_BYTE *)&ctype + (unsigned __int8)user_alpha2) & 3) == 0
    || SHIBYTE(user_alpha2) < 0
    || (*((_BYTE *)&ctype + HIBYTE(user_alpha2)) & 3) == 0 )
  {
    goto LABEL_19;
  }
LABEL_16:
  if ( (v3 & 1) == 0 )
  {
    v75[0] = user_alpha2;
    v6 = (char *)&user_alpha2 + 1;
    goto LABEL_24;
  }
  v4 = ieee80211_regdom;
  user_alpha2 = 14137;
  v5 = (unsigned __int8)*ieee80211_regdom;
  if ( !ieee80211_regdom )
  {
LABEL_23:
    v6 = v4 + 1;
    v75[0] = v5;
LABEL_24:
    v75[1] = *v6;
    goto LABEL_25;
  }
LABEL_21:
  if ( v5 != 48 || *((_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + (_QWORD)v4 + 1) != 48 )
    goto LABEL_23;
LABEL_25:
  raw_spin_lock(&reg_requests_lock);
  v7 = reg_requests_list;
  if ( reg_requests_list != (_UNKNOWN *)&reg_requests_list )
  {
    v8 = v74;
    v9 = off_4E40;
    *(_QWORD *)((char *)&unk_8 + (_QWORD)reg_requests_list) = v74;
    *v8 = v7;
    *v9 = &v73;
    v74 = (_QWORD **)v9;
    reg_requests_list = &reg_requests_list;
    off_4E40 = &reg_requests_list;
  }
  raw_spin_unlock(&reg_requests_lock);
  raw_spin_lock_bh(&reg_pending_beacons_lock);
  v10 = reg_pending_beacons;
  if ( reg_pending_beacons != (_UNKNOWN *)&reg_pending_beacons )
  {
    do
    {
      v12 = (_QWORD *)*v10;
      v11 = (_QWORD *)v10[1];
      if ( (_QWORD *)*v11 == v10 && (_QWORD *)v12[1] == v10 )
      {
        v12[1] = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
        v10 = v13;
      }
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      kfree(v10);
      v10 = v12;
    }
    while ( v12 != &reg_pending_beacons );
  }
  raw_spin_unlock_bh(&reg_pending_beacons_lock);
  v14 = reg_beacon_list;
  if ( reg_beacon_list != (_UNKNOWN *)&reg_beacon_list )
  {
    do
    {
      v16 = (_QWORD *)*v14;
      v15 = (_QWORD *)v14[1];
      if ( (_QWORD *)*v15 == v14 && (_QWORD *)v16[1] == v14 )
      {
        v16[1] = v15;
        *v15 = v16;
      }
      else
      {
        _list_del_entry_valid_or_report(v14);
        v14 = v17;
      }
      *v14 = 0xDEAD000000000100LL;
      v14[1] = 0xDEAD000000000122LL;
      kfree(v14);
      v14 = v16;
    }
    while ( v16 != &reg_beacon_list );
  }
  v18 = *((_BYTE *)cfg80211_world_regdom + 20);
  v19 = *((_BYTE *)cfg80211_world_regdom + 21);
  if ( !(unsigned int)rtnl_is_locked(v14) && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_2 = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
  v20 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    do
    {
      if ( ((_DWORD)v20[136] & 0x81) == 1 )
      {
        v21 = (int *)v20[164];
        if ( v21 && v21[5] >= 1 )
        {
          v22 = 0;
          v23 = 0;
          do
          {
            ++v23;
            v24 = *(_QWORD *)v21 + v22;
            v22 += 64;
            v25 = *(_QWORD *)(v24 + 32);
            v26 = *(_DWORD *)(v24 + 40);
            *(_BYTE *)(v24 + 28) = 0;
            *(_QWORD *)(v24 + 12) = v25;
            *(_DWORD *)(v24 + 20) = v26;
          }
          while ( v23 < v21[5] );
        }
        v27 = (int *)v20[165];
        if ( v27 && v27[5] >= 1 )
        {
          v28 = 0;
          v29 = 0;
          do
          {
            ++v29;
            v30 = *(_QWORD *)v27 + v28;
            v28 += 64;
            v31 = *(_QWORD *)(v30 + 32);
            v32 = *(_DWORD *)(v30 + 40);
            *(_BYTE *)(v30 + 28) = 0;
            *(_QWORD *)(v30 + 12) = v31;
            *(_DWORD *)(v30 + 20) = v32;
          }
          while ( v29 < v27[5] );
        }
        v33 = (int *)v20[166];
        if ( v33 && v33[5] >= 1 )
        {
          v34 = 0;
          v35 = 0;
          do
          {
            ++v35;
            v36 = *(_QWORD *)v33 + v34;
            v34 += 64;
            v37 = *(_QWORD *)(v36 + 32);
            v38 = *(_DWORD *)(v36 + 40);
            *(_BYTE *)(v36 + 28) = 0;
            *(_QWORD *)(v36 + 12) = v37;
            *(_DWORD *)(v36 + 20) = v38;
          }
          while ( v35 < v33[5] );
        }
        v39 = (int *)v20[167];
        if ( v39 && v39[5] >= 1 )
        {
          v40 = 0;
          v41 = 0;
          do
          {
            ++v41;
            v42 = *(_QWORD *)v39 + v40;
            v40 += 64;
            v43 = *(_QWORD *)(v42 + 32);
            v44 = *(_DWORD *)(v42 + 40);
            *(_BYTE *)(v42 + 28) = 0;
            *(_QWORD *)(v42 + 12) = v43;
            *(_DWORD *)(v42 + 20) = v44;
          }
          while ( v41 < v39[5] );
        }
        v45 = (int *)v20[168];
        if ( v45 && v45[5] >= 1 )
        {
          v46 = 0;
          v47 = 0;
          do
          {
            ++v47;
            v48 = *(_QWORD *)v45 + v46;
            v46 += 64;
            v49 = *(_QWORD *)(v48 + 32);
            v50 = *(_DWORD *)(v48 + 40);
            *(_BYTE *)(v48 + 28) = 0;
            *(_QWORD *)(v48 + 12) = v49;
            *(_DWORD *)(v48 + 20) = v50;
          }
          while ( v47 < v45[5] );
        }
        v51 = (int *)v20[169];
        if ( v51 && v51[5] >= 1 )
        {
          v52 = 0;
          v53 = 0;
          do
          {
            ++v53;
            v54 = *(_QWORD *)v51 + v52;
            v52 += 64;
            v55 = *(_QWORD *)(v54 + 32);
            v56 = *(_DWORD *)(v54 + 40);
            *(_BYTE *)(v54 + 28) = 0;
            *(_QWORD *)(v54 + 12) = v55;
            *(_DWORD *)(v54 + 20) = v56;
          }
          while ( v53 < v51[5] );
        }
      }
      v20 = (_UNKNOWN **)*v20;
    }
    while ( v20 != &cfg80211_rdev_list );
  }
  if ( (a2 & 1) != 0
    && ((v75[0] & 0x8000000000000000LL) != 0
     || (*((_BYTE *)&ctype + v75[0]) & 3) == 0
     || (v75[1] & 0x8000000000000000LL) != 0
     || (*((_BYTE *)&ctype + v75[1]) & 3) == 0
     || cfg80211_user_regdom && (unsigned __int64)cfg80211_user_regdom <= 0xFFFFFFFFFFFFF000LL) )
  {
    reset_regdomains(0, cfg80211_world_regdom);
    update_all_wiphy_regulatory(0);
    v57 = cfg80211_regdomain;
    if ( *(_BYTE *)(cfg80211_regdomain + 20) == 57
      && *(_BYTE *)(cfg80211_regdomain + 21) == 56
      && *((_DWORD *)last_request + 5) == 3 )
    {
      v58 = cfg80211_regdomain;
      cfg80211_rdev_by_wiphy_idx(*((_DWORD *)last_request + 4));
      v57 = v58;
    }
    print_rd_rules(v57);
    nl80211_common_reg_change_event(0x24u, (__int64)&core_request_world);
    *((_BYTE *)last_request + 37) = 1;
    raw_spin_lock(&reg_requests_lock);
    v59 = (_UNKNOWN **)reg_requests_list;
    raw_spin_unlock(&reg_requests_lock);
    if ( v59 != &reg_requests_list )
      queue_work_on(32, system_wq, &reg_work);
    if ( (v75[0] & 0x8000000000000000LL) == 0
      && (*((_BYTE *)&ctype + v75[0]) & 3) != 0
      && (v75[1] & 0x8000000000000000LL) == 0
      && (*((_BYTE *)&ctype + v75[1]) & 3) != 0
      && !(unsigned int)regulatory_hint_user((unsigned __int8 *)v75, 0) )
    {
      raw_spin_lock(&reg_requests_lock);
      v60 = off_4E40;
      v61 = off_4E40[1];
      if ( (_UNKNOWN **)*v61 == off_4E40 && (v62 = (__int64)*off_4E40, *((_UNKNOWN ***)*off_4E40 + 1) == off_4E40) )
      {
        *(_QWORD *)(v62 + 8) = v61;
        *v61 = v62;
      }
      else
      {
        _list_del_entry_valid_or_report(off_4E40);
      }
      *v60 = (_UNKNOWN *)0xDEAD000000000100LL;
      v60[1] = (_UNKNOWN *)0xDEAD000000000122LL;
      v63 = v60 - 6;
      v64 = raw_spin_unlock(&reg_requests_lock);
      if ( !(unsigned int)rtnl_is_locked(v64) && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
      {
        for_each_rdev_check_rtnl___already_done_2 = 1;
        _warn_printk(
          "RTNL: assertion failed at %s (%d)\n",
          "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
          166);
        __break(0x800u);
      }
      for ( i = (_UNKNOWN **)cfg80211_rdev_list; i != &cfg80211_rdev_list; i = (_UNKNOWN **)*i )
      {
        if ( ((_BYTE)i[136] & 0x80) != 0 && *((_DWORD *)v60 - 7) == 1 )
        {
          v67 = i[170];
          if ( v67 )
          {
            if ( *(v67 - 1) != -1916906463 )
              __break(0x8228u);
            ((void (__fastcall *)(_UNKNOWN **, _UNKNOWN **))v67)(i + 123, v60 - 6);
          }
        }
      }
      if ( last_request != (_UNKNOWN *)v63 )
      {
        if ( last_request != &core_request_world && last_request )
          kvfree_call_rcu(last_request, last_request);
        atomic_store((unsigned __int64)v63, (unsigned __int64 *)&last_request);
      }
      v68 = reg_copy_regd(cfg80211_user_regdom);
      set_regdom(v68);
    }
  }
  else
  {
    v66 = _kmalloc_cache_noprof(timer_delete, 3520, 64);
    if ( v66 )
    {
      *(_BYTE *)(v66 + 28) = v18;
      *(_BYTE *)(v66 + 29) = v19;
      *(_QWORD *)(v66 + 16) = 0xFFFFFFFFLL;
      queue_regulatory_request(v66);
    }
    if ( (v75[0] & 0x8000000000000000LL) == 0
      && (*((_BYTE *)&ctype + v75[0]) & 3) != 0
      && (v75[1] & 0x8000000000000000LL) == 0
      && (*((_BYTE *)&ctype + v75[1]) & 3) != 0 )
    {
      regulatory_hint_user((unsigned __int8 *)v75, 0);
    }
  }
  raw_spin_lock(&reg_requests_lock);
  v69 = v73;
  if ( v73 != &v73 )
  {
    v70 = off_4E40;
    v71 = (_UNKNOWN **)v74;
    v73[1] = off_4E40;
    *v70 = v69;
    *v71 = &reg_requests_list;
    off_4E40 = v71;
    v73 = &v73;
    v74 = &v73;
  }
  raw_spin_unlock(&reg_requests_lock);
  result = queue_work_on(32, system_wq, &reg_work);
  _ReadStatusReg(SP_EL0);
  return result;
}
