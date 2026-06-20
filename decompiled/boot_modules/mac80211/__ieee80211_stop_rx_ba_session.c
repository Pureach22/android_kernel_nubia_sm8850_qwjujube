__int64 __fastcall _ieee80211_stop_rx_ba_session(_QWORD *a1, unsigned int a2, __int16 a3, unsigned int a4, char a5)
{
  _QWORD *v6; // x24
  __int64 result; // x0
  char v9; // w8
  __int64 v10; // x20
  __int64 v12; // x1
  _QWORD v15[2]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v16; // [xsp+18h] [xbp-18h]
  _WORD v17[11]; // [xsp+1Ah] [xbp-16h]

  v6 = a1 + 336;
  *(_QWORD *)&v17[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = a1[9];
  v15[0] = 1;
  v15[1] = v6;
  v16 = a2;
  *(_QWORD *)v17 = 0;
  *(_QWORD *)&v17[3] = 0;
  if ( (unsigned __int16)a2 >= 0x10u )
    __break(0x5512u);
  v9 = a2;
  v10 = a1[(unsigned __int16)a2 + 87];
  if ( ((a1[108] >> a2) & 1) != 0 )
  {
    a1[(unsigned __int16)a2 + 87] = 0;
    v12 = a1[10];
    a1[108] &= ~(1LL << v9);
    result = drv_ampdu_action(result, v12, v15);
    if ( (_DWORD)result )
    {
      result = printk(&unk_BB816, a1[10] + 1640LL, a1 + 336, (unsigned __int16)a2);
      if ( !a3 )
      {
LABEL_5:
        if ( (a5 & 1) != 0 )
          result = ieee80211_send_delba(a1[10], v6, a2, 0, a4);
      }
    }
    else if ( !a3 )
    {
      goto LABEL_5;
    }
    if ( v10 )
    {
      timer_delete_sync(v10 + 56);
      raw_spin_lock_bh(v10 + 16);
      *(_BYTE *)(v10 + 155) |= 2u;
      raw_spin_unlock_bh(v10 + 16);
      timer_delete_sync(v10 + 96);
      result = call_rcu(v10, ieee80211_free_tid_rx);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
