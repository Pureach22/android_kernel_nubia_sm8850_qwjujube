__int64 __fastcall nl80211_del_interface(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20

  v2 = *(_QWORD *)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 32LL) )
    return 4294967201LL;
  v3 = *(_QWORD *)(a2 + 56);
  mutex_unlock(v2 + 992);
  if ( *(_QWORD *)(v3 + 32) )
    dev_close();
  else
    *(_QWORD *)(a2 + 56) = 0;
  mutex_lock(v2 + 992);
  return cfg80211_remove_virtual_intf(v2, v3);
}
