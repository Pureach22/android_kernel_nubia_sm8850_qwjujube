__int64 __fastcall dw9785_fw_wait_check_register(__int64 a1, __int64 a2, unsigned __int16 a3, unsigned __int16 a4)
{
  int v5; // w23
  int v8; // w25
  int v9; // w24
  unsigned int v10; // w22
  __int64 result; // x0
  int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v5 = a3;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  if ( a3 )
  {
    v8 = 0;
    v9 = 0;
    v10 = a4;
    while ( 1 )
    {
      cam_cci_i2c_read(
        *(_QWORD *)(a1 + 3672),
        (unsigned int)dword_BC370,
        &v12,
        *(unsigned int *)(a2 + 8),
        *(unsigned int *)(a2 + 12),
        1);
      if ( v12 == dword_BC374 )
        break;
      msleep(v10);
      ++v9;
      v8 += v10;
      if ( v5 == v9 )
        goto LABEL_5;
    }
    result = 0;
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "dw9785_fw_wait_check_register",
        228,
        "[dw9785_fw_wait_check_register] pass (addr : 0x%04X, data : 0x%04X, cnt: %d, delay: %dms)",
        dword_BC370,
        v12,
        v9,
        v8);
      result = 0;
    }
  }
  else
  {
LABEL_5:
    result = 0xFFFFFFFFLL;
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "dw9785_fw_wait_check_register",
        235,
        "[dw9785_fw_wait_check_register] fail (addr : 0x%04X, data : 0x%04X, cnt: %d, time: %dms)",
        dword_BC370,
        v12,
        v5,
        a4 * v5);
      result = 0xFFFFFFFFLL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
