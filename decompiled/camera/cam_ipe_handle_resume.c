__int64 __fastcall cam_ipe_handle_resume(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x21
  unsigned int v4; // w0
  __int64 v5; // x5
  unsigned int v6; // w19
  const char *v7; // x5
  __int64 v8; // x4
  unsigned int v9; // w0
  unsigned int v10; // w0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 3680);
  v12[0] = 0;
  if ( (v1[2] & 1) != 0 )
  {
    v2 = *v1;
    v4 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(*v1 + 4), 1, (_DWORD *)v12 + 1);
    if ( v4 )
    {
      v6 = v4;
      v7 = "power ctrl read failed rc=%d";
      v8 = 290;
LABEL_19:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        256,
        1,
        "cam_ipe_handle_resume",
        v8,
        v7,
        v6);
      goto LABEL_20;
    }
    if ( (v12[0] & 0x100000000LL) != 0 )
    {
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000100,
          4,
          "cam_ipe_handle_resume",
          295,
          "IPE pwr_ctrl set(%x)",
          HIDWORD(v12[0]));
      cam_cpas_reg_write(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 4), 1, 0, v5);
    }
    v9 = cam_ipe_transfer_gdsc_control(a1 + 96);
    if ( v9 )
    {
      v6 = v9;
      v7 = "failed to transfer gdsc control rc=%d";
      v8 = 303;
      goto LABEL_19;
    }
    v10 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 4), 1, (_DWORD *)v12 + 1);
    if ( v10 )
    {
      v6 = v10;
      v7 = "power ctrl read failed rc=%d";
      v8 = 311;
      goto LABEL_19;
    }
    v6 = cam_cpas_reg_read(*((_DWORD *)v1 + 2), 0, *(_DWORD *)(v2 + 8), 1, v12);
    if ( v6 )
    {
      v7 = "power status read failed rc=%d";
      v8 = 319;
      goto LABEL_19;
    }
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_ipe_handle_resume",
        323,
        "pwr_ctrl=%x pwr_status=%x",
        HIDWORD(v12[0]),
        LODWORD(v12[0]));
      goto LABEL_7;
    }
  }
  else
  {
    v6 = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_ipe_handle_resume",
        282,
        "CPAS IPE client not started");
LABEL_7:
      v6 = 0;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v6;
}
