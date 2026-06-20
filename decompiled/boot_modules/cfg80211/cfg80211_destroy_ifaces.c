__int64 __fastcall cfg80211_destroy_ifaces(__int64 a1)
{
  __int64 result; // x0
  __int64 *v3; // x20
  __int64 *v4; // x20
  __int64 *v5; // x22

  result = rtnl_is_locked(a1);
  if ( !(_DWORD)result && (cfg80211_destroy_ifaces___already_done & 1) == 0 )
  {
    cfg80211_destroy_ifaces___already_done = 1;
    result = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 343);
    __break(0x800u);
  }
  v3 = *(__int64 **)(a1 + 2328);
  if ( v3 != (__int64 *)(a1 + 2328) )
  {
    do
    {
      v5 = (__int64 *)*v3;
      if ( *((_BYTE *)v3 + 164) == 1 )
      {
        if ( v3[2] )
          dev_close();
        v4 = v3 - 2;
        mutex_lock(a1 + 992);
        cfg80211_leave(a1, v4);
        cfg80211_remove_virtual_intf(a1, v4);
        result = mutex_unlock(a1 + 992);
      }
      v3 = v5;
    }
    while ( v5 != (__int64 *)(a1 + 2328) );
  }
  return result;
}
