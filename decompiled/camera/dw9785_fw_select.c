__int64 __fastcall dw9785_fw_select(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  const char *v5; // x5
  __int64 v6; // x4
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_select",
      305,
      "Invalid Args");
    v4 = -22;
    goto LABEL_10;
  }
  if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "dw9785_fw_select",
      307,
      "[FMC block FW select] start");
  v4 = zte_cam_cci_i2c_write(
         a1 + 3656,
         (unsigned int)dword_BC380,
         (unsigned int)dword_BC384,
         *(unsigned int *)(a2 + 8),
         *(unsigned int *)(a2 + 12));
  msleep((unsigned int)dword_BC388);
  if ( !v4 )
  {
    cam_cci_i2c_read(
      *(_QWORD *)(a1 + 3672),
      (unsigned int)dword_BC380,
      &v11,
      *(unsigned int *)(a2 + 8),
      *(unsigned int *)(a2 + 12),
      1);
    if ( v11 != 32 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_fw_select",
        327,
        "[dw9785_download_fw] fmc register value 1st warning : %04x",
        v11);
      v4 = zte_cam_cci_i2c_write(
             a1 + 3656,
             (unsigned int)dword_BC380,
             32,
             *(unsigned int *)(a2 + 8),
             *(unsigned int *)(a2 + 12));
      msleep((unsigned int)dword_BC388);
      if ( v4 )
      {
        v5 = "Failed to dw9785 fmc register %d";
        v6 = 334;
        goto LABEL_8;
      }
      v8 = *(unsigned int *)(a2 + 8);
      v9 = *(unsigned int *)(a2 + 12);
      v10 = *(_QWORD *)(a1 + 3672);
      v11 = 0;
      cam_cci_i2c_read(v10, (unsigned int)dword_BC380, &v11, v8, v9, 1);
      if ( v11 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "dw9785_fw_select",
          345,
          "[dw9785_download_fw] 2nd fmc register value 2nd warning : %04x",
          v11);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "dw9785_fw_select",
          346,
          "[dw9785_download_fw] stop f/w download");
        v4 = 7;
        goto LABEL_10;
      }
    }
    v4 = 0;
    goto LABEL_10;
  }
  v5 = "Failed to dw9785 fw_select %d";
  v6 = 316;
LABEL_8:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x100000,
    1,
    "dw9785_fw_select",
    v6,
    v5,
    v4);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v4;
}
