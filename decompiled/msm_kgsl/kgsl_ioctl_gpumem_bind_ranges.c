unsigned __int64 __fastcall kgsl_ioctl_gpumem_bind_ranges(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x4
  unsigned __int64 result; // x0
  _QWORD *v6; // x19
  int v7; // w8
  __int64 v9; // x1
  int v10; // w21
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x21
  unsigned __int64 v15; // x22
  __int64 v16; // x0
  unsigned __int64 v17; // x20
  unsigned int unused_fd_flags; // w21
  _QWORD *v19; // x0
  __int64 v20; // x1
  __int64 v21; // x1
  unsigned int v27; // w8
  int v29; // w8
  unsigned int v31; // w8
  int v33; // w8

  v3 = *(unsigned int *)(a3 + 12);
  if ( !(_DWORD)v3 )
  {
    *(_DWORD *)(a3 + 12) = 32;
    return 0;
  }
  if ( (*(_DWORD *)(a3 + 20) & 3) == 2 )
    return -22;
  result = kgsl_sharedmem_create_bind_op(
             *(_QWORD *)(a1 + 8),
             *(_DWORD *)(a3 + 16),
             *(_QWORD *)a3,
             *(_DWORD *)(a3 + 8),
             v3);
  v6 = (_QWORD *)result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v7 = *(_DWORD *)(a3 + 20);
    if ( (v7 & 1) == 0 )
    {
      _X20 = (unsigned int *)(result + 104);
      __asm { PRFM            #0x11, [X20] }
      do
        v27 = __ldxr(_X20);
      while ( __stxr(v27 + 1, _X20) );
      if ( v27 )
      {
        if ( (((v27 + 1) | v27) & 0x80000000) == 0 )
        {
LABEL_9:
          v6[5] = 0xFFFFFFFE00000LL;
          v6[6] = v6 + 6;
          v6[7] = v6 + 6;
          v9 = system_wq;
          v6[8] = kgsl_sharedmem_bind_worker;
          queue_work_on(32, v9, v6 + 5);
          v10 = wait_for_completion_interruptible(v6 + 9);
          if ( v6 )
          {
            __asm { PRFM            #0x11, [X20] }
            do
              v29 = __ldxr(_X20);
            while ( __stlxr(v29 - 1, _X20) );
            if ( v29 == 1 )
            {
              __dmb(9u);
              kgsl_sharedmem_free_bind_op((unsigned __int64)v6);
            }
            else if ( v29 <= 0 )
            {
              refcount_warn_saturate(v6 + 13, 3);
            }
          }
          return v10;
        }
        v20 = 1;
      }
      else
      {
        v20 = 2;
      }
      refcount_warn_saturate(result + 104, v20);
      goto LABEL_9;
    }
    if ( (v7 & 2) == 0 )
    {
LABEL_13:
      _X20 = (unsigned int *)(v6 + 13);
      __asm { PRFM            #0x11, [X20] }
      do
        v31 = __ldxr(_X20);
      while ( __stxr(v31 + 1, _X20) );
      if ( v31 )
      {
        if ( (((v31 + 1) | v31) & 0x80000000) == 0 )
        {
LABEL_15:
          v6[5] = 0xFFFFFFFE00000LL;
          v6[6] = v6 + 6;
          v6[7] = v6 + 6;
          v12 = system_wq;
          v6[8] = kgsl_sharedmem_bind_worker;
          queue_work_on(32, v12, v6 + 5);
          result = 0;
          if ( v6 && (*(_DWORD *)(a3 + 20) & 2) == 0 )
          {
            __asm { PRFM            #0x11, [X20] }
            do
              v33 = __ldxr(_X20);
            while ( __stlxr(v33 - 1, _X20) );
            if ( v33 == 1 )
            {
              __dmb(9u);
              kgsl_sharedmem_free_bind_op((unsigned __int64)v6);
            }
            else if ( v33 <= 0 )
            {
              refcount_warn_saturate(v6 + 13, 3);
            }
            return 0;
          }
          return result;
        }
        v21 = 1;
      }
      else
      {
        v21 = 2;
      }
      refcount_warn_saturate(v6 + 13, v21);
      goto LABEL_15;
    }
    v13 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
    if ( v13 )
    {
      v14 = v13;
      v15 = v13;
      *(_DWORD *)(v13 + 64) = 0;
      v16 = dma_fence_context_alloc(1);
      v17 = v15;
      dma_fence_init(v15, &kgsl_sharedmem_bind_fence_ops, v14 + 64, v16, 0);
      unused_fd_flags = get_unused_fd_flags(0x80000);
      if ( (unused_fd_flags & 0x80000000) != 0 )
      {
        kfree(v15);
        v17 = (int)unused_fd_flags;
LABEL_24:
        if ( v17 < 0xFFFFFFFFFFFFF001LL )
        {
          v6[3] = kgsl_sharedmem_bind_fence_callback;
          v6[4] = v17;
          *(_DWORD *)(a3 + 24) = *(_DWORD *)(v17 + 68);
          goto LABEL_13;
        }
LABEL_28:
        kgsl_sharedmem_put_bind_op(v6);
        return v17;
      }
      v19 = (_QWORD *)sync_file_create(v15);
      if ( v19 )
      {
        fd_install(unused_fd_flags, *v19);
        *(_DWORD *)(v15 + 68) = unused_fd_flags;
        *(_QWORD *)(v15 + 72) = v6;
        goto LABEL_24;
      }
      put_unused_fd(unused_fd_flags);
      kfree(v15);
    }
    v17 = -12;
    goto LABEL_28;
  }
  return result;
}
