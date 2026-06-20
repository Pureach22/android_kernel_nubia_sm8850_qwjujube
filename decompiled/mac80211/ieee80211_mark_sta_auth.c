__int64 __fastcall ieee80211_mark_sta_auth(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x3

  v5 = *(_QWORD *)(a1 + 2480);
  printk(&unk_B7ACB, a1 + 1640, a3, a4);
  *(_BYTE *)(*(_QWORD *)(a1 + 2480) + 39LL) = 1;
  *(_QWORD *)(*(_QWORD *)(a1 + 2480) + 8LL) = jiffies + 1250LL;
  *(_BYTE *)(*(_QWORD *)(a1 + 2480) + 42LL) = 1;
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 2480) + 8LL);
  if ( !*(_QWORD *)(a1 + 2272) || v6 - *(_QWORD *)(a1 + 2280) < 0 )
    mod_timer(a1 + 2264, v6);
  v7 = sta_info_get(a1, v5 + 48);
  if ( v7 )
  {
    if ( !(unsigned int)sta_info_move_state(v7, 2) )
      return 1;
    printk(&unk_BB679, a1 + 1640, v5 + 48, v8);
  }
  else if ( (ieee80211_mark_sta_auth___already_done & 1) == 0 )
  {
    ieee80211_mark_sta_auth___already_done = 1;
    _warn_printk("%s: STA %pM not found", (const char *)(a1 + 1640), (const void *)(v5 + 48));
    __break(0x800u);
    return 0;
  }
  return 0;
}
