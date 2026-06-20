__int64 __fastcall dw9785_fw_checksum_check(__int64 a1, __int64 a2)
{
  int *v3; // x22
  unsigned int v5; // w0
  unsigned int v6; // w20
  int v8; // w19
  int v9; // w20
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  v11[0] = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_checksum_check",
      367,
      "Invalid Args");
    v6 = -22;
    goto LABEL_9;
  }
  v3 = &dw9785_fw_checksum_regs;
  v5 = cam_cci_i2c_read(
         *(_QWORD *)(a1 + 3672),
         (unsigned int)dw9785_fw_checksum_regs,
         &v10,
         *(unsigned int *)(a2 + 8),
         *(unsigned int *)(a2 + 12),
         1);
  if ( v5
    || (v3 = &dword_BC3D0,
        (v5 = cam_cci_i2c_read(
                *(_QWORD *)(a1 + 3672),
                (unsigned int)dword_BC3D0,
                (char *)&v10 + 4,
                *(unsigned int *)(a2 + 8),
                *(unsigned int *)(a2 + 12),
                1)) != 0)
    || (v3 = &dword_BC3E0,
        (v5 = cam_cci_i2c_read(
                *(_QWORD *)(a1 + 3672),
                (unsigned int)dword_BC3E0,
                v11,
                *(unsigned int *)(a2 + 8),
                *(unsigned int *)(a2 + 12),
                1)) != 0)
    || (v3 = &dword_BC3F0,
        (v5 = cam_cci_i2c_read(
                *(_QWORD *)(a1 + 3672),
                (unsigned int)dword_BC3F0,
                (char *)v11 + 4,
                *(unsigned int *)(a2 + 8),
                *(unsigned int *)(a2 + 12),
                1)) != 0) )
  {
    v6 = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_checksum_check",
      381,
      "Failed to read register 0x%04X: %d",
      *v3,
      v5);
    goto LABEL_9;
  }
  v8 = v11[0];
  v9 = HIDWORD(v11[0]);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x100000,
    1,
    "dw9785_fw_checksum_check",
    389,
    "[dw9785_fw_checksum] fw checksum(0x74FE) : 0x%04X%04X",
    v10,
    HIDWORD(v10));
  if ( v9 != 65280 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_checksum_check",
      396,
      "[dw9785_fw_checksum_check] read_verification_checksum : 0x%04X - fail",
      v9);
    v6 = 9;
    goto LABEL_9;
  }
  if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "dw9785_fw_checksum_check",
      393,
      "[dw9785_fw_checksum_check] read_verification_checksum : 0x%04X - pass",
      65280);
  if ( (~v8 & 7) != 0 )
  {
    if ( (v8 & 1) != 0 )
    {
      if ( (v8 & 2) != 0 )
        goto LABEL_21;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_fw_checksum_check",
        406,
        "[dw9785_fw_checksum_check] fw flash checksum(bit[0]) : 0x%04X - error",
        v8);
      if ( (v8 & 2) != 0 )
      {
LABEL_21:
        if ( (v8 & 4) != 0 )
        {
LABEL_23:
          v6 = 10;
          goto LABEL_9;
        }
LABEL_22:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x100000,
          1,
          "dw9785_fw_checksum_check",
          414,
          "[dw9785_fw_checksum_check] param flash checksum(bit[2]) : 0x%04X - error",
          v8);
        goto LABEL_23;
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_checksum_check",
      410,
      "[dw9785_fw_checksum_check] data_X flash checksum(bit[1]) : 0x%04X - error",
      v8);
    if ( (v8 & 4) != 0 )
      goto LABEL_23;
    goto LABEL_22;
  }
  v6 = 0;
  if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "dw9785_fw_checksum_check",
      402,
      "[dw9785_fw_checksum_check] flash_checksum(0x%04X) : 0x%04X - pass",
      53264,
      v8);
    v6 = 0;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v6;
}
