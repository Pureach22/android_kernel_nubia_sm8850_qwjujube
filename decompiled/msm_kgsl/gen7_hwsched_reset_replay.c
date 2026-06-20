__int64 __fastcall gen7_hwsched_reset_replay(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  _QWORD *i; // x23
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x9
  __int64 guilty_context; // x0
  _QWORD *v11; // x21
  _QWORD *v12; // x21
  _QWORD *v13; // x26
  _QWORD *v14; // t1
  int v15; // w0
  _BOOL4 v16; // w24
  int v18; // w8
  __int64 next; // x0
  __int64 v20; // x20
  _QWORD *v21; // x28
  __int64 v22; // x21
  _QWORD *v23; // x27
  __int64 v24; // x23
  char v25; // w0
  unsigned int v26; // w8
  unsigned int v27; // w9
  unsigned int v28; // w8
  unsigned int v29; // w9
  unsigned int v30; // w8
  _QWORD *v31; // x1
  _QWORD **v32; // x0
  _QWORD *v33; // x21
  char v34; // w27
  _QWORD *v35; // x8
  _QWORD *v36; // x26
  unsigned int v38; // w23
  __int64 v39; // x28
  unsigned int v40; // w8
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned int v43; // w8
  unsigned int v44; // w25
  unsigned int v46; // w9
  int v47; // w0
  _BOOL4 v48; // w8
  int v50; // w8
  _QWORD **v51; // x20
  _QWORD *v52; // x21
  _QWORD *v53; // x22
  _QWORD *v54; // x25
  int v57; // w8
  unsigned __int64 v65; // x10
  _QWORD **v66; // x10
  unsigned __int64 v67; // x11
  unsigned __int64 *v68; // x8
  _QWORD *v69; // [xsp+0h] [xbp-20h] BYREF
  _QWORD **v70; // [xsp+8h] [xbp-18h]
  int v71; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v72; // [xsp+18h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen7_gmu(a1);
  v3 = to_gen7_hwsched_hfi(a1);
  raw_read_lock(v3 + 4);
  for ( i = *(_QWORD **)(v3 + 16); i != (_QWORD *)(v3 + 16); i = (_QWORD *)*i )
  {
    if ( *((unsigned __int8 *)i - 112) == 129 )
      complete(i - 4);
  }
  raw_read_unlock(v3 + 4);
  if ( (*(_QWORD *)(v2 + 1096) & 2) == 0 )
    goto LABEL_123;
  gen7_disable_gpu_irq(a1);
  gen7_gmu_irq_disable(a1);
  gen7_hwsched_hfi_stop(a1);
  gen7_gmu_suspend(a1, 1);
  adreno_hwsched_reset_hfi_mem(a1);
  adreno_hwsched_unregister_contexts(a1);
  if ( *(_BYTE *)(a1 + 20832) == 1 )
  {
    v5 = *(_QWORD *)(a1 + 20824);
    if ( v5 )
    {
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20848) == 1 )
  {
    v6 = *(_QWORD *)(a1 + 20840);
    if ( v6 )
    {
      if ( v6 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  if ( *(_BYTE *)(a1 + 20864) == 1 )
  {
    v7 = *(_QWORD *)(a1 + 20856);
    if ( v7 )
    {
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        llcc_slice_deactivate();
    }
  }
  _X8 = (unsigned __int64 *)(v2 + 1096);
  __asm { PRFM            #0x11, [X8] }
  do
    v65 = __ldxr(_X8);
  while ( __stxr(v65 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  raw_spin_lock(a1 + 23152);
  *(_DWORD *)(a1 + 23156) = 0;
  raw_spin_unlock(a1 + 23152);
  gmu_core_mark_for_coldboot(a1);
  if ( (unsigned int)gen7_hwsched_boot(a1) )
    goto LABEL_127;
  adreno_hwsched_replay(a1);
  guilty_context = get_guilty_context(a1);
  if ( guilty_context )
  {
    _X20 = guilty_context;
    do
    {
      v11 = *(_QWORD **)(_X20 + 2056);
      if ( v11 == (_QWORD *)(_X20 + 2056) )
      {
        v16 = 1;
      }
      else
      {
        do
        {
          v14 = (_QWORD *)*v11;
          v12 = v11 - 8;
          v13 = v14;
          v15 = gen7_send_hw_fence_hfi_wait_ack(a1, v12, 1);
          v16 = v15 == 0;
          if ( v15 )
            break;
          adreno_hwsched_remove_hw_fence_entry(a1, v12);
          v11 = v13;
        }
        while ( v13 != (_QWORD *)(_X20 + 2056) );
      }
      __asm { PRFM            #0x11, [X20] }
      do
      {
        v18 = __ldxr((unsigned int *)_X20);
        v8 = (unsigned int)(v18 - 1);
      }
      while ( __stlxr(v8, (unsigned int *)_X20) );
      if ( v18 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X20);
        if ( !v16 )
          goto LABEL_127;
      }
      else if ( v18 <= 0 )
      {
        refcount_warn_saturate(_X20, 3);
        if ( !v16 )
          goto LABEL_127;
      }
      else if ( !v16 )
      {
        goto LABEL_127;
      }
      _X20 = get_guilty_context(a1);
    }
    while ( _X20 );
  }
  v69 = &v69;
  v70 = &v69;
  raw_read_lock(a1 + 11208);
  v71 = 0;
  next = idr_get_next(a1 + 11184, &v71);
  if ( next )
  {
    v20 = next;
    while ( 1 )
    {
      raw_spin_lock(v20 + 404);
      v21 = *(_QWORD **)(v20 + 2072);
      if ( v21 != (_QWORD *)(v20 + 2072) )
        break;
LABEL_42:
      raw_spin_unlock(v20 + 404);
      ++v71;
      v20 = idr_get_next(a1 + 11184, &v71);
      if ( !v20 )
        goto LABEL_66;
    }
    while ( 1 )
    {
      v22 = *(v21 - 1);
      v23 = (_QWORD *)*v21;
      v24 = *(_QWORD *)(v22 + 1648);
      v25 = kgsl_check_timestamp(a1, v22, *((unsigned int *)v21 - 10));
      v26 = *(_DWORD *)(v24 + 12);
      v27 = *((_DWORD *)v21 - 10);
      if ( v26 != v27 && (v26 <= v27 || ((v26 - v27) & 0x80000000) != 0) )
      {
        v28 = v26 ^ 0x80000000;
        v29 = v27 ^ 0x80000000;
        _CF = v28 >= v29;
        v30 = v28 - v29;
        if ( v30 == 0 || !_CF || v30 > 0x80000000 )
          break;
      }
      adreno_hwsched_remove_hw_fence_entry(a1, v21 - 8);
LABEL_46:
      v21 = v23;
      if ( v23 == (_QWORD *)(v20 + 2072) )
        goto LABEL_42;
    }
    if ( (v25 & 1) != 0 )
    {
      if ( !v22 || (*(_BYTE *)(v22 + 288) & 1) == 0 )
        goto LABEL_60;
    }
    else if ( !v22 )
    {
      goto LABEL_60;
    }
    if ( (*(_QWORD *)(v22 + 32) & 2) == 0 && (*(_QWORD *)(v22 + 32) & 4) == 0 )
    {
LABEL_61:
      v31 = v70;
      v32 = (_QWORD **)(v21 + 2);
      if ( v21 + 2 == &v69 || v70 == v32 || *v70 != &v69 )
      {
        _list_add_valid_or_report(v32, v70);
      }
      else
      {
        v70 = (_QWORD **)(v21 + 2);
        v21[2] = &v69;
        v21[3] = v31;
        *v31 = v32;
      }
      goto LABEL_46;
    }
LABEL_60:
    *(v21 - 4) |= 1uLL;
    goto LABEL_61;
  }
LABEL_66:
  raw_read_unlock(a1 + 11208);
  v33 = v69;
  if ( v69 == &v69 )
    goto LABEL_110;
  v34 = 0;
  do
  {
    v36 = (_QWORD *)*v33;
    v35 = (_QWORD *)v33[1];
    _X20 = *(v33 - 3);
    v38 = *((_DWORD *)v33 - 14);
    v39 = *(_QWORD *)(_X20 + 1648);
    if ( (_QWORD *)*v35 == v33 && (_QWORD *)v36[1] == v33 )
    {
      v36[1] = v35;
      *v35 = v36;
    }
    else
    {
      _list_del_entry_valid_or_report(v33);
    }
    *v33 = v33;
    v33[1] = v33;
    if ( (*(_BYTE *)(v33 - 6) & 1) != 0 )
    {
      v40 = *(_DWORD *)(v39 + 12);
      if ( v38 != v40 )
      {
        if ( v38 > v40 && ((v38 - v40) & 0x80000000) == 0
          || (v41 = v40 ^ 0x80000000, _CF = (v38 ^ 0x80000000) >= v41, v42 = (v38 ^ 0x80000000) - v41, v42 != 0 && _CF)
          && v42 <= 0x80000000 )
        {
          if ( _X20 )
          {
            v43 = *(_DWORD *)_X20;
            if ( *(_DWORD *)_X20 )
            {
              do
              {
                __asm { PRFM            #0x11, [X20] }
                do
                  v46 = __ldxr((unsigned int *)_X20);
                while ( v46 == v43 && __stxr(v43 + 1, (unsigned int *)_X20) );
                v44 = v43;
                if ( v46 == v43 )
                  break;
                v44 = 0;
                v43 = v46;
              }
              while ( v46 );
            }
            else
            {
              v44 = 0;
            }
            if ( (((v44 + 1) | v44) & 0x80000000) != 0 )
            {
              refcount_warn_saturate(_X20, 0);
              if ( !v44 )
                goto LABEL_92;
LABEL_91:
              v34 = 1;
              goto LABEL_92;
            }
            if ( v44 )
              goto LABEL_91;
          }
        }
      }
    }
LABEL_92:
    v47 = gen7_send_hw_fence_hfi_wait_ack(a1, v33 - 10, 0);
    v48 = v47 == 0;
    if ( !v47 && (v34 & 1) != 0 )
    {
      *(_DWORD *)(v39 + 12) = v38;
      if ( _X20 )
      {
        __asm { PRFM            #0x11, [X20] }
        do
          v50 = __ldxr((unsigned int *)_X20);
        while ( __stlxr(v50 - 1, (unsigned int *)_X20) );
        if ( v50 == 1 )
        {
          __dmb(9u);
          kgsl_context_destroy(_X20);
        }
        else if ( v50 <= 0 )
        {
          refcount_warn_saturate(_X20, 3);
        }
        v34 = 0;
        v48 = 1;
        v47 = 0;
      }
      else
      {
        v34 = 0;
        v48 = 1;
      }
    }
    if ( !v48 )
      break;
    v33 = v36;
  }
  while ( v36 != &v69 );
  if ( v47 )
  {
    v8 = (unsigned __int64)v69;
    v66 = &v69;
    if ( v69 != &v69 )
      goto LABEL_130;
    goto LABEL_127;
  }
LABEL_110:
  v51 = (_QWORD **)(to_gen7_hwsched_hfi(a1) + 208);
  v52 = *v51;
  if ( *v51 != v51 )
  {
    while ( 1 )
    {
      v53 = v52 - 8;
      v54 = (_QWORD *)*v52;
      if ( (unsigned int)gen7_send_hw_fence_hfi_wait_ack(a1, v52 - 8, 1) )
        break;
      _X21 = (unsigned int *)*(v52 - 1);
      adreno_hwsched_remove_hw_fence_entry(a1, v53);
      if ( _X21 )
      {
        __asm { PRFM            #0x11, [X21] }
        do
          v57 = __ldxr(_X21);
        while ( __stlxr(v57 - 1, _X21) );
        if ( v57 == 1 )
        {
          __dmb(9u);
          kgsl_context_destroy(_X21);
        }
        else if ( v57 <= 0 )
        {
          refcount_warn_saturate(_X21, 3);
        }
      }
      v52 = v54;
      if ( v54 == v51 )
        goto LABEL_122;
    }
    while ( 1 )
    {
LABEL_127:
      __break(0x800u);
LABEL_128:
      _list_del_entry_valid_or_report(v8);
      while ( 1 )
      {
        *(_QWORD *)v8 = v8;
        *(_QWORD *)(v8 + 8) = v8;
        v8 = v67;
        if ( (_QWORD **)v67 == v66 )
          break;
LABEL_130:
        v67 = *(_QWORD *)v8;
        v68 = *(unsigned __int64 **)(v8 + 8);
        if ( *v68 != v8 || *(_QWORD *)(v67 + 8) != v8 )
          goto LABEL_128;
        *(_QWORD *)(v67 + 8) = v68;
        *v68 = v67;
      }
    }
  }
LABEL_122:
  if ( (unsigned int)gen7_hwsched_disable_hw_fence_throttle(a1) )
    goto LABEL_127;
LABEL_123:
  _ReadStatusReg(SP_EL0);
  return 0;
}
