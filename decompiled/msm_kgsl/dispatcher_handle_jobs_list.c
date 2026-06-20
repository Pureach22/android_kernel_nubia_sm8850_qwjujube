__int64 __fastcall dispatcher_handle_jobs_list(__int64 result, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x25
  __int64 v7; // x26
  _QWORD *v8; // x22
  _DWORD *v9; // x23
  _QWORD *v10; // x1
  _QWORD *v12; // t2
  unsigned __int64 v13; // x9
  __int64 v14; // x8
  _QWORD *v15; // x21
  int v17; // w8
  unsigned __int64 v24; // x9
  __int64 v25; // x23
  __int64 v26; // x21
  unsigned int *v27; // x8
  unsigned int v28; // w27
  __int64 v29; // x26
  unsigned __int64 next_drawobj; // x0
  unsigned __int64 v31; // x25
  int v32; // w8
  int v33; // w26
  int v34; // w0
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x3
  int v38; // w26
  int v39; // w8
  unsigned int v40; // w8
  int v41; // w9
  __int64 v42; // x0
  unsigned int v43; // w21
  unsigned int v44; // w25
  unsigned int v45; // w8
  int v49; // w8
  __int64 v50; // [xsp+8h] [xbp-38h]
  __int64 v51; // [xsp+10h] [xbp-30h]
  __int64 v52; // [xsp+18h] [xbp-28h]
  unsigned int v53; // [xsp+24h] [xbp-1Ch]
  __int64 v54; // [xsp+28h] [xbp-18h]
  _DWORD *v55; // [xsp+30h] [xbp-10h]

  if ( !a4 )
    return result;
  v4 = result;
  result = llist_reverse_order(a4);
  if ( !result )
    return result;
  v7 = v4 + 8LL * a2;
  v8 = (_QWORD *)result;
  v9 = (_DWORD *)(v4 + 20412);
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    while ( 1 )
    {
      v10 = v8;
      v12 = v8;
      v8 = (_QWORD *)*v8;
      _X0 = v12[1];
      if ( !_X0 )
        goto LABEL_17;
      if ( (*(_QWORD *)(_X0 + 32) & 2) != 0 || (*(_QWORD *)(_X0 + 32) & 4) != 0 )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v17 = __ldxr((unsigned int *)_X0);
        while ( __stlxr(v17 - 1, (unsigned int *)_X0) );
        if ( v17 != 1 )
        {
LABEL_16:
          if ( v17 > 0 )
            goto LABEL_17;
          v15 = v10;
          refcount_warn_saturate(_X0, 3);
          goto LABEL_13;
        }
LABEL_12:
        __dmb(9u);
        v15 = v10;
        kgsl_context_destroy(_X0);
LABEL_13:
        v10 = v15;
        goto LABEL_17;
      }
      v13 = *(unsigned int *)(_X0 + 4);
      v14 = 1LL << v13;
      _X10 = (unsigned __int64 *)(a3 + 8 * (v13 >> 6));
      __asm { PRFM            #0x11, [X10] }
      do
        v24 = __ldxr(_X10);
      while ( __stlxr(v24 | v14, _X10) );
      __dmb(0xBu);
      if ( (v24 & v14) != 0 )
      {
        _X0 = v10[1];
        if ( !_X0 )
          goto LABEL_17;
        __asm { PRFM            #0x11, [X0] }
        do
          v17 = __ldxr((unsigned int *)_X0);
        while ( __stlxr(v17 - 1, (unsigned int *)_X0) );
        if ( v17 != 1 )
          goto LABEL_16;
        goto LABEL_12;
      }
      __dmb(9u);
      if ( !v9[1009] )
      {
        __dmb(9u);
        if ( !*v9 )
          break;
      }
      if ( a2 >= 0x11 )
        goto LABEL_88;
LABEL_25:
      _X0 = (__int64)v10;
LABEL_26:
      result = llist_add_batch(_X0);
      if ( !v8 )
        return result;
    }
    v55 = v9;
    v25 = v10[1];
    v26 = *(_QWORD *)(v25 + 1536);
    v27 = (unsigned int *)&dispatcher_q_inflight_lo;
    if ( *(int *)(v26 + 1244) <= 1 )
      v27 = (unsigned int *)&dispatcher_q_inflight_hi;
    v51 = (__int64)v10;
    v53 = *v27;
    if ( *(_DWORD *)(v26 + 1232) >= *v27 )
    {
      raw_spin_lock(v25 + 404);
      process_drawqueue_get_next_drawobj(v25);
      raw_spin_unlock(v25 + 404);
LABEL_41:
      _X0 = v51;
      v9 = v55;
      if ( a2 > 0x10 )
        goto LABEL_88;
      goto LABEL_26;
    }
    v50 = v7;
    v52 = v4;
    if ( context_drawobj_burst )
      break;
    v28 = 0;
LABEL_44:
    v38 = 0;
LABEL_61:
    v54 = v25 + 404;
    raw_spin_lock(v25 + 404);
    if ( v25 )
    {
LABEL_62:
      if ( (*(_QWORD *)(v25 + 32) & 4) == 0 )
      {
        v43 = *(_DWORD *)(v25 + 1512);
        v44 = context_drawqueue_size;
        _X0 = raw_spin_unlock(v54);
        if ( v43 >= v44 )
          goto LABEL_67;
        goto LABEL_66;
      }
    }
    raw_spin_unlock(v54);
LABEL_66:
    _X0 = _wake_up(v25 + 1440, 3, 0, 0);
LABEL_67:
    v4 = v52;
    if ( v38 )
      v45 = v38;
    else
      v45 = v28;
    v7 = v50;
    if ( v45 == -16 )
      goto LABEL_41;
    v10 = (_QWORD *)v51;
    v9 = v55;
    if ( v45 && v45 != -2 )
    {
      if ( a2 > 0x10 )
        goto LABEL_88;
      goto LABEL_25;
    }
    _X0 = *(unsigned int **)(v51 + 8);
    if ( _X0 )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v49 = __ldxr(_X0);
      while ( __stlxr(v49 - 1, _X0) );
      if ( v49 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X0);
        v10 = (_QWORD *)v51;
      }
      else if ( v49 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
        v10 = (_QWORD *)v51;
      }
    }
LABEL_17:
    result = kmem_cache_free(jobs_cache, v10);
    if ( !v8 )
      return result;
  }
  v28 = 0;
  v29 = v25 + 404;
  v54 = v25 + 404;
  while ( 1 )
  {
    if ( *(_DWORD *)(v26 + 1232) >= v53 )
      goto LABEL_44;
    __dmb(9u);
    if ( v55[1009] )
      goto LABEL_44;
    raw_spin_lock(v29);
    next_drawobj = process_drawqueue_get_next_drawobj(v25);
    v31 = next_drawobj;
    if ( !next_drawobj || next_drawobj >= 0xFFFFFFFFFFFFF001LL )
    {
      v42 = v29;
      if ( v31 <= 0xFFFFFFFFFFFFF000LL )
        v38 = 0;
      else
        v38 = v31;
      raw_spin_unlock(v42);
      goto LABEL_61;
    }
    v32 = ((unsigned __int8)*(_DWORD *)(v25 + 1432) + 1) & 0x7F;
    --*(_DWORD *)(v25 + 1512);
    *(_DWORD *)(v25 + 1432) = v32;
    raw_spin_unlock(v29);
    v33 = *(_DWORD *)(v31 + 20);
    v34 = sendcmd(v52, v31);
    if ( v34 )
      break;
    ++v28;
    *(_DWORD *)(v25 + 1544) = v33;
    v29 = v25 + 404;
    if ( v28 >= context_drawobj_burst )
      goto LABEL_44;
  }
  if ( v34 == -2 )
  {
LABEL_60:
    kgsl_drawobj_destroy(v31, v35, v36, v37);
    v38 = -2;
    goto LABEL_61;
  }
  v38 = v34;
  _X0 = raw_spin_lock(v54);
  if ( !v25 || (*(_QWORD *)(v25 + 32) & 2) != 0 || (*(_QWORD *)(v25 + 32) & 4) != 0 )
  {
    raw_spin_unlock(v54);
    goto LABEL_60;
  }
  v39 = *(_DWORD *)(v25 + 1432);
  if ( v39 )
    v40 = v39 - 1;
  else
    v40 = 127;
  if ( v40 != *(_DWORD *)(v25 + 1436) )
  {
    if ( v40 >= 0x80 )
      goto LABEL_88;
    goto LABEL_54;
  }
  __break(0x800u);
  if ( v40 < 0x80 )
  {
LABEL_54:
    *(_QWORD *)(v25 + 8LL * v40 + 408) = v31;
    v41 = *(_DWORD *)(v25 + 1512);
    *(_DWORD *)(v25 + 1432) = v40;
    *(_DWORD *)(v25 + 1512) = v41 + 1;
    ++*(_DWORD *)(v31 + 164);
    raw_spin_unlock(v54);
    raw_spin_lock(v54);
    goto LABEL_62;
  }
LABEL_88:
  __break(0x5512u);
  return process_drawqueue_get_next_drawobj(_X0);
}
