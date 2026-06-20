__int64 __fastcall fastrpc_dev_get_hlos_pid(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x19
  __int64 v9; // x20
  unsigned int v10; // w8
  unsigned int v12; // w22
  unsigned int v18; // w9
  __int64 v19; // x22
  __int64 v22; // x1
  unsigned int v24; // w8

  v8 = raw_spin_lock_irqsave(&g_frpc);
  if ( !a1 || *(_BYTE *)(a1 + 944) == 1 )
  {
    printk(&unk_24BE7, "fastrpc_dev_get_hlos_pid", v4, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    return -3;
  }
  else
  {
    v9 = *(_QWORD *)(a1 + 936);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 664);
      _X0 = (unsigned int *)(v9 + 664);
      if ( v10 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v18 = __ldxr(_X0);
          while ( v18 == v10 && __stxr(v10 + 1, _X0) );
          v12 = v10;
          if ( v18 == v10 )
            break;
          v12 = 0;
          v10 = v18;
        }
        while ( v18 );
      }
      else
      {
        v12 = 0;
      }
      if ( (((v12 + 1) | v12) & 0x80000000) != 0 )
      {
        refcount_warn_saturate(_X0, 0);
        if ( v12 )
          goto LABEL_15;
      }
      else if ( v12 )
      {
LABEL_15:
        v19 = *(_QWORD *)(v9 + 128);
        _X0 = (unsigned int *)(v19 + 51664);
        __asm { PRFM            #0x11, [X0] }
        do
          v24 = __ldxr(_X0);
        while ( __stxr(v24 + 1, _X0) );
        if ( v24 )
        {
          if ( (((v24 + 1) | v24) & 0x80000000) == 0 )
          {
LABEL_17:
            *a2 = *(_DWORD *)(v9 + 240);
            raw_spin_unlock_irqrestore(&g_frpc, v8);
            fastrpc_channel_ctx_put(v19);
            fastrpc_file_put((__int64 *)v9, 0);
            return 0;
          }
          v22 = 1;
        }
        else
        {
          v22 = 2;
        }
        refcount_warn_saturate(_X0, v22);
        goto LABEL_17;
      }
      printk(&unk_23635, "fastrpc_dev_get_hlos_pid", v9, v5, v6, v7);
      raw_spin_unlock_irqrestore(&g_frpc, v8);
      return -2;
    }
    else
    {
      printk(&unk_2657C, "fastrpc_dev_get_hlos_pid", v4, v5, v6, v7);
      raw_spin_unlock_irqrestore(&g_frpc, v8);
      return -9;
    }
  }
}
