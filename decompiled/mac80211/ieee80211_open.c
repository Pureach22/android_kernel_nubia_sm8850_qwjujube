__int64 __fastcall ieee80211_open(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v3; // w0
  __int64 v4; // x8
  unsigned int v5; // w19

  v1 = *(_QWORD *)(a1 + 1008);
  if ( (*(_DWORD *)v1 & 1) != 0 || !(*(_DWORD *)v1 | *(unsigned __int16 *)(v1 + 4)) )
    return 4294967197LL;
  mutex_lock(*(_QWORD *)(*(_QWORD *)(a1 + 4304) + 72LL));
  v3 = ieee80211_check_concurrent_iface(a1 + 2688, *(unsigned int *)(a1 + 7408));
  if ( !v3 )
    v3 = ieee80211_do_open(a1 + 2704, 1);
  v4 = *(_QWORD *)(a1 + 4304);
  v5 = v3;
  mutex_unlock(*(_QWORD *)(v4 + 72));
  return v5;
}
