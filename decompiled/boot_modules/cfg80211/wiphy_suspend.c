__int64 __fastcall wiphy_suspend(__int64 a1)
{
  __int64 coarse_with_offset; // x0
  _QWORD *i; // x22
  unsigned int v4; // w22
  _QWORD *j; // x22
  __int64 v6; // x0

  coarse_with_offset = ktime_get_coarse_with_offset(1);
  *(_QWORD *)(a1 - 1120) = coarse_with_offset / 1000000000;
  rtnl_lock(coarse_with_offset);
  mutex_lock(a1 - 392);
  if ( *(_BYTE *)(a1 + 912) == 1 )
  {
    if ( !*(_QWORD *)(a1 - 136) )
    {
      for ( i = *(_QWORD **)(a1 + 944); i != (_QWORD *)(a1 + 944); i = (_QWORD *)*i )
        cfg80211_leave(a1 - 1384, (__int64)(i - 2));
      cfg80211_process_rdev_events(a1 - 1384);
    }
    cfg80211_process_wiphy_works(a1 - 1384, nullptr);
    if ( !**(_QWORD **)(a1 - 1384) )
      goto LABEL_12;
    v4 = rdev_suspend(a1 - 1384, *(_QWORD *)(a1 - 136));
    if ( v4 == 1 )
    {
      for ( j = *(_QWORD **)(a1 + 944); j != (_QWORD *)(a1 + 944); j = (_QWORD *)*j )
        cfg80211_leave(a1 - 1384, (__int64)(j - 2));
      cfg80211_process_rdev_events(a1 - 1384);
      cfg80211_process_wiphy_works(a1 - 1384, nullptr);
      v4 = rdev_suspend(a1 - 1384, 0);
    }
    if ( !v4 )
    {
LABEL_12:
      v4 = 0;
      *(_BYTE *)(a1 - 412) = 1;
    }
  }
  else
  {
    v4 = 0;
  }
  v6 = mutex_unlock(a1 - 392);
  rtnl_unlock(v6);
  return v4;
}
