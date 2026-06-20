__int64 __fastcall dw9785_fw_eflash_erase(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v6; // w19
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x19
  __int64 v11; // x20

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_eflash_erase",
      275,
      "Invalid Args");
    return (unsigned int)-22;
  }
  v2 = debug_priority;
  v3 = debug_mdl & 0x100000;
  if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
  {
    v8 = a1;
    v9 = a2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x100000,
      4,
      "dw9785_fw_eflash_erase",
      277,
      "[dw9785_fw_eflash_erase] start");
    v2 = debug_priority;
    a2 = v9;
    a1 = v8;
    v3 = debug_mdl & 0x100000;
    if ( (debug_mdl & 0x100000) != 0 )
    {
LABEL_6:
      if ( !v2 )
      {
        v10 = a1;
        v11 = a2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v3,
          4,
          "dw9785_fw_eflash_erase",
          278,
          "[dw9785_fw_eflash_erase] prog_auto_erase Run");
        a2 = v11;
        a1 = v10;
      }
    }
  }
  else if ( v3 )
  {
    goto LABEL_6;
  }
  v4 = a2;
  v5 = a1;
  v6 = zte_cam_cci_i2c_write(
         a1 + 3656,
         (unsigned int)dword_BC3B0,
         (unsigned int)dword_BC3B4,
         *(unsigned int *)(a2 + 8),
         *(unsigned int *)(a2 + 12));
  msleep((unsigned int)dword_BC3B8);
  if ( v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_eflash_erase",
      287,
      "Failed to dw9785 fw_eflash_erase %d",
      v6);
  }
  else if ( (unsigned int)dw9785_fw_wait_check_register(v5, v4, 3u, 0x1Eu) )
  {
    v6 = 3;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_fw_eflash_erase",
      290,
      "[dw9785_fw_eflash_erase] fail");
  }
  else
  {
    v6 = 0;
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "dw9785_fw_eflash_erase",
        294,
        "[dw9785_fw_eflash_erase] finish");
      return 0;
    }
  }
  return v6;
}
