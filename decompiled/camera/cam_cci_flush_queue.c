__int64 __fastcall cam_cci_flush_queue(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x8
  __int64 v8; // x21
  __int64 result; // x0
  __int16 v10; // w8
  __int64 v11; // x0

  v2 = *(_QWORD *)(a1 + 672);
  v5 = cam_io_w_mb((unsigned int)(1 << a2), v2 + 52);
  if ( a2 >= 2 )
  {
    __break(0x5512u);
    return cam_cci_burst_read(v5, v6);
  }
  v7 = a1 + 544LL * a2;
  v8 = v7 + 4040;
  if ( !*(_DWORD *)(v7 + 4040) )
    *(_DWORD *)(v7 + 4104) = 0;
  result = cam_common_wait_for_completion_timeout(v7 + 4104);
  if ( result )
  {
    v10 = debug_mdl;
    if ( (debug_mdl & 0x4000) == 0 )
      return result;
  }
  else
  {
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_flush_queue",
        57,
        "CCI%d_I2C_M%d wait timeout for reset complete",
        *(_DWORD *)(a1 + 404),
        a2);
    if ( a2 )
      v11 = 258049;
    else
      v11 = 1009;
    *(_BYTE *)(v8 + 14) = 1;
    *(_DWORD *)v8 = 0;
    cam_io_w_mb(v11, v2 + 4);
    result = cam_common_wait_for_completion_timeout(v8 + 64);
    if ( !result )
    {
      result = ((__int64 (*)(__int64, const char *, ...))cam_print_log)(
                 3,
                 print_fmt_cam_context_state,
                 (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
                 "cam_cci_flush_queue",
                 78);
      *(_DWORD *)v8 = 0;
      return result;
    }
    *(_DWORD *)v8 = 0;
    v10 = debug_mdl;
    if ( (debug_mdl & 0x4000) == 0 )
      return result;
  }
  if ( !debug_priority )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v10 & 0x4000,
             4,
             "cam_cci_flush_queue",
             86,
             "CCI%d_I2C_M%d Success: Reset complete",
             *(_DWORD *)(a1 + 404),
             a2);
  return result;
}
