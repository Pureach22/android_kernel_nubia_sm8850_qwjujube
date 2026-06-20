__int64 __fastcall qrtr_local_enqueue(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x24
  __int64 v10; // x0
  __int64 v11; // x20
  int v13; // w8
  unsigned __int64 StatusReg; // x9
  int v15; // w4
  __int64 v16; // x0
  __int64 v17; // x0
  int v18; // w0
  int v21; // w21
  unsigned int v22; // w20
  int v24; // w9
  int v25; // w20
  int v27; // w8
  int v34; // w8

  v5 = *(_QWORD *)(a2 + 24);
  v10 = qrtr_port_lookup(*(_DWORD *)(a5 + 8));
  if ( !v10 )
  {
LABEL_30:
    v22 = -19;
    goto LABEL_31;
  }
  v11 = v10;
  if ( v10 == *(_QWORD *)(a2 + 24) )
  {
    _X0 = (unsigned int *)(v10 + 128);
    __asm { PRFM            #0x11, [X0] }
    do
      v27 = __ldxr(_X0);
    while ( __stlxr(v27 - 1, _X0) );
    if ( v27 == 1 )
    {
      __dmb(9u);
      sk_free(v11);
    }
    else if ( v27 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    goto LABEL_30;
  }
  if ( v5 && *(_DWORD *)(v5 + 284) == 102 )
  {
    sk_error_report(v5);
    _X0 = (unsigned int *)(v11 + 128);
    __asm { PRFM            #0x11, [X0] }
    do
      v34 = __ldxr(_X0);
    while ( __stlxr(v34 - 1, _X0) );
    if ( v34 == 1 )
    {
      __dmb(9u);
      sk_free(v11);
    }
    else if ( v34 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    v22 = 0;
    goto LABEL_31;
  }
  v13 = *(_DWORD *)(a4 + 4);
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(a2 + 40) = v13;
  v15 = *(_DWORD *)(a4 + 8);
  v16 = qrtr_local_ilc;
  *(_DWORD *)(a2 + 44) = v15;
  ipc_log_string(
    v16,
    "LOCAL ENQUEUE: cmd:0x%x src[0x%x:0x%x] dst[0x%x:0x%x] [%s] pid:%d\n",
    a3,
    *(_DWORD *)(a4 + 4),
    v15,
    *(_DWORD *)(a5 + 4),
    *(_DWORD *)(a5 + 8),
    (const char *)(StatusReg + 2320),
    *(_DWORD *)(StatusReg + 1800));
  if ( *(_DWORD *)(v11 + 848) == -2 )
  {
    while ( 1 )
    {
      v18 = sock_queue_rcv_skb_reason(v11, a2, 0);
      if ( v18 != -12 && v18 != -105 )
        break;
      v17 = raw_spin_lock_irqsave(v11 + 908);
      *(_DWORD *)(v11 + 872) = 0;
      *(_BYTE *)(v11 + 904) = 1;
      raw_spin_unlock_irqrestore(v11 + 908, v17);
      wait_for_completion(v11 + 872);
    }
  }
  else
  {
    v18 = sock_queue_rcv_skb_reason(v11, a2, 0);
  }
  _X8 = (unsigned int *)(v11 + 128);
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr(_X8);
  while ( __stlxr(v24 - 1, _X8) );
  if ( v24 == 1 )
  {
    __dmb(9u);
    v21 = v18;
    sk_free(v11);
    if ( v21 )
    {
LABEL_23:
      v22 = -28;
LABEL_31:
      sk_skb_reason_drop(0, a2, 2);
      return v22;
    }
  }
  else if ( v24 <= 0 )
  {
    v25 = v18;
    refcount_warn_saturate(_X8, 3);
    if ( v25 )
      goto LABEL_23;
  }
  else if ( v18 )
  {
    goto LABEL_23;
  }
  return 0;
}
