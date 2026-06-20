__int64 __fastcall sde_sync_wait(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 (*v5)(void); // x8
  __int64 v6; // x21
  char v7; // w0
  __int64 v9; // x0
  int v10; // w0
  int v11; // w21
  unsigned int status; // w0
  __int64 (__fastcall *v13)(_QWORD); // x8
  unsigned int v14; // w22
  int v15; // w23
  __int64 v16; // x0
  __int64 v18; // x26
  __int64 v19; // x1
  unsigned int v25; // w8
  int v27; // w8

  if ( !a1 )
    return -22;
  if ( (*(_QWORD *)(a1 + 48) & 1) != 0 )
    goto LABEL_8;
  v5 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8) + 32LL);
  if ( v5 )
  {
    v6 = a2;
    if ( *((_DWORD *)v5 - 1) != 1879296680 )
      __break(0x8228u);
    v7 = v5();
    LODWORD(a2) = v6;
    if ( (v7 & 1) != 0 )
    {
      dma_fence_signal(a1);
      a2 = v6;
LABEL_8:
      if ( a2 )
        return _msecs_to_jiffies((unsigned int)a2);
      else
        return 1;
    }
  }
  v9 = _msecs_to_jiffies((unsigned int)a2);
  v10 = dma_fence_wait_timeout(a1, 1, v9);
  v11 = v10;
  if ( v10 == -22 || !v10 || *(_DWORD *)(a1 + 60) )
  {
    status = dma_fence_get_status(a1);
    if ( (*(_QWORD *)(a1 + 48) & 0x10000) == 0 )
    {
      sde_fence_dump(a1);
      goto LABEL_49;
    }
    if ( status == -22 )
    {
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_2329C1, 4294967274LL);
      else
        printk(&unk_216E41, "sde_sync_wait");
      v11 = -9;
    }
    else
    {
      v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 32LL);
      if ( v13 )
      {
        v14 = status;
        if ( *((_DWORD *)v13 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v13(a1) & 1) != 0 )
        {
          if ( (_drm_debug & 4) != 0 )
            printk(&unk_269F00, v14);
          else
            printk(&unk_228653, "sde_sync_wait");
          goto LABEL_49;
        }
      }
      sde_fence_dump(a1);
      if ( (*(_QWORD *)(a1 + 48) & 0x10000) != 0 && (*(_QWORD *)(a1 + 48) & 0x20000) != 0 && *(_DWORD *)(a1 + 68) )
      {
        v15 = 0;
        while ( 1 )
        {
          v16 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL * v15);
          if ( v16 )
            break;
LABEL_27:
          if ( (unsigned int)++v15 >= *(_DWORD *)(a1 + 68) )
            goto LABEL_49;
        }
        _X22 = (unsigned int *)(v16 + 56);
        __asm { PRFM            #0x11, [X22] }
        do
          v25 = __ldxr(_X22);
        while ( __stxr(v25 + 1, _X22) );
        if ( v25 )
        {
          if ( (((v25 + 1) | v25) & 0x80000000) == 0 )
          {
LABEL_31:
            sde_fence_dump(v16);
            __asm { PRFM            #0x11, [X22] }
            do
              v27 = __ldxr(_X22);
            while ( __stlxr(v27 - 1, _X22) );
            if ( v27 == 1 )
            {
              __dmb(9u);
              dma_fence_release(_X22);
            }
            else if ( v27 <= 0 )
            {
              refcount_warn_saturate(_X22, 3);
            }
            goto LABEL_27;
          }
          v18 = v16;
          v19 = 1;
        }
        else
        {
          v18 = v16;
          v19 = 2;
        }
        refcount_warn_saturate(v16 + 56, v19);
        v16 = v18;
        goto LABEL_31;
      }
    }
  }
LABEL_49:
  if ( a3 )
    *a3 = *(_DWORD *)(a1 + 60);
  return v11;
}
