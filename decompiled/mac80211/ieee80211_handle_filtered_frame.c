__int64 __fastcall ieee80211_handle_filtered_frame(__int64 a1, _QWORD *a2, __int64 a3)
{
  int v3; // w9
  _WORD *v5; // x8
  __int64 v7; // x10
  int v8; // w9
  __int64 v9; // x10
  char v10; // w9
  unsigned __int64 v11; // x23
  __int64 v12; // x21
  _QWORD *v13; // x8
  __int64 result; // x0
  __int64 v15; // x0
  int v16; // w8
  unsigned __int64 v23; // x9

  v3 = *(_DWORD *)(a3 + 40);
  if ( (v3 & 0x24040) == 0 )
  {
    *(_QWORD *)(a3 + 72) = 0;
    *(_QWORD *)(a3 + 80) = 0;
    v5 = *(_WORD **)(a3 + 224);
    *(_QWORD *)(a3 + 56) = 0;
    *(_QWORD *)(a3 + 64) = 0;
    *(_QWORD *)(a3 + 48) = jiffies;
    v7 = a2[10];
    *(_DWORD *)(a3 + 80) = 64;
    *(_DWORD *)(a3 + 40) = v3 & 0xEE31A083 | 0x80000;
    *(_QWORD *)(a3 + 64) = v7 + 4720;
    ++a2[249];
    v8 = (unsigned __int16)*v5;
    if ( (v8 & 0x2000) != 0 )
    {
      v8 &= ~0x2000u;
      *v5 = v8;
    }
    if ( (v8 & 0x8C) == 0x88 )
    {
      v9 = 15;
      if ( (~v8 & 0x300) != 0 )
        v9 = 12;
      v10 = v5[v9];
      if ( (v10 & 0x10) != 0 )
        LOBYTE(v5[v9]) = v10 & 0xEF;
      v11 = (int)ieee802_1d_to_ac[v10 & 7];
    }
    else
    {
      v11 = 2;
    }
    while ( 1 )
    {
      _X8 = a2 + 27;
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stxr(v23 | 0x40, _X8) );
      v12 = a1;
      a1 = ieee80211_clear_fast_xmit(a2);
      if ( (a2[27] & 4) == 0 )
        break;
      if ( v11 < 5 )
      {
        v13 = &a2[3 * (int)v11];
        if ( *((_DWORD *)v13 + 86) <= 0x3Fu )
        {
          skb_queue_tail(v13 + 41);
          result = sta_info_recalc_tim((__int64)a2);
          if ( !*(_QWORD *)(v12 + 1960) )
          {
            v15 = round_jiffies(jiffies + 2500LL);
            return mod_timer(v12 + 1952, v15);
          }
          return result;
        }
        break;
      }
      __break(0x5512u);
    }
    if ( (a2[27] & 4) == 0 )
    {
      v16 = *(_DWORD *)(a3 + 40);
      if ( (v16 & 0x8000) == 0 )
      {
        *(_DWORD *)(a3 + 40) = v16 | 0x8000;
        return ieee80211_add_pending_skb(v12, a3);
      }
    }
    a1 = v12;
  }
  ieee80211_report_used_skb(a1, a3, 1, 0);
  return dev_kfree_skb_any_reason(a3, 2);
}
