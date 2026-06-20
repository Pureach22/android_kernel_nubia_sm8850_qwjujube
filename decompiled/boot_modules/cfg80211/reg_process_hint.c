unsigned __int64 __fastcall reg_process_hint(unsigned __int64 a1)
{
  __int64 v2; // x0
  int v3; // w20
  unsigned __int64 result; // x0
  unsigned int v5; // w9
  int v6; // w9
  int v7; // w8
  int v8; // w8
  __int64 v9; // x11
  __int64 v10; // x11
  _UNKNOWN **v11; // x22
  _UNKNOWN **v12; // x8
  unsigned __int64 v13; // x25
  char v14; // w8
  unsigned __int64 v15; // x21
  char v16; // w27
  int v17; // w26
  __int64 v18; // x21
  unsigned __int64 v19; // x22
  _UNKNOWN **v20; // x22

  v2 = *(unsigned int *)(a1 + 16);
  v3 = *(_DWORD *)(a1 + 20);
  if ( (_DWORD)v2 != -1 )
  {
    result = (unsigned __int64)wiphy_idx_to_wiphy(v2);
    if ( v3 <= 1 )
      goto LABEL_3;
LABEL_13:
    if ( v3 != 2 )
    {
      if ( v3 != 3 )
        goto LABEL_21;
      if ( !result )
        goto LABEL_102;
      v6 = *(_DWORD *)((char *)&qword_10 + (_QWORD)last_request + 4);
      if ( v6 == 1 && *(_DWORD *)((char *)&_ksymtab___cfg80211_get_bss + (_QWORD)last_request) == 1 )
      {
        if ( cfg80211_regdomain && *(unsigned __int8 *)(cfg80211_regdomain + 20) == *(unsigned __int8 *)(a1 + 28) )
        {
          v7 = *(unsigned __int8 *)(cfg80211_regdomain + 21);
          goto LABEL_45;
        }
        goto LABEL_102;
      }
      if ( (*(_BYTE *)(result + 104) & 0x10) != 0 )
        goto LABEL_102;
      v9 = *(char *)(a1 + 28);
      if ( (v9 & 0x8000000000000000LL) == 0 && (*((_BYTE *)&ctype + v9) & 3) != 0 )
      {
        v10 = *(char *)(a1 + 29);
        if ( (v10 & 0x8000000000000000LL) == 0 && v6 == 3 && (*((_BYTE *)&ctype + v10) & 3) != 0 )
        {
          v11 = (_UNKNOWN **)result;
          v12 = wiphy_idx_to_wiphy(*(unsigned int *)((char *)&qword_10 + (_QWORD)last_request));
          result = (unsigned __int64)v11;
          if ( v12 != v11 )
          {
            if ( cfg80211_regdomain && *(unsigned __int8 *)(cfg80211_regdomain + 20) == *(unsigned __int8 *)(a1 + 28) )
            {
              v7 = *(unsigned __int8 *)(cfg80211_regdomain + 21);
LABEL_45:
              if ( v7 != *(unsigned __int8 *)(a1 + 29) )
                goto LABEL_102;
              goto LABEL_46;
            }
LABEL_102:
            if ( (_UNKNOWN *)a1 != &core_request_world && last_request != (_UNKNOWN *)a1 )
              return kfree(a1);
            return result;
          }
          if ( cfg80211_regdomain
            && *(unsigned __int8 *)(cfg80211_regdomain + 20) == *(unsigned __int8 *)(a1 + 28)
            && *(unsigned __int8 *)(cfg80211_regdomain + 21) == *(unsigned __int8 *)(a1 + 29) )
          {
LABEL_46:
            v13 = result;
            if ( (_UNKNOWN *)a1 != &core_request_world && last_request != (_UNKNOWN *)a1 )
              result = kfree(a1);
LABEL_85:
            if ( (*(_BYTE *)(v13 + 104) & 2) != 0 )
            {
              wiphy_update_regulatory(v13, (unsigned int)v3);
              wiphy_all_share_dfs_chan_state(v13);
              return mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
            }
            return result;
          }
        }
      }
      *(_WORD *)(a1 + 36) = 0;
      result = reg_query_database(a1);
      if ( (result & 1) == 0 )
        goto LABEL_102;
      if ( last_request == (_UNKNOWN *)a1 )
        return result;
      result = (unsigned __int64)last_request;
      if ( last_request != &core_request_world && last_request )
        result = kvfree_call_rcu(last_request, last_request);
LABEL_101:
      atomic_store(a1, (unsigned __int64 *)&last_request);
      return result;
    }
    if ( !result )
      goto LABEL_102;
    v8 = *((_DWORD *)last_request + 5);
    if ( v8 == 2 )
    {
      if ( cfg80211_regdomain
        && *(unsigned __int8 *)(cfg80211_regdomain + 20) == *(unsigned __int8 *)(a1 + 28)
        && *(unsigned __int8 *)(cfg80211_regdomain + 21) == *(unsigned __int8 *)(a1 + 29) )
      {
LABEL_69:
        v15 = result;
        v16 = 0;
        v17 = 1;
        goto LABEL_71;
      }
    }
    else if ( !v8 )
    {
      if ( !cfg80211_regdomain
        || *(unsigned __int8 *)(cfg80211_regdomain + 20) != *(unsigned __int8 *)(a1 + 28)
        || *(unsigned __int8 *)(cfg80211_regdomain + 21) != *(unsigned __int8 *)(a1 + 29) )
      {
        *(_WORD *)(a1 + 36) = 0;
LABEL_87:
        result = reg_query_database(a1);
        if ( (result & 1) == 0 )
          goto LABEL_102;
        if ( last_request == (_UNKNOWN *)a1 )
          return result;
        result = (unsigned __int64)last_request;
        if ( last_request != &core_request_world && last_request )
          result = kvfree_call_rcu(last_request, last_request);
        goto LABEL_101;
      }
      goto LABEL_69;
    }
    v15 = result;
    v17 = 0;
    v16 = 1;
LABEL_71:
    result = reg_copy_regd(cfg80211_regdomain);
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_102;
    v13 = v15;
    v18 = *(_QWORD *)(v15 + 384);
    v19 = result;
    if ( !(unsigned int)rtnl_is_locked(result) && (reg_process_hint_driver___already_done & 1) == 0 )
    {
      reg_process_hint_driver___already_done = 1;
      _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 2828);
      __break(0x800u);
    }
    mutex_lock(v13);
    atomic_store(v19, (unsigned __int64 *)(v13 + 384));
    mutex_unlock(v13);
    if ( v18 )
      kvfree_call_rcu(v18, v18);
    *(_BYTE *)(a1 + 36) = v16;
    *(_BYTE *)(a1 + 37) = 0;
    if ( v17 )
    {
      nl80211_common_reg_change_event(0x24u, a1);
      if ( last_request != (_UNKNOWN *)a1 )
      {
        if ( last_request != &core_request_world && last_request )
          kvfree_call_rcu(last_request, last_request);
        atomic_store(a1, (unsigned __int64 *)&last_request);
      }
      *((_BYTE *)last_request + 37) = 1;
      raw_spin_lock(&reg_requests_lock);
      v20 = (_UNKNOWN **)reg_requests_list;
      result = raw_spin_unlock(&reg_requests_lock);
      if ( v20 != &reg_requests_list )
        result = queue_work_on(32, system_wq, &reg_work);
      goto LABEL_85;
    }
    goto LABEL_87;
  }
  result = 0;
  if ( v3 > 1 )
    goto LABEL_13;
LABEL_3:
  if ( !v3 )
  {
    result = reg_query_database(a1);
    if ( (result & 1) == 0 )
      goto LABEL_102;
    *(_WORD *)(a1 + 36) = 0;
    if ( last_request == (_UNKNOWN *)a1 )
      return result;
    result = (unsigned __int64)last_request;
    if ( last_request != &core_request_world && last_request )
      result = kvfree_call_rcu(last_request, last_request);
    goto LABEL_101;
  }
  if ( v3 != 1 )
  {
LABEL_21:
    result = _warn_printk("invalid initiator %d\n", v3);
    __break(0x800u);
    goto LABEL_102;
  }
  if ( *(_DWORD *)(a1 + 20) == 1 && *(_DWORD *)(a1 + 24) == 1 )
    goto LABEL_102;
  v5 = *(_DWORD *)((char *)&qword_10 + (_QWORD)last_request + 4);
  if ( v5 != 3 )
  {
    if ( v5 == 1 )
    {
      if ( *(_DWORD *)((char *)&_ksymtab___cfg80211_get_bss + (_QWORD)last_request) == 1
        || (_ksymtab___cfg80211_radar_event[(_QWORD)last_request] & 1) != 0 )
      {
        goto LABEL_102;
      }
    }
    else if ( v5 > 2 )
    {
LABEL_55:
      v14 = cfg80211_regdomain;
      if ( cfg80211_regdomain )
      {
        if ( *(unsigned __int8 *)(cfg80211_regdomain + 20) == *(unsigned __int8 *)(a1 + 28)
          && *(unsigned __int8 *)(cfg80211_regdomain + 21) == *(unsigned __int8 *)(a1 + 29) )
        {
          goto LABEL_102;
        }
        v14 = 0;
      }
      goto LABEL_59;
    }
    if ( last_request == (_UNKNOWN *)-28LL
      || !cfg80211_regdomain
      || *(unsigned __int8 *)(cfg80211_regdomain + 20) != *((unsigned __int8 *)last_request + 28)
      || *(unsigned __int8 *)(cfg80211_regdomain + 21) != byte_1D[(_QWORD)last_request] )
    {
      goto LABEL_102;
    }
    goto LABEL_55;
  }
  v14 = 1;
LABEL_59:
  *(_BYTE *)(a1 + 36) = v14;
  *(_BYTE *)(a1 + 37) = 0;
  result = reg_query_database(a1);
  if ( (result & 1) == 0 )
    goto LABEL_102;
  if ( last_request != (_UNKNOWN *)a1 )
  {
    result = (unsigned __int64)last_request;
    if ( last_request != &core_request_world && last_request )
      result = kvfree_call_rcu(last_request, last_request);
    atomic_store(a1, (unsigned __int64 *)&last_request);
  }
  user_alpha2 = *(_WORD *)(a1 + 28);
  return result;
}
