__int64 __fastcall cam_context_flush_ctx_to_hw(__int64 a1)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x10
  _QWORD *v4; // x11
  unsigned int v5; // w27
  _QWORD **v6; // x9
  __int64 *v7; // x24
  __int64 v8; // x22
  __int64 **v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x11
  unsigned __int64 v13; // x26
  char v14; // w21
  __int64 v15; // x20
  unsigned int v16; // w8
  unsigned int v23; // w9
  unsigned int v24; // w9
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x26
  __int64 v27; // x20
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 *v30; // x1
  _QWORD *v31; // x20
  _QWORD *v32; // x8
  _QWORD *i; // x8
  __int64 v34; // x9
  __int64 v35; // x12
  __int64 v36; // x8
  __int64 *v37; // x10
  void (__fastcall *v38)(__int64, __int64 *); // x8
  __int64 v39; // x0
  _QWORD *v40; // x9
  _QWORD *v41; // x10
  _QWORD *v42; // x11
  __int64 *v43; // x24
  __int64 v44; // x22
  __int64 **v45; // x8
  __int64 v46; // x9
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x26
  __int64 v49; // x27
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 *v52; // x1
  unsigned int v53; // w20
  _QWORD *v55; // [xsp+18h] [xbp-48h] BYREF
  _QWORD **v56; // [xsp+20h] [xbp-40h]
  __int64 v57; // [xsp+28h] [xbp-38h] BYREF
  __int64 v58; // [xsp+30h] [xbp-30h]
  _QWORD *v59; // [xsp+38h] [xbp-28h]
  __int64 v60; // [xsp+40h] [xbp-20h]
  _QWORD *v61; // [xsp+48h] [xbp-18h]
  __int64 v62; // [xsp+50h] [xbp-10h]
  __int64 v63; // [xsp+58h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = nullptr;
  v62 = 0;
  v59 = nullptr;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = nullptr;
  v56 = nullptr;
  if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x80000,
      4,
      "cam_context_flush_ctx_to_hw",
      853,
      "[%s] E: NRT flush ctx",
      (const char *)a1);
  mutex_lock(a1 + 416);
  v55 = &v55;
  v56 = &v55;
  raw_spin_lock(a1 + 120);
  v2 = *(_QWORD **)(a1 + 144);
  if ( v2 != (_QWORD *)(a1 + 144) )
  {
    v3 = v55;
    v4 = *(_QWORD **)(a1 + 152);
    v2[1] = &v55;
    v55 = v2;
    *v4 = v3;
    v3[1] = v4;
    *(_QWORD *)(a1 + 144) = a1 + 144;
    *(_QWORD *)(a1 + 152) = a1 + 144;
  }
  raw_spin_unlock(a1 + 120);
  if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      3,
      "cam_context_flush_ctx_to_hw",
      869,
      "[%s][%d] : Moving all pending requests from pending_list to temp_list",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
  v5 = -1;
  v6 = &v55;
  HIDWORD(v62) = *(_DWORD *)(a1 + 464);
  do
  {
    v6 = (_QWORD **)*v6;
    ++v5;
  }
  while ( v6 != &v55 );
  if ( !v5 )
    goto LABEL_47;
  if ( mem_trace_en == 1 )
  {
    v59 = (_QWORD *)cam_mem_trace_alloc(8LL * v5, 0xCC0u, 0, "cam_context_flush_ctx_to_hw", 0x36Du);
    if ( v59 )
      goto LABEL_13;
LABEL_92:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_flush_ctx_to_hw",
      880,
      "[%s][%d] : Flush array memory alloc fail",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
    mutex_unlock(a1 + 416);
    goto LABEL_95;
  }
  v59 = (_QWORD *)_kvmalloc_node_noprof(8LL * v5, 0, 3520, 0xFFFFFFFFLL);
  if ( !v59 )
    goto LABEL_92;
LABEL_13:
  v7 = v55;
  if ( v55 != &v55 )
  {
    v8 = a1 + 176;
    do
    {
      v9 = (__int64 **)v7[1];
      if ( *v9 == v7 && (v10 = *v7, *(__int64 **)(*v7 + 8) == v7) )
      {
        *(_QWORD *)(v10 + 8) = v9;
        *v9 = (__int64 *)v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
      }
      *v7 = (__int64)v7;
      v7[1] = (__int64)v7;
      *((_DWORD *)v7 + 24) = 1;
      cam_smmu_buffer_tracker_putref(v7 + 14);
      v11 = (unsigned int)v58;
      v12 = v7[4];
      LODWORD(v58) = v58 + 1;
      v59[v11] = v12;
      if ( *((_DWORD *)v7 + 16) )
      {
        v13 = 0;
        v14 = 0;
        v15 = 16;
        do
        {
          if ( (unsigned int)cam_sync_deregister_callback(cam_context_sync_callback, v7, *(unsigned int *)(v7[7] + v15)) )
          {
            v16 = *((_DWORD *)v7 + 16);
          }
          else
          {
            cam_context_putref(a1);
            _X8 = (unsigned int *)v7 + 21;
            __asm { PRFM            #0x11, [X8] }
            do
            {
              v23 = __ldxr(_X8);
              v24 = v23 + 1;
            }
            while ( __stlxr(v24, _X8) );
            __dmb(0xBu);
            v16 = *((_DWORD *)v7 + 16);
            v14 |= v24 == v16;
          }
          ++v13;
          v15 += 64;
        }
        while ( v13 < v16 );
      }
      else
      {
        v14 = 0;
      }
      v25 = *((unsigned int *)v7 + 20);
      if ( (_DWORD)v25 )
      {
        v26 = 0;
        v27 = 16;
        do
        {
          v28 = *(unsigned int *)(v7[9] + v27);
          if ( (_DWORD)v28 != -1 )
          {
            if ( (unsigned int)cam_sync_signal(v28, 4, 2) == -114 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x80000,
                1,
                "cam_context_flush_ctx_to_hw",
                926,
                "Req: %llu already signalled, sync_id:%d",
                v7[3],
                *(_DWORD *)(v7[9] + v27));
              break;
            }
            v25 = *((unsigned int *)v7 + 20);
          }
          ++v26;
          v27 += 64;
        }
        while ( v26 < v25 );
      }
      if ( (v14 & 1) != 0 )
      {
        v29 = v7[17];
        v7[13] = 0;
        if ( v29 )
        {
          cam_common_mem_free(v29);
          v7[17] = 0;
        }
        raw_spin_lock(a1 + 120);
        v30 = *(__int64 **)(a1 + 184);
        if ( v7 == (__int64 *)v8 || v30 == v7 || *v30 != v8 )
        {
          _list_add_valid_or_report(v7);
        }
        else
        {
          *(_QWORD *)(a1 + 184) = v7;
          *v7 = v8;
          v7[1] = (__int64)v30;
          *v30 = (__int64)v7;
        }
        raw_spin_unlock(a1 + 120);
      }
      if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x80000,
          3,
          "cam_context_flush_ctx_to_hw",
          951,
          "[%s][%d] : Deleting req[%llu] from temp_list",
          (const char *)a1,
          *(_DWORD *)(a1 + 32),
          v7[3]);
      v7 = v55;
    }
    while ( v55 != &v55 );
  }
LABEL_47:
  mutex_unlock(a1 + 416);
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 208) + 120LL) )
  {
    raw_spin_lock(a1 + 120);
    v31 = (_QWORD *)(a1 + 128);
    v5 = -1;
    v32 = (_QWORD *)(a1 + 128);
    do
    {
      v32 = (_QWORD *)*v32;
      ++v5;
    }
    while ( v32 != v31 );
    if ( !v5 )
    {
LABEL_55:
      raw_spin_unlock(a1 + 120);
      if ( (unsigned int)v58 | (unsigned int)v60 )
      {
        v36 = *(_QWORD *)(a1 + 264);
        v37 = *(__int64 **)(a1 + 208);
        LODWORD(v62) = 1;
        v57 = v36;
        v38 = (void (__fastcall *)(__int64, __int64 *))v37[15];
        v39 = *v37;
        if ( *((_DWORD *)v38 - 1) != 1863972096 )
          __break(0x8228u);
        v38(v39, &v57);
      }
      goto LABEL_59;
    }
    if ( mem_trace_en == 1 )
    {
      v61 = (_QWORD *)cam_mem_trace_alloc(8LL * v5, 0x820u, 0, "cam_context_flush_ctx_to_hw", 0x3CCu);
      if ( v61 )
        goto LABEL_53;
    }
    else
    {
      v61 = (_QWORD *)_kvmalloc_node_noprof(8LL * v5, 0, 2336, 0xFFFFFFFFLL);
      if ( v61 )
      {
LABEL_53:
        for ( i = (_QWORD *)*v31; i != v31; i = (_QWORD *)*i )
        {
          v34 = (unsigned int)v60;
          v35 = i[4];
          LODWORD(v60) = v60 + 1;
          v61[v34] = v35;
        }
        goto LABEL_55;
      }
    }
    raw_spin_unlock(a1 + 120);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_flush_ctx_to_hw",
      976,
      "[%s][%d] : Flush array memory alloc fail",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
LABEL_95:
    v53 = -12;
    goto LABEL_96;
  }
LABEL_59:
  v55 = &v55;
  v56 = &v55;
  raw_spin_lock(a1 + 120);
  v40 = *(_QWORD **)(a1 + 128);
  if ( v40 != (_QWORD *)(a1 + 128) )
  {
    v41 = v55;
    v42 = *(_QWORD **)(a1 + 136);
    v40[1] = &v55;
    v55 = v40;
    *v42 = v41;
    v41[1] = v42;
    *(_QWORD *)(a1 + 128) = a1 + 128;
    *(_QWORD *)(a1 + 136) = a1 + 128;
  }
  raw_spin_unlock(a1 + 120);
  if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      3,
      "cam_context_flush_ctx_to_hw",
      1004,
      "[%s][%d] : Moving all requests from active_list to temp_list",
      (const char *)a1,
      *(_DWORD *)(a1 + 32));
  if ( v5 )
  {
    v43 = v55;
    if ( v55 != &v55 )
    {
      v44 = a1 + 176;
      do
      {
        v45 = (__int64 **)v43[1];
        if ( *v45 == v43 && (v46 = *v43, *(__int64 **)(*v43 + 8) == v43) )
        {
          *(_QWORD *)(v46 + 8) = v45;
          *v45 = (__int64 *)v46;
        }
        else
        {
          _list_del_entry_valid_or_report(v43);
        }
        *v43 = (__int64)v43;
        v43[1] = (__int64)v43;
        cam_smmu_buffer_tracker_putref(v43 + 14);
        v47 = *((unsigned int *)v43 + 20);
        if ( (_DWORD)v47 )
        {
          v48 = 0;
          v49 = 16;
          do
          {
            v50 = *(unsigned int *)(v43[9] + v49);
            if ( (_DWORD)v50 != -1 )
            {
              if ( (unsigned int)cam_sync_signal(v50, 4, 2) == -114 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x80000,
                  1,
                  "cam_context_flush_ctx_to_hw",
                  1028,
                  "Req: %llu already signalled ctx: %pK dev_name: %s dev_handle: %d ctx_state: %d",
                  v43[3],
                  (const void *)v43[13],
                  (const char *)v43[13],
                  *(_DWORD *)(v43[13] + 60),
                  *(_DWORD *)(v43[13] + 240));
                break;
              }
              v47 = *((unsigned int *)v43 + 20);
            }
            ++v48;
            v49 += 64;
          }
          while ( v48 < v47 );
        }
        v51 = v43[17];
        if ( v51 )
        {
          cam_common_mem_free(v51);
          v43[17] = 0;
        }
        v43[13] = 0;
        raw_spin_lock(a1 + 120);
        v52 = *(__int64 **)(a1 + 184);
        if ( v43 == (__int64 *)v44 || v52 == v43 || *v52 != v44 )
        {
          _list_add_valid_or_report(v43);
        }
        else
        {
          *(_QWORD *)(a1 + 184) = v43;
          *v43 = v44;
          v43[1] = (__int64)v52;
          *v52 = (__int64)v43;
        }
        raw_spin_unlock(a1 + 120);
        if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            3,
            "cam_context_flush_ctx_to_hw",
            1046,
            "[%s][%d] : Moving req[%llu] from temp_list to free_list",
            (const char *)a1,
            *(_DWORD *)(a1 + 32),
            v43[3]);
        v43 = v55;
      }
      while ( v55 != &v55 );
    }
  }
  v53 = 0;
  if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x80000,
      4,
      "cam_context_flush_ctx_to_hw",
      1050,
      "[%s] X: NRT flush ctx",
      (const char *)a1);
    v53 = 0;
  }
LABEL_96:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v61, 0);
  else
    kvfree(v61);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v59, 0);
  else
    kvfree(v59);
  _ReadStatusReg(SP_EL0);
  return v53;
}
