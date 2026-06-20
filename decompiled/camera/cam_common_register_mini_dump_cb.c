__int64 __fastcall cam_common_register_mini_dump_cb(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v3; // x8
  const char *v4; // x5
  __int64 v5; // x4
  _QWORD *v7; // x20
  __int64 result; // x0
  unsigned int v9; // w19

  v3 = (unsigned __int8)byte_394010;
  if ( (unsigned __int8)byte_394010 >= 6uLL )
  {
    v4 = "No free index available";
    v5 = 269;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_register_mini_dump_cb",
      v5,
      v4);
    return 4294967274LL;
  }
  if ( !a1 || !a2 )
  {
    v4 = "Invalid params";
    v5 = 274;
    goto LABEL_8;
  }
  v7 = (_QWORD *)((char *)&g_minidump_dev_info + 8 * (unsigned __int8)byte_394010);
  *v7 = a1;
  scnprintf((char *)&g_minidump_dev_info + 16 * v3 + 48, 16, a2);
  v7[18] = a3;
  ++byte_394010;
  if ( (byte_394011 & 1) != 0 )
    return 0;
  result = qcom_va_md_register("Camera", &cam_common_md_notify_blk);
  if ( (_DWORD)result )
  {
    v9 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_register_mini_dump_cb",
      288,
      "Camera VA minidump register failed");
    return v9;
  }
  else
  {
    byte_394011 = 1;
  }
  return result;
}
