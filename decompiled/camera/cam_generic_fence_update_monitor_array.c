__int64 __fastcall cam_generic_fence_update_monitor_array(__int64 result, __int64 a2, __int64 a3, int a4)
{
  int v4; // w8
  int v5; // w20
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x23
  __int64 v11; // x23
  __int64 v13; // x8
  __int64 v14; // x8
  unsigned __int64 v15; // x20
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x10

  if ( !a3 )
    return result;
  v4 = result + 127;
  v5 = result;
  if ( (int)result >= 0 )
    v4 = result;
  v8 = (__int64)v4 >> 7;
  v9 = *(_QWORD *)(a3 + 8LL * (v4 >> 7));
  if ( v9 )
    goto LABEL_13;
  if ( a2 )
  {
    v10 = a2;
    mutex_lock(a2);
    a2 = v10;
    if ( *(_QWORD *)(a3 + 8 * v8) )
      goto LABEL_12;
  }
  v11 = a2;
  if ( mem_trace_en == 1 )
    v9 = cam_mem_trace_alloc(206848, 0xCC0u, 0, "cam_generic_expand_monitor_table", 0x19u);
  else
    v9 = _kvmalloc_node_noprof(206848, 0, 3520, 0xFFFFFFFFLL);
  a2 = v11;
  *(_QWORD *)(a3 + 8 * v8) = v9;
  if ( v9 )
  {
    if ( !v11 )
    {
LABEL_13:
      _X9 = v9 + 1616LL * (v5 - ((_DWORD)v8 << 7));
      if ( !a4 )
        *(_QWORD *)_X9 = -1;
      v13 = 896;
      if ( *(_BYTE *)(_X9 + 168) )
        v13 = 176;
      v14 = _X9 + v13;
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v21 = __ldxr((unsigned __int64 *)_X9);
        v22 = v21 + 1;
      }
      while ( __stlxr(v22, (unsigned __int64 *)_X9) );
      __dmb(0xBu);
      v15 = v14 + 24 * (v22 % 0x1E);
      result = ktime_get_real_ts64(v15);
      *(_DWORD *)(v15 + 16) = a4;
      return result;
    }
LABEL_12:
    mutex_unlock(a2);
    v9 = *(_QWORD *)(a3 + 8 * v8);
    goto LABEL_13;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    128,
    1,
    "cam_generic_expand_monitor_table",
    31,
    "Error allocating memory %d, idx %d",
    206848,
    v5);
  if ( v11 )
    mutex_unlock(v11);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           128,
           1,
           "cam_generic_fence_update_monitor_array",
           131,
           "Failed to expand monitor table");
}
