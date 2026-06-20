__int64 __fastcall fastrpc_dev_unmap_dma(__int64 a1, __int64 *a2)
{
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x22
  __int64 v9; // x19
  unsigned int v10; // w8
  unsigned int v12; // w20
  unsigned int v18; // w9
  __int64 v19; // x20
  int *v20; // x23
  __int64 v22; // x0
  int v23; // w25
  int v24; // w22
  __int64 v25; // x22
  __int64 i; // x21
  unsigned int v27; // w8
  __int64 v28; // x10
  int v29; // w0
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v33; // x21
  int v34; // w8
  __int64 result; // x0
  __int64 v36; // x1
  unsigned int v38; // w8
  unsigned int v41; // w8
  int v43; // w8
  _QWORD v44[3]; // [xsp+0h] [xbp-B0h] BYREF
  _QWORD v45[15]; // [xsp+18h] [xbp-98h] BYREF
  _QWORD v46[4]; // [xsp+90h] [xbp-20h] BYREF

  v46[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = raw_spin_lock_irqsave(&g_frpc);
  if ( !a1 || *(_BYTE *)(a1 + 944) == 1 )
  {
    printk(&unk_24BE7, "fastrpc_dev_unmap_dma", v4, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    result = -3;
    goto LABEL_40;
  }
  v9 = *(_QWORD *)(a1 + 936);
  if ( !v9 )
  {
    printk(&unk_2657C, "fastrpc_dev_unmap_dma", v4, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    result = -9;
    goto LABEL_40;
  }
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
LABEL_45:
    printk(&unk_24DA5, "fastrpc_dev_unmap_dma", v9, v5, v6, v7);
    raw_spin_unlock_irqrestore(&g_frpc, v8);
    result = -2;
    goto LABEL_40;
  }
  if ( !v12 )
    goto LABEL_45;
LABEL_15:
  v19 = *(_QWORD *)(v9 + 128);
  v20 = (int *)(v19 + 64136);
  _X0 = (unsigned int *)(v19 + 51664);
  __asm { PRFM            #0x11, [X0] }
  do
    v38 = __ldxr(_X0);
  while ( __stxr(v38 + 1, _X0) );
  if ( v38 )
  {
    if ( (((v38 + 1) | v38) & 0x80000000) == 0 )
      goto LABEL_17;
    v36 = 1;
  }
  else
  {
    v36 = 2;
  }
  refcount_warn_saturate(_X0, v36);
LABEL_17:
  *(_BYTE *)(v9 + 307) = 1;
  raw_spin_unlock_irqrestore(&g_frpc, v8);
  v22 = raw_spin_lock_irqsave(v19 + 51600);
  v23 = *v20;
  if ( *v20 )
  {
    raw_spin_unlock_irqrestore(v19 + 51600, v22);
    v24 = -32;
  }
  else
  {
    ++*(_DWORD *)(v19 + 64180);
    raw_spin_unlock_irqrestore(v19 + 51600, v22);
    mutex_lock(v9 + 328);
    v25 = *a2;
    if ( *a2 )
    {
      raw_spin_lock(v9 + 320);
      for ( i = *(_QWORD *)(v9 + 16); ; i = *(_QWORD *)i )
      {
        if ( i == v9 + 16 )
        {
          raw_spin_unlock(v9 + 320);
          goto LABEL_31;
        }
        if ( *(_QWORD *)(i + 32) == v25 && *(_DWORD *)(i + 24) == -1 )
          break;
      }
      raw_spin_unlock(v9 + 320);
      _X9 = (unsigned int *)(i + 120);
      __asm { PRFM            #0x11, [X9] }
      while ( 1 )
      {
        v41 = __ldxr(_X9);
        if ( v41 != 2 )
          break;
        if ( !__stlxr(3u, _X9) )
        {
          __dmb(0xBu);
          break;
        }
      }
      if ( v41 == 2 )
      {
        mutex_unlock(v9 + 328);
        v27 = *(_DWORD *)(v9 + 244);
        v28 = *(_QWORD *)(i + 72);
        v44[1] = *(_QWORD *)(i + 96);
        v44[0] = v27;
        v46[0] = v44;
        v46[1] = 24;
        v46[2] = 0;
        v44[2] = v28;
        v45[0] = 0x501000000000001LL;
        v45[1] = v46;
        memset(&v45[2], 0, 104);
        v29 = fastrpc_internal_invoke(v9, 1, v45);
        if ( v29 )
        {
          v24 = v29;
          printk(&unk_258E4, *(_QWORD *)(i + 64), *(_QWORD *)(i + 96), *(_QWORD *)(i + 72), v30, v31);
          *(_DWORD *)(i + 120) = 2;
        }
        else
        {
          *(_DWORD *)(i + 120) = 0;
          mutex_lock(v9 + 328);
          if ( i )
          {
            _X0 = (unsigned int *)(i + 112);
            __asm { PRFM            #0x11, [X0] }
            do
              v43 = __ldxr(_X0);
            while ( __stlxr(v43 - 1, _X0) );
            if ( v43 == 1 )
            {
              __dmb(9u);
              _fastrpc_free_map(i);
            }
            else if ( v43 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
          mutex_unlock(v9 + 328);
          v24 = 0;
        }
        goto LABEL_33;
      }
      v24 = -114;
    }
    else
    {
LABEL_31:
      v24 = -2;
    }
    mutex_unlock(v9 + 328);
  }
LABEL_33:
  v33 = raw_spin_lock_irqsave(v19 + 51600);
  if ( *(int *)(v9 + 628) >= 3 && *(_BYTE *)(v9 + 307) == 1 )
    complete(v9 + 472);
  *(_BYTE *)(v9 + 307) = 0;
  if ( !v23 )
  {
    v34 = *(_DWORD *)(v19 + 64180) - 1;
    *(_DWORD *)(v19 + 64180) = v34;
    if ( !v34 )
      _wake_up(v19 + 64216, 1, 1, 0);
  }
  raw_spin_unlock_irqrestore(v19 + 51600, v33);
  fastrpc_channel_ctx_put(v19);
  fastrpc_file_put((__int64 *)v9, 0);
  result = v24;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
