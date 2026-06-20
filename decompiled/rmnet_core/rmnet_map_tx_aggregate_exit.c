__int64 __fastcall rmnet_map_tx_aggregate_exit(__int64 a1)
{
  __int64 v2; // x1
  _QWORD *v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x23
  __int64 v6; // x0
  __int64 v7; // x1
  _QWORD *v8; // x20
  _QWORD *v9; // x8
  _QWORD *v10; // x23
  __int64 v11; // x0

  hrtimer_cancel(a1 + 2112);
  cancel_work_sync(a1 + 2176);
  hrtimer_cancel(a1 + 2312);
  cancel_work_sync(a1 + 2376);
  raw_spin_lock_bh(a1 + 2208);
  if ( *(_DWORD *)(a1 + 2232) == -115 )
  {
    v2 = *(_QWORD *)(a1 + 2216);
    if ( v2 )
    {
      sk_skb_reason_drop(0, v2, 2);
      *(_QWORD *)(a1 + 2216) = 0;
      *(_BYTE *)(a1 + 2236) = 0;
      *(_QWORD *)(a1 + 2080) = 0;
      *(_QWORD *)(a1 + 2088) = 0;
    }
    *(_DWORD *)(a1 + 2232) = 0;
  }
  v3 = *(_QWORD **)(a1 + 2240);
  if ( v3 != (_QWORD *)(a1 + 2240) )
  {
    do
    {
      v5 = (_QWORD *)*v3;
      v4 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v4 == v3 && (_QWORD *)v5[1] == v3 )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      v6 = v3[2];
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      rmnet_mem_put_page_entry(v6);
      kfree(v3);
      v3 = v5;
    }
    while ( v5 != (_QWORD *)(a1 + 2240) );
  }
  *(_QWORD *)(a1 + 2256) = 0;
  raw_spin_unlock_bh(a1 + 2208);
  raw_spin_lock_bh(a1 + 2408);
  if ( *(_DWORD *)(a1 + 2432) == -115 )
  {
    v7 = *(_QWORD *)(a1 + 2416);
    if ( v7 )
    {
      sk_skb_reason_drop(0, v7, 2);
      *(_QWORD *)(a1 + 2416) = 0;
      *(_BYTE *)(a1 + 2436) = 0;
      *(_QWORD *)(a1 + 2280) = 0;
      *(_QWORD *)(a1 + 2288) = 0;
    }
    *(_DWORD *)(a1 + 2432) = 0;
  }
  v8 = *(_QWORD **)(a1 + 2440);
  if ( v8 != (_QWORD *)(a1 + 2440) )
  {
    do
    {
      v10 = (_QWORD *)*v8;
      v9 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v9 == v8 && (_QWORD *)v10[1] == v8 )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      v11 = v8[2];
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      rmnet_mem_put_page_entry(v11);
      kfree(v8);
      v8 = v10;
    }
    while ( v10 != (_QWORD *)(a1 + 2440) );
  }
  *(_QWORD *)(a1 + 2456) = 0;
  return raw_spin_unlock_bh(a1 + 2408);
}
