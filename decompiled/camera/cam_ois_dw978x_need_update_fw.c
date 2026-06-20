bool __fastcall cam_ois_dw978x_need_update_fw(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  _BOOL4 v4; // w19

  if ( a1 && (v1 = *(_QWORD *)(a1 + 88)) != 0 && (v2 = *(_QWORD *)(v1 + 744)) != 0 )
  {
    v4 = of_find_property(v2, "firmware-update-enable", 0) != 0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x100000,
      3,
      "cam_ois_dw978x_need_update_fw",
      502,
      "%s: firmware update enabled: %d",
      (const char *)(a1 + 4516),
      v4);
    return v4;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x100000,
      1,
      "cam_ois_dw978x_need_update_fw",
      497,
      "Invalid device node configuration");
    return 0;
  }
}
