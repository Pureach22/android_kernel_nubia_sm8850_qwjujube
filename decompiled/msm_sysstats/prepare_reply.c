__int64 __fastcall prepare_reply(unsigned int *a1, unsigned int a2, __int64 *a3, __int16 a4)
{
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned __int64 StatusReg; // x8
  unsigned int *v13; // x9
  unsigned int v14; // w22
  unsigned int v15; // w22
  __int64 v16; // x9

  v7 = _alloc_skb((((a4 + 7) & 0x3FC) + 19) & 0x3FC, 3264, 0, 0xFFFFFFFFLL);
  if ( !v7 )
    return 4294967284LL;
  v8 = v7;
  if ( a1 )
  {
    v10 = *a1;
    v9 = a1[1];
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v13 = (unsigned int *)((char *)&sysstats_seqnum + _ReadStatusReg(TPIDR_EL1));
    do
    {
      v14 = __ldxr(v13);
      v15 = v14 + 1;
    }
    while ( __stxr(v15, v13) );
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
    v10 = v15 - 1;
    v7 = v8;
    v9 = 0;
  }
  if ( genlmsg_put(v7, v9, v10, &family, 0, a2) )
  {
    *a3 = v8;
    return 0;
  }
  else
  {
    sk_skb_reason_drop(0, v8, 2);
    return 4294967274LL;
  }
}
