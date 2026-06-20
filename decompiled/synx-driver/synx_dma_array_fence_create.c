__int64 __fastcall synx_dma_array_fence_create(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  unsigned __int64 v4; // x19
  __int64 v5; // x4
  __int64 v6; // x5
  unsigned __int64 v7; // x20
  __int64 result; // x0
  unsigned int v9; // w23
  __int64 v10; // x8
  __int64 v12; // x8
  unsigned int v13; // w10
  __int64 v14; // x1
  unsigned int v20; // w8
  unsigned __int64 v21; // x0
  __int64 v22; // x4
  __int64 v23; // x5
  unsigned __int64 v24; // x22
  unsigned __int64 v25; // x0
  __int64 v26; // x4
  __int64 v27; // x5
  unsigned __int64 v28; // x19
  unsigned int v29; // w0
  __int64 v30; // x5
  unsigned int v31; // w20
  unsigned int v32; // w8
  unsigned int v33; // w24
  __int64 v34; // x8
  int v37; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v40; // x24
  unsigned __int64 v43; // x3
  int v46; // w8
  int v48; // w8

  v3 = a1;
  v4 = 8LL * *(unsigned int *)(a1 + 8);
  v7 = _kmalloc_noprof(v4, 3520);
  result = 4294967274LL;
  if ( !v7 )
    return result;
  do
  {
    if ( v7 > 0xFFFFFFFFFFFFF000LL )
      return result;
    if ( !*(_DWORD *)(v3 + 8) )
    {
      v9 = 0;
LABEL_55:
      _X8 = &test_dma_seq_counter;
      __asm { PRFM            #0x11, [X8] }
      do
        v43 = __ldxr((unsigned __int64 *)&test_dma_seq_counter);
      while ( __stlxr(v43 + 1, (unsigned __int64 *)&test_dma_seq_counter) );
      __dmb(0xBu);
      v21 = dma_fence_array_create(*(unsigned int *)(v3 + 8), v7, a2);
      if ( v21 )
      {
        v24 = v21;
        if ( v21 < 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(v3 + 16) = v21;
          dma_fence_enable_sw_signaling(v21);
          v25 = _kmalloc_cache_noprof(raw_spin_unlock_bh, 3520, 24);
          v28 = v25;
          if ( v25 && v25 < 0xFFFFFFFFFFFFF001LL )
          {
            v29 = dma_fence_add_callback(v24, v25, synx_dma_fence_callback);
            if ( v29 )
            {
              v31 = v29;
              if ( v29 == -2 )
              {
                if ( (synx_debug & 8) != 0 )
                  printk(&unk_29E2A, &unk_2A972, "synx_dma_array_fence_create", 529, v24, v30);
              }
              else if ( (synx_debug & 1) != 0 )
              {
                printk(&unk_2958D, &unk_29207, "synx_dma_array_fence_create", 532, v24, v29);
              }
              _X0 = (unsigned int *)(v24 + 56);
              __asm { PRFM            #0x11, [X0] }
              do
                v48 = __ldxr(_X0);
              while ( __stlxr(v48 - 1, _X0) );
              if ( v48 == 1 )
              {
                __dmb(9u);
                dma_fence_release(_X0);
              }
              else if ( v48 <= 0 )
              {
                refcount_warn_saturate(_X0, 3);
              }
              kfree(v28);
              return v31;
            }
            else
            {
              if ( (synx_debug & 8) != 0 )
                printk(&unk_2A128, &unk_2A972, "synx_dma_array_fence_create", 541, v24, v28);
              return 0;
            }
          }
          else
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_2B2C1, &unk_29207, "synx_dma_array_fence_create", 517, v26, v27);
            _X0 = (unsigned int *)(v24 + 56);
            __asm { PRFM            #0x11, [X0] }
            do
              v46 = __ldxr(_X0);
            while ( __stlxr(v46 - 1, _X0) );
            if ( v46 == 1 )
            {
              __dmb(9u);
              dma_fence_release(_X0);
              return 4294967284LL;
            }
            else
            {
              if ( v46 <= 0 )
                refcount_warn_saturate(_X0, 3);
              return 4294967284LL;
            }
          }
        }
      }
      if ( (synx_debug & 1) != 0 )
        printk(&unk_282E6, &unk_29207, "synx_dma_array_fence_create", 502, v22, v23);
      v3 = 4294967235LL;
      if ( v9 )
        goto LABEL_33;
LABEL_44:
      kfree(v7);
      return (unsigned int)v3;
    }
    v9 = 0;
    while ( 1 )
    {
      v10 = *(_QWORD *)(*(_QWORD *)v3 + 8LL * (int)v9);
      if ( *(_UNKNOWN **)(v10 + 8) == &dma_fence_array_ops )
        break;
      if ( v10 )
      {
        _X0 = (unsigned int *)(v10 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v20 = __ldxr(_X0);
        while ( __stxr(v20 + 1, _X0) );
        if ( !v20 )
        {
          v14 = 2;
          goto LABEL_16;
        }
        if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
        {
          v14 = 1;
LABEL_16:
          refcount_warn_saturate(_X0, v14);
        }
      }
      v12 = (int)v9;
      if ( v4 <= 8LL * (int)v9 )
        goto LABEL_53;
      v13 = *(_DWORD *)(v3 + 8);
      ++v9;
      *(_QWORD *)(v7 + 8 * v12) = *(_QWORD *)(*(_QWORD *)v3 + 8 * v12);
      if ( v9 >= v13 )
        goto LABEL_55;
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_29E62, &unk_29207, "synx_dma_array_fence_create", 483, v5, v6);
    v3 = 0;
    if ( !v9 )
      goto LABEL_44;
LABEL_33:
    v32 = v9 - 1;
    a2 = 0xFFFFFFFFLL;
    while ( v4 > 8LL * (int)v32 )
    {
      v33 = v32;
      v34 = *(_QWORD *)(v7 + 8LL * (int)v32);
      if ( v34 )
      {
        _X0 = (unsigned int *)(v34 + 56);
        __asm { PRFM            #0x11, [X0] }
        do
          v37 = __ldxr(_X0);
        while ( __stlxr(v37 - 1, _X0) );
        if ( v37 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X0);
        }
        else if ( v37 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      v32 = v33 - 1;
      if ( !v33 )
        goto LABEL_44;
    }
LABEL_53:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v40 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &synx_dma_array_fence_create__alloc_tag;
    v4 = 8LL * *(unsigned int *)(v3 + 8);
    v7 = _kmalloc_noprof(v4, 3520);
    *(_QWORD *)(StatusReg + 80) = v40;
    result = 4294967274LL;
  }
  while ( v7 );
  return result;
}
