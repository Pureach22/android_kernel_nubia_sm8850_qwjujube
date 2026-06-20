__int64 __fastcall adreno_dispatcher_queue_cmds(__int64 *a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int *a5)
{
  __int64 v5; // x27
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v11; // x26
  __int64 v12; // x19
  __int64 v13; // x0
  unsigned int v14; // w8
  __int64 v15; // x22
  bool v16; // w28
  unsigned int v17; // w21
  __int64 v18; // x23
  bool v19; // w28
  __int64 v20; // x0
  unsigned int v21; // w23
  __int64 v22; // x9
  __int64 v23; // x28
  __int64 v24; // x22
  int v25; // w9
  unsigned int v26; // w8
  unsigned int v27; // w8
  unsigned int *v28; // x10
  unsigned int v29; // w9
  unsigned int v30; // w9
  unsigned int v31; // w9
  unsigned int v32; // w9
  unsigned int v33; // w9
  bool v34; // cc
  unsigned int v35; // w10
  unsigned int v36; // w9
  unsigned int v37; // w10
  unsigned __int64 v38; // x9
  __int64 v39; // x10
  unsigned int v40; // w8
  unsigned int v41; // w9
  char v42; // w0
  char v43; // w9
  int v44; // w8
  unsigned __int64 v47; // x11
  __int64 v48; // x10
  int v49; // w8
  unsigned __int64 v52; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v58; // x9
  unsigned __int64 v65; // x9
  unsigned int v66; // w10
  unsigned int v67; // w10
  unsigned int v68; // w10
  __int64 v69; // x23
  char v70; // w21
  unsigned int v71; // w22
  unsigned __int64 StatusReg; // x22
  __int64 v73; // x23
  __int64 v74; // x0
  unsigned __int64 v77; // x8
  unsigned int v78; // [xsp+8h] [xbp-38h]
  _QWORD v79[6]; // [xsp+10h] [xbp-30h] BYREF

  v79[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a4 || (v5 = (__int64)&unk_B000, context_drawqueue_size - 1 < a4) )
  {
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( !a2 || (v7 = *a1, (*(_QWORD *)(a2 + 32) & 4) != 0) )
  {
    result = 4294967261LL;
    goto LABEL_15;
  }
  if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
  {
    result = 4294967294LL;
    goto LABEL_15;
  }
  LODWORD(v11) = a4;
  result = adreno_verify_cmdobj(a1, a2, a3, a4);
  if ( !(_DWORD)result )
  {
    wait_for_completion(v7 + 8720);
    v12 = kmem_cache_alloc_noprof(jobs_cache, 3264);
    if ( !v12 )
      goto LABEL_133;
LABEL_9:
    *(_QWORD *)(v12 + 8) = a2;
    raw_spin_lock(a2 + 404);
    v13 = a2;
    if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
    {
      v17 = -35;
    }
    else
    {
      if ( (*(_QWORD *)(a2 + 32) & 2) == 0 )
      {
        v14 = v11;
        if ( *(_DWORD *)(a2 + 1512) + (int)v11 <= (unsigned int)(*(_DWORD *)(v5 + 3944) - 1) )
        {
LABEL_37:
          v21 = *a5;
          v22 = a3;
          if ( (v14 != 1 || *(_DWORD *)(*(_QWORD *)a3 + 16LL) != 4) && (*(_BYTE *)(v13 + 200) & 0x80) != 0 )
          {
            if ( (v66 = *(_DWORD *)(v13 + 392), v66 == v21)
              || v66 > v21 && ((v66 - v21) & 0x80000000) == 0
              || (v67 = v66 ^ 0x80000000,
                  _CF = v67 >= (v21 ^ 0x80000000),
                  v68 = v67 - (v21 ^ 0x80000000),
                  v68 != 0 && _CF)
              && v68 <= 0x80000000 )
            {
LABEL_113:
              raw_spin_unlock(v13 + 404);
              kmem_cache_free(jobs_cache, v12);
              result = 4294967262LL;
              goto LABEL_15;
            }
          }
          v11 = 0;
          v23 = v13 + 408;
          if ( v14 <= 1 )
            v5 = 1;
          else
            v5 = v14;
          v78 = v21 ^ 0x80000000;
          while ( 1 )
          {
            v24 = *(_QWORD *)(v22 + 8 * v11);
            v25 = *(_DWORD *)(v24 + 16);
            if ( v25 <= 3 )
              break;
            switch ( v25 )
            {
              case 4:
                *a5 = 0;
                break;
              case 8:
                v29 = *(_DWORD *)(v13 + 392);
                if ( (*(_BYTE *)(v13 + 200) & 0x80) != 0 )
                {
                  if ( v29 == v21 || v29 > v21 && ((v29 - v21) & 0x80000000) == 0 )
                    goto LABEL_113;
                  v33 = v29 ^ 0x80000000;
                  v35 = v33 - v78;
                  v34 = v33 > v78;
                  v30 = v21;
                  if ( v34 )
                  {
                    v30 = v21;
                    if ( v35 < 0x80000001 )
                      goto LABEL_113;
                  }
                }
                else
                {
                  v30 = v29 + 1;
                }
                *(_DWORD *)(v13 + 392) = v30;
                *a5 = v30;
                *(_DWORD *)(v24 + 20) = v30;
                *(_DWORD *)(v13 + 1528) = *a5;
                goto LABEL_47;
              case 16:
                break;
              default:
                goto LABEL_130;
            }
            *(_DWORD *)(v24 + 20) = 0;
LABEL_47:
            queue_drawobj(v13, v24);
            ++v11;
            v13 = a2;
            v22 = a3;
            if ( v11 == v5 )
            {
              v69 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a3 + 8LL) + 1536LL);
              adreno_track_context(v7, v69 + 208, a2);
              raw_spin_unlock(a2 + 404);
              if ( !(unsigned int)kgsl_context_get((unsigned int *)a2) )
              {
                kmem_cache_free(jobs_cache, v12);
                goto LABEL_134;
              }
              trace_dispatch_queue_context(a2);
              if ( *(_DWORD *)(a2 + 8) < 0x11u )
              {
                llist_add_batch(v12);
                if ( *(_DWORD *)(v69 + 1232) < (unsigned int)context_drawobj_burst )
                  adreno_dispatcher_issuecmds(v7);
                goto LABEL_134;
              }
LABEL_132:
              __break(0x5512u);
              StatusReg = _ReadStatusReg(SP_EL0);
              v73 = *(_QWORD *)(StatusReg + 80);
              v74 = jobs_cache;
              *(_QWORD *)(StatusReg + 80) = &adreno_dispatcher_queue_cmds__alloc_tag;
              v12 = kmem_cache_alloc_noprof(v74, 3264);
              *(_QWORD *)(StatusReg + 80) = v73;
              if ( v12 )
                goto LABEL_9;
LABEL_133:
              result = 4294967284LL;
              goto LABEL_15;
            }
          }
          if ( v25 == 1 )
          {
            v31 = *(_DWORD *)(v13 + 392);
            if ( (*(_BYTE *)(v13 + 200) & 0x80) != 0 )
            {
              if ( v31 == v21 || v31 > v21 && ((v31 - v21) & 0x80000000) == 0 )
                goto LABEL_113;
              v36 = v31 ^ 0x80000000;
              v37 = v36 - v78;
              v34 = v36 > v78;
              v32 = v21;
              if ( v34 )
              {
                v32 = v21;
                if ( v37 < 0x80000001 )
                  goto LABEL_113;
              }
            }
            else
            {
              v32 = v31 + 1;
            }
            *(_DWORD *)(v13 + 392) = v32;
            *a5 = v32;
            *(_DWORD *)(v24 + 20) = v32;
            v38 = *(unsigned int *)(v13 + 1432);
            v39 = *(unsigned int *)(v13 + 1436);
            while ( v38 != v39 )
            {
              if ( v38 >= 0x80 )
                goto LABEL_132;
              v48 = *(_QWORD *)(v23 + 8 * v38);
              if ( *(_DWORD *)(v48 + 16) == 2 )
              {
                _X10 = (unsigned __int64 *)(v48 + 56);
                __asm { PRFM            #0x11, [X10] }
                do
                  v47 = __ldxr(_X10);
                while ( __stxr(v47 | 1, _X10) );
              }
              v39 = *(unsigned int *)(v13 + 1436);
              v38 = ((_BYTE)v38 + 1) & 0x7F;
            }
            v49 = *(_DWORD *)(v13 + 200);
            *(_DWORD *)(v13 + 1528) = *a5;
            if ( (v49 & 0x200) != 0 )
            {
              _X8 = (unsigned __int64 *)(v24 + 72);
              __asm { PRFM            #0x11, [X8] }
              do
                v52 = __ldxr(_X8);
              while ( __stxr(v52 | 0x10, _X8) );
              goto LABEL_46;
            }
            if ( (v49 & 0x10000000) != 0 )
            {
              _X8 = (unsigned __int64 *)(v24 + 72);
              __asm { PRFM            #0x11, [X8] }
              do
                v58 = __ldxr(_X8);
              while ( __stxr(v58 | 2, _X8) );
              goto LABEL_46;
            }
          }
          else
          {
            if ( v25 != 2 )
            {
LABEL_130:
              raw_spin_unlock(v13 + 404);
              kmem_cache_free(jobs_cache, v12);
              result = 4294967274LL;
              goto LABEL_15;
            }
            v26 = *(_DWORD *)(v13 + 392);
            if ( (*(_BYTE *)(v13 + 200) & 0x80) != 0 )
            {
              if ( v26 == v21
                || (v28 = a5, v26 > v21) && ((v26 - v21) & 0x80000000) == 0
                || (v40 = v26 ^ 0x80000000, v41 = v40 - v78, v34 = v40 > v78, v27 = v21, v34)
                && (v27 = v21, v41 < 0x80000001) )
              {
                v70 = 0;
                v71 = -34;
LABEL_125:
                raw_spin_unlock(v13 + 404);
                kmem_cache_free(jobs_cache, v12);
                result = v71;
                if ( (v70 & 1) == 0 )
                  goto LABEL_15;
LABEL_134:
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
                goto LABEL_15;
              }
            }
            else
            {
              v27 = v26 + 1;
              v28 = a5;
            }
            *(_DWORD *)(v13 + 392) = v27;
            *v28 = v27;
            *(_DWORD *)(v24 + 20) = v27;
            if ( !*(_DWORD *)(v13 + 1512) )
            {
              v42 = kgsl_check_timestamp(*(_QWORD *)v24, *(_QWORD *)(v24 + 8), *(unsigned int *)(v13 + 1528));
              v28 = a5;
              v43 = v42;
              v13 = a2;
              if ( (v43 & 1) != 0 )
              {
                retire_timestamp(v24);
                v13 = a2;
                v70 = 1;
                v71 = 1;
                goto LABEL_125;
              }
            }
            *(_DWORD *)(v24 + 120) = *(_DWORD *)(v13 + 1528);
            v44 = *(_DWORD *)(v13 + 200);
            *(_DWORD *)(v13 + 1528) = *v28;
            if ( (v44 & 0x200) != 0 )
            {
              _X8 = (unsigned __int64 *)(v24 + 72);
              __asm { PRFM            #0x11, [X8] }
              do
                v55 = __ldxr(_X8);
              while ( __stxr(v55 | 0x10, _X8) );
              goto LABEL_46;
            }
            if ( (v44 & 0x10000000) != 0 )
            {
              _X8 = (unsigned __int64 *)(v24 + 72);
              __asm { PRFM            #0x11, [X8] }
              do
                v65 = __ldxr(_X8);
              while ( __stxr(v65 | 2, _X8) );
              goto LABEL_46;
            }
          }
          *(_QWORD *)(v24 + 72) = *(_QWORD *)(v7 + 19664);
LABEL_46:
          cmdobj_set_flags();
          v13 = a2;
          goto LABEL_47;
        }
        raw_spin_unlock(a2 + 404);
        v15 = _msecs_to_jiffies((unsigned int)context_queue_wait);
        raw_spin_lock(a2 + 404);
        v16 = (*(_QWORD *)(a2 + 32) & 4) != 0 || (unsigned int)(*(_DWORD *)(a2 + 1512) + v11) < *(_DWORD *)(v5 + 3944);
        raw_spin_unlock(a2 + 404);
        if ( v16 && v15 == 0 )
          v15 = 1;
        if ( !v16 && v15 )
        {
          memset(v79, 0, 40);
          v18 = _msecs_to_jiffies((unsigned int)context_queue_wait);
          init_wait_entry(v79, 0);
          while ( 1 )
          {
            v19 = 1;
            v15 = prepare_to_wait_event(a2 + 1440, v79, 1);
            raw_spin_lock(a2 + 404);
            if ( (*(_QWORD *)(a2 + 32) & 4) == 0 )
              v19 = (unsigned int)(*(_DWORD *)(a2 + 1512) + v11) < *(_DWORD *)(v5 + 3944);
            raw_spin_unlock(a2 + 404);
            v20 = v19 && v18 == 0 ? 1LL : v18;
            if ( v19 || !v20 )
              break;
            if ( v15 )
              goto LABEL_34;
            v18 = schedule_timeout();
          }
          LODWORD(v15) = v20;
          finish_wait(a2 + 1440, v79);
        }
LABEL_34:
        raw_spin_lock(a2 + 404);
        if ( (int)v15 < 1 )
        {
          v13 = a2;
          if ( (_DWORD)v15 )
            v17 = v15;
          else
            v17 = -110;
          goto LABEL_122;
        }
        v13 = a2;
        if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
        {
          v17 = -35;
          goto LABEL_122;
        }
        v14 = v11;
        if ( (*(_QWORD *)(a2 + 32) & 2) == 0 )
          goto LABEL_37;
      }
      v17 = -2;
    }
LABEL_122:
    raw_spin_unlock(v13 + 404);
    kmem_cache_free(jobs_cache, v12);
    result = v17;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
