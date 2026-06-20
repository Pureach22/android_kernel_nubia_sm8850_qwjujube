__int64 __fastcall cam_cci_load_report_cmd(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x23
  __int64 v7; // x24
  int v8; // w0
  int v9; // w22
  __int64 v10; // x25
  int v11; // w8
  __int64 v12; // x0
  int *v13; // x25
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x0
  int v17; // w8
  __int16 v18; // w22
  int v20; // w21
  unsigned int v21; // w25
  int v22; // w0
  unsigned int v23; // [xsp+1Ch] [xbp-4h]

  v3 = *(_QWORD *)(a1 + 672);
  v7 = (a3 << 8) + (a2 << 9);
  v8 = cam_io_r_mb(v3 + v7 + 772);
  if ( a2 >= 2 || a3 > 1 )
  {
    __break(0x5512u);
    JUMPOUT(0x26910C);
  }
  v9 = v8;
  v10 = a1 + 32LL * a2 + 16LL * a3;
  v11 = *(_DWORD *)(v10 + 3976);
  v12 = (16 * v11) | 0x308u;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v23 = (16 * v11) | 0x308;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_load_report_cmd",
      358,
      "CCI%d_I2C_M%d_Q%d_REPORT_CMD curr_w_cnt: %d report_id %d",
      *(_DWORD *)(a1 + 404),
      a2,
      a3,
      v9,
      v11);
    v12 = v23;
  }
  v13 = (int *)(v10 + 3976);
  cam_io_w_mb(v12, v3 + v7 + 784);
  v14 = a1 + 544LL * a2 + 4040;
  if ( *(_BYTE *)(v14 + a3 + 488) == 1 )
  {
    v15 = v14 + 4LL * a3;
    v16 = (unsigned int)(*(_DWORD *)(v15 + 492) + 1);
    *(_DWORD *)(v15 + 492) = v16;
  }
  else
  {
    v16 = (unsigned int)(v9 + 1);
  }
  if ( *v13 == 15 )
    v17 = 0;
  else
    v17 = *v13 + 1;
  *v13 = v17;
  v18 = debug_mdl;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v20 = *(_DWORD *)(a1 + 404);
    v21 = v16;
    v22 = cam_io_r_mb(v3 + v7 + 768);
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v18 & 0x4000,
      4,
      "cam_cci_load_report_cmd",
      374,
      "CCI%d_I2C_M%d_Q%d_EXEC_WORD_CNT_ADDR %d (ReadValue: %u)",
      v20,
      a2,
      a3,
      v21,
      v22);
    v16 = v21;
  }
  return cam_io_w_mb(v16, v3 + v7 + 768);
}
