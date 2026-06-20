__int64 __fastcall fastrpc_internal_invoke(__int64 a1, unsigned int a2, int *a3)
{
  __int64 v3; // x8
  unsigned int v4; // w25
  __int64 result; // x0
  unsigned int v8; // w20
  __int64 *v9; // x9
  __int64 v10; // x22
  unsigned int v11; // w20
  int v12; // w23
  __int64 v13; // x9
  __int64 v14; // x26
  __int64 v15; // x0
  unsigned __int64 v16; // x21
  int v17; // w10
  int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x0
  unsigned __int64 v21; // x8
  __int64 v22; // x0
  unsigned __int64 v23; // x28
  __int64 v24; // x0
  size_t v25; // x2
  __int64 v26; // x1
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x12
  __int64 v32; // x13
  __int64 v33; // x11
  __int64 v34; // x8
  unsigned __int64 v35; // x10
  __int64 v36; // x9
  unsigned __int64 v37; // x0
  _QWORD *v38; // x26
  unsigned __int64 v39; // x11
  __int64 v40; // x11
  __int64 v41; // x12
  __int64 v42; // x27
  __int64 v44; // x11
  __int64 v45; // x10
  __int64 v46; // x9
  __int64 v47; // x0
  int *v48; // x8
  int v49; // w8
  int v50; // w9
  int v51; // w8
  __int64 v52; // x2
  unsigned __int64 *v53; // x1
  __int64 v54; // x28
  __int64 v55; // x9
  _QWORD *v56; // x8
  __int64 v57; // x9
  __int64 v58; // x24
  int v59; // w28
  __int64 v60; // x1
  __int64 v61; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v63; // x28
  __int64 (__fastcall *v64)(__int64, const char *); // x8
  __int64 v65; // x0
  __int64 v66; // t1
  __int64 v67; // x8
  unsigned int v73; // w9
  __int64 v74; // x0
  int v75; // w8
  _QWORD *v76; // x24
  int v77; // w8
  _QWORD *v78; // x24
  int v79; // w8
  unsigned int v80; // w22
  unsigned int v81; // w8
  int v82; // w8
  _QWORD *v83; // x22
  unsigned int v84; // w19
  int v85; // w9
  unsigned int v86; // w22
  _QWORD *v87; // x8
  __int64 v88; // x1
  __int64 v89; // x2
  __int64 v90; // x3
  __int64 v91; // x4
  __int64 v92; // x5
  __int64 n; // [xsp+20h] [xbp-40h]
  unsigned int v94; // [xsp+2Ch] [xbp-34h]
  __int64 v95; // [xsp+30h] [xbp-30h] BYREF
  __int64 v96; // [xsp+38h] [xbp-28h]
  _QWORD v97[2]; // [xsp+40h] [xbp-20h] BYREF
  unsigned int v98; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v99; // [xsp+58h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 128);
  v98 = 0;
  v4 = a3[10];
  v97[0] = 0;
  v97[1] = 0;
  if ( *(_DWORD *)(v3 + 64136) )
  {
    result = 4294967264LL;
    goto LABEL_3;
  }
  if ( *(_DWORD *)(a1 + 280) )
  {
    v8 = a2;
    ktime_get_real_ts64(v97);
    a2 = v8;
  }
  v9 = *(__int64 **)(a1 + 136);
  if ( !v9 )
  {
    result = 4294967274LL;
    goto LABEL_3;
  }
  result = 4294967264LL;
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL) )
  {
    v10 = *v9;
    if ( *v9 )
    {
      v11 = *a3;
      v12 = a3[1];
      if ( !a2 && v11 == 1 )
      {
        if ( (unsigned int)__ratelimit(&fastrpc_internal_invoke__rs, "fastrpc_internal_invoke") )
          dev_warn(v10, "user app trying to send a kernel RPC message (%d)\n", 1);
        result = 0xFFFFFFFFLL;
        goto LABEL_3;
      }
      v13 = *(_QWORD *)(a1 + 184);
      if ( v13 && *(_QWORD *)(v13 + 24) != *(_QWORD *)(v13 + 32) && *(_DWORD *)(a1 + 268) == 3 )
        goto LABEL_3;
      v94 = a2;
      if ( a2 )
        goto LABEL_19;
      v37 = fastrpc_context_restore_interrupted(a1, a3);
      v16 = v37;
      if ( v37 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_87;
      if ( v37 )
      {
        trace_fastrpc_context_restore(
          **(unsigned int **)(v37 + 240),
          v37,
          *(_QWORD *)(v37 + 152),
          *(unsigned int *)(v37 + 160),
          *(unsigned int *)(v37 + 164));
        v38 = nullptr;
        goto LABEL_112;
      }
      while ( 1 )
      {
LABEL_19:
        v14 = *(_QWORD *)(a1 + 128);
        v15 = _kmalloc_cache_noprof(wait_for_completion_interruptible, 3520, 296);
        v16 = v15;
        if ( !v15 )
        {
          v16 = -12;
          goto LABEL_86;
        }
        v17 = (unsigned __int8)v12 >> 4;
        *(_QWORD *)v15 = v15;
        v18 = BYTE2(v12) + BYTE1(v12);
        *(_QWORD *)(v15 + 8) = v15;
        *(_QWORD *)(v15 + 184) = a1;
        *(_DWORD *)(v15 + 16) = v17 + (v12 & 0xF) + v18;
        *(_DWORD *)(v15 + 20) = v18;
        if ( !(v17 + (v12 & 0xF) + v18) )
          goto LABEL_45;
        v19 = *(unsigned int *)(v15 + 16);
        if ( (v19 & 0x80000000) != 0 )
        {
          *(_QWORD *)(v15 + 208) = 0;
          v42 = -12;
          goto LABEL_85;
        }
        v20 = _kmalloc_noprof(8 * v19, 3520);
        *(_QWORD *)(v16 + 208) = v20;
        if ( !v20 )
          goto LABEL_44;
        v21 = *(int *)(v16 + 16);
        if ( !is_mul_ok(v21, 0x30u) )
        {
          *(_QWORD *)(v16 + 232) = 0;
          v42 = -12;
          goto LABEL_85;
        }
        v22 = _kmalloc_noprof(48 * v21, 3520);
        *(_QWORD *)(v16 + 232) = v22;
        if ( !v22 )
          goto LABEL_44;
        v23 = *(int *)(v16 + 16);
        if ( !is_mul_ok(v23, 0x18u) )
        {
          *(_QWORD *)(v16 + 224) = 0;
          v42 = -12;
          goto LABEL_85;
        }
        v24 = _kmalloc_noprof(24 * v23, 3520);
        *(_QWORD *)(v16 + 224) = v24;
        if ( !v24 )
        {
LABEL_44:
          v42 = -12;
          goto LABEL_85;
        }
        v25 = 24LL * *(int *)(v16 + 16);
        if ( !v94 )
          break;
        if ( 24 * v23 >= v25 )
        {
          memcpy(*(void **)(v16 + 224), *((const void **)a3 + 1), v25);
          goto LABEL_30;
        }
        v61 = _fortify_panic(17);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                         + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
            & 1) != 0 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          v63 = qword_22A60;
          if ( qword_22A60 )
          {
            do
            {
              v64 = *(__int64 (__fastcall **)(__int64, const char *))v63;
              v65 = *(_QWORD *)(v63 + 8);
              if ( *(_DWORD *)(*(_QWORD *)v63 - 4LL) != -110690895 )
                __break(0x8228u);
              v61 = v64(v65, "context_alloc: begin");
              v66 = *(_QWORD *)(v63 + 24);
              v63 += 24;
            }
            while ( v66 );
          }
          v67 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v67;
          if ( !v67 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v61);
        }
      }
      if ( v25 >> 31 )
      {
        __break(0x800u);
        goto LABEL_62;
      }
      v58 = *((_QWORD *)a3 + 1);
      n = 24LL * *(int *)(v16 + 16);
      v59 = v24;
      _check_object_size();
      if ( inline_copy_from_user(v59, v58, n) )
      {
LABEL_62:
        v42 = -14;
        goto LABEL_85;
      }
LABEL_30:
      v26 = *(int *)(v16 + 20);
      *((_QWORD *)a3 + 1) = *(_QWORD *)(v16 + 224);
      if ( (int)v26 >= 1 )
      {
        v27 = 0;
        v28 = 0;
        v29 = 0;
        do
        {
          *(_QWORD *)(*(_QWORD *)(v16 + 232) + v28) = *(_QWORD *)(*(_QWORD *)(v16 + 224) + v27);
          v30 = *(_QWORD *)(v16 + 232);
          v31 = *(_QWORD *)(v30 + v28);
          v32 = *(_QWORD *)(*(_QWORD *)(v16 + 224) + v27 + 8);
          if ( __CFADD__(v32, v31) )
            goto LABEL_62;
          v27 += 24;
          *(_QWORD *)(v30 + v28 + 8) = v32 + v31;
          v33 = *(_QWORD *)(v16 + 232) + v28;
          v28 += 48;
          *(_DWORD *)(v33 + 16) = v29++;
          v26 = *(int *)(v16 + 20);
        }
        while ( v29 < v26 );
      }
      sort(*(_QWORD *)(v16 + 232), v26, 48, olaps_cmp, 0);
      if ( *(int *)(v16 + 20) >= 1 )
      {
        v34 = 0;
        v35 = 0;
        v36 = 24;
        do
        {
          v40 = *(_QWORD *)(v16 + 232);
          if ( *(_QWORD *)(v40 + v36 - 24) >= v35 )
          {
            *(_QWORD *)(v40 + v36 + 8) = *(_QWORD *)(v40 + v36 - 16);
            *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36) = *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 - 24);
            *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 + 16) = 0;
            v39 = *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 - 16);
          }
          else
          {
            *(_QWORD *)(v40 + v36) = v35;
            *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 + 8) = *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 - 16);
            *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 + 16) = v35 - *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36 - 24);
            v41 = *(_QWORD *)(v16 + 232) + v36;
            v39 = *(_QWORD *)(v41 - 16);
            if ( v39 <= v35 )
            {
              *(_QWORD *)(v41 + 8) = 0;
              *(_QWORD *)(*(_QWORD *)(v16 + 232) + v36) = 0;
              v39 = v35;
            }
          }
          ++v34;
          v36 += 48;
          v35 = v39;
        }
        while ( v34 < *(int *)(v16 + 20) );
      }
LABEL_45:
      _X0 = (unsigned int *)(v14 + 51664);
      __asm { PRFM            #0x11, [X0] }
      do
        v73 = __ldxr(_X0);
      while ( __stxr(v73 + 1, _X0) );
      v48 = a3;
      if ( v73 )
      {
        if ( (((v73 + 1) | v73) & 0x80000000) == 0 )
          goto LABEL_47;
        v60 = 1;
      }
      else
      {
        v60 = 2;
      }
      refcount_warn_saturate(_X0, v60);
      v48 = a3;
LABEL_47:
      v44 = *((_QWORD *)v48 + 3);
      v45 = *((_QWORD *)v48 + 4);
      *(_QWORD *)(v16 + 48) = *((_QWORD *)v48 + 2);
      v46 = *(_QWORD *)(v16 + 184);
      *(_QWORD *)(v16 + 64) = v44;
      *(_QWORD *)(v16 + 72) = v45;
      if ( *(_DWORD *)(v46 + 280) )
      {
        v47 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
        *(_QWORD *)(v16 + 248) = v47;
        if ( !v47 )
        {
          v42 = -12;
LABEL_84:
          fastrpc_channel_ctx_put(v14);
LABEL_85:
          kfree(*(_QWORD *)(v16 + 208));
          kfree(*(_QWORD *)(v16 + 232));
          kfree(*(_QWORD *)(v16 + 224));
          kfree(v16);
          v16 = v42;
LABEL_86:
          v74 = v94;
          if ( v16 < 0xFFFFFFFFFFFFF001LL )
          {
            v75 = *(_DWORD *)(a1 + 280);
            if ( v75 )
              v38 = *(_QWORD **)(v16 + 248);
            else
              v38 = nullptr;
            v95 = 0;
            v96 = 0;
            if ( v38 )
              v76 = v38 + 5;
            else
              v76 = nullptr;
            if ( v75 && v76 )
            {
              ktime_get_real_ts64(&v95);
              v74 = v94;
            }
            result = fastrpc_get_args(v74, v16);
            if ( (_DWORD)result )
              goto LABEL_133;
            if ( *(_DWORD *)(a1 + 280) && v76 )
              *v76 += getnstimediff(&v95);
            trace_fastrpc_msg();
            __dmb(2u);
            v77 = *(_DWORD *)(a1 + 280);
            if ( v38 )
              v78 = v38 + 4;
            else
              v78 = nullptr;
            v95 = 0;
            v96 = 0;
            if ( v77 && v78 )
              ktime_get_real_ts64(&v95);
            result = fastrpc_invoke_send(v4, v16, v94, v11);
            if ( (_DWORD)result )
              goto LABEL_133;
            if ( *(_DWORD *)(a1 + 280) && v78 )
              *v78 += getnstimediff(&v95);
            trace_fastrpc_msg();
LABEL_112:
            if ( v11 >= 0x15
              && (*(_BYTE *)(a1 + 305) & 1) != 0
              && (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 60LL) - 1) <= 1 )
            {
              v79 = *(_DWORD *)(a1 + 268);
              if ( v79 == 9 || v79 == 7 )
                *(_DWORD *)(v16 + 100) = 5;
            }
            fastrpc_wait_for_completion(v16, &v98, v94);
            if ( v98 )
            {
              v80 = v98;
              trace_fastrpc_msg();
              result = v80;
              v81 = v98;
              if ( !v16 )
              {
LABEL_137:
                if ( v16 )
                {
                  v85 = *(_DWORD *)(a1 + 280);
                  if ( v85 )
                  {
                    v86 = result;
                    if ( !v81 )
                    {
                      fastrpc_update_invoke_count(v38, v97);
                      v85 = *(_DWORD *)(a1 + 280);
                    }
                  }
                  else
                  {
                    v86 = result;
                  }
                  if ( v85 )
                  {
                    if ( v11 >= 0xF )
                    {
                      v87 = *(_QWORD **)(v16 + 248);
                      if ( v87 )
                      {
                        trace_fastrpc_perf_counters(
                          v11,
                          *(unsigned int *)(v16 + 36),
                          *v87,
                          v87[1],
                          v87[2],
                          v87[3],
                          v87[4],
                          v87[5],
                          v87[6],
                          v87[7],
                          v87[8],
                          v87[9]);
                        if ( *(_DWORD *)(a1 + 280) )
                        {
                          if ( *(_QWORD *)(v16 + 248) )
                          {
                            if ( *(_QWORD *)(v16 + 64) )
                            {
                              v88 = inline_copy_to_user();
                              if ( (_DWORD)v88 )
                                printk(&unk_23CD2, v88, v89, v90, v91, v92);
                            }
                          }
                        }
                      }
                    }
                  }
                  raw_spin_lock(a1 + 320);
                  _list_del_entry((_QWORD *)v16);
                  *(_QWORD *)v16 = 0xDEAD000000000100LL;
                  *(_QWORD *)(v16 + 8) = 0xDEAD000000000122LL;
                  raw_spin_unlock(a1 + 320);
                  kref_put((unsigned int *)(v16 + 104), (__int64 (*)(void))fastrpc_context_free);
                  trace_fastrpc_msg();
                  result = v86;
                }
                goto LABEL_3;
              }
LABEL_134:
              if ( v81 == -512 )
              {
                v84 = result;
                fastrpc_context_save_interrupted(v16);
                result = v84;
                goto LABEL_3;
              }
              goto LABEL_137;
            }
            trace_fastrpc_msg();
            if ( (*(_BYTE *)(v16 + 96) & 1) == 0 )
            {
              dev_err(v10, "Error: Invalid workdone state for handle 0x%x, sc 0x%x\n", v11, v12);
              result = 4294967186LL;
              v81 = v98;
              if ( !v16 )
                goto LABEL_137;
              goto LABEL_134;
            }
            __dmb(1u);
            v82 = *(_DWORD *)(a1 + 280);
            if ( v38 )
              v83 = v38 + 6;
            else
              v83 = nullptr;
            v95 = 0;
            v96 = 0;
            if ( v82 && v83 )
              ktime_get_real_ts64(&v95);
            result = fastrpc_put_args(v16, v94);
            if ( !(_DWORD)result )
            {
              if ( *(_DWORD *)(a1 + 280) && v83 )
                *v83 += getnstimediff(&v95);
              trace_fastrpc_msg();
              result = *(unsigned int *)(v16 + 24);
            }
LABEL_133:
            v81 = v98;
            if ( !v16 )
              goto LABEL_137;
            goto LABEL_134;
          }
LABEL_87:
          result = (unsigned int)v16;
          goto LABEL_3;
        }
        v48 = a3;
        *(_QWORD *)(v47 + 72) = *(int *)(*(_QWORD *)(v16 + 184) + 248LL);
      }
      v49 = *v48;
      *(_DWORD *)(v16 + 24) = -1;
      v50 = *(_DWORD *)(a1 + 248);
      *(_DWORD *)(v16 + 36) = v12;
      *(_DWORD *)(v16 + 40) = v49;
      v51 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      *(_QWORD *)(v16 + 240) = v14;
      *(_DWORD *)(v16 + 28) = v51;
      *(_DWORD *)(v16 + 32) = v50;
      *(_DWORD *)(v16 + 100) = 0;
      *(_BYTE *)(v16 + 96) = 0;
      *(_DWORD *)(v16 + 112) = 0;
      _init_swait_queue_head(v16 + 120, "&x->wait", &init_completion___key);
      raw_spin_lock(a1 + 320);
      v52 = a1 + 32;
      v53 = *(unsigned __int64 **)(a1 + 40);
      if ( v16 == a1 + 32 || (unsigned __int64 *)v16 == v53 || *v53 != v52 )
      {
        _list_add_valid_or_report(v16, v53, v52);
      }
      else
      {
        *(_QWORD *)(a1 + 40) = v16;
        *(_QWORD *)v16 = v52;
        *(_QWORD *)(v16 + 8) = v53;
        *v53 = v16;
      }
      raw_spin_unlock(a1 + 320);
      v54 = raw_spin_lock_irqsave(v14 + 51600);
      LODWORD(v42) = idr_alloc_cyclic(v14 + 51608, v16, 1, 1024, 2080);
      if ( (v42 & 0x80000000) == 0 )
      {
        v55 = *(_QWORD *)(v14 + 64168) + 1LL;
        *(_QWORD *)(v14 + 64168) = v55;
        *(_QWORD *)(v16 + 80) |= ((unsigned __int16)(v42 & 0x3FF) << 6) | (unsigned __int64)(v55 << 16);
        raw_spin_unlock_irqrestore(v14 + 51600, v54);
        *(_DWORD *)(v16 + 104) = 1;
        goto LABEL_86;
      }
      raw_spin_unlock_irqrestore(v14 + 51600, v54);
      raw_spin_lock(a1 + 320);
      v56 = *(_QWORD **)(v16 + 8);
      if ( *v56 == v16 && (v57 = *(_QWORD *)v16, *(_QWORD *)(*(_QWORD *)v16 + 8LL) == v16) )
      {
        *(_QWORD *)(v57 + 8) = v56;
        *v56 = v57;
      }
      else
      {
        _list_del_entry_valid_or_report(v16);
      }
      *(_QWORD *)v16 = 0xDEAD000000000100LL;
      *(_QWORD *)(v16 + 8) = 0xDEAD000000000122LL;
      raw_spin_unlock(a1 + 320);
      v42 = (int)v42;
      goto LABEL_84;
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
