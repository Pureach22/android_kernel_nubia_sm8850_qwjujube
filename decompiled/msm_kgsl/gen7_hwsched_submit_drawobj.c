__int64 __fastcall gen7_hwsched_submit_drawobj(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x1
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w22
  unsigned int *v9; // x23
  int v10; // w8
  int v11; // w8
  __int64 v12; // x9
  __int64 v13; // x9
  unsigned int v14; // w10
  _DWORD *v15; // x8
  size_t v16; // x2
  __int64 v17; // x21
  int v18; // w8
  _QWORD *v19; // x28
  __int64 v20; // x21
  _QWORD *v21; // x23
  _QWORD *v22; // x27
  __int64 v23; // x24
  __int64 v24; // x26
  __int64 v25; // x25
  __int64 (__fastcall *v26)(_QWORD); // x8
  unsigned int v27; // w0
  __int64 v28; // x24
  unsigned int v30; // w8
  unsigned int v31; // w22
  unsigned int v37; // w9
  void (__fastcall *v38)(_QWORD); // x8
  int v39; // w8
  unsigned int v40; // w20
  _QWORD *i; // x10
  __int64 v42; // x8
  unsigned int v43; // w8
  unsigned int v44; // w9
  __int64 v45; // x22
  unsigned int v46; // w8
  unsigned int v47; // w9
  char irq_bit; // w0
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
  _QWORD v73[4]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v74; // [xsp+40h] [xbp-10h]
  __int64 v75; // [xsp+48h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 8);
  v74 = 0;
  v5 = v4;
  memset(v73, 0, sizeof(v73));
  if ( !gen7_hwsched_submit_drawobj_cmdbuf )
  {
    gen7_hwsched_submit_drawobj_cmdbuf = devm_kmalloc(*(_QWORD *)(a1 + 11168) + 16LL, 1024, 3520);
    if ( !gen7_hwsched_submit_drawobj_cmdbuf )
    {
      result = 4294967284LL;
      goto LABEL_89;
    }
    v5 = *(_QWORD *)(a2 + 8);
  }
  result = hfi_context_register_0(a1, v5);
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(a2 + 16) & 4) == 0 )
    {
      if ( (*(_QWORD *)(a2 + 56) & 0x80) != 0 )
      {
        raw_spin_lock(v4 + 404);
        process_hw_fence_queue(a1, v4, *(unsigned int *)(a2 + 20));
      }
      else
      {
        v7 = *(_DWORD *)(a2 + 160);
        v8 = 32;
        if ( v7 <= 0x52 && (*(_QWORD *)(a2 + 56) & 1) == 0 )
          v8 = 12 * v7 + 32;
        v9 = (unsigned int *)gen7_hwsched_submit_drawobj_cmdbuf;
        memset((void *)gen7_hwsched_submit_drawobj_cmdbuf, 0, v8);
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
              v12 = 24624;
            else
              v12 = 24616;
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
            v42 = *(_QWORD *)(a2 + 136);
            v74 = a2;
            v9[4] = v42;
            LODWORD(v42) = v9[2] | 0x10;
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
        _X9 = (unsigned int *)(a1 + 22928);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v59 = __ldxr(_X9);
          v60 = v59 + 1;
        }
        while ( __stlxr(v60, _X9) );
        __dmb(0xBu);
        *v9 = (v8 << 6) & 0xFF00 | (v60 << 20) | 0x82;
        if ( (adreno_hwsched_context_queue_enabled(a1) & 1) != 0 )
        {
          result = adreno_gmu_context_queue_write(a1, v4 + 1640);
          if ( (_DWORD)result )
            goto LABEL_89;
        }
        else
        {
          result = gen7_hfi_dispatch_queue_write(
                     a1,
                     (unsigned int)(*(_DWORD *)(*(_QWORD *)(a2 + 8) + 292LL) + 3),
                     v9,
                     v8,
                     a2,
                     v73);
          if ( (_DWORD)result )
            goto LABEL_89;
        }
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
        irq_bit = get_irq_bit(a1, a2);
        gmu_core_regwrite(a1, 129428, v45 << (irq_bit + 2));
        *(_DWORD *)(v4 + 396) = *(_DWORD *)(a2 + 20);
        raw_spin_lock(v4 + 404);
        process_hw_fence_queue(a1, v4, *(unsigned int *)(a2 + 20));
        *(_DWORD *)(v4 + 2096) = *(_DWORD *)(a2 + 20);
      }
      raw_spin_unlock(v4 + 404);
      result = 0;
      goto LABEL_89;
    }
    v16 = (32 * *(_DWORD *)(a2 + 136)) | 0x14u;
    if ( (unsigned int)v16 >= 0x401 )
    {
      __break(0x800u);
      result = 4294967206LL;
      goto LABEL_89;
    }
    v17 = gen7_hwsched_submit_drawobj_cmdbuf;
    v70 = *(_QWORD *)(a2 + 8);
    v71 = (32 * *(_DWORD *)(a2 + 136)) | 0x14;
    memset((void *)gen7_hwsched_submit_drawobj_cmdbuf, 0, v16);
    v72 = (_DWORD *)v17;
    *(_DWORD *)(v17 + 16) = *(_DWORD *)(a2 + 136);
    if ( !*(_DWORD *)(a2 + 136) )
    {
LABEL_91:
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
      _X9 = (unsigned int *)(a1 + 22928);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v55 = __ldxr(_X9);
        v56 = v55 + 1;
      }
      while ( __stlxr(v56, _X9) );
      __dmb(0xBu);
      *v72 = (v71 << 6) & 0xFD00 | (v56 << 20) | 0x98;
      result = adreno_gmu_context_queue_write(a1, v70 + 1640);
      goto LABEL_89;
    }
    v18 = 0;
    v19 = (_QWORD *)(v17 + 20);
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v20 = v18;
      v21 = *(_QWORD **)(*(_QWORD *)(a2 + 144) + 16LL * v18);
      if ( (is_kgsl_fence(v21) & 1) != 0 )
        break;
      v27 = kgsl_hw_fence_add_waiter(a1, v21, 0);
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
        goto LABEL_89;
      }
      if ( (kgsl_hw_fence_signaled(v21) & 1) != 0 || (v21[6] & 1) != 0 )
        v19[2] |= 2uLL;
      *v19 = v21[4];
      v28 = v21[5];
LABEL_50:
      v19[1] = v28;
      v38 = *(void (__fastcall **)(_QWORD))(v21[1] + 16LL);
      if ( v38 )
      {
        if ( *((_DWORD *)v38 - 1) != -352706110 )
          __break(0x8228u);
        v38(v21);
      }
      v18 = v20 + 1;
      v19 += 3;
      if ( (unsigned int)(v20 + 1) >= *(_DWORD *)(a2 + 136) )
        goto LABEL_91;
    }
    v22 = (_QWORD *)(*(_QWORD *)(a2 + 144) + 16 * v20);
    v23 = *v22;
    v24 = *(_QWORD *)(*v22 + 72LL);
    v19[2] |= 1uLL;
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
        *v19 = *(unsigned int *)(v23 + 96);
        v28 = *(unsigned int *)(v23 + 100);
        goto LABEL_50;
      }
    }
LABEL_48:
    v19[2] |= 1uLL;
    goto LABEL_49;
  }
LABEL_89:
  _ReadStatusReg(SP_EL0);
  return result;
}
