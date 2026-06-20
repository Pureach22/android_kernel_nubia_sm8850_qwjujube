__int64 __fastcall ieee80211_init_rate_ctrl_alg(__int64 a1, const char *a2)
{
  const char ***v5; // x20
  const char *v6; // x22
  const char **v7; // x23
  _UNKNOWN **v8; // x26
  const char *v9; // x21
  _UNKNOWN **v10; // x24
  const char *v11; // x8
  __int64 v12; // x0
  const char **v13; // x8

  if ( (unsigned int)rtnl_is_locked() || (ieee80211_init_rate_ctrl_alg___already_done & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 1316) )
      return 4294967280LL;
  }
  else
  {
    ieee80211_init_rate_ctrl_alg___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/rate.c", 985);
    __break(0x800u);
    if ( *(_DWORD *)(a1 + 1316) )
      return 4294967280LL;
  }
  if ( (*(_QWORD *)(a1 + 96) & 1) == 0 )
  {
    v5 = (const char ***)_kmalloc_cache_noprof(_usecs_to_jiffies, 3264, 16);
    if ( !v5 )
    {
LABEL_36:
      dev_warn(*(_QWORD *)(a1 + 72) + 392LL, "Failed to select rate control algorithm\n");
      return 4294967294LL;
    }
    kernel_param_lock(&_this_module);
    if ( a2 )
      v6 = a2;
    else
      v6 = (const char *)ieee80211_default_rc_algo;
    if ( v6 )
    {
      mutex_lock(&rate_ctrl_mutex);
      v8 = &rate_ctrl_algs;
      while ( 1 )
      {
        v8 = (_UNKNOWN **)*v8;
        if ( v8 == &rate_ctrl_algs )
          break;
        v7 = (const char **)v8[2];
        if ( !strcmp(v7[1], v6) )
          goto LABEL_20;
      }
      v7 = nullptr;
LABEL_20:
      mutex_unlock(&rate_ctrl_mutex);
    }
    else
    {
      v7 = nullptr;
    }
    if ( a2 && !v7 )
    {
      v9 = (const char *)ieee80211_default_rc_algo;
      if ( !ieee80211_default_rc_algo )
      {
        kernel_param_unlock(&_this_module);
        *v5 = nullptr;
LABEL_35:
        kfree(v5);
        goto LABEL_36;
      }
      mutex_lock(&rate_ctrl_mutex);
      v10 = &rate_ctrl_algs;
      while ( 1 )
      {
        v10 = (_UNKNOWN **)*v10;
        if ( v10 == &rate_ctrl_algs )
          break;
        v7 = (const char **)v10[2];
        if ( !strcmp(v7[1], v9) )
          goto LABEL_30;
      }
      v7 = nullptr;
LABEL_30:
      mutex_unlock(&rate_ctrl_mutex);
    }
    kernel_param_unlock(&_this_module);
    *v5 = v7;
    if ( v7 )
    {
      v11 = v7[2];
      if ( *((_DWORD *)v11 - 1) != 265677605 )
        __break(0x8228u);
      v12 = ((__int64 (__fastcall *)(__int64))v11)(a1);
      v5[1] = (const char **)v12;
      if ( v12 )
      {
        if ( *(_QWORD *)(a1 + 2536) )
          __break(0x800u);
        v13 = *v5;
        *(_QWORD *)(a1 + 2536) = v5;
        dev_printk(&unk_BBEF5, *(_QWORD *)(a1 + 72) + 392LL, "Selected rate control algorithm '%s'\n", v13[1]);
        return 0;
      }
    }
    goto LABEL_35;
  }
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 464) + 256LL) )
    return 0;
  __break(0x800u);
  return 4294967274LL;
}
