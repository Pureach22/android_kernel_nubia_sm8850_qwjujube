__int64 __fastcall cfg80211_dev_rename(_QWORD *a1, const char *a2)
{
  const char *v4; // x1
  __int64 result; // x0
  unsigned __int64 v6; // x1

  if ( !(unsigned int)rtnl_is_locked(a1) && (cfg80211_dev_rename___already_done & 1) == 0 )
  {
    cfg80211_dev_rename___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 131);
    __break(0x800u);
    v4 = (const char *)a1[187];
    if ( v4 )
      goto LABEL_5;
    goto LABEL_4;
  }
  v4 = (const char *)a1[187];
  if ( !v4 )
LABEL_4:
    v4 = (const char *)a1[173];
LABEL_5:
  result = strcmp(a2, v4);
  if ( (_DWORD)result )
  {
    result = cfg80211_dev_check_name(a1, a2);
    if ( (result & 0x80000000) == 0 )
    {
      result = device_rename(a1 + 173, a2);
      if ( !(_DWORD)result )
      {
        v6 = a1[288];
        if ( v6 )
        {
          if ( v6 <= 0xFFFFFFFFFFFFF000LL )
            debugfs_rename(*(_QWORD *)(v6 + 24), v6, *(_QWORD *)(v6 + 24), a2);
        }
        nl80211_notify_wiphy(a1, 3);
        return 0;
      }
    }
  }
  return result;
}
