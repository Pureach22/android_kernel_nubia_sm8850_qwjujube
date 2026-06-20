__int64 __fastcall qcom_mhi_qrtr_send(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned int v6; // w21
  __int64 v7; // x0
  __int64 v9; // x1
  unsigned int v15; // w8
  int v17; // w9

  v4 = *(_QWORD *)(a2 + 24);
  if ( !v4 )
    goto LABEL_4;
LABEL_2:
  _X0 = (unsigned int *)(v4 + 128);
  __asm { PRFM            #0x11, [X0] }
  do
    v15 = __ldxr(_X0);
  while ( __stxr(v15 + 1, _X0) );
  if ( v15 )
  {
    if ( (((v15 + 1) | v15) & 0x80000000) == 0 )
      goto LABEL_4;
    v9 = 1;
  }
  else
  {
    v9 = 2;
  }
  refcount_warn_saturate(_X0, v9);
  while ( 1 )
  {
LABEL_4:
    v6 = wait_for_completion_interruptible(a1 + 40);
    if ( !v6 )
    {
      if ( *(_DWORD *)(a2 + 116) && !_pskb_pull_tail(a2) )
      {
        v6 = -12;
      }
      else
      {
        v6 = mhi_queue_skb(*(_QWORD *)(a1 + 24), 1, a2, *(unsigned int *)(a2 + 112), 2);
        if ( v6 == -11 || !v6 )
          goto LABEL_24;
      }
    }
    v7 = *(_QWORD *)(a2 + 24);
    if ( v7 )
    {
      _X8 = (unsigned int *)(v7 + 128);
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stlxr(v17 - 1, _X8) );
      if ( v17 == 1 )
      {
        __dmb(9u);
        sk_free(v7);
      }
      else if ( v17 <= 0 )
      {
        refcount_warn_saturate(v7 + 128, 3);
      }
    }
    sk_skb_reason_drop(0, a2, 2);
LABEL_24:
    if ( v6 != -11 )
      return v6;
    *(_DWORD *)(a1 + 72) = 0;
    wait_for_completion(a1 + 72);
    v4 = *(_QWORD *)(a2 + 24);
    if ( v4 )
      goto LABEL_2;
  }
}
