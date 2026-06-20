__int64 __fastcall set_regdom(unsigned __int64 a1)
{
  unsigned int v1; // w21
  int v2; // w1
  int v3; // w2
  _BYTE *v4; // x20
  unsigned __int64 v5; // x19
  int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x8
  unsigned int v10; // w12
  unsigned int v11; // w11
  bool v12; // cf
  unsigned int v13; // w11
  __int64 v14; // x0
  __int64 v15; // x21
  unsigned __int64 v16; // x1
  unsigned __int64 v17; // x19
  __int64 v19; // x0
  _UNKNOWN **v20; // x22
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x8
  unsigned int v24; // w11
  unsigned int v25; // w10
  unsigned int v26; // w10
  __int64 v27; // x22
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  unsigned int v32; // w11
  unsigned int v33; // w10
  unsigned int v34; // w10
  unsigned int v35; // w20
  __int64 v36; // x23
  unsigned __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x19
  _UNKNOWN **v40; // x21

  v1 = -61;
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL )
    return v1;
  if ( !last_request )
    goto LABEL_39;
  if ( (*((_BYTE *)last_request + 37) & 1) != 0 )
    goto LABEL_39;
  v2 = *((unsigned __int8 *)last_request + 28);
  if ( v2 != *(unsigned __int8 *)(a1 + 20) )
    goto LABEL_39;
  v3 = *((unsigned __int8 *)last_request + 29);
  if ( v3 != *(unsigned __int8 *)(a1 + 21) )
    goto LABEL_39;
  v4 = last_request;
  v5 = a1;
  v6 = *((_DWORD *)last_request + 5);
  if ( v6 > 1 )
  {
    if ( v6 == 2 )
    {
      if ( v2 == 48 && v3 == 48 )
        goto LABEL_81;
      if ( cfg80211_regdomain
        && *(unsigned __int8 *)(cfg80211_regdomain + 20) == v2
        && *(unsigned __int8 *)(cfg80211_regdomain + 21) == v3 )
      {
        goto LABEL_52;
      }
      v21 = *(unsigned int *)(a1 + 16);
      if ( !(_DWORD)v21 )
        goto LABEL_84;
      if ( (unsigned int)v21 <= 0x80 )
      {
        v22 = 0;
        v23 = 96 * v21;
        do
        {
          v24 = *(_DWORD *)(a1 + v22 + 28);
          if ( !v24 )
            goto LABEL_84;
          v25 = *(_DWORD *)(a1 + v22 + 32);
          v12 = v25 >= v24;
          v26 = v25 - v24;
          if ( v26 == 0 || !v12 || *(_DWORD *)(a1 + v22 + 36) > v26 )
            goto LABEL_84;
          v22 += 96;
        }
        while ( v23 != v22 );
        v19 = (__int64)wiphy_idx_to_wiphy(*((unsigned int *)last_request + 4));
        if ( !v19 )
        {
LABEL_83:
          v1 = -19;
          goto LABEL_115;
        }
        v27 = v19;
        if ( (v4[36] & 1) != 0 )
        {
          v19 = regdom_intersect(v5, cfg80211_regdomain);
          if ( !v19 )
          {
            v1 = -22;
            goto LABEL_115;
          }
          v15 = v19;
          v28 = *(_QWORD *)(v27 + 384);
          atomic_store(v5, (unsigned __int64 *)(v27 + 384));
          if ( v28 )
            kvfree_call_rcu(v28, v28);
LABEL_29:
          v16 = v15;
        }
        else
        {
          if ( !(unsigned int)rtnl_is_locked(v19) && (reg_set_rd_driver___already_done & 1) == 0 )
          {
            reg_set_rd_driver___already_done = 1;
            _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 3886);
            __break(0x800u);
          }
          mutex_lock(v27);
          if ( *(_QWORD *)(v27 + 384) )
            v36 = *(_QWORD *)(v27 + 384);
          else
            v36 = 0;
          v37 = reg_copy_regd(v5);
          v1 = v37;
          if ( v37 > 0xFFFFFFFFFFFFF000LL )
          {
            mutex_unlock(v27);
            if ( !v1 )
              goto LABEL_103;
            if ( v1 != -114 )
            {
              v19 = 0;
              goto LABEL_115;
            }
            goto LABEL_52;
          }
          atomic_store(v37, (unsigned __int64 *)(v27 + 384));
          if ( v36 )
            kvfree_call_rcu(v36, v36);
          mutex_unlock(v27);
LABEL_101:
          v16 = v5;
        }
LABEL_102:
        reset_regdomains(0, v16);
        goto LABEL_103;
      }
    }
    else
    {
      if ( v6 != 3 )
      {
LABEL_38:
        v17 = a1;
        _warn_printk("invalid initiator %d\n", v6);
        __break(0x800u);
        a1 = v17;
LABEL_39:
        kfree(a1);
        return (unsigned int)-22;
      }
      if ( *((_BYTE *)last_request + 28) )
      {
        if ( !*((_BYTE *)last_request + 29)
          && ((v2 & 0x80) != 0
           || (*((_BYTE *)&ctype + *((unsigned __int8 *)last_request + 28)) & 3) == 0
           || (ctype & 3) == 0) )
        {
LABEL_81:
          v19 = 0;
          v1 = -22;
LABEL_115:
          restore_regulatory_settings(v19, 0);
LABEL_116:
          kfree(v5);
          return v1;
        }
      }
      else
      {
        v19 = 0;
        v1 = -22;
        if ( (ctype & 3) == 0 || (char)v3 < 0 )
          goto LABEL_115;
        a1 = v5;
        if ( (*((_BYTE *)&ctype + *((unsigned __int8 *)last_request + 29)) & 3) == 0 )
          goto LABEL_81;
      }
      v29 = *(unsigned int *)(a1 + 16);
      if ( !(_DWORD)v29 )
        goto LABEL_84;
      if ( (unsigned int)v29 <= 0x80 )
      {
        v30 = 0;
        v31 = 96 * v29;
        while ( 1 )
        {
          v32 = *(_DWORD *)(a1 + v30 + 28);
          if ( !v32 )
            break;
          v33 = *(_DWORD *)(a1 + v30 + 32);
          v12 = v33 >= v32;
          v34 = v33 - v32;
          if ( v34 == 0 || !v12 || *(_DWORD *)(a1 + v30 + 36) > v34 )
            break;
          v30 += 96;
          if ( v31 == v30 )
          {
            v19 = (__int64)wiphy_idx_to_wiphy(*((unsigned int *)last_request + 4));
            if ( !v19 )
              goto LABEL_83;
            if ( (v4[36] & 1) == 0 )
              goto LABEL_101;
            goto LABEL_81;
          }
        }
LABEL_84:
        v35 = 0;
LABEL_114:
        printk(&unk_B858B);
        print_rd_rules(v5);
        v1 = -22;
        v19 = v35;
        goto LABEL_115;
      }
    }
    v35 = 0;
    __break(0x800u);
    goto LABEL_114;
  }
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      if ( !(unsigned int)rtnl_is_locked(a1) && (cfg80211_save_user_regdom___already_done & 1) == 0 )
      {
        cfg80211_save_user_regdom___already_done = 1;
        _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 471);
        __break(0x800u);
      }
      if ( (unsigned __int64)cfg80211_user_regdom <= 0xFFFFFFFFFFFFF000LL )
        kfree(cfg80211_user_regdom);
      cfg80211_user_regdom = reg_copy_regd(v5);
      if ( !cfg80211_regdomain
        || *(unsigned __int8 *)(cfg80211_regdomain + 20) != *(unsigned __int8 *)(v5 + 20)
        || *(unsigned __int8 *)(cfg80211_regdomain + 21) != *(unsigned __int8 *)(v5 + 21) )
      {
        v7 = *(unsigned int *)(v5 + 16);
        if ( (_DWORD)v7 )
        {
          if ( (unsigned int)v7 > 0x80 )
          {
            __break(0x800u);
          }
          else
          {
            v8 = 0;
            v9 = 96 * v7;
            while ( 1 )
            {
              v10 = *(_DWORD *)(v5 + v8 + 28);
              if ( !v10 )
                break;
              v11 = *(_DWORD *)(v5 + v8 + 32);
              v12 = v11 >= v10;
              v13 = v11 - v10;
              if ( v13 == 0 || !v12 || *(_DWORD *)(v5 + v8 + 36) > v13 )
                break;
              v8 += 96;
              if ( v9 == v8 )
              {
                if ( (v4[36] & 1) == 0 )
                {
                  v16 = v5;
                  goto LABEL_102;
                }
                v14 = regdom_intersect(v5, cfg80211_regdomain);
                if ( v14 )
                {
                  v15 = v14;
                  kfree(v5);
                  goto LABEL_29;
                }
                v19 = 1;
                v1 = -22;
                goto LABEL_115;
              }
            }
          }
        }
        v35 = 1;
        goto LABEL_114;
      }
LABEL_52:
      *((_BYTE *)last_request + 37) = 1;
      raw_spin_lock(&reg_requests_lock);
      v20 = (_UNKNOWN **)reg_requests_list;
      raw_spin_unlock(&reg_requests_lock);
      if ( v20 != &reg_requests_list )
        queue_work_on(32, system_wq, &reg_work);
      v1 = -114;
      goto LABEL_116;
    }
    goto LABEL_38;
  }
  v19 = 0;
  v1 = -22;
  if ( v2 != 48 || v3 != 48 )
    goto LABEL_115;
  if ( !last_request )
    __break(0x800u);
  reset_regdomains(0, v5);
  cfg80211_world_regdom = (_UNKNOWN *)v5;
LABEL_103:
  if ( (v4[36] & 1) == 0 && cfg80211_regdomain != v5 )
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  update_all_wiphy_regulatory(*((unsigned int *)v4 + 5));
  v38 = cfg80211_regdomain;
  if ( *(_BYTE *)(cfg80211_regdomain + 20) == 57
    && *(_BYTE *)(cfg80211_regdomain + 21) == 56
    && *((_DWORD *)last_request + 5) == 3 )
  {
    v39 = cfg80211_regdomain;
    cfg80211_rdev_by_wiphy_idx(*((_DWORD *)last_request + 4));
    v38 = v39;
  }
  print_rd_rules(v38);
  nl80211_common_reg_change_event(0x24u, (__int64)v4);
  *((_BYTE *)last_request + 37) = 1;
  raw_spin_lock(&reg_requests_lock);
  v40 = (_UNKNOWN **)reg_requests_list;
  raw_spin_unlock(&reg_requests_lock);
  if ( v40 != &reg_requests_list )
    queue_work_on(32, system_wq, &reg_work);
  return 0;
}
