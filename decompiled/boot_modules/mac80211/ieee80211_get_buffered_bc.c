__int64 __fastcall ieee80211_get_buffered_bc(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  _DWORD **v5; // x24
  _QWORD *v6; // x8
  _QWORD *v7; // x21
  __int64 v8; // x20
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v12[8]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v13; // [xsp+40h] [xbp-10h]
  __int64 v14; // [xsp+48h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  memset(v12, 0, sizeof(v12));
  lock = _rcu_read_lock(a1, a2);
  v5 = *(_DWORD ***)(a2 + 920);
  if ( v5
    && *(_DWORD *)a2 == 3
    && (v6 = *(_QWORD **)(a2 - 568)) != nullptr
    && *v6
    && !*(_DWORD *)(a2 - 2156)
    && *(_BYTE *)(a2 - 2152) == 1
    && (v7 = (_QWORD *)(a2 - 2184), (lock = skb_dequeue(a2 - 2184)) != 0) )
  {
    v8 = lock;
    v9 = a2 - 4720;
    while ( 1 )
    {
      --*(_DWORD *)(a1 + 5000);
      if ( (_QWORD *)*v7 != v7 && *(_DWORD *)(v8 + 112) >= 2u )
        **(_WORD **)(v8 + 224) |= 0x2000u;
      if ( *(_DWORD *)(v9 + 4720) == 3 )
        v9 = *(_QWORD *)(v8 + 16) + 2688LL;
      if ( !(unsigned int)ieee80211_tx_prepare(v9, v12, nullptr, v8) )
        break;
      ieee80211_free_txskb(a1, v8);
      lock = skb_dequeue(v7);
      v8 = lock;
      v10 = 0;
      if ( !lock )
        goto LABEL_18;
    }
    HIDWORD(v13) |= 4u;
    *(_DWORD *)(v8 + 44) = *(_DWORD *)(v8 + 44) & 0xFFFFFFF8 | **v5 & 7;
    lock = invoke_tx_handlers((__int64)v12);
    if ( (_DWORD)lock )
      v10 = 0;
    else
      v10 = v8;
  }
  else
  {
    v10 = 0;
  }
LABEL_18:
  _rcu_read_unlock(lock);
  _ReadStatusReg(SP_EL0);
  return v10;
}
