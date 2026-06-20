__int64 __fastcall wiphy_resume(__int64 a1)
{
  __int64 v2; // x21
  int coarse_with_offset; // w0
  __int64 v4; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  unsigned int v6; // w21
  __int64 v7; // x0

  v2 = a1 - 1384;
  coarse_with_offset = ktime_get_coarse_with_offset(1);
  v4 = cfg80211_bss_age(v2, coarse_with_offset / 1000000000 - (unsigned int)*(_QWORD *)(a1 - 1120));
  rtnl_lock(v4);
  mutex_lock(a1 - 392);
  if ( *(_BYTE *)(a1 + 912) == 1 && *(_QWORD *)(*(_QWORD *)v2 + 8LL) )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 8LL);
    if ( *((_DWORD *)v5 - 1) != -1328306748 )
      __break(0x8228u);
    v6 = v5(a1 - 392);
  }
  else
  {
    v6 = 0;
  }
  *(_BYTE *)(a1 - 412) = 0;
  queue_work_on(32, system_unbound_wq, a1 - 464);
  v7 = mutex_unlock(a1 - 392);
  if ( v6 )
    v7 = ((__int64 (__fastcall *)(__int64))cfg80211_shutdown_all_interfaces)(a1 - 392);
  rtnl_unlock(v7);
  return v6;
}
