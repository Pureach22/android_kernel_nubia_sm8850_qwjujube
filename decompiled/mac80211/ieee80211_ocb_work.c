__int64 __fastcall ieee80211_ocb_work(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  _QWORD *v3; // x22
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int16 v6; // w9
  __int64 v7; // x21
  __int64 inserted; // x0
  __int64 v9; // x0
  unsigned __int64 v16; // x8
  int v17; // [xsp+0h] [xbp-10h] BYREF
  __int16 v18; // [xsp+4h] [xbp-Ch]
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 2336) )
  {
    v1 = result;
    raw_spin_lock_bh(result + 2312);
    v2 = *(_QWORD **)(v1 + 2320);
    v3 = (_QWORD *)(v1 + 2320);
    if ( v2 != (_QWORD *)(v1 + 2320) )
    {
      do
      {
        v4 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v4 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          *(_QWORD *)(v5 + 8) = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        *v2 = 0xDEAD000000000100LL;
        v2[1] = 0xDEAD000000000122LL;
        raw_spin_unlock_bh(v1 + 2312);
        v6 = *((_WORD *)v2 + 1346);
        v7 = v2[10];
        v17 = *((_DWORD *)v2 + 672);
        v18 = v6;
        sta_info_move_state(v2, 2);
        sta_info_move_state(v2, 3);
        sta_info_move_state(v2, 4);
        rate_control_rate_init(v2);
        inserted = sta_info_insert_rcu(v2);
        if ( (_DWORD)inserted )
          inserted = sta_info_get(v7, &v17);
        _rcu_read_unlock(inserted);
        raw_spin_lock_bh(v1 + 2312);
        v2 = (_QWORD *)*v3;
      }
      while ( (_QWORD *)*v3 != v3 );
    }
    result = raw_spin_unlock_bh(v1 + 2312);
    _X9 = (unsigned __int64 *)(v1 + 2304);
    __asm { PRFM            #0x11, [X9] }
    do
      v16 = __ldxr(_X9);
    while ( __stlxr(v16 & 0xFFFFFFFFFFFFFFFELL, _X9) );
    __dmb(0xBu);
    if ( (v16 & 1) != 0 )
    {
      ieee80211_sta_expire(v1, 60000);
      v9 = round_jiffies(jiffies + 15000LL);
      result = mod_timer(v1 + 2264, v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
