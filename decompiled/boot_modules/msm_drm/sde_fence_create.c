__int64 __fastcall sde_fence_create(__int64 a1, _QWORD *a2, int a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x25
  int unused_fd_flags; // w24
  __int64 v14; // x0
  _QWORD *v15; // x27
  int v16; // w8
  unsigned __int64 v17; // x0
  int v18; // w28
  __int64 v19; // x4
  char v20; // w8
  _QWORD *v21; // x0
  __int64 v22; // x2
  _QWORD *v23; // x1
  __int64 result; // x0
  __int64 v27; // x1
  int v28; // w7
  unsigned int v34; // w8
  int v36; // w8
  int v38; // w8
  unsigned int v39; // [xsp+14h] [xbp-2Ch] BYREF
  __int64 v40; // [xsp+18h] [xbp-28h]
  unsigned int *v41; // [xsp+20h] [xbp-20h]
  __int64 v42; // [xsp+28h] [xbp-18h]
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    printk(&unk_216E84, "sde_fence_create");
    result = 4294967274LL;
    goto LABEL_35;
  }
  v8 = raw_spin_lock_irqsave(a1 + 16);
  v9 = (unsigned int)(*(_DWORD *)a1 + a3);
  raw_spin_unlock_irqrestore(a1 + 16, v8);
  v10 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, 144);
  v11 = v10;
  if ( v10 )
  {
    *(_QWORD *)(v10 + 64) = a1;
    snprintf((char *)(v10 + 72), 0x18u, "sde_fence:%s:%u", (const char *)(a1 + 64), v9);
    dma_fence_init(v11, &sde_fence_ops, a1 + 16, *(_QWORD *)(a1 + 24), v9);
    _X0 = (unsigned int *)(a1 + 12);
    __asm { PRFM            #0x11, [X0] }
    do
      v34 = __ldxr(_X0);
    while ( __stxr(v34 + 1, _X0) );
    if ( v34 )
    {
      if ( (((v34 + 1) | v34) & 0x80000000) == 0 )
        goto LABEL_6;
      v27 = 1;
    }
    else
    {
      v27 = 2;
    }
    refcount_warn_saturate(_X0, v27);
LABEL_6:
    *(_DWORD *)(a1 + 36) = v9;
    unused_fd_flags = get_unused_fd_flags(0);
    if ( unused_fd_flags < 0 )
    {
      printk(&unk_24D836, "_sde_fence_create_fd");
      _X0 = (unsigned int *)(v11 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v36 = __ldxr(_X0);
      while ( __stlxr(v36 - 1, _X0) );
      if ( v36 == 1 )
      {
        __dmb(9u);
        dma_fence_release(_X0);
      }
      else if ( v36 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    else
    {
      v14 = sync_file_create(v11);
      if ( v14 )
      {
        v15 = (_QWORD *)v14;
        if ( a4 )
        {
          v16 = *(_DWORD *)(a4 + 64);
          v17 = *(_QWORD *)(a4 + 168);
          v42 = 0;
          v43 = 0;
          v40 = 0;
          v41 = nullptr;
          v18 = v16 - 1;
          v39 = 0;
          if ( v17 && v17 < 0xFFFFFFFFFFFFF001LL )
          {
            v41 = &v39;
            v42 = v11;
            LODWORD(v43) = 4;
            if ( (unsigned int)synx_create() )
            {
              printk(&unk_232A15, "sde_fence_create_hw_fence");
            }
            else
            {
              v19 = v39;
              v20 = _drm_debug;
              *(_QWORD *)(v11 + 120) = a4;
              *(_QWORD *)(v11 + 128) = v19;
              if ( (v20 & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "create hfence index:%llu ctl:%d ctx:%llu seqno:%llu name:%s\n",
                  v19,
                  v18,
                  *(_QWORD *)(v11 + 32),
                  *(_QWORD *)(v11 + 40),
                  (const char *)(v11 + 72));
            }
          }
          else
          {
            printk(&unk_247027, "sde_fence_create_hw_fence");
          }
        }
        fd_install((unsigned int)unused_fd_flags, *v15);
        *(_DWORD *)(v11 + 112) = unused_fd_flags;
        raw_spin_lock(a1 + 20);
        v21 = (_QWORD *)(v11 + 96);
        v22 = a1 + 48;
        v23 = *(_QWORD **)(a1 + 56);
        if ( v11 + 96 == a1 + 48 || v23 == v21 || *v23 != v22 )
        {
          _list_add_valid_or_report(v21, v23);
        }
        else
        {
          *(_QWORD *)(a1 + 56) = v21;
          *(_QWORD *)(v11 + 96) = v22;
          *(_QWORD *)(v11 + 104) = v23;
          *v23 = v21;
        }
        raw_spin_unlock(a1 + 20);
      }
      else
      {
        put_unused_fd((unsigned int)unused_fd_flags);
        printk(&unk_271221, "_sde_fence_create_fd");
        _X0 = (unsigned int *)(v11 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v38 = __ldxr(_X0);
        while ( __stlxr(v38 - 1, _X0) );
        if ( v38 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
          unused_fd_flags = -22;
        }
        else
        {
          if ( v38 <= 0 )
            refcount_warn_saturate(_X0, 3);
          unused_fd_flags = -22;
        }
      }
    }
    goto LABEL_29;
  }
  unused_fd_flags = -12;
LABEL_29:
  *a2 = unused_fd_flags;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "fd:%d trigger:%d commit:%d offset:%d\n", unused_fd_flags, v9, *(_DWORD *)a1, a3);
  if ( a4 )
    v28 = *(_DWORD *)(a4 + 64);
  else
    v28 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_fence_create", 1278, -1, *(_DWORD *)(a1 + 8), v9, unused_fd_flags, v28, 239);
  result = unused_fd_flags & (unsigned int)(unused_fd_flags >> 31);
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
