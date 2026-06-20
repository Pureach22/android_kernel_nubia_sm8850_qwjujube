__int64 __fastcall cam_cci_set_clk_param(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  unsigned int v6; // w22
  __int64 v7; // x20
  __int64 v9; // x23
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x24
  int v13; // w9
  unsigned int v14; // w10
  __int16 v15; // w8
  __int64 v16; // x25
  __int64 v17; // x26
  __int64 v18; // x27
  __int64 v19; // x28
  __int64 v20; // x8
  unsigned __int16 *v21; // x20

  v4 = *(_QWORD *)(a2 + 8);
  v5 = *(unsigned int *)(v4 + 16);
  if ( (unsigned int)v5 >= 3 )
    goto LABEL_18;
  v6 = *(_DWORD *)(v4 + 12);
  v7 = a1;
  if ( v6 >= 4 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_set_clk_param",
      676);
    return 4294967274LL;
  }
  v9 = *(_QWORD *)(a1 + 672);
  v10 = a1 + 544LL * (unsigned int)v5;
  v11 = v10 + 4040;
  a1 = mutex_lock(v10 + 4056);
  if ( (_DWORD)v5 == 2 )
  {
LABEL_18:
    __break(0x5512u);
    return cam_cci_validate_queue(a1, a2, a3, a4);
  }
  else
  {
    v12 = v7 + 5128;
    v13 = *(_DWORD *)(v7 + 5128 + 4 * v5);
    v14 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 14);
    if ( v6 == v13 )
    {
      if ( v14 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_set_clk_param",
          688,
          "CCI%d_I2C_M%d, curr_freq: %d",
          *(_DWORD *)(v7 + 404),
          v5,
          v6);
      mutex_lock(v11 + 360);
      v15 = *(_WORD *)(v11 + 408);
      if ( !v15 )
      {
        down(v11 + 336);
        v15 = *(_WORD *)(v11 + 408);
      }
      *(_WORD *)(v11 + 408) = v15 + 1;
      mutex_unlock(v11 + 360);
    }
    else
    {
      if ( v14 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_set_clk_param",
          698,
          "CCI%d_I2C_M%d, curr_freq: %d, req_freq: %d",
          *(_DWORD *)(v7 + 404),
          v5,
          v13,
          v6);
      down(v11 + 336);
      mutex_lock(v11 + 360);
      ++*(_WORD *)(v11 + 408);
      mutex_unlock(v11 + 360);
      if ( (_DWORD)v5 )
      {
        v16 = 528;
        v17 = 524;
        v18 = 520;
        v19 = 516;
        v20 = 512;
      }
      else
      {
        v16 = 272;
        v17 = 268;
        v18 = 264;
        v19 = 260;
        v20 = 256;
      }
      v21 = (unsigned __int16 *)(v7 + 24LL * v6 + 5140);
      cam_io_w_mb(v21[1] | (*v21 << 16), v9 + v20);
      cam_io_w_mb(v21[3] | (v21[2] << 16), v9 + v19);
      cam_io_w_mb(v21[5] | (v21[4] << 16), v9 + v18);
      cam_io_w_mb(v21[6], v9 + v17);
      cam_io_w_mb(
        (16 * *((unsigned __int8 *)v21 + 15))
      | (*((unsigned __int8 *)v21 + 14) << 8)
      | (unsigned int)*((unsigned __int8 *)v21 + 16),
        v9 + v16);
      *(_DWORD *)(v12 + 4 * v5) = v6;
    }
    mutex_unlock(v11 + 16);
    return 0;
  }
}
