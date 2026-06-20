__int64 __fastcall cam_ois_dw9785_reset(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  unsigned int v5; // w3
  unsigned int v6; // w0
  unsigned int v7; // w19
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 48);
  v5 = *(_DWORD *)(a2 + 56);
  v9 = 0;
  v6 = cam_ois_write_regs(a1, a2, v4, v5);
  if ( v6 )
  {
    v7 = v6;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_dw9785_reset",
      249,
      "Failed to dw9785 reset %d",
      v6);
  }
  else
  {
    cam_cci_i2c_read(
      *(_QWORD *)(a1 + 3672),
      (unsigned int)dw9785_extra_regs,
      &v9,
      *(unsigned int *)(a2 + 8),
      *(unsigned int *)(a2 + 12),
      1);
    msleep(1);
    if ( v9 == 38789 )
    {
      v7 = 0;
      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "cam_ois_dw9785_reset",
          261,
          "[dw9785_mcu_enable] pass");
        v7 = 0;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_dw9785_reset",
        263,
        "[dw9785_mcu_enable] fail");
      v7 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
