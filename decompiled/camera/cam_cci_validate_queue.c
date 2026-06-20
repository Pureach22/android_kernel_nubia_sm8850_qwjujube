__int64 __fastcall cam_cci_validate_queue(__int64 a1, int a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x24
  __int64 v9; // x27
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x26
  __int64 v14; // x25
  unsigned int v15; // w22
  __int64 v16; // x8
  __int64 v17; // x23
  __int64 v18; // x0
  __int64 v19; // x27
  int v20; // w8
  int v21; // w8
  unsigned int *v22; // x26
  unsigned int *v23; // x28
  __int64 v24; // x23
  __int64 result; // x0
  unsigned int v26; // w21
  int v27; // w22
  unsigned int v28; // [xsp+2Ch] [xbp-4h]

  v4 = *(_QWORD *)(a1 + 672);
  v9 = (a4 << 8) + (a3 << 9);
  v10 = cam_io_r_mb(v4 + v9 + 772);
  if ( (debug_mdl & 0x4000) == 0 || debug_priority )
  {
    if ( a4 <= 1 )
    {
      v13 = a3;
      v14 = a4;
      goto LABEL_5;
    }
LABEL_26:
    __break(0x5512u);
    return cam_cci_write_i2c_queue(v10, v11, v12);
  }
  if ( a4 > 1 )
    goto LABEL_26;
  v13 = a3;
  v27 = v10;
  v14 = a4;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x4000,
    4,
    "cam_cci_validate_queue",
    107,
    "CCI%d_I2C_M%d_Q%d_CUR_WORD_CNT_ADDR %d len %d max %d",
    *(_DWORD *)(a1 + 404),
    a3,
    a4,
    v10,
    a2,
    *(_DWORD *)(a1 + 32LL * a3 + 16LL * a4 + 3972));
  LODWORD(v10) = v27;
LABEL_5:
  v15 = v10 + 1;
  v16 = a1 + 32 * v13 + 16 * v14;
  if ( (unsigned int)(v10 + 1 + a2) <= *(_DWORD *)(v16 + 3972) )
    return 0;
  v17 = v16 + 3972;
  v18 = (16 * *(_DWORD *)(v16 + 3976)) | 0x308u;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v28 = (16 * *(_DWORD *)(v16 + 3976)) | 0x308;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_validate_queue",
      117,
      "CCI%d_I2C_M%d_Q%d_REPORT_CMD",
      *(_DWORD *)(a1 + 404),
      a3,
      a4);
    v18 = v28;
  }
  v19 = v4 + v9;
  cam_io_w_mb(v18, v19 + 784);
  v20 = *(_DWORD *)(v17 + 4);
  if ( v20 == 15 )
    v21 = 0;
  else
    v21 = v20 + 1;
  *(_DWORD *)(v17 + 4) = v21;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_validate_queue",
      128,
      "CCI%d_I2C_M%d_Q%d_EXEC_WORD_CNT_ADDR %d",
      *(_DWORD *)(a1 + 404),
      a3,
      a4,
      v15);
  cam_io_w_mb(v15, v19 + 768);
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_validate_queue",
      132,
      "CCI%d_I2C_M%d_Q%d_START_ADDR",
      *(_DWORD *)(a1 + 404),
      a3,
      a4);
  v22 = (unsigned int *)(a1 + 544LL * (unsigned int)v13 + 4040);
  v23 = &v22[v14];
  v24 = raw_spin_lock_irqsave(v23 + 82);
  v23[80] = 1;
  cam_io_w_mb((unsigned int)(1 << (a4 + 2 * a3)), v4 + 8);
  v23[1] = 1;
  raw_spin_unlock_irqrestore(v23 + 82, v24);
  if ( cam_common_wait_for_completion_timeout((__int64)&v22[8 * v14 + 64]) )
  {
    result = *v22;
    if ( (result & 0x80000000) != 0 )
    {
      v26 = *v22;
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_validate_queue",
        154);
      *v22 = 0;
      return v26;
    }
  }
  else
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_validate_queue",
      147);
    cam_cci_flush_queue(a1, a3);
    return 4294967274LL;
  }
  return result;
}
