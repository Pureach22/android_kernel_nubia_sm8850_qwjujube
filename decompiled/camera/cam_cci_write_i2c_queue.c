__int64 __fastcall cam_cci_write_i2c_queue(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x23
  unsigned int v7; // w19

  v3 = *(_QWORD *)(a1 + 672);
  v7 = cam_cci_validate_queue(a1, 1, a3, 1u);
  if ( (v7 & 0x80000000) != 0 )
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_write_i2c_queue",
      184);
  }
  else
  {
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_write_i2c_queue",
        190,
        "CCI%d_I2C_M%d_Q%d_LOAD_DATA_ADDR:val 0x%x:0x%x ",
        *(_DWORD *)(a1 + 404),
        a3,
        1,
        (a3 << 9) + 1040,
        a2);
    cam_io_w_mb(a2, v3 + (((a3 & 0x3FFFFF) << 9) | 0x100) + 784);
  }
  return v7;
}
