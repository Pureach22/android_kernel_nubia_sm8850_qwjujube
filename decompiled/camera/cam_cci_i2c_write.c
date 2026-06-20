__int64 __fastcall cam_cci_i2c_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v5; // x6
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x9
  __int64 v9; // x19
  unsigned int v11; // w22
  unsigned int v12; // w20
  __int64 v13; // x24
  unsigned int v14; // w0
  __int64 v15; // x9
  unsigned int v16; // w0
  unsigned int v17; // w8
  unsigned int v18; // w22
  unsigned int v19; // w21
  unsigned int v21; // w0
  __int64 v22; // x23
  int v23; // [xsp+10h] [xbp-10h]

  v4 = *(_QWORD *)(a1 + 240);
  if ( !v4 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_i2c_write",
      2017);
    return 4294967274LL;
  }
  if ( *(_DWORD *)(v4 + 3968) )
  {
    v5 = *(unsigned int *)(v4 + 404);
    v6 = "invalid cci: %d state: %d";
    v7 = 2023;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_i2c_write",
      v7,
      v6,
      v5);
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(a2 + 8);
  v9 = *(unsigned int *)(v8 + 16);
  if ( (unsigned int)v9 >= 2 )
  {
    v5 = *(unsigned int *)(v4 + 404);
    v6 = "CCI%d_I2C_M%d Invalid I2C master addr";
    v7 = 2030;
    goto LABEL_7;
  }
  v11 = a4;
  v12 = a3;
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v22 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_i2c_write",
      2036,
      "CCI%d_I2C_M%d_Q%d set param sid 0x%x retries %d id_map %d",
      *(_DWORD *)(v4 + 404),
      v9,
      a3,
      *(unsigned __int16 *)(v8 + 20),
      *(unsigned __int16 *)(v8 + 28),
      *(unsigned __int16 *)(v8 + 30));
    a2 = v22;
  }
  v13 = a2;
  v14 = cam_cci_set_clk_param(v4, a2, a3, a4);
  if ( (v14 & 0x80000000) != 0 )
  {
    v19 = v14;
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_i2c_write",
      2042);
    return v19;
  }
  if ( v12 >= 3
    || (v15 = v4 + 544LL * (unsigned int)v9 + 4040 + 32LL * v12,
        *(_DWORD *)(v15 + 256) = 0,
        *(_DWORD *)(v15 + 416) = 0,
        v12 == 2) )
  {
    __break(0x5512u);
    return cam_cci_i2c_write_async();
  }
  v16 = cam_cci_validate_queue(v4, *(_DWORD *)(v4 + 32 * v9 + 16LL * v12 + 3972) - 1, v9, v12);
  if ( (v16 & 0x80000000) != 0 )
  {
    v18 = v16;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, unsigned int, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_i2c_write",
      2057,
      "CCI%d_I2C_M%d_Q%d Initial validataion failed rc %d",
      *(unsigned int *)(v4 + 404),
      (unsigned int)v9,
      v12,
      v16,
      v23);
  }
  else
  {
    v17 = *(unsigned __int16 *)(*(_QWORD *)(v13 + 8) + 28LL);
    if ( v17 < 4 )
    {
      if ( *(_DWORD *)(v13 + 16) == 8 )
      {
        v21 = cam_cci_data_queue_burst(v4, v13, v12, v11);
        if ( (v21 & 0x80000000) != 0 )
        {
          v18 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, unsigned int, int))cam_print_log)(
            3,
            0x4000,
            1,
            "cam_cci_i2c_write",
            2071,
            "CCI%d_I2C_M%d_Q%d Failed in queueing i2c Burst write data for rc: %d",
            *(unsigned int *)(v4 + 404),
            (unsigned int)v9,
            v12,
            v21,
            v23);
          goto LABEL_20;
        }
      }
      else
      {
        v21 = cam_cci_data_queue(v4, v13, v12, v11);
        if ( (v21 & 0x80000000) != 0 )
        {
          v18 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, unsigned int, int))cam_print_log)(
            3,
            0x4000,
            1,
            "cam_cci_i2c_write",
            2079,
            "CCI%d_I2C_M%d_Q%d Failed in queueing the data for rc: %d",
            *(unsigned int *)(v4 + 404),
            (unsigned int)v9,
            v12,
            v21,
            v23);
          goto LABEL_20;
        }
      }
      v18 = v21;
      goto LABEL_20;
    }
    v18 = v16;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int, unsigned int, int))cam_print_log)(
      3,
      0x4000,
      1,
      "cam_cci_i2c_write",
      2063,
      "CCI%d_I2C_M%d_Q%d Invalid read retries info retries from slave: %d, max retries: %d",
      *(unsigned int *)(v4 + 404),
      (unsigned int)v9,
      v12,
      v17,
      3);
  }
LABEL_20:
  mutex_lock(v4 + 544LL * (unsigned int)v9 + 4400);
  if ( --*(_WORD *)(v4 + 544LL * (unsigned int)v9 + 4448) == 0 )
    up(v4 + 544LL * (unsigned int)v9 + 4376);
  mutex_unlock(v4 + 544LL * (unsigned int)v9 + 4400);
  return v18;
}
