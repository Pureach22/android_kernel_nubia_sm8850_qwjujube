__int64 __fastcall cam_context_flush_req_to_hw(__int64 a1, __int64 *a2)
{
  __int64 v4; // x25
  __int64 *v5; // x20
  __int64 **v6; // x8
  __int64 *v7; // x9
  __int64 v8; // x8
  __int64 v9; // x11
  __int64 v10; // x8
  __int64 *v11; // x9
  void (__fastcall *v12)(__int64, __int64 *); // x8
  __int64 v13; // x0
  unsigned __int64 v14; // x26
  char v15; // w25
  __int64 v16; // x27
  unsigned int v17; // w8
  unsigned int v24; // w9
  unsigned int v25; // w9
  __int64 v26; // x7
  __int64 v27; // x4
  unsigned int v28; // w20
  int v29; // w8
  __int64 **v30; // x8
  __int64 v31; // x9
  __int64 v32; // x8
  __int64 v33; // x11
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x26
  __int64 v36; // x27
  unsigned int v37; // w21
  __int64 v38; // x0
  __int64 v39; // x2
  __int64 *v40; // x1
  const char *v41; // x8
  __int64 v43; // [xsp+18h] [xbp-38h] BYREF
  __int64 v44; // [xsp+20h] [xbp-30h]
  _QWORD *v45; // [xsp+28h] [xbp-28h]
  __int64 v46; // [xsp+30h] [xbp-20h]
  _QWORD *v47; // [xsp+38h] [xbp-18h]
  __int64 v48; // [xsp+40h] [xbp-10h]
  __int64 v49; // [xsp+48h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v47 = nullptr;
  v48 = 0;
  v45 = nullptr;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x80000,
      4,
      "cam_context_flush_req_to_hw",
      1069,
      "[%s] E: NRT flush req",
      (const char *)a1);
  if ( mem_trace_en != 1 )
  {
    v45 = (_QWORD *)_kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
    if ( v45 )
      goto LABEL_6;
LABEL_31:
    v26 = *(unsigned int *)(a1 + 32);
    v27 = 1074;
    goto LABEL_32;
  }
  v45 = (_QWORD *)cam_mem_trace_alloc(8, 0xCC0u, 0, "cam_context_flush_req_to_hw", 0x42Fu);
  if ( !v45 )
    goto LABEL_31;
LABEL_6:
  mutex_lock(a1 + 416);
  raw_spin_lock(a1 + 120);
  v5 = (__int64 *)(a1 + 144);
  while ( 1 )
  {
    v5 = (__int64 *)*v5;
    if ( v5 == (__int64 *)(a1 + 144) )
      break;
    if ( v5[3] == *(_QWORD *)(v4 + 24) )
    {
      if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x80000,
          3,
          "cam_context_flush_req_to_hw",
          1087,
          "[%s][%d] : Deleting req[%llu] from pending_list",
          (const char *)a1,
          *(_DWORD *)(a1 + 32),
          v5[3]);
      v6 = (__int64 **)v5[1];
      if ( *v6 == v5 && (v7 = (__int64 *)*v5, *(__int64 **)(*v5 + 8) == v5) )
      {
        v7[1] = (__int64)v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      *v5 = (__int64)v5;
      v5[1] = (__int64)v5;
      v8 = (unsigned int)v44;
      *((_DWORD *)v5 + 24) = 1;
      v9 = v5[4];
      LODWORD(v44) = v8 + 1;
      v45[v8] = v9;
      break;
    }
  }
  raw_spin_unlock(a1 + 120);
  mutex_unlock(a1 + 416);
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 208) + 120LL) )
  {
    if ( (_DWORD)v44 )
    {
LABEL_17:
      v10 = *(_QWORD *)(a1 + 264);
      v11 = *(__int64 **)(a1 + 208);
      LODWORD(v48) = 0;
      v43 = v10;
      v12 = (void (__fastcall *)(__int64, __int64 *))v11[15];
      v13 = *v11;
      if ( *((_DWORD *)v12 - 1) != 1863972096 )
        __break(0x8228u);
      v12(v13, &v43);
      goto LABEL_20;
    }
    if ( mem_trace_en == 1 )
    {
      v47 = (_QWORD *)cam_mem_trace_alloc(8, 0xCC0u, 0, "cam_context_flush_req_to_hw", 0x44Du);
      if ( v47 )
        goto LABEL_37;
    }
    else
    {
      v47 = (_QWORD *)_kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
      if ( v47 )
      {
LABEL_37:
        raw_spin_lock(a1 + 120);
        v5 = (__int64 *)(a1 + 128);
        while ( 1 )
        {
          v5 = (__int64 *)*v5;
          if ( v5 == (__int64 *)(a1 + 128) )
            break;
          if ( v5[3] == *(_QWORD *)(v4 + 24) )
          {
            if ( (a2[1] & 1) == 0 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x80000,
                1,
                "cam_context_flush_req_to_hw",
                1117,
                "[%s][%d] : Flushing active request id: %llu is not supported",
                (const char *)a1,
                *(_DWORD *)(a1 + 32),
                v5[3]);
              raw_spin_unlock(a1 + 120);
              v28 = -1;
              goto LABEL_74;
            }
            v30 = (__int64 **)v5[1];
            if ( *v30 == v5 && (v31 = *v5, *(__int64 **)(*v5 + 8) == v5) )
            {
              *(_QWORD *)(v31 + 8) = v30;
              *v30 = (__int64 *)v31;
            }
            else
            {
              _list_del_entry_valid_or_report(v5);
            }
            *v5 = (__int64)v5;
            v5[1] = (__int64)v5;
            v32 = (unsigned int)v46;
            v33 = v5[4];
            LODWORD(v46) = v46 + 1;
            v47[v32] = v33;
            break;
          }
        }
        raw_spin_unlock(a1 + 120);
        if ( (unsigned int)v44 | (unsigned int)v46 )
          goto LABEL_17;
        goto LABEL_20;
      }
    }
    v26 = *(unsigned int *)(a1 + 32);
    v27 = 1104;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_flush_req_to_hw",
      v27,
      "[%s][%d] : Flush array memory alloc fail",
      a1,
      v26);
    v28 = -12;
    goto LABEL_74;
  }
LABEL_20:
  if ( !v5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_flush_req_to_hw",
      1201,
      "[%s][%d] : No pending or active request to flush for req id: %llu",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      *(_QWORD *)(v4 + 24));
    v28 = -22;
    v29 = debug_mdl;
    if ( (debug_mdl & 0x80000) == 0 )
      goto LABEL_74;
    goto LABEL_72;
  }
  if ( !(_DWORD)v44 )
  {
    v15 = 0;
    goto LABEL_50;
  }
  if ( *((_DWORD *)v5 + 16) )
  {
    v14 = 0;
    v15 = 0;
    v16 = 16;
    do
    {
      if ( (unsigned int)cam_sync_deregister_callback(cam_context_sync_callback, v5, *(unsigned int *)(v5[7] + v16)) )
      {
        v17 = *((_DWORD *)v5 + 16);
      }
      else
      {
        cam_context_putref(a1);
        _X8 = (unsigned int *)v5 + 21;
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v24 = __ldxr(_X8);
          v25 = v24 + 1;
        }
        while ( __stlxr(v25, _X8) );
        __dmb(0xBu);
        v17 = *((_DWORD *)v5 + 16);
        v15 |= v25 == v17;
      }
      ++v14;
      v16 += 64;
    }
    while ( v14 < v17 );
    if ( (_DWORD)v44 )
      goto LABEL_53;
LABEL_50:
    if ( !(_DWORD)v46 )
      goto LABEL_71;
    goto LABEL_53;
  }
  v15 = 0;
LABEL_53:
  cam_smmu_buffer_tracker_putref(v5 + 14);
  v34 = *((unsigned int *)v5 + 20);
  if ( (_DWORD)v34 )
  {
    v35 = 0;
    v36 = 16;
    do
    {
      v37 = *(_DWORD *)(v5[9] + v36);
      if ( v37 != -1 )
      {
        if ( (unsigned int)cam_sync_signal(v37, 4, 2) == -114 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_context_flush_req_to_hw",
            1170,
            "Req: %llu already signalled, sync_id:%d",
            v5[3],
            v37);
          break;
        }
        v34 = *((unsigned int *)v5 + 20);
      }
      ++v35;
      v36 += 64;
    }
    while ( v35 < v34 );
  }
  if ( ((_DWORD)v46 != 0) | v15 & 1 )
  {
    v38 = v5[17];
    v5[13] = 0;
    if ( v38 )
    {
      cam_common_mem_free(v38);
      v5[17] = 0;
    }
    raw_spin_lock(a1 + 120);
    v39 = a1 + 176;
    v40 = *(__int64 **)(a1 + 184);
    if ( v5 == (__int64 *)(a1 + 176) || v40 == v5 || *v40 != v39 )
    {
      _list_add_valid_or_report(v5);
    }
    else
    {
      *(_QWORD *)(a1 + 184) = v5;
      *v5 = v39;
      v5[1] = (__int64)v40;
      *v40 = (__int64)v5;
    }
    raw_spin_unlock(a1 + 120);
    if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
    {
      v41 = "pending_list";
      if ( (_DWORD)v46 )
        v41 = "active_list";
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, __int64, const char *))cam_print_log)(
        3,
        0x80000,
        3,
        "cam_context_flush_req_to_hw",
        1193,
        "[%s][%d] : Moving req[%llu] from %s to free_list",
        a1,
        *(unsigned int *)(a1 + 32),
        v5[3],
        v41);
    }
  }
LABEL_71:
  v28 = 0;
  v29 = debug_mdl;
  if ( (debug_mdl & 0x80000) == 0 )
    goto LABEL_74;
LABEL_72:
  if ( !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      *(_QWORD *)&v29 & 0x80000LL,
      4,
      "cam_context_flush_req_to_hw",
      1205,
      "[%s] X: NRT flush req",
      (const char *)a1);
LABEL_74:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v47, 0);
  else
    kvfree(v47);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v45, 0);
  else
    kvfree(v45);
  _ReadStatusReg(SP_EL0);
  return v28;
}
