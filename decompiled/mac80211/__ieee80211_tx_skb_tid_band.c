__int64 __fastcall _ieee80211_tx_skb_tid_band(__int64 a1, __int64 a2, int a3, int a4, char a5)
{
  __int64 v5; // x21
  unsigned int v7; // w9
  __int16 v8; // w8
  __int64 i; // x20
  char v11; // w22
  __int64 v12; // x23
  __int64 lock; // x0
  __int64 v14; // x9
  int v15; // w10
  int v16; // w9
  unsigned int v18; // w9
  unsigned int v19; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x0

  v5 = *(_QWORD *)(a2 + 224);
  v7 = ieee802_1d_to_ac[a3 & 7];
  v8 = v5 - *(_DWORD *)(a2 + 216);
  *(_DWORD *)(a2 + 144) = a3;
  *(_WORD *)(a2 + 186) = v8;
  *(_WORD *)(a2 + 124) = v7;
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a1 + 1608);
  if ( *(_WORD *)(a1 + 5800) )
  {
    LODWORD(i) = a4;
    if ( a4 < 0 )
    {
      if ( *(_DWORD *)(a1 + 5842) == *(_DWORD *)(v5 + 10)
        && *(unsigned __int16 *)(a1 + 5846) == *(unsigned __int16 *)(v5 + 14) )
      {
        LODWORD(i) = 15;
      }
      else
      {
        v11 = a5;
        v12 = a1;
        lock = _rcu_read_lock(a1, a2);
        for ( i = 0; i != 15; ++i )
        {
          v14 = *(_QWORD *)(v12 + 5680 + 8 * i);
          if ( v14 )
          {
            v15 = *(_DWORD *)(v14 + 28);
            v16 = *(unsigned __int16 *)(v14 + 32);
            if ( v15 == *(_DWORD *)(v5 + 10) && v16 == *(unsigned __int16 *)(v5 + 14) )
            {
              _rcu_read_unlock(lock);
              a1 = v12;
              goto LABEL_21;
            }
          }
        }
        _rcu_read_unlock(lock);
        __break(0x800u);
        a1 = v12;
        v18 = __clz(__rbit32(*(unsigned __int16 *)(v12 + 5802)));
        if ( *(_WORD *)(v12 + 5802) )
          v19 = v18 + 1;
        else
          v19 = 0;
        LODWORD(i) = v19 - 1;
LABEL_21:
        a5 = v11;
      }
    }
  }
  else
  {
    LODWORD(i) = 0;
  }
  *(_DWORD *)(a2 + 80) |= (_DWORD)i << 28;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a2 + 44) & 0xFFFFFFF8 | a5 & 7;
  v21 = ieee80211_xmit(a1, 0, a2);
  return local_bh_enable_3(v21);
}
