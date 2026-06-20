__int64 __fastcall cam_ois_read_firmware_ver(__int64 a1, __int64 a2)
{
  int v4; // w6
  int v5; // w7
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x0
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x0
  int v12; // w0
  unsigned int v13; // w19
  __int64 result; // x0
  unsigned int v15; // w20
  int v16; // [xsp+10h] [xbp-10h] BYREF
  int v17; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_read_firmware_ver",
      516,
      "Invalid Args");
LABEL_15:
    result = 0xFFFFFF;
    goto LABEL_16;
  }
  *(_WORD *)(*(_QWORD *)(a1 + 3672) + 20LL) = *(_WORD *)(a2 + 4) >> 1;
  *(_DWORD *)(*(_QWORD *)(a1 + 3672) + 12LL) = 0;
  msleep(5);
  v4 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 != 1 )
  {
    if ( v4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_read_firmware_ver",
        533,
        "Unsupported OIS model: %d",
        v4);
      v5 = -22;
    }
    else
    {
      v5 = cam_ois_write_regs(a1, a2, *(_QWORD *)(a2 + 48), *(_DWORD *)(a2 + 56));
      if ( !v5 )
        goto LABEL_9;
    }
    goto LABEL_14;
  }
  v5 = cam_ois_dw9785_reset(a1, a2);
  if ( v5 )
  {
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_read_firmware_ver",
      537,
      "%s: Failed to reset %d",
      (const char *)(a1 + 4516),
      v5);
    goto LABEL_15;
  }
LABEL_9:
  v6 = *(unsigned int *)(a2 + 8);
  v7 = *(unsigned int *)(a2 + 12);
  v8 = *(_QWORD *)(a1 + 3672);
  v17 = 0;
  if ( (cam_cci_i2c_read(v8, 28673, &v17, v6, v7, 1) & 0x80000000) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_read_firmware_ver",
      545,
      "%s :%d: read vers id fail\n",
      "cam_ois_read_firmware_ver",
      545);
  v9 = *(unsigned int *)(a2 + 8);
  v10 = *(unsigned int *)(a2 + 12);
  v11 = *(_QWORD *)(a1 + 3672);
  v16 = 0;
  v12 = cam_cci_i2c_read(v11, 28674, &v16, v9, v10, 1);
  if ( v12 )
  {
    v13 = v12;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_read_firmware_ver",
      551,
      "read date fail %d",
      v12);
    result = v13;
  }
  else
  {
    v15 = v16 | (v17 << 16);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_read_firmware_ver",
      557,
      "%s ver:0x%x, date:0x%x firmware_ver:0x%x\n",
      (const char *)(a1 + 4516),
      v17,
      v16,
      v15);
    result = v15;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
