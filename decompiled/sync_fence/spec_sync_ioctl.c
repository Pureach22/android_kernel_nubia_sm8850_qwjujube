__int64 __fastcall spec_sync_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x27
  unsigned __int64 StatusReg; // x24
  char v5; // w8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x25
  unsigned __int64 v8; // x2
  unsigned __int64 v9; // x23
  char v10; // w8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x2
  __int64 v13; // x9
  unsigned __int64 v14; // x8
  char v15; // w10
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x19
  unsigned __int64 v18; // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  __int64 fence; // x0
  __int64 v29; // x20
  __int64 (*v30)(void); // x8
  __int64 *v31; // x8
  int v32; // w8
  __int64 v33; // x12
  __int64 v34; // x0
  __int64 v35; // x21
  __int64 v36; // x22
  unsigned __int64 v37; // x8
  size_t v38; // x23
  size_t v39; // x1
  unsigned __int64 v40; // x9
  unsigned __int64 v42; // x8
  __int64 v43; // x0
  unsigned __int64 v44; // x8
  unsigned __int64 v46; // x9
  unsigned __int64 v47; // x8
  unsigned __int64 v49; // x9
  unsigned __int64 v50; // x8
  unsigned __int64 v52; // x9
  unsigned __int64 v53; // x21
  __int64 v54; // x20
  int v55; // w8
  unsigned __int64 v57; // x8
  unsigned __int64 v59; // x9
  unsigned __int64 v60; // x8
  unsigned __int64 v62; // x9
  int v63; // w8
  bool v64; // w22
  __int64 v65; // x0
  int v68; // w8
  unsigned int v69; // w23
  _BOOL4 v70; // w21
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x21
  __int64 v74; // x0
  _QWORD *v75; // x20
  __int64 *v76; // x22
  _QWORD *v77; // x1
  char v78; // w9
  unsigned __int64 v79; // x9
  unsigned __int64 v80; // x9
  unsigned __int64 v82; // x10
  unsigned __int64 v83; // x8
  unsigned __int64 v85; // x9
  unsigned int v86; // w22
  int v89; // w8
  int v90; // w20
  __int64 v91; // x0
  void *v92; // x0
  int v93; // w23
  int v94; // w26
  __int64 v95; // x1
  unsigned int v97; // w8
  __int64 v98; // x22
  int v101; // w8
  unsigned __int64 v105; // x9
  unsigned __int64 v108; // x9
  unsigned __int64 v112; // x9
  unsigned __int64 v115; // x10
  int v117; // w8
  unsigned __int64 v118; // [xsp+0h] [xbp-20h]
  __int64 v119; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v120; // [xsp+10h] [xbp-10h]
  __int64 v121; // [xsp+18h] [xbp-8h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == -1073201659 )
    goto LABEL_18;
  if ( a2 != -1072677373 )
  {
    if ( a2 != -1072939516 )
    {
      LODWORD(v17) = -25;
      goto LABEL_143;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(_BYTE *)(StatusReg + 70);
    LODWORD(v120) = 0;
    v119 = 0;
    if ( (v5 & 0x20) != 0 || (v6 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v6 = a3 & ((__int64)(a3 << 8) >> 8);
    v7 = 0x7FFFFFFFF4LL;
    if ( v6 > 0x7FFFFFFFF4LL )
    {
      v8 = 12;
      goto LABEL_9;
    }
    v47 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v49 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v49 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v49);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v47);
    v118 = a3;
    v8 = _arch_copy_from_user(&v119, a3 & 0xFF7FFFFFFFFFFFFFLL, 12);
    v50 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v52 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v52 - 4096);
    _WriteStatusReg(TTBR1_EL1, v52);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v50);
    if ( v8 )
    {
LABEL_9:
      if ( v8 >= 0xD )
        goto LABEL_17;
      goto LABEL_22;
    }
    LODWORD(v17) = get_unused_fd_flags(0x80000);
    if ( (v17 & 0x80000000) != 0 )
    {
      printk(&unk_7A74, "spec_sync_create_array");
      goto LABEL_143;
    }
    if ( (unsigned int)(v119 - 33) <= 0xFFFFFFDF )
    {
      printk(&unk_78C8, "spec_sync_create_array");
      v90 = -34;
      goto LABEL_135;
    }
    v3 = qword_7B90;
    v53 = 8LL * (unsigned int)v119;
    v54 = _kmalloc_noprof(v53, 3520);
    if ( v54 )
    {
LABEL_60:
      if ( (_DWORD)v119 )
      {
        v55 = 0;
        _X22 = (unsigned int *)(v3 + 56);
        while ( 1 )
        {
          if ( v53 <= 8LL * v55 )
            goto LABEL_132;
          v94 = v55;
          *(_QWORD *)(v54 + 8LL * v55) = v3;
          if ( v3 )
          {
            __asm { PRFM            #0x11, [X22] }
            do
              v97 = __ldxr(_X22);
            while ( __stxr(v97 + 1, _X22) );
            if ( v97 )
            {
              if ( (((v97 + 1) | v97) & 0x80000000) == 0 )
                goto LABEL_122;
              v95 = 1;
            }
            else
            {
              v95 = 2;
            }
            refcount_warn_saturate(v3 + 56, v95);
          }
LABEL_122:
          v69 = v119;
          v55 = v94 + 1;
          if ( v94 + 1 >= (unsigned int)v119 )
            goto LABEL_78;
        }
      }
      v69 = 0;
LABEL_78:
      v70 = (v119 & 0x200000000LL) == 0;
      v71 = dma_fence_context_alloc(1);
      v72 = dma_fence_array_create(v69, v54, v71, 0, v70);
      if ( v72 )
      {
        v73 = v72;
        _X8 = (unsigned __int64 *)(v72 + 48);
        __asm { PRFM            #0x11, [X8] }
        do
          v105 = __ldxr(_X8);
        while ( __stxr(v105 | 4, _X8) );
        _X8 = (unsigned __int64 *)(v72 + 48);
        __asm { PRFM            #0x11, [X8] }
        do
          v108 = __ldxr(_X8);
        while ( __stxr(v108 | 0x10000, _X8) );
        v74 = sync_file_create(v72);
        if ( v74 )
        {
          v75 = (_QWORD *)v74;
          v76 = (__int64 *)_kmalloc_cache_noprof(dma_fence_enable_sw_signaling, 3520, 24);
          if ( v76 )
          {
            fd_install((unsigned int)v17, *v75);
            *v76 = v73;
            mutex_lock(&unk_7BC0);
            v77 = (_QWORD *)qword_7BF8;
            if ( (__int64 *)qword_7BF8 == v76 + 1 || *(__int64 **)qword_7BF8 != &qword_7BF0 )
            {
              _list_add_valid_or_report(v76 + 1);
            }
            else
            {
              qword_7BF8 = (__int64)(v76 + 1);
              v76[1] = (__int64)&qword_7BF0;
              v76[2] = (__int64)v77;
              *v77 = v76 + 1;
            }
            mutex_unlock(&unk_7BC0);
            v78 = *(_BYTE *)(StatusReg + 70);
            LODWORD(v120) = v17;
            if ( (v78 & 0x20) != 0 || (v79 = v118, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v79 = v118 & ((__int64)(v118 << 8) >> 8);
            if ( v79 > v7 )
              goto LABEL_22;
            v80 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v82 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v82 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v82);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v80);
            v43 = _arch_copy_to_user(v118 & 0xFF7FFFFFFFFFFFFFLL, &v119, 12);
            v83 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v85 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v85 - 4096);
            _WriteStatusReg(TTBR1_EL1, v85);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v83);
            goto LABEL_53;
          }
          fput(*v75);
          v90 = -12;
        }
        else
        {
          printk(&unk_78AB, "spec_sync_create_array");
          v90 = -22;
        }
        _X0 = (unsigned int *)(v73 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v117 = __ldxr(_X0);
        while ( __stlxr(v117 - 1, _X0) );
        if ( v117 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
        }
        else if ( v117 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      else
      {
        if ( (_DWORD)v119 )
        {
          v86 = 0;
          _X21 = (unsigned int *)(v3 + 56);
          do
          {
            if ( v3 )
            {
              __asm { PRFM            #0x11, [X21] }
              do
                v89 = __ldxr(_X21);
              while ( __stlxr(v89 - 1, _X21) );
              if ( v89 == 1 )
              {
                __dmb(9u);
                dma_fence_release(v3 + 56);
              }
              else if ( v89 <= 0 )
              {
                refcount_warn_saturate(v3 + 56, 3);
              }
            }
            ++v86;
          }
          while ( v86 < (unsigned int)v119 );
        }
        kfree(v54);
        v90 = -22;
      }
LABEL_135:
      put_unused_fd((unsigned int)v17);
      LODWORD(v17) = v90;
      goto LABEL_143;
    }
LABEL_134:
    v90 = -12;
    goto LABEL_135;
  }
  v9 = _ReadStatusReg(SP_EL0);
  v10 = *(_BYTE *)(v9 + 70);
  v119 = 0;
  v120 = 0;
  if ( (v10 & 0x20) != 0 || (v11 = a3, (*(_QWORD *)v9 & 0x4000000) != 0) )
    v11 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v11 > 0x7FFFFFFFF0LL )
  {
    v12 = 16;
    goto LABEL_16;
  }
  v18 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v24 = *(_QWORD *)(v9 + 8);
  _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v24);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v18);
  v12 = _arch_copy_from_user(&v119, a3 & 0xFF7FFFFFFFFFFFFFLL, 16);
  v25 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v27 - 4096);
  _WriteStatusReg(TTBR1_EL1, v27);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v25);
  if ( v12 )
  {
LABEL_16:
    if ( v12 >= 0x11 )
    {
LABEL_17:
      a1 = _fortify_panic(15);
LABEL_18:
      v13 = *(_QWORD *)(a1 + 32);
      v14 = _ReadStatusReg(SP_EL0);
      v15 = *(_BYTE *)(v14 + 70);
      LODWORD(v119) = *(_DWORD *)(v13 + 124);
      if ( (v15 & 0x20) != 0 || (v16 = a3, (*(_QWORD *)v14 & 0x4000000) != 0) )
        v16 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v16 > 0x7FFFFFFFFCLL )
        goto LABEL_22;
      v40 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v42 = *(_QWORD *)(v14 + 8);
      _WriteStatusReg(TTBR1_EL1, v42 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v42);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v40);
      v43 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v119, 4);
      v44 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v46 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v46 - 4096);
      _WriteStatusReg(TTBR1_EL1, v46);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v44);
LABEL_53:
      if ( v43 )
        LODWORD(v17) = -14;
      else
        LODWORD(v17) = 0;
      goto LABEL_143;
    }
LABEL_22:
    LODWORD(v17) = -14;
    goto LABEL_143;
  }
  fence = sync_file_get_fence((unsigned int)v119);
  if ( !fence )
  {
    printk(&unk_785A, "spec_sync_bind_array");
    LODWORD(v17) = -22;
    goto LABEL_143;
  }
  v29 = fence;
  if ( (*(_QWORD *)(fence + 48) & 1) != 0 )
    goto LABEL_114;
  v30 = *(__int64 (**)(void))(*(_QWORD *)(fence + 8) + 32LL);
  if ( v30 )
  {
    if ( *((_DWORD *)v30 - 1) != 1879296680 )
      __break(0x8228u);
    if ( (v30() & 1) != 0 )
    {
      dma_fence_signal(v29);
LABEL_114:
      v92 = &unk_767F;
      goto LABEL_115;
    }
  }
  mutex_lock(&unk_7BC0);
  v31 = &qword_7BF0;
  do
  {
    v31 = (__int64 *)*v31;
    if ( v31 == &qword_7BF0 )
    {
      mutex_unlock(&unk_7BC0);
      v92 = &unk_7963;
LABEL_115:
      printk(v92, "spec_sync_bind_array");
      LODWORD(v17) = -22;
      goto LABEL_137;
    }
  }
  while ( *(v31 - 1) != v29 );
  mutex_unlock(&unk_7BC0);
  StatusReg = *(unsigned int *)(v29 + 68);
  if ( !(_DWORD)StatusReg )
  {
LABEL_39:
    v17 = 4 * StatusReg;
    v34 = _kmalloc_noprof(4 * StatusReg, 3520);
    v35 = v34;
    if ( !v34 )
    {
      LODWORD(v17) = -12;
      goto LABEL_137;
    }
    if ( (unsigned int)StatusReg >> 29 )
    {
      __break(0x800u);
      LODWORD(v17) = -14;
      goto LABEL_107;
    }
    v36 = 4 * StatusReg;
    v7 = v120;
    _check_object_size(v34, 4 * StatusReg, 0);
    if ( (*(_BYTE *)(v9 + 70) & 0x20) != 0 || (v37 = v7, (*(_QWORD *)v9 & 0x4000000) != 0) )
      v37 = v7 & ((__int64)(v7 << 8) >> 8);
    if ( 0x8000000000LL - v36 >= v37 )
    {
      v57 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v59 = *(_QWORD *)(v9 + 8);
      _WriteStatusReg(TTBR1_EL1, v59 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v59);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v57);
      v38 = _arch_copy_from_user(v35, v7 & 0xFF7FFFFFFFFFFFFFLL, 4 * StatusReg);
      v60 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v62 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v62 - 4096);
      _WriteStatusReg(TTBR1_EL1, v62);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v60);
      if ( !v38 )
        goto LABEL_63;
    }
    else
    {
      v38 = 4 * StatusReg;
    }
    if ( v17 >= v36 - v38 )
      v39 = v17 - (v36 - v38);
    else
      v39 = 0;
    if ( v39 < v38 )
      goto LABEL_133;
    memset((void *)(v35 + v36 - v38), 0, v38);
    if ( v38 )
    {
      LODWORD(v17) = -14;
LABEL_107:
      kfree(v35);
      goto LABEL_137;
    }
LABEL_63:
    raw_spin_lock(*(_QWORD *)v29);
    if ( !(_DWORD)StatusReg )
    {
      v64 = 0;
LABEL_102:
      _X8 = (unsigned __int64 *)(v29 + 48);
      __asm { PRFM            #0x11, [X8] }
      do
        v115 = __ldxr(_X8);
      while ( __stxr(v115 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
      raw_spin_unlock(*(_QWORD *)v29);
      dma_fence_enable_sw_signaling(v29);
      clear_fence_array_tracker(0);
      v93 = 0;
LABEL_152:
      _X8 = (unsigned __int64 *)(v29 + 48);
      __asm { PRFM            #0x11, [X8] }
      do
        v112 = __ldxr(_X8);
      while ( __stxr(v112 | 0x20000, _X8) );
      _wake_up(&unk_7C00, 3, 0, 0);
      LODWORD(v17) = 0;
      if ( v64 )
      {
        if ( (*(_QWORD *)(v29 + 48) & 1) != 0 )
          __break(0x800u);
        v91 = *(_QWORD *)v29;
        *(_DWORD *)(v29 + 60) = -22;
        raw_spin_unlock(v91);
        dma_fence_signal(v29);
        clear_fence_array_tracker(0);
        LODWORD(v17) = v93;
      }
      goto LABEL_107;
    }
    v63 = 0;
    v7 = (unsigned __int64)&loc_7000;
    v64 = 1;
    while ( 1 )
    {
      if ( v17 <= 4LL * v63 )
        goto LABEL_132;
      v3 = v63;
      v65 = sync_file_get_fence(*(unsigned int *)(v35 + 4LL * v63));
      if ( !v65 )
      {
        if ( v17 > 4 * v3 )
        {
          printk(&unk_78EF, "spec_sync_bind_array");
          v93 = -22;
          goto LABEL_152;
        }
        goto LABEL_132;
      }
      if ( *(_QWORD *)(v65 + 32) == *(_QWORD *)(v29 + 32) && *(_QWORD *)(v65 + 40) == *(_QWORD *)(v29 + 40) )
        break;
      *(_QWORD *)(*(_QWORD *)(v29 + 80) + 8 * v3) = v65;
      if ( qword_7B90 )
      {
        _X0 = (unsigned int *)(qword_7B90 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v68 = __ldxr(_X0);
        while ( __stlxr(v68 - 1, _X0) );
        if ( v68 == 1 )
        {
          __dmb(9u);
          ((void (*)(void))dma_fence_release)();
        }
        else if ( v68 <= 0 )
        {
          ((void (*)(void))refcount_warn_saturate)();
        }
      }
      v63 = v3 + 1;
      v64 = (int)v3 + 1 < (unsigned int)StatusReg;
      if ( (_DWORD)StatusReg == (_DWORD)v3 + 1 )
        goto LABEL_102;
    }
    if ( v17 > 4 * v3 )
    {
      printk(&unk_79A0, "spec_sync_bind_array");
      v93 = -22;
      goto LABEL_152;
    }
LABEL_132:
    __break(1u);
LABEL_133:
    _fortify_panic(15);
    v98 = *(_QWORD *)(StatusReg + 80);
    v53 = 8LL * (unsigned int)v119;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    v54 = _kmalloc_noprof(v53, 3520);
    *(_QWORD *)(StatusReg + 80) = v98;
    if ( v54 )
      goto LABEL_60;
    goto LABEL_134;
  }
  v32 = 0;
  while ( 1 )
  {
    v33 = *(_QWORD *)(*(_QWORD *)(v29 + 80) + 8LL * v32);
    if ( *(_QWORD *)(v33 + 32) != 0xFAFADADAFAFADADALL || *(_QWORD *)(v33 + 40) != 0xEFA9CE00EFA9CE00LL )
      break;
    if ( (_DWORD)StatusReg == ++v32 )
      goto LABEL_39;
  }
  dma_fence_get_status(v29);
  printk(&unk_7788, "spec_sync_bind_array");
  LODWORD(v17) = -22;
LABEL_137:
  _X0 = (unsigned int *)(v29 + 56);
  __asm { PRFM            #0x11, [X0] }
  do
    v101 = __ldxr(_X0);
  while ( __stlxr(v101 - 1, _X0) );
  if ( v101 == 1 )
  {
    __dmb(9u);
    ((void (*)(void))dma_fence_release)();
  }
  else if ( v101 <= 0 )
  {
    ((void (*)(void))refcount_warn_saturate)();
  }
LABEL_143:
  _ReadStatusReg(SP_EL0);
  return (int)v17;
}
