__int64 __fastcall cam_ois_dw978x_firmware_download(__int64 a1, int *a2)
{
  int v2; // w6
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0xFFFFFF;
  if ( a1 && a2 )
  {
    v2 = *a2;
    if ( *a2 == 1 )
    {
      if ( !(unsigned int)dw9785_download_fw(a1, (__int64)a2, &v5) )
        goto LABEL_12;
    }
    else if ( v2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x100000,
        1,
        "cam_ois_dw978x_firmware_download",
        795,
        "Unsupported OIS model: %d",
        v2);
    }
    else if ( !(unsigned int)dw978x_download_fw(a1, (__int64)a2, &v5) )
    {
      goto LABEL_12;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_dw978x_firmware_download",
      799,
      "%s: FirmWare Download failed",
      (const char *)(a1 + 4516));
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_dw978x_firmware_download",
      782,
      "Invalid Args");
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v5;
}
