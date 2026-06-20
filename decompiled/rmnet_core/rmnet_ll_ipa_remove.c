__int64 __fastcall rmnet_ll_ipa_remove(_QWORD *a1)
{
  __int64 v2; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x9
  unsigned int *v5; // x9
  unsigned int v6; // w12
  __int64 v7; // x9
  __int64 *i; // x1
  __int64 v9; // x8
  _QWORD *v10; // x9

  v2 = *(_QWORD *)(*a1 + 40LL);
  if ( v2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v4 = *(_QWORD *)(v2 + 1320);
    v5 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v4);
    do
      v6 = __ldxr(v5);
    while ( __stxr(v6 - 1, v5) );
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  kfree(*a1);
  *a1 = 0;
  raw_spin_lock_bh(&rmnet_ll_tx_lock);
  for ( i = (__int64 *)tx_pending_list;
        (__int64 *)tx_pending_list != &tx_pending_list && tx_pending_list;
        i = (__int64 *)tx_pending_list )
  {
    --dword_2FE20;
    v9 = *i;
    v10 = (_QWORD *)i[1];
    *i = 0;
    i[1] = 0;
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    sk_skb_reason_drop(0, i, 2);
  }
  return raw_spin_unlock_bh(&rmnet_ll_tx_lock);
}
