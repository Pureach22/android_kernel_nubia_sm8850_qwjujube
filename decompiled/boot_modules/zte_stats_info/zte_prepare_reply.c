__int64 __fastcall zte_prepare_reply(__int64 a1, __int64 *a2, __int16 a3)
{
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned __int64 StatusReg; // x8
  unsigned int *v9; // x9
  unsigned int v10; // w21
  __int64 v11; // x9

  v5 = _alloc_skb((((a3 + 7) & 0xFFC) + 19) & 0xFFC, 3264, 0, 0xFFFFFFFFLL);
  if ( !v5 )
    return 4294967284LL;
  v6 = v5;
  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v9 = (unsigned int *)((char *)&zte_taskstats_seqnum + _ReadStatusReg(TPIDR_EL1));
    do
      v10 = __ldxr(v9);
    while ( __stxr(v10 + 1, v9) );
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
  }
  if ( genlmsg_put() )
  {
    *a2 = v6;
    return 0;
  }
  else
  {
    sk_skb_reason_drop(0, v6, 2);
    return 4294967274LL;
  }
}
