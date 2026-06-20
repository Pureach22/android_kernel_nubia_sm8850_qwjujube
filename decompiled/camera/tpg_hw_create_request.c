_QWORD *__fastcall tpg_hw_create_request(_DWORD *a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x21
  __int64 v6; // x8
  __int64 v7; // x0
  _QWORD *result; // x0
  __int64 v9; // x8
  unsigned __int64 v10; // x9
  __int64 v11; // x11

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_create_request",
      1319,
      "Invalid params");
    return nullptr;
  }
  if ( mem_trace_en == 1 )
  {
    v4 = (_QWORD *)cam_mem_trace_alloc(120, 0xCC0u, 0, "tpg_hw_create_request", 0x52Cu);
    if ( !v4 )
      goto LABEL_20;
  }
  else
  {
    v4 = (_QWORD *)_kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    if ( !v4 )
    {
LABEL_20:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_create_request",
        1326,
        "TPG[%d] request allocation failed",
        *a1);
      return nullptr;
    }
  }
  *v4 = a2;
  v5 = v4;
  v6 = *(unsigned int *)(*((_QWORD *)a1 + 4) + 4LL);
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(32 * v6, 0xCC0u, 0, "tpg_hw_create_request", 0x536u);
  else
    v7 = _kvmalloc_node_noprof(32 * v6, 0, 3520, 0xFFFFFFFFLL);
  v5[11] = v7;
  *((_DWORD *)v5 + 24) = 0;
  if ( !v7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_create_request",
      1339,
      "TPG[%d] vc slot allocation failed",
      *a1);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    return nullptr;
  }
  result = v5;
  v5[13] = v5 + 13;
  v5[14] = v5 + 13;
  if ( *(_DWORD *)(*((_QWORD *)a1 + 4) + 4LL) )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      *(_DWORD *)(v5[11] + v9) = v10++;
      *(_DWORD *)(v5[11] + v9 + 4) = -1;
      *(_DWORD *)(v5[11] + v9 + 8) = 0;
      v11 = v5[11] + v9;
      v9 += 32;
      *(_QWORD *)(v11 + 16) = v11 + 16;
      *(_QWORD *)(v11 + 24) = v11 + 16;
    }
    while ( v10 < *(unsigned int *)(*((_QWORD *)a1 + 4) + 4LL) );
  }
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "tpg_hw_create_request",
      1352,
      "TPG[%d] request(%lld) allocated success",
      *a1,
      a2);
    return v5;
  }
  return result;
}
