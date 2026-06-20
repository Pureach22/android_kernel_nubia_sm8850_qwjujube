__int64 __fastcall dw9785_download_fw(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x21
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  unsigned int v11; // w0
  unsigned int v12; // w19
  __int64 result; // x0
  int v14; // w8
  __int64 v15; // x1
  __int64 v16; // x21
  unsigned int v17; // w0
  const char *v18; // x5
  __int64 v19; // x4
  unsigned int v20; // w0
  int firmware_ver; // w8
  _QWORD *v22; // [xsp+0h] [xbp-50h] BYREF
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v24; // [xsp+10h] [xbp-40h]
  __int64 v25; // [xsp+18h] [xbp-38h]
  __int64 v26; // [xsp+20h] [xbp-30h]
  __int64 v27; // [xsp+28h] [xbp-28h]
  __int64 v28; // [xsp+30h] [xbp-20h]
  __int64 v29; // [xsp+38h] [xbp-18h]
  __int64 v30; // [xsp+40h] [xbp-10h]
  __int64 v31; // [xsp+48h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  *(_QWORD *)s = 0;
  v24 = 0;
  v22 = nullptr;
  if ( a1 && a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      3,
      "dw9785_download_fw",
      708,
      "dw9785_download_fw %s Entry",
      (const char *)(a1 + 4516));
    snprintf(s, 0x40u, "%s.prog", (const char *)(a1 + 4516));
    v11 = request_firmware(&v22, s, v3 + 16, v7, v8, v9, v10);
    if ( v11 )
    {
      v12 = v11;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_download_fw",
        717,
        "Failed to locate %s",
        s);
LABEL_20:
      result = v12;
      goto LABEL_21;
    }
    v14 = debug_priority;
    v15 = debug_mdl & 0x100000;
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v15,
        4,
        "dw9785_download_fw",
        719,
        "fw->size %d",
        *v22);
      v14 = debug_priority;
      v15 = debug_mdl & 0x100000;
    }
    v16 = v22[1];
    if ( v15 && !v14 )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v15,
        4,
        "dw9785_download_fw",
        722,
        "[dw9785_download_fw] start");
    v17 = cam_ois_dw9785_reset(a1, a2);
    if ( v17 )
    {
      v18 = "Failed to dw9785 reset %d";
      v12 = v17;
      v19 = 725;
LABEL_19:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x100000,
        1,
        "dw9785_download_fw",
        v19,
        v18,
        v12);
      goto LABEL_20;
    }
    if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100000,
        4,
        "dw9785_download_fw",
        727,
        "[dw9785_ois_reset] done : standby");
    v20 = cam_ois_write_regs(a1, a2, *(_QWORD *)(a2 + 16), *(_DWORD *)(a2 + 24));
    if ( v20 )
    {
      v18 = "Failed to dw978x init %d";
      v12 = v20;
      v19 = 731;
      goto LABEL_19;
    }
    if ( (unsigned int)dw9785_fw_eflash_erase(a1, a2) )
    {
      result = 3;
    }
    else if ( (unsigned int)dw9785_fw_select(a1, a2) )
    {
      result = 7;
    }
    else
    {
      if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x100000,
          4,
          "dw9785_download_fw",
          745,
          "[dw9785_download_fw] sequential write start");
      dw9785_write_ois_firmware(a1, v16);
      msleep(300);
      if ( (unsigned int)dw9785_fw_wait_check_register(a1, a2, 0x1Eu, 0x64u) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "dw9785_download_fw",
          750,
          "[dw9785_download_fw] sequential write done");
      cam_ois_dw9785_reset(a1, a2);
      if ( (unsigned int)dw9785_fw_checksum_check(a1, a2) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "dw9785_download_fw",
          762,
          "[dw9785_download_fw] fw download cheksum fail.");
        result = 6;
        if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x100000,
            4,
            "dw9785_download_fw",
            763,
            "[dw9785_download_fw] finish");
          result = 6;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x100000,
          1,
          "dw9785_download_fw",
          759,
          "[dw9785_download_fw] fw download success.");
        if ( (debug_mdl & 0x100000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x100000,
            4,
            "dw9785_download_fw",
            760,
            "[dw9785_download_fw] finish");
        msleep(5);
        firmware_ver = cam_ois_read_firmware_ver(a1, a2);
        result = 0;
        *a3 = firmware_ver;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "dw9785_download_fw",
      706,
      "Invalid Args");
    result = 4294967274LL;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
