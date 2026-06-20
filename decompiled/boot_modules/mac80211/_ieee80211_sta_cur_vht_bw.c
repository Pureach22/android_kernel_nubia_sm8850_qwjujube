__int64 __fastcall ieee80211_sta_cur_vht_bw(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v4; // w21
  __int64 lock; // x0
  unsigned __int64 v6; // x8
  __int64 v7; // x8
  unsigned int v8; // w0
  unsigned int v9; // w8
  __int64 v10; // x9
  unsigned int v11; // w9

  v2 = *(_QWORD *)(a1 + 32);
  if ( a2 )
  {
    v4 = *(_DWORD *)(a2 + 8);
  }
  else
  {
    lock = _rcu_read_lock(a1, 0);
    v6 = *(unsigned __int8 *)(a1 + 6);
    if ( v6 >= 0x10 )
    {
      __break(0x5512u);
      return ieee80211_sta_init_nss(lock);
    }
    v7 = *(_QWORD *)(*(_QWORD *)(v2 + 80) + 8 * v6 + 5680);
    if ( !v7 )
    {
      __break(0x800u);
      _rcu_read_unlock(lock);
      return 0;
    }
    v4 = *(_DWORD *)(v7 + 144);
    _rcu_read_unlock(lock);
    a2 = 0;
  }
  v8 = ((__int64 (__fastcall *)(__int64, __int64))ieee80211_sta_cap_rx_bw)(a1, a2);
  v9 = *(_DWORD *)(a1 + 912);
  if ( v8 < v9 )
    v9 = v8;
  if ( (*(_QWORD *)(v2 + 216) & 0x800) != 0
    && (*(_QWORD *)(v2 + 216) & 0x10000) != 0
    && (*(_QWORD *)(v2 + 216) & 8) != 0
    && *(_QWORD *)(v2 + 1336) )
  {
    v10 = *(unsigned int *)(v2 + 1344);
    if ( (unsigned int)v10 < 0xE && ((0x203Fu >> v10) & 1) != 0 )
    {
      v11 = dword_C0F88[v10];
      goto LABEL_19;
    }
  }
  else if ( v4 < 0xE && ((0x203Fu >> v4) & 1) != 0 )
  {
    v11 = dword_C0F88[v4];
    goto LABEL_19;
  }
  v11 = 0;
  __break(0x800u);
LABEL_19:
  if ( v9 >= v11 )
    return v11;
  else
    return v9;
}
