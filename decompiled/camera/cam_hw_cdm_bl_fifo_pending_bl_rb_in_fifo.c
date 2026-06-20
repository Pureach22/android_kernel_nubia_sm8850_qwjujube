__int64 __fastcall cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo(__int64 a1, unsigned int a2, int *a3)
{
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  int v6; // w19
  unsigned int *v7; // x8
  int *v8; // x22
  __int64 v9; // x8

  if ( a2 >= 4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo",
      288,
      "BL_FIFO index is wrong. fifo_idx %d",
      a2);
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(a1 + 3680);
  v5 = a2 >> 1;
  v6 = a2 & 1;
  v7 = *(unsigned int **)(**(_QWORD **)(v4 + 232) + 8LL * (unsigned int)v5 + 112);
  if ( v7 )
  {
    v8 = a3;
    if ( cam_cdm_read_hw_reg(a1, *v7, a3) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo",
        301,
        "Error reading CDM register");
      return 4294967291LL;
    }
    a3 = v8;
    v9 = *(_QWORD *)(**(_QWORD **)(v4 + 232) + 8 * v5 + 112);
    *v8 = ((unsigned int)*v8 >> (*(_DWORD *)(v9 + 12) * v6)) & *(_DWORD *)(v9 + 4);
  }
  result = 0;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_bl_fifo_pending_bl_rb_in_fifo",
      315,
      "Number of pending bl entries:%d in fifo: %d",
      *a3,
      v6);
    return 0;
  }
  return result;
}
