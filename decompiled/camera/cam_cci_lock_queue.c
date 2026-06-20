__int64 __fastcall cam_cci_lock_queue(__int64 result, unsigned int a2, int a3, int a4)
{
  __int64 v4; // x21
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x0
  __int16 v13; // w8
  int v14; // w6
  unsigned int v15; // w20
  unsigned int v16; // [xsp+1Ch] [xbp-4h]

  if ( !a3 )
  {
    v4 = *(_QWORD *)(result + 672);
    v6 = a2 << 9;
    v7 = result;
    if ( a4 )
      v8 = 6;
    else
      v8 = 7;
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      v16 = v8;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_lock_queue",
        218,
        "CCI%d_I2C_M%d_Q%d_LOAD_DATA_ADDR:val 0x%x:0x%x ",
        *(_DWORD *)(v7 + 404),
        a2,
        0,
        v6 + 784,
        v8);
      v8 = v16;
    }
    v9 = cam_io_w_mb(v8, v4 + v6 + 784);
    if ( a2 > 1 )
    {
      __break(0x5512u);
      return cam_cci_transfer_end(v9, v10, v11);
    }
    if ( *(_BYTE *)(v7 + 544LL * a2 + 4528) == 1 )
    {
      v12 = (unsigned int)(*(_DWORD *)(v7 + 544LL * a2 + 4532) + 1);
      *(_DWORD *)(v7 + 544LL * a2 + 4532) = v12;
      v13 = debug_mdl;
      if ( (debug_mdl & 0x4000) == 0 )
        return cam_io_w_mb(v12, v4 + v6 + 768);
    }
    else
    {
      v12 = cam_io_r_mb(v4 + v6 + 772);
      v13 = debug_mdl;
      if ( (debug_mdl & 0x4000) == 0 )
        return cam_io_w_mb(v12, v4 + v6 + 768);
    }
    if ( !debug_priority )
    {
      v14 = *(_DWORD *)(v7 + 404);
      v15 = v12;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v13 & 0x4000,
        4,
        "cam_cci_lock_queue",
        231,
        "CCI%d_I2C_M%d_Q%d_EXEC_WORD_CNT_ADDR %d",
        v14,
        a2,
        0,
        v12);
      v12 = v15;
    }
    return cam_io_w_mb(v12, v4 + v6 + 768);
  }
  return result;
}
