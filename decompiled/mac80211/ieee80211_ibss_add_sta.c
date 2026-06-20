__int64 __fastcall ieee80211_ibss_add_sta(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x21
  __int64 v6; // x20
  __int64 v7; // x3
  int v9; // w23
  __int64 lock; // x0
  unsigned int **v11; // x8
  __int64 v12; // x23
  __int64 v13; // x19

  v4 = *(_QWORD *)(a1 + 1616);
  v6 = a1;
  if ( *(_QWORD *)(v4 + 1608) >= 0x80u )
  {
    a1 = net_ratelimit();
    if ( (_DWORD)a1 )
      a1 = printk(&unk_BB3D4, v6 + 1640, a3, v7);
    goto LABEL_10;
  }
  if ( !*(_DWORD *)(a1 + 2520) )
    goto LABEL_10;
  v9 = *(_DWORD *)(a1 + 2346) ^ *(_DWORD *)a2 | *(unsigned __int16 *)(a1 + 2350) ^ *(unsigned __int16 *)(a2 + 4);
  lock = _rcu_read_lock(a1, a2);
  if ( v9 )
    return 0;
  v11 = *(unsigned int ***)(v6 + 5640);
  if ( !v11 )
  {
    __break(0x800u);
    return 0;
  }
  v12 = **v11;
  _rcu_read_unlock(lock);
  a1 = sta_info_alloc(v6, a3, 3264);
  if ( !a1 )
  {
LABEL_10:
    _rcu_read_lock(a1, a2);
    return 0;
  }
  if ( (unsigned int)v12 >= 6 )
  {
    __break(0x5512u);
    return ieee80211_ibss_csa_mark_radar(a1);
  }
  else
  {
    v13 = a1;
    *(_DWORD *)(a1 + 4 * v12 + 2900) = ieee80211_mandatory_rates(*(_QWORD *)(*(_QWORD *)(v4 + 72) + 8 * v12 + 328)) | a4;
    return ieee80211_ibss_finish_sta(v13);
  }
}
