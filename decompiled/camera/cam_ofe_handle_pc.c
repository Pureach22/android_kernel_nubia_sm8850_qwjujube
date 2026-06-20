__int64 __fastcall cam_ofe_handle_pc(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x21
  unsigned int v4; // w0
  unsigned int v5; // w19
  const char *v6; // x5
  __int64 v7; // x4
  unsigned int v8; // w0
  __int64 v9; // x5
  unsigned int gdsc_control; // w0
  unsigned int v11; // w0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 3680);
  v13[0] = 0;
  if ( (v1[2] & 1) != 0 )
  {
    v2 = *v1;
    v4 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(*v1 + 4), 1, (_DWORD *)v13 + 1);
    if ( v4 )
    {
      v5 = v4;
      v6 = "power ctrl read failed rc=%d";
      v7 = 217;
LABEL_19:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        256,
        1,
        "cam_ofe_handle_pc",
        v7,
        v6,
        v5);
      goto LABEL_20;
    }
    if ( (v13[0] & 0x100000000LL) == 0 )
    {
      v8 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 8), 1, v13);
      if ( v8 )
      {
        v5 = v8;
        v6 = "power status read failed rc=%d";
        v7 = 226;
        goto LABEL_19;
      }
      cam_cpas_reg_write(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 4), 1, 1, v9);
      if ( LODWORD(v13[0]) >= 4 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x2000000,
          2,
          "cam_ofe_handle_pc",
          236,
          "OFE: pwr_status(%x):pwr_ctrl(%x)",
          LODWORD(v13[0]),
          HIDWORD(v13[0]));
    }
    gdsc_control = cam_ofe_get_gdsc_control(a1 + 96);
    if ( gdsc_control )
    {
      v5 = gdsc_control;
      v6 = "failed to get gdsc control rc=%d";
      v7 = 241;
      goto LABEL_19;
    }
    v11 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 4), 1, (_DWORD *)v13 + 1);
    if ( v11 )
    {
      v5 = v11;
      v6 = "power ctrl read failed rc=%d";
      v7 = 249;
      goto LABEL_19;
    }
    v5 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 8), 1, v13);
    if ( v5 )
    {
      v6 = "power status read failed rc=%d";
      v7 = 257;
      goto LABEL_19;
    }
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_ofe_handle_pc",
        261,
        "pwr_ctrl=%x pwr_status=%x",
        HIDWORD(v13[0]),
        LODWORD(v13[0]));
      goto LABEL_7;
    }
  }
  else
  {
    v5 = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_ofe_handle_pc",
        209,
        "CPAS OFE client not started");
LABEL_7:
      v5 = 0;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v5;
}
