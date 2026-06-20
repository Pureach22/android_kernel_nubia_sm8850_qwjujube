__int64 __fastcall adreno_hwsched_queue_cmds(__int64 *a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int *a5)
{
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x24
  __int64 v8; // x9
  _QWORD *v9; // x12
  unsigned int i; // w10
  __int64 result; // x0
  unsigned int v15; // w27
  __int64 v16; // x20
  __int64 v17; // x0
  unsigned int v18; // w8
  unsigned int v19; // w22
  __int64 v20; // x22
  __int64 j; // x23
  bool v22; // w28
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x0
  unsigned int v29; // w22
  __int64 v31; // x8
  __int64 v32; // x23
  __int64 v33; // x28
  unsigned int v34; // w19
  __int64 v35; // x1
  int v36; // w9
  unsigned int v37; // w8
  unsigned int *v38; // x10
  unsigned int v39; // w8
  unsigned int v40; // w9
  unsigned int *v41; // x8
  unsigned int v42; // w9
  unsigned int v43; // w9
  unsigned int v44; // w9
  unsigned int v45; // w9
  bool v46; // cc
  unsigned int v47; // w10
  unsigned int v48; // w9
  unsigned int v49; // w10
  unsigned __int64 v50; // x9
  __int64 v51; // x10
  unsigned int v52; // w8
  unsigned int v53; // w9
  unsigned int v54; // w22
  __int64 v55; // x27
  char v56; // w0
  char v57; // w9
  unsigned __int64 v63; // x11
  __int64 v64; // x10
  unsigned int v65; // w9
  unsigned int v66; // w9
  unsigned int v67; // w9
  __int64 v68; // x19
  __int64 v69; // x1
  __int64 v70; // x2
  __int64 v71; // x3
  unsigned __int64 StatusReg; // x22
  __int64 v73; // x23
  __int64 v74; // x0
  unsigned __int64 v77; // x8
  unsigned int v78; // [xsp+Ch] [xbp-34h]
  _QWORD v79[6]; // [xsp+10h] [xbp-30h] BYREF

  v79[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 - 127 < 0xFFFFFF82 )
  {
LABEL_8:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v5 = *a1;
  v6 = 0;
  v7 = a4;
  do
  {
    v8 = *(_QWORD *)(a3 + 8 * v6);
    if ( (*(_BYTE *)(v8 + 16) & 1) != 0 )
    {
      v9 = *(_QWORD **)(v8 + 88);
      for ( i = *(_DWORD *)(v8 + 160); v9 != (_QWORD *)(v8 + 88); v9 = (_QWORD *)*v9 )
        *(_DWORD *)(v8 + 160) = ++i;
      if ( i > 0x7D0 )
        goto LABEL_8;
    }
    ++v6;
  }
  while ( v6 != a4 );
  if ( !a2 || (*(_QWORD *)(a2 + 32) & 4) != 0 )
  {
    result = 4294967261LL;
    goto LABEL_21;
  }
  if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
  {
    result = 4294967294LL;
    goto LABEL_21;
  }
  v15 = a4;
  result = adreno_verify_cmdobj(a1, a2, a3, a4);
  if ( !(_DWORD)result )
  {
    wait_for_completion(v5 + 8720);
    v16 = kmem_cache_alloc_noprof(jobs_cache_0, 3264);
    if ( !v16 )
      goto LABEL_113;
    while ( 1 )
    {
      *(_QWORD *)(v16 + 8) = a2;
      raw_spin_lock(a2 + 404);
      v17 = a2;
      if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
      {
LABEL_44:
        v34 = -35;
LABEL_92:
        raw_spin_unlock(v17 + 404);
        kmem_cache_free(jobs_cache_0, v16);
        result = v34;
        break;
      }
      if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
        goto LABEL_91;
      v18 = v15;
      if ( *(_DWORD *)(a2 + 1512) + v15 < 0x7F )
        goto LABEL_39;
      raw_spin_unlock(a2 + 404);
      raw_spin_lock(a2 + 404);
      if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
      {
        raw_spin_unlock(a2 + 404);
      }
      else
      {
        v19 = *(_DWORD *)(a2 + 1512) + v15;
        raw_spin_unlock(a2 + 404);
        if ( v19 < 0x7F )
        {
          LODWORD(v20) = 2500;
          goto LABEL_36;
        }
      }
      memset(v79, 0, 40);
      init_wait_entry(v79, 0);
      for ( j = 2500; ; j = schedule_timeout(v28, v23, v24, v25, v26, v27) )
      {
        v20 = prepare_to_wait_event(a2 + 1440, v79, 1);
        raw_spin_lock(a2 + 404);
        v22 = (*(_QWORD *)(a2 + 32) & 4) == 0 && *(_DWORD *)(a2 + 1512) + v15 < 0x7F;
        raw_spin_unlock(a2 + 404);
        v28 = v22 && j == 0 ? 1LL : j;
        if ( v22 || !v28 )
          break;
        if ( v20 )
          goto LABEL_36;
      }
      LODWORD(v20) = v28;
      finish_wait(a2 + 1440, v79);
LABEL_36:
      raw_spin_lock(a2 + 404);
      if ( (int)v20 < 1 )
      {
        v17 = a2;
        if ( (_DWORD)v20 )
          v34 = v20;
        else
          v34 = -110;
        goto LABEL_92;
      }
      v17 = a2;
      if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
        goto LABEL_44;
      v18 = v15;
      if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
      {
LABEL_91:
        v34 = -2;
        goto LABEL_92;
      }
LABEL_39:
      v29 = *a5;
      _ZF = v18 == 1;
      v31 = a3;
      if ( (!_ZF || *(_DWORD *)(*(_QWORD *)a3 + 16LL) != 4) && (*(_BYTE *)(v17 + 200) & 0x80) != 0 )
      {
        if ( (v65 = *(_DWORD *)(v17 + 392), v65 == v29)
          || v65 > v29 && ((v65 - v29) & 0x80000000) == 0
          || (v66 = v65 ^ 0x80000000, _CF = v66 >= (v29 ^ 0x80000000), v67 = v66 - (v29 ^ 0x80000000), v67 != 0 && _CF)
          && v67 <= 0x80000000 )
        {
LABEL_99:
          raw_spin_unlock(v17 + 404);
          kmem_cache_free(jobs_cache_0, v16);
          result = 4294967262LL;
          break;
        }
      }
      v32 = 0;
      v15 = v29 ^ 0x80000000;
      v33 = v17 + 408;
      v78 = *a5;
      do
      {
        v35 = *(_QWORD *)(v31 + 8 * v32);
        v36 = *(_DWORD *)(v35 + 16);
        if ( v36 > 3 )
        {
          if ( v36 == 4 )
          {
            *a5 = 0;
LABEL_46:
            *(_DWORD *)(v35 + 20) = 0;
            goto LABEL_47;
          }
          if ( v36 != 8 )
          {
            if ( v36 != 16 )
              goto LABEL_110;
            goto LABEL_46;
          }
          v40 = *(_DWORD *)(v17 + 392);
          v41 = a5;
          if ( (*(_BYTE *)(v17 + 200) & 0x80) != 0 )
          {
            if ( v40 == v29 || v40 > v29 && ((v40 - v29) & 0x80000000) == 0 )
              goto LABEL_99;
            v45 = v40 ^ 0x80000000;
            v47 = v45 - v15;
            v46 = v45 > v15;
            v42 = v29;
            if ( v46 )
            {
              v42 = v29;
              if ( v47 < 0x80000001 )
                goto LABEL_99;
            }
          }
          else
          {
            v42 = v40 + 1;
          }
          *(_DWORD *)(v17 + 392) = v42;
          *a5 = v42;
          *(_DWORD *)(v35 + 20) = v42;
          goto LABEL_68;
        }
        if ( v36 == 1 )
        {
          v43 = *(_DWORD *)(v17 + 392);
          v41 = a5;
          if ( (*(_BYTE *)(v17 + 200) & 0x80) != 0 )
          {
            if ( v43 == v29 || v43 > v29 && ((v43 - v29) & 0x80000000) == 0 )
              goto LABEL_99;
            v48 = v43 ^ 0x80000000;
            v49 = v48 - v15;
            v46 = v48 > v15;
            v44 = v29;
            if ( v46 )
            {
              v44 = v29;
              if ( v49 < 0x80000001 )
                goto LABEL_99;
            }
          }
          else
          {
            v44 = v43 + 1;
          }
          *(_DWORD *)(v17 + 392) = v44;
          *a5 = v44;
          *(_DWORD *)(v35 + 20) = v44;
          v50 = *(unsigned int *)(v17 + 1432);
          v51 = *(unsigned int *)(v17 + 1436);
          while ( v50 != v51 )
          {
            if ( v50 >= 0x80 )
              goto LABEL_112;
            v64 = *(_QWORD *)(v33 + 8 * v50);
            if ( *(_DWORD *)(v64 + 16) == 2 )
            {
              _X10 = (unsigned __int64 *)(v64 + 56);
              __asm { PRFM            #0x11, [X10] }
              do
                v63 = __ldxr(_X10);
              while ( __stxr(v63 | 1, _X10) );
            }
            v51 = *(unsigned int *)(v17 + 1436);
            v50 = ((_BYTE)v50 + 1) & 0x7F;
          }
LABEL_68:
          *(_DWORD *)(v17 + 1528) = *v41;
          goto LABEL_47;
        }
        if ( v36 != 2 )
        {
LABEL_110:
          raw_spin_unlock(v17 + 404);
          kmem_cache_free(jobs_cache_0, v16);
          result = 4294967274LL;
          goto LABEL_21;
        }
        v37 = *(_DWORD *)(v17 + 392);
        v38 = a5;
        if ( (*(_BYTE *)(v17 + 200) & 0x80) != 0 )
        {
          if ( v37 == v29 || v37 > v29 && ((v37 - v29) & 0x80000000) == 0 )
            goto LABEL_99;
          v52 = v37 ^ 0x80000000;
          v53 = v52 - v15;
          v46 = v52 > v15;
          v39 = v29;
          if ( v46 )
          {
            v39 = v29;
            if ( v53 < 0x80000001 )
              goto LABEL_99;
          }
        }
        else
        {
          v39 = v37 + 1;
        }
        *(_DWORD *)(v17 + 392) = v39;
        *a5 = v39;
        *(_DWORD *)(v35 + 20) = v39;
        if ( !*(_DWORD *)(v17 + 1512) )
        {
          v54 = v15;
          v55 = v35;
          v56 = kgsl_check_timestamp(*(_QWORD *)v35, *(_QWORD *)(v35 + 8), *(unsigned int *)(v17 + 1528));
          v35 = v55;
          v15 = v54;
          v29 = v78;
          v38 = a5;
          v57 = v56;
          v17 = a2;
          if ( (v57 & 1) != 0 )
          {
            v68 = v35;
            retire_timestamp_only(v35);
            kgsl_drawobj_destroy(v68, v69, v70, v71);
            raw_spin_unlock(a2 + 404);
            kmem_cache_free(jobs_cache_0, v16);
            result = 0;
            goto LABEL_21;
          }
        }
        *(_DWORD *)(v35 + 120) = *(_DWORD *)(v17 + 1528);
        *(_DWORD *)(v17 + 1528) = *v38;
LABEL_47:
        queue_drawobj_0();
        ++v32;
        v17 = a2;
        v31 = a3;
      }
      while ( v32 != v7 );
      adreno_track_context(v5, 0, (_QWORD *)a2);
      raw_spin_unlock(a2 + 404);
      if ( !kref_get_unless_zero((unsigned int *)a2) )
      {
        kmem_cache_free(jobs_cache_0, v16);
        goto LABEL_114;
      }
      trace_dispatch_queue_context_0(a2);
      if ( *(_DWORD *)(a2 + 8) < 0x11u )
      {
        llist_add_batch(v16);
        adreno_hwsched_issuecmds(v5);
LABEL_114:
        _X9 = (unsigned __int64 *)(a2 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v77 = __ldxr(_X9);
        while ( __stlxr(v77 & 0xFFFFFFFFFFFEFFFFLL, _X9) );
        __dmb(0xBu);
        if ( (v77 & 0x10000) != 0 )
          result = 4294967225LL;
        else
          result = 0;
        break;
      }
LABEL_112:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v73 = *(_QWORD *)(StatusReg + 80);
      v74 = jobs_cache_0;
      *(_QWORD *)(StatusReg + 80) = &adreno_hwsched_queue_cmds__alloc_tag;
      v16 = kmem_cache_alloc_noprof(v74, 3264);
      *(_QWORD *)(StatusReg + 80) = v73;
      if ( !v16 )
      {
LABEL_113:
        result = 4294967284LL;
        break;
      }
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
