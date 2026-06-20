__int64 __fastcall tpg_hw_add_stream_v3(__int64 a1, __int64 a2, const void *a3)
{
  _QWORD *v6; // x0
  _QWORD *v8; // x21
  __int64 v9; // x10
  int v10; // w11
  int v11; // w6
  int v12; // w8
  __int64 v13; // x9
  __int64 v14; // x8
  int v15; // w13
  unsigned int v16; // w20
  _QWORD *v17; // x0
  __int64 v18; // x2
  _QWORD *v19; // x1
  __int64 v20; // x8
  __int64 v21; // x1
  __int64 v22; // x4
  _QWORD *v23; // x0
  __int64 v24; // x2
  _QWORD *v25; // x1
  __int64 v26; // x10
  int v27; // w10
  int v28; // w10

  if ( a1 && a2 && a3 )
  {
    *(_DWORD *)(a1 + 4) = 3;
    mutex_lock(a1 + 48);
    if ( mem_trace_en == 1 )
      v6 = (_QWORD *)cam_mem_trace_alloc(1176, 0xCC0u, 0, "tpg_hw_add_stream_v3", 0x58Bu);
    else
      v6 = (_QWORD *)_kvmalloc_node_noprof(1176, 0, 3520, 0xFFFFFFFFLL);
    v8 = v6;
    if ( v6 )
    {
      memcpy(v6, a3, 0x488u);
      v9 = *(_QWORD *)(a1 + 32);
      v10 = *(_DWORD *)(v9 + 4);
      if ( v10 )
      {
        v11 = *((unsigned __int16 *)v8 + 34);
        v12 = 0;
        while ( 1 )
        {
          v13 = v12;
          v14 = *(_QWORD *)(a2 + 88) + 32LL * v12;
          v15 = *(_DWORD *)(v14 + 4);
          if ( v15 == v11 )
            break;
          if ( v15 == -1 )
          {
            v23 = v8 + 145;
            v24 = v14 + 16;
            v25 = *(_QWORD **)(v14 + 24);
            if ( v8 + 145 == (_QWORD *)(v14 + 16) || v25 == v23 || *v25 != v24 )
            {
              _list_add_valid_or_report(v23);
              v11 = v27;
            }
            else
            {
              *(_QWORD *)(v14 + 24) = v23;
              v8[145] = v24;
              v8[146] = v25;
              *v25 = v23;
            }
            ++*(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v13 + 8);
            *(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v13 + 4) = v11;
            v26 = debug_mdl;
            ++*(_DWORD *)(a2 + 96);
            v16 = 0;
            if ( (v26 & 0x200000000LL) != 0 && !debug_priority )
            {
              v21 = v26 & 0x200000000LL;
              v22 = 1195;
              goto LABEL_32;
            }
            goto LABEL_16;
          }
          v12 = v13 + 1;
          if ( v10 == (_DWORD)v13 + 1 )
            goto LABEL_14;
        }
        if ( *(_DWORD *)(v14 + 8) >= *(_DWORD *)(v9 + 8) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000000LL,
            1,
            "assign_vc_slot_v3",
            1180,
            "vc[%d]dt[%d]=>slot[%d] is overlfown",
            v11,
            *((unsigned __int16 *)v8 + 35),
            v13);
          goto LABEL_15;
        }
        v17 = v8 + 145;
        v18 = v14 + 16;
        v19 = *(_QWORD **)(v14 + 24);
        if ( v8 + 145 == (_QWORD *)(v14 + 16) || v19 == v17 || *v19 != v18 )
        {
          _list_add_valid_or_report(v17);
          v11 = v28;
        }
        else
        {
          *(_QWORD *)(v14 + 24) = v17;
          v8[145] = v18;
          v8[146] = v19;
          *v19 = v17;
        }
        ++*(_DWORD *)(*(_QWORD *)(a2 + 88) + 32 * v13 + 8);
        v20 = *(_QWORD *)(a2 + 88);
        v16 = 0;
        *(_DWORD *)(v20 + 32 * v13 + 4) = v11;
        if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        {
          v21 = debug_mdl & 0x200000000LL;
          v22 = 1170;
LABEL_32:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            v21,
            4,
            "assign_vc_slot_v3",
            v22,
            "vc[%d]dt[%d]=>slot[%d]");
          v16 = 0;
        }
      }
      else
      {
LABEL_14:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "assign_vc_slot_v3",
          1200,
          "No slot matched");
LABEL_15:
        v16 = -22;
      }
LABEL_16:
      mutex_unlock(a1 + 48);
      return v16;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_add_stream_v3",
        1422,
        "TPG[%d] stream allocation failed",
        *(_DWORD *)a1);
      mutex_unlock(a1 + 48);
      return 4294967284LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_add_stream_v3",
      1413,
      "Invalid params");
    return 4294967274LL;
  }
}
