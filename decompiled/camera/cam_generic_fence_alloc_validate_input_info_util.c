__int64 __fastcall cam_generic_fence_alloc_validate_input_info_util(__int64 a1, unsigned __int64 *a2)
{
  size_t v2; // x7
  __int64 v5; // x0
  unsigned __int64 v7; // x0
  int v8; // w8
  _QWORD *v9; // x19
  int v10; // w7
  int v11; // w6

  *a2 = 0;
  v2 = *(unsigned int *)(a1 + 12);
  if ( (unsigned int)v2 <= 0x8F )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      128,
      1,
      "cam_generic_fence_alloc_validate_input_info_util",
      1160,
      "Size is invalid expected: 0x%llx actual: 0x%llx",
      144);
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(a1 + 16);
  if ( mem_trace_en == 1 )
  {
    v7 = memdup_user_trace(v5, v2, "cam_generic_fence_alloc_validate_input_info_util", 0x48Du);
    if ( !v7 )
      goto LABEL_11;
  }
  else
  {
    v7 = memdup_user(v5, v2);
    if ( !v7 )
    {
LABEL_11:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_alloc_validate_input_info_util",
        1168,
        "memdup failed for hdl: %d size: 0x%x",
        *(_QWORD *)(a1 + 16),
        *(_DWORD *)(a1 + 12));
      return 4294967284LL;
    }
  }
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_11;
  v8 = *(_DWORD *)(v7 + 4);
  if ( (unsigned int)(v8 - 11) <= 0xFFFFFFF5 )
  {
    v9 = (_QWORD *)v7;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_generic_fence_alloc_validate_input_info_util",
      1176,
      "Invalid number of fences: %u for batching",
      v8);
    goto LABEL_15;
  }
  v10 = *(_DWORD *)(a1 + 12);
  v11 = 112 * (v8 - 1) + 144;
  if ( v10 != v11 )
  {
    v9 = (_QWORD *)v7;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_generic_fence_alloc_validate_input_info_util",
      1186,
      "Invalid input size expected: 0x%x actual: 0x%x for fences: %u",
      v11,
      v10,
      v8);
LABEL_15:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    return 4294967274LL;
  }
  *a2 = v7;
  return 0;
}
