__int64 __fastcall fastrpc_driver_unregister(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x21
  __int64 v23; // x0
  __int64 **v24; // x8
  __int64 v25; // x9
  __int64 *v26; // x10
  __int64 v27; // x1
  unsigned int v33; // w8

  v2 = raw_spin_lock_irqsave(&g_frpc);
  v3 = a1[24];
  v4 = v2;
  if ( !v3 )
  {
    raw_spin_unlock_irqrestore(&g_frpc, v2);
    return printk(&unk_2658B, v5, v6, v7, v8, v9);
  }
  if ( *(_BYTE *)(v3 + 944) != 1 )
  {
    v15 = *(_QWORD *)(v3 + 936);
    if ( !v15 )
    {
      raw_spin_unlock_irqrestore(&g_frpc, v2);
      return printk(&unk_25D57, v16, v17, v18, v19, v20);
    }
    v21 = *(_QWORD *)(v15 + 128);
    _X0 = (unsigned int *)(v21 + 51664);
    __asm { PRFM            #0x11, [X0] }
    do
      v33 = __ldxr(_X0);
    while ( __stxr(v33 + 1, _X0) );
    if ( v33 )
    {
      if ( (((v33 + 1) | v33) & 0x80000000) == 0 )
        goto LABEL_9;
      v27 = 1;
    }
    else
    {
      v27 = 2;
    }
    refcount_warn_saturate(_X0, v27);
LABEL_9:
    v23 = raw_spin_lock_irqsave(v21 + 51600);
    v24 = (__int64 **)a1[1];
    v25 = v23;
    if ( *v24 == a1 && (v26 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
    {
      v26[1] = (__int64)v24;
      *v24 = v26;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
    }
    *a1 = (__int64)a1;
    a1[1] = (__int64)a1;
    raw_spin_unlock_irqrestore(v21 + 51600, v25);
    raw_spin_unlock_irqrestore(&g_frpc, v4);
    fastrpc_channel_ctx_put(v21);
    return printk(&unk_25D25, *((unsigned int *)a1 + 50), v11, v12, v13, v14);
  }
  raw_spin_unlock_irqrestore(&g_frpc, v2);
  kfree(v3);
  return printk(&unk_25D25, *((unsigned int *)a1 + 50), v11, v12, v13, v14);
}
