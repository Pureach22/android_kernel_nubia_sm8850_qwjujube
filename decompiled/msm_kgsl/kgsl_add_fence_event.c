__int64 __fastcall kgsl_add_fence_event(
        _QWORD *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int64 a4,
        int a5,
        __int64 *a6)
{
  __int64 v6; // x25
  unsigned int v13; // w19
  unsigned int v19; // w8
  __int64 result; // x0
  unsigned int v24; // w8
  unsigned int v25; // w19
  unsigned int v27; // w9
  __int64 v28; // x19
  unsigned int v29; // w8
  __int64 v30; // x0
  __int64 v31; // x0
  _QWORD *v32; // x8
  __int64 v33; // x2
  _QWORD *v34; // x1
  __int64 v35; // x9
  unsigned int unused_fd_flags; // w0
  char v37; // w22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v42; // x8
  __int64 v43; // x0
  unsigned __int64 v44; // x9
  unsigned __int64 v46; // x10
  char v47; // w21
  unsigned int v48; // w22
  _DWORD *v49; // x8
  __int64 v50; // x22
  unsigned int v51; // w9
  __int64 v52; // x8
  unsigned int v53; // w2
  unsigned int v54; // w25
  unsigned int v56; // w10
  int v57; // w0
  int v58; // w23
  int v60; // w8
  __int64 v61; // x0
  int v63; // w8
  int v65; // w8
  unsigned int v66; // w20
  __int64 v67; // x9
  __int64 v68; // x8
  _QWORD *v69; // x10
  int v73; // w8
  int v75; // w9
  unsigned int v76; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v77; // [xsp+8h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76 = -1;
  if ( a5 != 4 )
    goto LABEL_18;
  v6 = *a6;
  raw_read_lock(*a6 + 11208);
  _X0 = idr_find(v6 + 11184, a2);
  if ( !_X0 || (*(_QWORD *)(_X0 + 32) & 2) != 0 )
  {
    raw_read_unlock(v6 + 11208);
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  v13 = *(_DWORD *)_X0;
  if ( *(_DWORD *)_X0 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v19 = __ldxr((unsigned int *)_X0);
      while ( v19 == v13 && __stxr(v13 + 1, (unsigned int *)_X0) );
      if ( v19 == v13 )
        break;
      v13 = v19;
    }
    while ( v19 );
  }
  _X20 = _X0;
  if ( (((v13 + 1) | v13) & 0x80000000) != 0 )
    refcount_warn_saturate(_X0, 0);
  raw_read_unlock(v6 + 11208);
  if ( !v13 )
    goto LABEL_18;
  _X0 = _X20;
  if ( *(__int64 **)(_X20 + 16) != a6 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v60 = __ldxr((unsigned int *)_X20);
    while ( __stlxr(v60 - 1, (unsigned int *)_X20) );
    if ( v60 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy(_X20);
    }
    else if ( v60 <= 0 )
    {
      refcount_warn_saturate(_X20, 3);
    }
    goto LABEL_18;
  }
  if ( (*(_QWORD *)(_X20 + 32) & 4) != 0 )
  {
    v28 = 0;
    v29 = -22;
LABEL_108:
    v47 = 1;
    goto LABEL_128;
  }
  _X22 = *(_QWORD *)(_X20 + 56);
  v24 = *(_DWORD *)_X22;
  if ( *(_DWORD *)_X22 )
  {
    do
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v27 = __ldxr((unsigned int *)_X22);
      while ( v27 == v24 && __stxr(v24 + 1, (unsigned int *)_X22) );
      v25 = v24;
      if ( v27 == v24 )
        break;
      v25 = 0;
      v24 = v27;
    }
    while ( v27 );
  }
  else
  {
    v25 = 0;
  }
  if ( (((v25 + 1) | v25) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X22, 0);
    _X0 = _X20;
    if ( !v25 )
      goto LABEL_107;
  }
  else if ( !v25 )
  {
    goto LABEL_107;
  }
  v28 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 136);
  _X0 = _X20;
  if ( !v28 )
  {
    if ( _X22 )
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v63 = __ldxr((unsigned int *)_X22);
      while ( __stlxr(v63 - 1, (unsigned int *)_X22) );
      if ( v63 == 1 )
      {
        __dmb(9u);
        v61 = _X22;
LABEL_105:
        kfree(v61);
        goto LABEL_106;
      }
      if ( v63 <= 0 )
      {
        refcount_warn_saturate(_X22, 3);
LABEL_106:
        _X0 = _X20;
      }
    }
LABEL_107:
    v28 = 0;
    v29 = -12;
    goto LABEL_108;
  }
  *(_QWORD *)(v28 + 72) = _X22;
  *(_DWORD *)(v28 + 96) = *(_DWORD *)(_X20 + 4);
  *(_DWORD *)(v28 + 100) = a3;
  dma_fence_init(v28, &kgsl_sync_fence_ops, _X22 + 64, *(_QWORD *)(_X22 + 40), a3);
  v30 = sync_file_create(v28);
  *(_QWORD *)(v28 + 64) = v30;
  if ( !v30 )
  {
    if ( _X22 )
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v65 = __ldxr((unsigned int *)_X22);
      while ( __stlxr(v65 - 1, (unsigned int *)_X22) );
      if ( v65 == 1 )
      {
        __dmb(9u);
        kfree(_X22);
      }
      else if ( v65 <= 0 )
      {
        refcount_warn_saturate(_X22, 3);
      }
    }
    dev_err(**(_QWORD **)(_X20 + 40), "Create sync_file failed\n");
    v61 = v28;
    goto LABEL_105;
  }
  *(_QWORD *)(v28 + 112) = v28 + 112;
  *(_QWORD *)(v28 + 120) = v28 + 112;
  *(_DWORD *)(v28 + 128) = 1;
  v31 = raw_spin_lock_irqsave(_X22 + 64);
  v32 = (_QWORD *)(v28 + 80);
  v33 = _X22 + 48;
  v34 = *(_QWORD **)(_X22 + 56);
  v35 = v31;
  if ( v28 + 80 == _X22 + 48 || v34 == v32 || *v34 != v33 )
  {
    _list_add_valid_or_report(v28 + 80, v34);
  }
  else
  {
    *(_QWORD *)(_X22 + 56) = v32;
    *(_QWORD *)(v28 + 80) = v33;
    *(_QWORD *)(v28 + 88) = v34;
    *v34 = v32;
  }
  raw_spin_unlock_irqrestore(_X22 + 64, v35);
  unused_fd_flags = get_unused_fd_flags(0);
  v76 = unused_fd_flags;
  if ( (unused_fd_flags & 0x80000000) != 0 )
  {
    v48 = unused_fd_flags;
    if ( !(unsigned int)__ratelimit(&kgsl_add_fence_event__rs, "kgsl_add_fence_event") )
    {
      v47 = 0;
      _X0 = _X20;
      v29 = v48;
      goto LABEL_128;
    }
    dev_crit(*a1, "Unable to get a file descriptor: %d\n", v48);
    v29 = v48;
    v47 = 0;
LABEL_57:
    _X0 = _X20;
    goto LABEL_128;
  }
  kgsl_readtimestamp((__int64)a1);
  if ( a3 && ((a3 ^ 0x80000000) >= 0x80000000 || 0x80000000 - (a3 ^ 0x80000000) > 0x80000000) )
  {
    v50 = _kmalloc_cache_noprof(raw_read_lock, 3264, 16);
    _X0 = _X20;
    if ( !v50 )
    {
      v47 = 0;
      v29 = -12;
      goto LABEL_128;
    }
    v51 = *(_DWORD *)_X20;
    v52 = (__int64)a1;
    if ( *(_DWORD *)_X20 )
    {
      v53 = a3;
      do
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v56 = __ldxr((unsigned int *)_X20);
        while ( v56 == v51 && __stxr(v51 + 1, (unsigned int *)_X20) );
        v54 = v51;
        if ( v56 == v51 )
          break;
        v54 = 0;
        v51 = v56;
      }
      while ( v56 );
    }
    else
    {
      v54 = 0;
      v53 = a3;
    }
    if ( (((v54 + 1) | v54) & 0x80000000) != 0 )
    {
      refcount_warn_saturate(_X20, 0);
      v53 = a3;
      v52 = (__int64)a1;
      _X0 = _X20;
      if ( v54 )
        goto LABEL_75;
    }
    else if ( v54 )
    {
LABEL_75:
      *(_QWORD *)v50 = _X0;
      *(_DWORD *)(v50 + 8) = v53;
      v57 = kgsl_add_event(v52, (__int64 *)(_X0 + 64), v53, (__int64)kgsl_sync_fence_event_cb, v50);
      if ( !v57 )
      {
        v37 = 0;
        goto LABEL_44;
      }
      __asm { PRFM            #0x11, [X20] }
      do
        v75 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(v75 - 1, (unsigned int *)_X20) );
      v58 = v57;
      if ( v75 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X20);
      }
      else if ( v75 <= 0 )
      {
        refcount_warn_saturate(_X20, 3);
      }
LABEL_86:
      kfree(v50);
      v47 = 0;
      _X0 = _X20;
      v29 = v58;
      goto LABEL_128;
    }
    v58 = -2;
    goto LABEL_86;
  }
  kgsl_sync_timeline_signal(*(_QWORD *)(_X20 + 56));
  v37 = 1;
LABEL_44:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v39 = a4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v39 = a4 & ((__int64)(a4 << 8) >> 8);
  if ( v39 <= 0x7FFFFFFFFCLL )
  {
    v40 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v42 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v42 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v42);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v40);
    v43 = _arch_copy_to_user(a4 & 0xFF7FFFFFFFFFFFFFLL, &v76, 4);
    v44 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v46 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v46 - 4096);
    _WriteStatusReg(TTBR1_EL1, v46);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v44);
    if ( !v43 )
    {
      if ( (v37 & 1) == 0 )
      {
        v49 = *(_DWORD **)(a1[1094] + 296LL);
        if ( *(v49 - 1) != 948496705 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, __int64))v49)(a1, v28);
      }
      fd_install(v76, **(_QWORD **)(v28 + 64));
      v47 = 0;
      v29 = 0;
      goto LABEL_57;
    }
  }
  _X0 = _X20;
  v47 = 0;
  v29 = -14;
LABEL_128:
  __asm { PRFM            #0x11, [X0] }
  do
    v67 = __ldxr((unsigned int *)_X0);
  while ( __stlxr(v67 - 1, (unsigned int *)_X0) );
  v66 = v29;
  if ( (_DWORD)v67 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy(_X0);
  }
  else
  {
    if ( (int)v67 > 0 )
      goto LABEL_113;
    refcount_warn_saturate(_X0, 3);
  }
  v29 = v66;
LABEL_113:
  result = v29;
  if ( v29 )
  {
    if ( (v76 & 0x80000000) == 0 )
    {
      put_unused_fd(v76);
      result = v66;
    }
    if ( v28 )
    {
      if ( (v47 & 1) != 0 )
        goto LABEL_125;
      raw_spin_lock(*(_QWORD *)(v28 + 72) + 64LL);
      v67 = v28 + 80;
      v68 = *(_QWORD *)(v28 + 80);
      if ( v68 == v28 + 80 )
        goto LABEL_134;
      if ( (v47 & 1) != 0 )
        goto LABEL_125;
      v69 = *(_QWORD **)(v28 + 88);
      if ( *v69 != v67 || *(_QWORD *)(v68 + 8) != v67 )
        goto LABEL_126;
      *(_QWORD *)(v68 + 8) = v69;
      *v69 = v68;
      while ( 1 )
      {
        _X0 = (unsigned int *)(v28 + 56);
        *(_QWORD *)(v28 + 80) = v28 + 80;
        *(_QWORD *)(v28 + 88) = v67;
        v67 = 1;
        __asm { PRFM            #0x11, [X0] }
        do
          v73 = __ldxr(_X0);
        while ( __stlxr(v73 - 1, _X0) );
        if ( v73 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
          if ( (v47 & 1) == 0 )
            goto LABEL_135;
        }
        else if ( v73 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
          if ( (v47 & 1) == 0 )
          {
LABEL_135:
            raw_spin_unlock(*(_QWORD *)(v28 + 72) + 64LL);
            fput(**(_QWORD **)(v28 + 64));
            result = v66;
            break;
          }
        }
        else
        {
LABEL_134:
          if ( (v47 & 1) == 0 )
            goto LABEL_135;
        }
LABEL_125:
        __break(1u);
LABEL_126:
        _list_del_entry_valid_or_report(v67);
      }
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
