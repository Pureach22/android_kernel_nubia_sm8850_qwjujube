__int64 __fastcall tpg_hw_add_stream(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 v17; // x10
  __int64 v18; // x8
  int v19; // w11
  int v20; // w6
  __int64 v21; // x9
  __int64 v22; // x10
  int v23; // w13
  unsigned int v24; // w21
  _QWORD *v25; // x8
  __int64 v26; // x2
  _QWORD *v27; // x1
  __int64 v28; // x1
  __int64 v29; // x4
  _QWORD *v30; // x8
  __int64 v31; // x2
  _QWORD *v32; // x1
  __int64 v33; // x8
  int v34; // w11
  int v35; // w11

  if ( !a1 || !a2 || !a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_add_stream",
      1269,
      "Invalid params");
    return 4294967274LL;
  }
  *(_DWORD *)(a1 + 4) = 1;
  mutex_lock(a1 + 48);
  if ( mem_trace_en == 1 )
  {
    v6 = cam_mem_trace_alloc(128, 0xCC0u, 0, "tpg_hw_add_stream", 0x4FBu);
    if ( !v6 )
      goto LABEL_34;
  }
  else
  {
    v6 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    if ( !v6 )
    {
LABEL_34:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_add_stream",
        1278,
        "TPG[%d] stream allocation failed",
        *(_DWORD *)a1);
      mutex_unlock(a1 + 48);
      return 4294967284LL;
    }
  }
  v8 = *(_QWORD *)(a3 + 8);
  *(_QWORD *)v6 = *(_QWORD *)a3;
  *(_QWORD *)(v6 + 8) = v8;
  v9 = *(_QWORD *)(a3 + 40);
  v10 = *(_QWORD *)(a3 + 16);
  v11 = *(_QWORD *)(a3 + 24);
  *(_QWORD *)(v6 + 32) = *(_QWORD *)(a3 + 32);
  *(_QWORD *)(v6 + 40) = v9;
  *(_QWORD *)(v6 + 16) = v10;
  *(_QWORD *)(v6 + 24) = v11;
  v12 = *(_QWORD *)(a3 + 72);
  v13 = *(_QWORD *)(a3 + 48);
  v14 = *(_QWORD *)(a3 + 56);
  *(_QWORD *)(v6 + 64) = *(_QWORD *)(a3 + 64);
  *(_QWORD *)(v6 + 72) = v12;
  *(_QWORD *)(v6 + 48) = v13;
  *(_QWORD *)(v6 + 56) = v14;
  v16 = *(_QWORD *)(a3 + 88);
  v15 = *(_QWORD *)(a3 + 96);
  v17 = *(_QWORD *)(a3 + 80);
  *(_BYTE *)(v6 + 104) = *(_BYTE *)(a3 + 104);
  *(_QWORD *)(v6 + 88) = v16;
  *(_QWORD *)(v6 + 96) = v15;
  *(_QWORD *)(v6 + 80) = v17;
  v18 = *(_QWORD *)(a1 + 32);
  v19 = *(_DWORD *)(v18 + 4);
  if ( v19 )
  {
    v20 = *(unsigned __int16 *)(v6 + 65);
    LODWORD(v21) = 0;
    while ( 1 )
    {
      v21 = (int)v21;
      v22 = *(_QWORD *)(a2 + 88) + 32LL * (int)v21;
      v23 = *(_DWORD *)(v22 + 4);
      if ( v23 == v20 )
        break;
      if ( v23 == -1 )
      {
        v30 = (_QWORD *)(v6 + 112);
        v31 = v22 + 16;
        v32 = *(_QWORD **)(v22 + 24);
        if ( v6 + 112 == v22 + 16 || v32 == v30 || *v32 != v31 )
        {
          _list_add_valid_or_report(v6 + 112);
          v20 = v34;
        }
        else
        {
          *(_QWORD *)(v22 + 24) = v30;
          *(_QWORD *)(v6 + 112) = v31;
          *(_QWORD *)(v6 + 120) = v32;
          *v32 = v30;
        }
        v24 = 0;
        ++*(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v21 + 8);
        *(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v21 + 4) = v20;
        v33 = debug_mdl;
        ++*(_DWORD *)(a2 + 96);
        if ( (v33 & 0x200000000LL) != 0 && !debug_priority )
        {
          v28 = v33 & 0x200000000LL;
          v29 = 1135;
          goto LABEL_32;
        }
        goto LABEL_16;
      }
      LODWORD(v21) = v21 + 1;
      if ( v19 == (_DWORD)v21 )
        goto LABEL_14;
    }
    if ( *(_DWORD *)(v22 + 8) >= *(_DWORD *)(v18 + 8) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "assign_vc_slot",
        1120,
        "vc[%d]dt[%d]=>slot[%d] is overlfown",
        v20,
        *(unsigned __int16 *)(v6 + 67),
        v21);
      goto LABEL_15;
    }
    v25 = (_QWORD *)(v6 + 112);
    v26 = v22 + 16;
    v27 = *(_QWORD **)(v22 + 24);
    if ( v6 + 112 == v22 + 16 || v27 == v25 || *v27 != v26 )
    {
      _list_add_valid_or_report(v6 + 112);
      v20 = v35;
    }
    else
    {
      *(_QWORD *)(v22 + 24) = v25;
      *(_QWORD *)(v6 + 112) = v26;
      *(_QWORD *)(v6 + 120) = v27;
      *v27 = v25;
    }
    v24 = 0;
    ++*(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v21 + 8);
    *(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v21 + 4) = v20;
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      v28 = debug_mdl & 0x200000000LL;
      v29 = 1109;
LABEL_32:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v28,
        4,
        "assign_vc_slot",
        v29,
        "vc[%d]dt[%d]=>slot[%d]");
      v24 = 0;
    }
  }
  else
  {
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "assign_vc_slot",
      1140,
      "No slot matched");
LABEL_15:
    v24 = -22;
  }
LABEL_16:
  mutex_unlock(a1 + 48);
  return v24;
}
