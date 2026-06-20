__int64 __fastcall ieee80211_tdls_handle_disconnect(__int64 a1, const void *a2)
{
  unsigned __int64 sta; // x0
  __int64 v5; // x3

  _rcu_read_lock(a1, a2);
  sta = ieee80211_find_sta(a1 + 4720, a2);
  if ( !sta || (*(_BYTE *)(sta + 24) & 1) == 0 )
    return _rcu_read_unlock(sta);
  _rcu_read_unlock(sta);
  if ( *(_DWORD *)(a1 + 4720) == 2 && (*(_BYTE *)(a1 + 4728) & 1) != 0 )
    return cfg80211_tdls_oper_request(*(_QWORD *)(a1 + 1608));
  else
    return printk(&unk_BB729, a1 + 1640, 2, v5);
}
