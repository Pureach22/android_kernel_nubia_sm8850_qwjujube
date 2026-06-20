__int64 __fastcall hwsched_handle_jobs_list(__int64 result, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  _QWORD *v7; // x22
  _QWORD *v8; // x1
  _QWORD *v10; // t2
  unsigned __int64 v11; // x9
  __int64 v12; // x8
  _QWORD *v14; // x19
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  unsigned __int64 v19; // x19
  int v20; // w20
  int v21; // w28
  __int64 v22; // x27
  int v23; // w8
  unsigned __int64 v24; // x26
  int v25; // w8
  int v26; // w8
  unsigned int v27; // w8
  unsigned int v28; // w10
  unsigned int v30; // w9
  int v32; // w8
  int v33; // w8
  unsigned __int64 v34; // x9
  __int64 v35; // x28
  unsigned int v36; // w19
  __int64 v37; // x0
  int v38; // w8
  int v39; // w0
  __int64 (__fastcall *v40)(__int64, unsigned __int64); // x8
  int v41; // w0
  __int64 v42; // x12
  int v43; // w8
  unsigned __int64 *v44; // x10
  unsigned __int64 **v45; // x1
  unsigned __int64 **v46; // x0
  __int64 v47; // x1
  __int64 v48; // x2
  __int64 v49; // x3
  __int64 v50; // x1
  unsigned __int64 v53; // x9
  unsigned __int64 v56; // x8
  unsigned int v58; // w8
  unsigned __int64 v61; // x9
  unsigned __int64 v64; // x8
  unsigned __int64 v67; // x9
  unsigned int v68; // w27
  unsigned int v69; // w19
  __int64 v70; // x1
  __int64 v71; // x2
  __int64 v72; // x3
  int v73; // w8
  unsigned int v74; // w8
  int v75; // w9
  int v76; // w8
  __int64 v78; // x1
  __int64 v79; // x2
  __int64 v80; // x3
  int v82; // w8
  unsigned __int64 v89; // x9
  int v91; // w8
  int v93; // w8
  unsigned __int64 *v94; // [xsp+8h] [xbp-58h]
  unsigned __int64 *v95; // [xsp+18h] [xbp-48h]
  int v96; // [xsp+24h] [xbp-3Ch]
  unsigned __int64 v97; // [xsp+28h] [xbp-38h]
  unsigned __int64 StatusReg; // [xsp+40h] [xbp-20h]
  __int64 v99; // [xsp+48h] [xbp-18h]
  unsigned int v100; // [xsp+54h] [xbp-Ch]
  _QWORD *v101; // [xsp+58h] [xbp-8h]

  if ( !a4 )
    return result;
  v4 = result;
  result = llist_reverse_order(a4);
  if ( !result )
    return result;
  v7 = (_QWORD *)result;
  v95 = (unsigned __int64 *)(v4 + 22768);
  StatusReg = _ReadStatusReg(SP_EL0);
  v100 = a2;
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = v7;
      v10 = v7;
      v7 = (_QWORD *)*v7;
      _X0 = v10[1];
      if ( !_X0 )
        goto LABEL_5;
      if ( (*(_QWORD *)(_X0 + 32) & 2) == 0 && (*(_QWORD *)(_X0 + 32) & 4) == 0 )
        break;
      __asm { PRFM            #0x11, [X0] }
      do
        v82 = __ldxr((unsigned int *)_X0);
      while ( __stlxr(v82 - 1, (unsigned int *)_X0) );
      if ( v82 == 1 )
      {
        __dmb(9u);
LABEL_16:
        v14 = v8;
        kgsl_context_destroy(_X0);
        goto LABEL_17;
      }
      if ( v82 <= 0 )
        goto LABEL_178;
LABEL_5:
      result = kmem_cache_free(jobs_cache_0, v8);
      if ( !v7 )
        return result;
    }
    v11 = *(unsigned int *)(_X0 + 4);
    v12 = 1LL << v11;
    _X10 = (unsigned __int64 *)(a3 + 8 * (v11 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v89 = __ldxr(_X10);
    while ( __stlxr(v89 | v12, _X10) );
    __dmb(0xBu);
    _X25 = v8[1];
    if ( (v89 & v12) != 0 )
    {
      if ( _X25 )
      {
        __asm { PRFM            #0x11, [X25] }
        do
          v91 = __ldxr((unsigned int *)_X25);
        while ( __stlxr(v91 - 1, (unsigned int *)_X25) );
        if ( v91 == 1 )
        {
          __dmb(9u);
          _X0 = _X25;
          goto LABEL_16;
        }
        if ( v91 > 0 )
          goto LABEL_5;
        _X0 = _X25;
LABEL_178:
        v14 = v8;
        refcount_warn_saturate(_X0, 3);
LABEL_17:
        v8 = v14;
        goto LABEL_5;
      }
      goto LABEL_5;
    }
    v101 = v8;
    v15 = raw_spin_lock(_X25 + 404);
    v19 = *(unsigned int *)(_X25 + 1432);
    if ( v19 != *(_DWORD *)(_X25 + 1436) )
      break;
    v20 = 0;
    v21 = 0;
LABEL_130:
    raw_spin_unlock(_X25 + 404);
LABEL_131:
    raw_spin_lock(_X25 + 404);
    v68 = v100;
    if ( !_X25 || (*(_QWORD *)(_X25 + 32) & 4) != 0 )
    {
LABEL_149:
      v15 = raw_spin_unlock(_X25 + 404);
    }
    else
    {
LABEL_133:
      v69 = *(_DWORD *)(_X25 + 1512);
      v15 = raw_spin_unlock(_X25 + 404);
      if ( v69 <= 0x7E )
        v15 = _wake_up(_X25 + 1440, 3, 0, 0);
    }
    v8 = v101;
    if ( v21 )
      v76 = v21;
    else
      v76 = v20;
    if ( v76 == -28 )
    {
      if ( v68 >= 0x11 )
        goto LABEL_184;
    }
    else
    {
      if ( !v76 || v76 == -2 )
      {
        _X0 = (unsigned int *)v101[1];
        if ( _X0 )
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v93 = __ldxr(_X0);
          while ( __stlxr(v93 - 1, _X0) );
          if ( v93 == 1 )
          {
            __dmb(9u);
            kgsl_context_destroy(_X0);
            v8 = v101;
          }
          else if ( v93 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
            v8 = v101;
          }
        }
        goto LABEL_5;
      }
      if ( v68 > 0x10 )
        goto LABEL_184;
    }
    result = llist_add_batch(v101);
    if ( !v7 )
      return result;
  }
  v20 = 0;
  v22 = _X25 + 408;
  v99 = a3;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v19 >= 0x80 )
        goto LABEL_184;
      v24 = *(_QWORD *)(v22 + 8 * v19);
      if ( !v24 )
      {
LABEL_128:
        v21 = 0;
        goto LABEL_129;
      }
      v25 = *(_DWORD *)(v24 + 16);
      if ( v25 <= 7 )
        break;
      if ( v25 == 8 )
      {
        if ( (*(_QWORD *)(v24 + 56) & 2) != 0 )
        {
LABEL_39:
          v26 = ((unsigned __int8)*(_DWORD *)(_X25 + 1432) + 1) & 0x7F;
          --*(_DWORD *)(_X25 + 1512);
          *(_DWORD *)(_X25 + 1432) = v26;
          retire_timestamp_only(v24);
          goto LABEL_24;
        }
        _X9 = (unsigned __int64 *)(v24 + 56);
        __asm { PRFM            #0x11, [X9] }
        do
          v56 = __ldxr(_X9);
        while ( __stlxr(v56 | 1, _X9) );
        __dmb(0xBu);
        if ( (v56 & 1) != 0 )
        {
LABEL_63:
          v24 = -11;
          goto LABEL_64;
        }
        if ( _X25 )
        {
          v27 = *(_DWORD *)_X25;
          if ( *(_DWORD *)_X25 )
          {
            do
            {
              __asm { PRFM            #0x11, [X25] }
              do
                v30 = __ldxr((unsigned int *)_X25);
              while ( v30 == v27 && __stxr(v27 + 1, (unsigned int *)_X25) );
              v28 = v27;
              if ( v30 == v27 )
                break;
              v28 = 0;
              v27 = v30;
            }
            while ( v30 );
          }
          else
          {
            v28 = 0;
          }
          if ( (((v28 + 1) | v28) & 0x80000000) != 0 )
            refcount_warn_saturate(_X25, 0);
        }
        _X0 = (unsigned int *)(v24 + 32);
        __asm { PRFM            #0x11, [X0] }
        do
          v58 = __ldxr(_X0);
        while ( __stxr(v58 + 1, _X0) );
        if ( v58 )
        {
          if ( (((v58 + 1) | v58) & 0x80000000) == 0 )
          {
LABEL_62:
            kgsl_sharedmem_bind_ranges(*(_QWORD *)(v24 + 64));
            goto LABEL_63;
          }
          v50 = 1;
        }
        else
        {
          v50 = 2;
        }
        refcount_warn_saturate(_X0, v50);
        goto LABEL_62;
      }
      if ( v25 != 16 )
        goto LABEL_46;
LABEL_23:
      v23 = ((unsigned __int8)*(_DWORD *)(_X25 + 1432) + 1) & 0x7F;
      --*(_DWORD *)(_X25 + 1512);
      *(_DWORD *)(_X25 + 1432) = v23;
LABEL_24:
      v15 = kgsl_drawobj_destroy(v24, v16, v17, v18);
      v19 = ((int)v19 + 1) & 0x7FLL;
      if ( v19 == *(_DWORD *)(_X25 + 1436) )
        goto LABEL_128;
    }
    if ( v25 == 2 )
    {
      if ( (*(_BYTE *)(v24 + 24) & 2) == 0
        || (kgsl_check_timestamp(*(_QWORD *)v24, *(_QWORD *)(v24 + 8), *(unsigned int *)(v24 + 120)) & 1) == 0 )
      {
        if ( (*(_QWORD *)(v24 + 56) & 1) == 0 )
          goto LABEL_63;
        goto LABEL_64;
      }
      _X8 = (unsigned __int64 *)(v24 + 56);
      __asm { PRFM            #0x11, [X8] }
      do
        v53 = __ldxr(_X8);
      while ( __stxr(v53 | 0x80, _X8) );
      if ( (*(_QWORD *)(v4 + 22496) & 0x10) != 0 )
      {
        retire_timestamp_only(v24);
        goto LABEL_64;
      }
      goto LABEL_39;
    }
    if ( v25 != 4 )
    {
      if ( v25 != 1 )
      {
LABEL_46:
        v24 = -22;
        goto LABEL_64;
      }
      if ( *(_DWORD *)(v24 + 160) >= 0x53u && *(_QWORD *)(v4 + 22832) )
      {
        LODWORD(v24) = -28;
LABEL_166:
        v21 = v24;
LABEL_129:
        a3 = v99;
        goto LABEL_130;
      }
      goto LABEL_64;
    }
    if ( !*(_DWORD *)(v24 + 72) )
      goto LABEL_23;
    if ( (*(_QWORD *)(v4 + 22496) & 0x10) == 0 || (*(_QWORD *)(v24 + 128) & 2) == 0 )
    {
      if ( !*(_QWORD *)(v24 + 120) )
      {
        *(_QWORD *)(v24 + 120) = jiffies + 1250LL;
        mod_timer(v24 + 80);
      }
      goto LABEL_63;
    }
LABEL_64:
    if ( v24 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_166;
    v32 = ((unsigned __int8)*(_DWORD *)(_X25 + 1432) + 1) & 0x7F;
    --*(_DWORD *)(_X25 + 1512);
    *(_DWORD *)(_X25 + 1432) = v32;
    raw_spin_unlock(_X25 + 404);
    v33 = *(_DWORD *)(v24 + 16);
    if ( (v33 & 1) != 0 || v33 == 2 && (*(_QWORD *)(v24 + 56) & 1) != 0 )
      v34 = v24;
    else
      v34 = 0;
    v35 = *(_QWORD *)(v24 + 8);
    v97 = v34;
    v36 = *(_DWORD *)(StatusReg + 148);
    v96 = *(_DWORD *)(StatusReg + 152);
    v37 = kmem_cache_alloc_noprof(obj_cache, 3264);
    if ( !v37 )
      break;
    v94 = (unsigned __int64 *)v37;
    rt_mutex_lock(v4 + 11088);
    if ( v36 >= 0x64 )
      sched_set_fifo(StatusReg);
    __dmb(9u);
    if ( *(_DWORD *)(v4 + 20412) || *(_DWORD *)(v4 + 24448) )
    {
      v21 = -16;
      goto LABEL_76;
    }
    if ( !v35 || (*(_QWORD *)(v35 + 32) & 2) != 0 )
    {
      v21 = -2;
      goto LABEL_76;
    }
    v38 = *(_DWORD *)(v4 + 22504);
    *(_DWORD *)(v4 + 22504) = v38 + 1;
    if ( !v38 && (*(_QWORD *)(v4 + 22496) & 1) == 0 )
    {
      v39 = adreno_active_count_get(v4);
      if ( v39 )
      {
        v21 = v39;
        --*(_DWORD *)(v4 + 22504);
        goto LABEL_76;
      }
      _X8 = (unsigned __int64 *)(v4 + 22496);
      __asm { PRFM            #0x11, [X8] }
      do
        v67 = __ldxr(_X8);
      while ( __stxr(v67 | 1, _X8) );
    }
    v40 = **(__int64 (__fastcall ***)(__int64, unsigned __int64))(v4 + 22784);
    if ( *((_DWORD *)v40 - 1) != -1013122788 )
      __break(0x8228u);
    v41 = v40(v4, v24);
    v42 = v4 + 20412;
    v43 = *(_DWORD *)(v4 + 22504);
    if ( v41 )
    {
      v21 = v41;
      if ( v43 == 1 )
      {
        adreno_active_count_put(v4);
        _X8 = (unsigned __int64 *)(v4 + 22496);
        __asm { PRFM            #0x11, [X8] }
        do
          v61 = __ldxr(_X8);
        while ( __stxr(v61 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        v42 = v4 + 20412;
      }
      --*(_DWORD *)(v42 + 2092);
    }
    else
    {
      v44 = v94;
      if ( v43 == 1 )
      {
        _X9 = (unsigned __int64 *)(v4 + 22496);
        __asm { PRFM            #0x11, [X9] }
        do
          v64 = __ldxr(_X9);
        while ( __stlxr(v64 | 2, _X9) );
        __dmb(0xBu);
        v44 = v94;
        if ( (v64 & 2) == 0 )
          *(_DWORD *)(v4 + 22800) = 0;
      }
      if ( (*(_BYTE *)(v24 + 16) & 1) != 0 )
      {
        if ( (*(_QWORD *)(v24 + 56) & 0x80) != 0 )
        {
          kmem_cache_free(obj_cache, v44);
          kgsl_drawobj_destroy(v24, v47, v48, v49);
          v21 = 0;
          goto LABEL_76;
        }
        if ( *(_DWORD *)(v24 + 160) >= 0x53u )
        {
          *(_QWORD *)(v4 + 22832) = v24;
          kref_get(v24 + 32);
          v44 = v94;
        }
      }
      v45 = *(unsigned __int64 ***)(v4 + 22776);
      *v44 = v24;
      v46 = (unsigned __int64 **)(v44 + 1);
      if ( v44 + 1 == v95 || v45 == v46 || *v45 != v95 )
      {
        _list_add_valid_or_report(v46, v45);
        v21 = 0;
      }
      else
      {
        v21 = 0;
        *(_QWORD *)(v4 + 22776) = v46;
        v44[1] = (unsigned __int64)v95;
        v44[2] = (unsigned __int64)v45;
        *v45 = (unsigned __int64 *)v46;
      }
    }
LABEL_76:
    if ( v36 >= 0x64 )
      sched_set_normal(StatusReg, (unsigned int)(v96 - 120));
    rt_mutex_unlock(v4 + 11088);
    if ( v21 )
    {
      kmem_cache_free(obj_cache, v94);
      if ( v21 != -2 )
        goto LABEL_138;
      kgsl_drawobj_destroy(v24, v70, v71, v72);
      goto LABEL_165;
    }
    if ( v97 )
      *(_DWORD *)(_X25 + 1544) = *(_DWORD *)(v24 + 20);
    ++v20;
    v15 = raw_spin_lock(_X25 + 404);
    v19 = *(unsigned int *)(_X25 + 1432);
    v21 = 0;
    a3 = v99;
    if ( v19 == *(_DWORD *)(_X25 + 1436) )
      goto LABEL_130;
  }
  v21 = -12;
LABEL_138:
  v15 = raw_spin_lock(_X25 + 404);
  if ( !_X25 || (*(_QWORD *)(_X25 + 32) & 2) != 0 || (*(_QWORD *)(_X25 + 32) & 4) != 0 )
  {
    raw_spin_unlock(_X25 + 404);
    kgsl_drawobj_destroy(v24, v78, v79, v80);
    v21 = -2;
LABEL_165:
    a3 = v99;
    goto LABEL_131;
  }
  v73 = *(_DWORD *)(_X25 + 1432);
  if ( v73 )
    v74 = v73 - 1;
  else
    v74 = 127;
  if ( v74 == *(_DWORD *)(_X25 + 1436) )
  {
    __break(0x800u);
    if ( v74 >= 0x80 )
      goto LABEL_184;
LABEL_146:
    *(_QWORD *)(v22 + 8LL * v74) = v24;
    v75 = *(_DWORD *)(_X25 + 1512);
    *(_DWORD *)(_X25 + 1432) = v74;
    *(_DWORD *)(_X25 + 1512) = v75 + 1;
    if ( (*(_BYTE *)(v24 + 16) & 1) != 0 )
      ++*(_DWORD *)(v24 + 164);
    raw_spin_unlock(_X25 + 404);
    raw_spin_lock(_X25 + 404);
    a3 = v99;
    v68 = v100;
    if ( (*(_QWORD *)(_X25 + 32) & 4) == 0 )
      goto LABEL_133;
    goto LABEL_149;
  }
  if ( v74 < 0x80 )
    goto LABEL_146;
LABEL_184:
  __break(0x5512u);
  return retire_timestamp_only(v15);
}
