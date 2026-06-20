__int64 __fastcall gen8_hwsched_submit_drawobj(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x1
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w22
  _DWORD *v9; // x23
  int v10; // w8
  int v11; // w8
  __int64 v12; // x9
  __int64 v13; // x9
  int v14; // w10
  _DWORD *v15; // x8
  size_t v16; // x2
  __int64 v17; // x21
  int v18; // w8
  __int64 v19; // x28
  __int64 v20; // x22
  _QWORD *v21; // x23
  _QWORD *v22; // x27
  __int64 v23; // x24
  __int64 v24; // x26
  __int64 v25; // x25
  __int64 (__fastcall *v26)(_QWORD); // x8
  unsigned int v27; // w0
  __int64 v28; // x24
  unsigned int v30; // w8
  unsigned int v31; // w21
  unsigned int v37; // w9
  void (__fastcall *v38)(_QWORD); // x8
  int v39; // w8
  unsigned int v40; // w20
  _QWORD *i; // x10
  int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w9
  __int64 v45; // x22
  unsigned int v46; // w8
  unsigned int v47; // w9
  char irq_bit_0; // w0
  unsigned __int64 v52; // x8
  unsigned int v55; // w8
  unsigned int v56; // w8
  unsigned int v59; // w8
  unsigned int v60; // w8
  unsigned __int64 v63; // x8
  unsigned __int64 v66; // x10
  unsigned __int64 v69; // x10
  __int64 v70; // [xsp+8h] [xbp-48h]
  int v71; // [xsp+10h] [xbp-40h]
  _DWORD *v72; // [xsp+18h] [xbp-38h]

  _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(a2 + 8);
  v5 = v4;
  if ( !gen8_hwsched_submit_drawobj_cmdbuf )
  {
    gen8_hwsched_submit_drawobj_cmdbuf = devm_kmalloc(*(_QWORD *)(a1 + 11168) + 16LL, 1024, 3520);
    if ( !gen8_hwsched_submit_drawobj_cmdbuf )
    {
      result = 4294967284LL;
      goto LABEL_86;
    }
    v5 = *(_QWORD *)(a2 + 8);
  }
  result = hfi_context_register_1(a1, v5);
  if ( (_DWORD)result )
    goto LABEL_86;
  if ( (*(_BYTE *)(a2 + 16) & 4) != 0 )
  {
    v16 = (32 * *(_DWORD *)(a2 + 136)) | 0x14u;
    if ( (unsigned int)v16 >= 0x401 )
    {
      __break(0x800u);
      result = 4294967206LL;
      goto LABEL_86;
    }
    v17 = gen8_hwsched_submit_drawobj_cmdbuf;
    v70 = *(_QWORD *)(a2 + 8);
    v71 = (32 * *(_DWORD *)(a2 + 136)) | 0x14;
    memset((void *)gen8_hwsched_submit_drawobj_cmdbuf, 0, v16);
    v72 = (_DWORD *)v17;
    *(_DWORD *)(v17 + 16) = *(_DWORD *)(a2 + 136);
    if ( !*(_DWORD *)(a2 + 136) )
    {
LABEL_88:
      _X9 = (unsigned __int64 *)(a2 + 128);
      __asm { PRFM            #0x11, [X9] }
      do
        v52 = __ldxr(_X9);
      while ( __stlxr(v52 | 4, _X9) );
      __dmb(0xBu);
      if ( (v52 & 4) != 0 )
      {
        v39 = *(_DWORD *)(a2 + 20);
      }
      else
      {
        v39 = *(_DWORD *)(v70 + 2092) + 1;
        *(_DWORD *)(v70 + 2092) = v39;
        *(_DWORD *)(a2 + 20) = v39;
      }
      v72[3] = v39;
      *v72 = 152;
      _X9 = (unsigned int *)(a1 + 22928);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v55 = __ldxr(_X9);
        v56 = v55 + 1;
      }
      while ( __stlxr(v56, _X9) );
      __dmb(0xBu);
      *v72 |= (v71 << 6) & 0xFD00 | (v56 << 20);
      result = adreno_gmu_context_queue_write(a1, v70 + 1640);
      goto LABEL_86;
    }
    v18 = 0;
    v19 = v17 + 20;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v20 = v18;
      v21 = *(_QWORD **)(*(_QWORD *)(a2 + 144) + 16LL * v18);
      if ( (is_kgsl_fence(v21) & 1) != 0 )
        break;
      v27 = kgsl_hw_fence_add_waiter(a1, v21, v19 + 4);
      if ( v27 )
      {
        v40 = v27;
        adreno_hwsched_syncobj_kfence_put(a2);
        _X8 = (unsigned __int64 *)(a2 + 128);
        __asm { PRFM            #0x11, [X8] }
        do
          v66 = __ldxr(_X8);
        while ( __stxr(v66 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        result = v40;
        *(_DWORD *)(a2 + 20) = 0;
        _X8 = (unsigned __int64 *)(a2 + 128);
        __asm { PRFM            #0x11, [X8] }
        do
          v69 = __ldxr(_X8);
        while ( __stxr(v69 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
        goto LABEL_86;
      }
      if ( (kgsl_hw_fence_signaled(v21) & 1) != 0 || (v21[6] & 1) != 0 )
        *(_QWORD *)(v19 + 24) |= 2uLL;
      *(_QWORD *)(v19 + 8) = v21[4];
      v28 = v21[5];
LABEL_50:
      *(_QWORD *)(v19 + 16) = v28;
      v38 = *(void (__fastcall **)(_QWORD))(v21[1] + 16LL);
      if ( v38 )
      {
        if ( *((_DWORD *)v38 - 1) != -352706110 )
          __break(0x8228u);
        v38(v21);
      }
      *(_DWORD *)v19 = 8;
      v19 += 32;
      v18 = v20 + 1;
      if ( (unsigned int)(v20 + 1) >= *(_DWORD *)(a2 + 136) )
        goto LABEL_88;
    }
    v22 = (_QWORD *)(*(_QWORD *)(a2 + 144) + 16 * v20);
    v23 = *v22;
    v24 = *(_QWORD *)(*v22 + 72LL);
    *(_QWORD *)(v19 + 24) |= 1uLL;
    v25 = raw_spin_lock_irqsave(v24 + 64);
    if ( (*(_QWORD *)(v23 + 48) & 1) != 0 )
      goto LABEL_48;
    v26 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v23 + 8) + 32LL);
    if ( !v26 )
      goto LABEL_34;
    if ( *((_DWORD *)v26 - 1) != 1879296680 )
      __break(0x8228u);
    if ( (v26(v23) & 1) != 0 )
    {
      dma_fence_signal_locked(v23);
    }
    else
    {
LABEL_34:
      _X0 = *(unsigned int **)(v24 + 80);
      if ( _X0 )
      {
        v30 = *_X0;
        if ( *_X0 )
        {
          do
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v37 = __ldxr(_X0);
            while ( v37 == v30 && __stxr(v30 + 1, _X0) );
            v31 = v30;
            if ( v37 == v30 )
              break;
            v31 = 0;
            v30 = v37;
          }
          while ( v37 );
        }
        else
        {
          v31 = 0;
        }
        if ( (((v31 + 1) | v31) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(_X0, 0);
          if ( !v31 )
            goto LABEL_48;
        }
        else if ( !v31 )
        {
          goto LABEL_48;
        }
        v22[1] = *(_QWORD *)(v24 + 80);
LABEL_49:
        raw_spin_unlock_irqrestore(v24 + 64, v25);
        *(_QWORD *)(v19 + 8) = *(unsigned int *)(v23 + 96);
        v28 = *(unsigned int *)(v23 + 100);
        goto LABEL_50;
      }
    }
LABEL_48:
    *(_QWORD *)(v19 + 24) |= 1uLL;
    goto LABEL_49;
  }
  if ( (*(_QWORD *)(a2 + 56) & 0x80) != 0 )
  {
    raw_spin_lock(v4 + 404);
    process_hw_fence_queue_0(a1, v4, *(unsigned int *)(a2 + 20));
LABEL_85:
    raw_spin_unlock(v4 + 404);
    result = 0;
    goto LABEL_86;
  }
  v7 = *(_DWORD *)(a2 + 160);
  v8 = 32;
  if ( v7 <= 0x52 && (*(_QWORD *)(a2 + 56) & 1) == 0 )
    v8 = 12 * v7 + 32;
  v9 = (_DWORD *)gen8_hwsched_submit_drawobj_cmdbuf;
  memset((void *)gen8_hwsched_submit_drawobj_cmdbuf, 0, v8);
  v9[1] = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 4LL);
  v9[2] = 32;
  if ( (*(_QWORD *)(a2 + 24) & 0x100LL) != 0 )
    v10 = 288;
  else
    v10 = 32;
  v9[2] = v10;
  v9[3] = *(_DWORD *)(a2 + 20);
  if ( (*(_QWORD *)(a2 + 56) & 1) == 0 )
  {
    if ( *(_DWORD *)(a2 + 160) < 0x53u )
    {
      v15 = v9 + 8;
    }
    else
    {
      v11 = v10 | 0x200;
      if ( (*(_QWORD *)(a2 + 56) & 0x20LL) != 0 )
        v12 = 24688;
      else
        v12 = 24680;
      v13 = *(_QWORD *)(a1 + v12);
      v14 = *(_DWORD *)(v13 + 184);
      v9[2] = v11;
      v9[7] = v14;
      v15 = *(_DWORD **)(v13 + 8);
    }
    for ( i = *(_QWORD **)(a2 + 88); i != (_QWORD *)(a2 + 88); i = (_QWORD *)*i )
    {
      *(_QWORD *)v15 = i[4];
      v15[2] = i[5];
      v15 += 3;
    }
    v9[6] = *(_DWORD *)(a2 + 160);
    if ( (*(_BYTE *)(a2 + 24) & 0x10) != 0 && *(_QWORD *)(a2 + 128) )
    {
      v9[4] = *(_QWORD *)(a2 + 136);
      v42 = v9[2] | 0x10;
      v9[5] = *(_DWORD *)(a2 + 140);
      v9[2] = v42;
    }
    _X9 = (unsigned __int64 *)(a2 + 56);
    __asm { PRFM            #0x11, [X9] }
    do
      v63 = __ldxr(_X9);
    while ( __stlxr(v63 & 0xFFFFFFFFFFFFFEFFLL, _X9) );
    __dmb(0xBu);
    if ( (v63 & 0x100) != 0 )
      v9[2] |= 0x100000u;
  }
  adreno_drawobj_set_constraint(a1, a2);
  *v9 = 130;
  _X9 = (unsigned int *)(a1 + 22928);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v59 = __ldxr(_X9);
    v60 = v59 + 1;
  }
  while ( __stlxr(v60, _X9) );
  __dmb(0xBu);
  *v9 |= (v8 << 6) & 0xFF00 | (v60 << 20);
  result = adreno_gmu_context_queue_write(a1, v4 + 1640);
  if ( !(_DWORD)result )
  {
    v43 = *(_DWORD *)(*(_QWORD *)(v4 + 1648) + 16LL);
    v44 = *(_DWORD *)(v4 + 2092);
    if ( v43 != v44 && (v43 <= v44 || ((v43 - v44) & 0x80000000) != 0) )
    {
      v46 = v43 ^ 0x80000000;
      v47 = v44 ^ 0x80000000;
      if ( v46 - v47 < 0x80000001 && v46 > v47 )
        v45 = 1;
      else
        v45 = 32;
    }
    else
    {
      v45 = 1;
    }
    irq_bit_0 = get_irq_bit_0(a1, *(_QWORD *)(a2 + 8));
    gmu_core_regwrite(a1, 129428, v45 << (irq_bit_0 + 2));
    *(_DWORD *)(v4 + 396) = *(_DWORD *)(a2 + 20);
    raw_spin_lock(v4 + 404);
    process_hw_fence_queue_0(a1, v4, *(unsigned int *)(a2 + 20));
    *(_DWORD *)(v4 + 2096) = *(_DWORD *)(a2 + 20);
    goto LABEL_85;
  }
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return result;
}
