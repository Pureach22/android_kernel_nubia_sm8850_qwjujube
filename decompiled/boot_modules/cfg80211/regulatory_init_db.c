__int64 regulatory_init_db()
{
  unsigned int v0; // w19
  unsigned int builtin_regdb_keys; // w0
  _BYTE *v3; // x19
  __int64 v4; // x0
  char v5; // w8

  v0 = -22;
  if ( reg_pdev && (unsigned __int64)reg_pdev <= 0xFFFFFFFFFFFFF000LL )
  {
    builtin_regdb_keys = load_builtin_regdb_keys();
    if ( builtin_regdb_keys )
    {
      v0 = builtin_regdb_keys;
      platform_device_unregister(reg_pdev);
    }
    else
    {
      v3 = cfg80211_world_regdom;
      v4 = _kmalloc_cache_noprof(timer_delete, 3520, 64);
      if ( v4 )
      {
        *(_BYTE *)(v4 + 28) = v3[20];
        v5 = v3[21];
        *(_QWORD *)(v4 + 16) = 0xFFFFFFFFLL;
        *(_BYTE *)(v4 + 29) = v5;
        queue_regulatory_request(v4);
        if ( !ieee80211_regdom
          || *ieee80211_regdom != 48
          || *((_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + (_QWORD)ieee80211_regdom + 1) != 48 )
        {
          regulatory_hint_user((unsigned __int8 *)ieee80211_regdom, 0);
        }
        return 0;
      }
      else
      {
        platform_device_unregister(reg_pdev);
        return (unsigned int)-12;
      }
    }
  }
  return v0;
}
