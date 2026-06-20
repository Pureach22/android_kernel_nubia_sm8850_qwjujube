__int64 __fastcall cam_cci_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x6
  __int64 v5; // x20
  __int64 v6; // x19
  __int64 v7; // x6
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x7
  __int64 result; // x0
  int v12; // w8
  __int64 v13; // x23
  unsigned int inited; // w0
  __int64 v15; // x8
  unsigned int v16; // w20
  unsigned int v17; // w0
  unsigned int v18; // w0
  int v19; // w0
  int v20; // w0
  __int64 v21; // x8
  unsigned int v22; // w0
  __int64 v23; // x8
  __int64 v24; // x8
  int v25; // w0
  __int64 v26; // [xsp+0h] [xbp-280h]
  __int64 v27; // [xsp+8h] [xbp-278h] BYREF
  __int64 v28; // [xsp+10h] [xbp-270h]
  _QWORD s[77]; // [xsp+18h] [xbp-268h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  memset(s, 0, 0x260u);
  v4 = *(_QWORD *)(a1 + 240);
  if ( a2 && v4 )
  {
    v5 = *(_QWORD *)(v4 + 672);
    v6 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 16LL);
    if ( !v5 )
    {
      v7 = *(unsigned int *)(v4 + 404);
      v8 = "CCI%d_I2C_M%d failed: invalid params base:%pK";
      v9 = 145;
      v10 = (unsigned int)v6;
      v26 = 0;
      goto LABEL_8;
    }
    if ( (unsigned int)v6 >= 2 )
    {
      v7 = *(unsigned int *)(v4 + 404);
      v8 = "CCI%d_I2C_M%d Incorrect Master";
      v9 = 152;
      v10 = (unsigned int)v6;
LABEL_8:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
        3,
        0x4000,
        1,
        "cam_cci_init",
        v9,
        v8,
        v7,
        v10,
        v26,
        v27,
        v28);
      result = 4294967274LL;
      goto LABEL_35;
    }
    if ( !*(_QWORD *)(v4 + 8 * v6 + 5280) )
    {
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_init",
        158);
      result = 4294967284LL;
      goto LABEL_35;
    }
    v12 = *(unsigned __int8 *)(v4 + 3964);
    v13 = v4;
    *(_BYTE *)(v4 + 3964) = v12 + 1;
    if ( v12 )
    {
      inited = cam_cci_init_master(v4, (unsigned int)v6);
      v15 = v13;
      v16 = inited;
      if ( inited )
      {
        ((void (*)(__int64, const char *, ...))cam_print_log)(
          3,
          print_fmt_cam_context_state,
          (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
          "cam_cci_init",
          167);
        v15 = v13;
        --*(_BYTE *)(v13 + 3964);
      }
      if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_init",
          171,
          "CCI%d_I2C_M%d ref_count %d",
          *(_DWORD *)(v15 + 404),
          v6,
          *(unsigned __int8 *)(v15 + 3964));
      goto LABEL_34;
    }
    v17 = *(_DWORD *)(v4 + 5816);
    LODWORD(v28) = 2;
    LODWORD(v27) = 0;
    *(_QWORD *)((char *)&s[1] + 4) = 0x10000000001LL;
    LODWORD(s[0]) = 1;
    s[3] = 1024;
    s[4] = 1024;
    s[5] = 1024;
    v18 = cam_cpas_start(v17, (__int64)&v27, (__int64)s);
    if ( v18 )
    {
      v16 = v18;
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_init",
        187);
LABEL_34:
      result = v16;
      goto LABEL_35;
    }
    ((void (__fastcall *)(__int64, __int64))cam_cci_get_clk_rates)(v13, a2);
    v19 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
            v13 + 384,
            0xFFFFFFFFLL,
            1,
            *(unsigned int *)(v13 + 3256),
            1);
    if ( v19 < 0 )
    {
      if ( (debug_mdl & 0x4000) != 0 )
      {
        v16 = v19;
        v23 = v13;
        if ( debug_priority )
        {
LABEL_33:
          v25 = *(_DWORD *)(v23 + 5816);
          --*(_BYTE *)(v23 + 3964);
          cam_cpas_stop(v25);
          goto LABEL_34;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x4000,
          4,
          "cam_cci_init",
          198,
          "CCI%d_I2C_M%d request platform resources failed, rc: %d",
          *(_DWORD *)(v13 + 404),
          v6,
          v19);
      }
      else
      {
        v16 = v19;
      }
LABEL_32:
      v23 = v13;
      goto LABEL_33;
    }
    v20 = cam_io_r_mb(v5);
    v21 = v13;
    *(_DWORD *)(v13 + 3960) = v20;
    if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000,
        4,
        "cam_cci_init",
        204,
        "CCI%d_I2C_M%d hw_version = 0x%x",
        *(_DWORD *)(v13 + 404),
        v6,
        v20);
      v21 = v13;
    }
    *(_BYTE *)(v13 + 5792) = 11;
    *(_BYTE *)(v13 + 5273) = 1;
    v22 = cam_cci_init_master(v21, (unsigned int)v6);
    if ( v22 )
    {
      v16 = v22;
      ((void (*)(__int64, const char *, ...))cam_print_log)(
        3,
        print_fmt_cam_context_state,
        (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
        "cam_cci_init",
        212);
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
        v13 + 384,
        0xFFFFFFFFLL,
        1,
        1);
      goto LABEL_32;
    }
    *(_QWORD *)(v13 + 5128) = 0x400000004LL;
    cam_io_w_mb(2147450871, v5 + 3076);
    cam_io_w_mb(2147450871, v5 + 3080);
    cam_io_w_mb(14483456, v5 + 3088);
    cam_io_w_mb(14483456, v5 + 3092);
    cam_io_w_mb(1, v5 + 3072);
    v24 = v13;
    if ( *(_DWORD *)(v13 + 3960) != 268566537 )
    {
      cam_io_w_mb(48, v5 + 288);
      cam_io_w_mb(48, v5 + 544);
      v24 = v13;
    }
    result = 0;
    *(_DWORD *)(v24 + 3968) = 0;
  }
  else
  {
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_init",
      124);
    result = 4294967274LL;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
