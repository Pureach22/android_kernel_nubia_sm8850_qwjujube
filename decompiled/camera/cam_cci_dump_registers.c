__int64 __fastcall cam_cci_dump_registers(__int64 result, unsigned int a2, int a3)
{
  __int64 v5; // x26
  __int64 i; // x20
  __int64 v7; // x24
  __int64 v8; // x21
  __int64 v9; // x7
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x4
  const char *v13; // x5
  __int64 v14; // x6

  if ( (*(_BYTE *)(result + 5888) & 6) != 0 )
  {
    v5 = *(_QWORD *)(result + 672);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      255);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      258);
    for ( i = 0; i != 56; i += 4 )
    {
      cam_io_r_mb(v5 + i);
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
        "cam_cci_dump_registers",
        263);
    }
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      268);
    v7 = (a2 << 8) + 256;
    cam_io_r_mb(v5 + v7);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 4));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 8));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 0xC));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 0x10));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 0x14));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 0x1C));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    cam_io_r_mb(v5 + (v7 | 0x20));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      276);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      281);
    v8 = (a2 << 9) + (a3 << 8) + 768;
    cam_io_r_mb(v5 + v8);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    cam_io_r_mb(v5 + (v8 | 4));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    cam_io_r_mb(v5 + (v8 | 8));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    cam_io_r_mb(v5 + (v8 | 0xC));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    cam_io_r_mb(v5 + (v8 | 0x10));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    cam_io_r_mb(v5 + (v8 | 0x14));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    cam_io_r_mb(v5 + (v8 | 0x18));
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      287);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      291);
    cam_io_r_mb(v5 + 3072);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      296);
    cam_io_r_mb(v5 + 3076);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      296);
    cam_io_r_mb(v5 + 3080);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      296);
    cam_io_r_mb(v5 + 3084);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      296);
    cam_io_r_mb(v5 + 3088);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      296);
    cam_io_r_mb(v5 + 3092);
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 3,
      "cam_cci_dump_registers",
      296);
    v9 = (unsigned int)cam_io_r_mb(v5 + 3096);
    v10 = 0x4000;
    v11 = 3;
    v12 = 296;
    v13 = "offset = 0x%X value = 0x%X";
    v14 = 3096;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
             3,
             v10,
             v11,
             "cam_cci_dump_registers",
             v12,
             v13,
             v14,
             v9);
  }
  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
  {
    v14 = *(unsigned int *)(result + 404);
    v13 = "CCI%d_I2C_M%d_Q%d Nack and Timeout dump is not enabled";
    v10 = debug_mdl & 0x4000;
    v11 = 4;
    v12 = 250;
    v9 = a2;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
             3,
             v10,
             v11,
             "cam_cci_dump_registers",
             v12,
             v13,
             v14,
             v9);
  }
  return result;
}
