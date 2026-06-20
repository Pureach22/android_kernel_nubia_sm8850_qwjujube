__int64 __fastcall sta_info_free(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x23
  __int64 v5; // x8
  __int64 v6; // x20
  unsigned int v7; // w8
  int v8; // w1
  _QWORD *v9; // x8
  __int64 v10; // x0
  __int64 v11; // x2
  void (__fastcall *v12)(__int64, __int64, __int64); // x8

  v3 = 0;
  v4 = a2 + 1640;
  do
  {
    v5 = a2 + 8 * v3;
    if ( *(_QWORD *)(v5 + 2568) )
    {
      v6 = *(_QWORD *)(v5 + 2568);
      if ( v6 )
      {
        *(_WORD *)(a2 + 2872) &= ~(unsigned __int16)(1LL << v3);
        *(_QWORD *)(v5 + 2568) = 0;
        *(_QWORD *)(v5 + 3128) = 0;
        if ( v6 != v4 )
        {
          free_percpu(*(_QWORD *)(v6 + 104));
          kvfree_call_rcu(v6 + 1176, v6);
        }
        _ieee80211_sta_recalc_aggregates(a2, *(unsigned __int16 *)(*(_QWORD *)(a2 + 80) + 5802LL));
      }
      else
      {
        __break(0x800u);
      }
    }
    ++v3;
  }
  while ( v3 != 15 );
  do
  {
    v7 = *(_DWORD *)(a2 + 208);
    if ( v7 < 2 )
      break;
    if ( (*(_QWORD *)(a2 + 216) & 0x100000) != 0 )
    {
      __break(0x800u);
      v7 = *(_DWORD *)(a2 + 208);
    }
    v8 = sta_info_move_state(a2, v7 - 1, 1);
    if ( v8 && (sta_info_free___already_done & 1) == 0 )
    {
      sta_info_free___already_done = 1;
      _warn_printk("sta_info_move_state() returned %d\n", v8);
      __break(0x800u);
      break;
    }
  }
  while ( !v8 );
  v9 = *(_QWORD **)(a2 + 128);
  if ( v9 )
  {
    v10 = v9[1];
    v11 = *(_QWORD *)(a2 + 136);
    v12 = *(void (__fastcall **)(__int64, __int64, __int64))(*v9 + 64LL);
    if ( *((_DWORD *)v12 - 1) != -1073837200 )
      __break(0x8228u);
    v12(v10, a2 + 2688, v11);
  }
  kfree(*(_QWORD *)(a2 + 2736) - 232LL);
  kfree(*(_QWORD *)(a2 + 2704));
  free_percpu(*(_QWORD *)(a2 + 1744));
  return kfree(a2);
}
