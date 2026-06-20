__int64 __fastcall _sta_info_destroy_part2(__int64 a1, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  int v6; // w9
  unsigned int v7; // w8
  __int64 v8; // x21

  v3 = *(_QWORD *)(a1 + 72);
  v2 = *(_QWORD *)(a1 + 80);
  ieee80211_sta_tear_down_BA_sessions((_QWORD *)a1, 3u);
  if ( *(_DWORD *)(a1 + 208) == 4 && (unsigned int)sta_info_move_state(a1, 3, a2 & 1) )
    __break(0x800u);
  ieee80211_free_sta_keys(v3, a1);
  _sta_info_recalc_tim(a1, 1);
  *(_BYTE *)(a1 + 202) = 1;
  v6 = *(_DWORD *)(v3 + 1992) + 1;
  --*(_QWORD *)(v3 + 1608);
  *(_DWORD *)(v3 + 1992) = v6;
  while ( 1 )
  {
    v7 = *(_DWORD *)(a1 + 208);
    if ( v7 < 2 )
      break;
    if ( (unsigned int)sta_info_move_state(a1, v7 - 1, a2 & 1) )
    {
      __break(0x800u);
      break;
    }
  }
  if ( *(_BYTE *)(a1 + 204) == 1 && (unsigned int)drv_sta_state(v3, v2, a1, 1, 0) )
    __break(0x800u);
  v8 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 264);
  if ( v8 )
    sta_set_sinfo(a1, v8, 1);
  cfg80211_del_sta_sinfo(*(_QWORD *)(v2 + 1608), a1 + 2688, v8, 3264);
  kfree(v8);
  ieee80211_destroy_frag_cache((__int64 **)(a1 + 1368));
  return cleanup_single_sta(a1);
}
