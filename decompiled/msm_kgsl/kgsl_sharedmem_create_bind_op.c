__int64 __fastcall kgsl_sharedmem_create_bind_op(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, __int64 a5)
{
  unsigned int *id; // x0
  __int64 v11; // x19
  __int64 v12; // x0
  int v13; // w26
  __int64 v14; // x9
  __int64 v15; // x26
  __int64 v16; // x27
  int v17; // w28
  int v18; // w8
  __int64 v19; // x11
  __int64 v20; // x9
  unsigned __int64 v21; // x12
  __int64 v22; // x9
  __int64 v23; // x25
  unsigned __int64 v24; // x8
  size_t v25; // x26
  unsigned __int64 v26; // x1
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x10
  unsigned int *v34; // x0
  __int64 v35; // x9
  __int64 v36; // x8
  unsigned __int64 v38; // x10
  __int64 v39; // x11
  unsigned __int64 v40; // x10
  unsigned int v42; // w10
  __int64 v43; // x9
  unsigned __int64 v44; // x25
  __int64 v45; // x26
  __int64 (__fastcall *v46)(_QWORD, _QWORD, _QWORD); // x0
  int v52; // w8
  unsigned int v56; // w9
  unsigned int v59; // w10
  int v61; // w8
  int v63; // w8
  unsigned int v66; // w10
  unsigned __int64 v67; // [xsp+8h] [xbp-48h]
  __int64 v68; // [xsp+10h] [xbp-40h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-38h]
  size_t n; // [xsp+20h] [xbp-30h]
  unsigned __int64 v71; // [xsp+28h] [xbp-28h] BYREF
  unsigned __int64 v72; // [xsp+30h] [xbp-20h]
  __int64 v73; // [xsp+38h] [xbp-18h]
  __int64 v74; // [xsp+40h] [xbp-10h]
  __int64 v75; // [xsp+48h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a4 )
    goto LABEL_66;
  id = kgsl_sharedmem_find_id(a1, a2);
  if ( !id )
  {
    v11 = -2;
    goto LABEL_67;
  }
  _X20 = (unsigned __int64)id;
  if ( (id[21] & 4) == 0 )
  {
    if ( (unsigned __int64)id <= 0xFFFFFFFFFFFFF000LL )
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v52 = __ldxr(id);
      while ( __stlxr(v52 - 1, id) );
      if ( v52 == 1 )
      {
        __dmb(9u);
        kgsl_mem_entry_destroy(id);
        v11 = -22;
        goto LABEL_67;
      }
      if ( v52 <= 0 )
      {
        refcount_warn_saturate(id, 3);
        v11 = -22;
        goto LABEL_67;
      }
    }
LABEL_66:
    v11 = -22;
    goto LABEL_67;
  }
  v11 = _kmalloc_cache_noprof(_check_object_size, 3520, 112);
  if ( !v11 )
    goto LABEL_57;
  while ( 2 )
  {
    v12 = _kvmalloc_node_noprof(32LL * a4, 0, 77248, 0xFFFFFFFFLL);
    *(_QWORD *)(v11 + 8) = v12;
    if ( !v12 )
    {
      kfree(v11);
      if ( _X20 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_77;
      __asm { PRFM            #0x11, [X20] }
      do
        v63 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(v63 - 1, (unsigned int *)_X20) );
      if ( v63 != 1 )
      {
        if ( v63 <= 0 )
          goto LABEL_81;
        goto LABEL_77;
      }
      goto LABEL_62;
    }
    *(_DWORD *)(v11 + 16) = a4;
    *(_QWORD *)v11 = _X20;
    _X8 = (unsigned int *)(a1 + 496);
    __asm { PRFM            #0x11, [X8] }
    do
      v56 = __ldxr(_X8);
    while ( __stxr(v56 + 1, _X8) );
    v13 = kgsl_reclaim_to_pinned_state(a1);
    if ( v13 )
    {
LABEL_71:
      _X8 = (unsigned int *)(a1 + 496);
      __asm { PRFM            #0x11, [X8] }
      do
        v59 = __ldxr(_X8);
      while ( __stxr(v59 - 1, _X8) );
      kgsl_sharedmem_free_bind_op(v11);
      v11 = v13;
      goto LABEL_67;
    }
    if ( (unsigned int)a5 >= 0x20 )
      v14 = 32;
    else
      v14 = (unsigned int)a5;
    v15 = a3 << 8;
    v16 = 0;
    v17 = 0;
    v67 = 0x8000000000LL - v14;
    StatusReg = _ReadStatusReg(SP_EL0);
    n = v14;
    while ( 1 )
    {
      v73 = 0;
      v74 = 0;
      v23 = a3 + v16;
      v71 = 0;
      v72 = 0;
      _check_object_size(&v71, n, 0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v24 = a3 + v16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v24 = v23 & (v15 >> 8);
      v68 = v15;
      v25 = n;
      if ( v67 < v24 )
        break;
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v29 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v29);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
      v25 = _arch_copy_from_user(&v71, v23 & 0xFF7FFFFFFFFFFFFFLL, n);
      v30 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v32 - 4096);
      _WriteStatusReg(TTBR1_EL1, v32);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v30);
      if ( v25 )
        break;
LABEL_29:
      if ( (v72 & 0xFFF) != 0 )
        goto LABEL_51;
      v13 = -22;
      if ( !v73 || (v73 & 0xFFF) != 0 )
        goto LABEL_71;
      v33 = *(_QWORD *)(_X20 + 48);
      if ( v33 <= v72 )
      {
LABEL_51:
        v13 = -22;
        goto LABEL_71;
      }
      v13 = -22;
      if ( v73 + v72 <= v72 || v73 + v72 > v33 )
        goto LABEL_71;
      if ( !(_DWORD)v74 && HIDWORD(v74) == 2 )
      {
        v18 = 0;
        v19 = 32LL * v17;
        v20 = v17;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v19 + 24) = 0;
        v21 = v72;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v19) = v72;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v19 + 8) = v21 + v73 - 1;
      }
      else
      {
        v34 = kgsl_sharedmem_find_id(a1, v74);
        v35 = 32LL * v17;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v35 + 24) = v34;
        v36 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + v35 + 24);
        if ( !v36 )
        {
          v13 = -2;
          goto LABEL_71;
        }
        _X9 = (unsigned int *)(v36 + 372);
        __asm { PRFM            #0x11, [X9] }
        do
          v42 = __ldxr(_X9);
        while ( __stxr(v42 + 1, _X9) );
        v43 = *(_QWORD *)(v36 + 80);
        if ( (v43 & 0x400000000LL) != 0 )
          goto LABEL_51;
        if ( ((*(_DWORD *)(_X20 + 80) ^ (unsigned int)v43) & 8) != 0 )
        {
          v13 = -1;
          goto LABEL_71;
        }
        if ( (unsigned int)(HIDWORD(v74) - 3) < 0xFFFFFFFE )
          goto LABEL_51;
        if ( HIDWORD(v74) == 1 )
        {
          if ( (v71 & 0xFFF) != 0 )
            goto LABEL_51;
          v38 = *(_QWORD *)(v36 + 48);
          if ( v38 <= v71 )
            goto LABEL_51;
          v13 = -22;
          if ( v73 + v71 <= v71 || v73 + v71 > v38 )
            goto LABEL_71;
        }
        else if ( v71 )
        {
          goto LABEL_51;
        }
        v20 = v17;
        v39 = 32LL * v17;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v39 + 24) = v36;
        v40 = v72;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v39) = v72;
        *(_QWORD *)(*(_QWORD *)(v11 + 8) + v39 + 8) = v40 + v73 - 1;
        v18 = v71;
      }
      v22 = 32 * v20;
      ++v17;
      v16 += a5;
      *(_DWORD *)(*(_QWORD *)(v11 + 8) + v22 + 16) = v18;
      *(_DWORD *)(*(_QWORD *)(v11 + 8) + v22 + 20) = HIDWORD(v74);
      v15 = v68 + (a5 << 8);
      if ( a4 == v17 )
      {
        _X8 = (unsigned int *)(a1 + 496);
        __asm { PRFM            #0x11, [X8] }
        do
          v66 = __ldxr(_X8);
        while ( __stxr(v66 - 1, _X8) );
        *(_DWORD *)(v11 + 72) = 0;
        _init_swait_queue_head(v11 + 80, "&x->wait", &init_completion___key_7);
        *(_DWORD *)(v11 + 104) = 1;
        goto LABEL_67;
      }
    }
    if ( n - v25 <= 0x20 )
      v26 = 32 - (n - v25);
    else
      v26 = 0;
    if ( v26 >= v25 )
    {
      memset((char *)&v71 + n - v25, 0, v25);
      if ( v25 )
      {
        v13 = -14;
        goto LABEL_71;
      }
      goto LABEL_29;
    }
    _fortify_panic(15, v26, v25);
    v44 = _ReadStatusReg(SP_EL0);
    v45 = *(_QWORD *)(v44 + 80);
    v46 = _check_object_size;
    *(_QWORD *)(v44 + 80) = &kgsl_sharedmem_create_bind_op__alloc_tag;
    v11 = _kmalloc_cache_noprof(v46, 3520, 112);
    *(_QWORD *)(v44 + 80) = v45;
    if ( v11 )
      continue;
    break;
  }
LABEL_57:
  if ( _X20 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_77;
  __asm { PRFM            #0x11, [X20] }
  do
    v61 = __ldxr((unsigned int *)_X20);
  while ( __stlxr(v61 - 1, (unsigned int *)_X20) );
  if ( v61 == 1 )
  {
LABEL_62:
    __dmb(9u);
    kgsl_mem_entry_destroy((_QWORD *)_X20);
    goto LABEL_77;
  }
  if ( v61 > 0 )
    goto LABEL_77;
LABEL_81:
  refcount_warn_saturate(_X20, 3);
LABEL_77:
  v11 = -12;
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return v11;
}
