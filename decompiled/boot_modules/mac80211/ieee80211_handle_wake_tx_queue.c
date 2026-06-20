__int64 __fastcall ieee80211_handle_wake_tx_queue(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x0
  __int64 *v8; // x21
  __int64 v9; // x0
  __int64 v10; // x2
  _DWORD *v11; // x8
  __int64 result; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock(a1 + 400);
  ieee80211_txq_schedule_start(a1, *(unsigned __int8 *)(a2 + 17), v4, v5, v6);
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD))ieee80211_next_txq)(a1, *(unsigned __int8 *)(a2 + 17));
  if ( v7 )
  {
    v8 = (__int64 *)v7;
    do
    {
      v13[0] = v8[1];
      v9 = ieee80211_tx_dequeue(a1, v8);
      if ( v9 )
      {
        v10 = v9;
        do
        {
          v11 = **(_DWORD ***)(a1 + 464);
          if ( *(v11 - 1) != 638598288 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD *, __int64))v11)(a1, v13, v10);
          v10 = ieee80211_tx_dequeue(a1, v8);
        }
        while ( v10 );
      }
      _ieee80211_schedule_txq(a1, (unsigned __int64)v8, 0);
      v8 = (__int64 *)((__int64 (__fastcall *)(__int64, _QWORD))ieee80211_next_txq)(a1, *(unsigned __int8 *)(a2 + 17));
    }
    while ( v8 );
  }
  result = raw_spin_unlock(a1 + 400);
  _ReadStatusReg(SP_EL0);
  return result;
}
