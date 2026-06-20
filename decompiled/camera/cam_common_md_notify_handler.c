__int64 cam_common_md_notify_handler()
{
  int v0; // w0
  __int64 result; // x0
  __int64 v2; // [xsp+0h] [xbp-40h] BYREF
  char v3[8]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v4; // [xsp+10h] [xbp-30h]
  __int64 v5; // [xsp+18h] [xbp-28h]
  __int64 v6; // [xsp+20h] [xbp-20h]
  int v7; // [xsp+28h] [xbp-18h]
  int v8; // [xsp+2Ch] [xbp-14h]
  void *v9; // [xsp+30h] [xbp-10h]
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  v3[7] = 0;
  strcpy(v3, "Camera");
  v6 = 0;
  v8 = 0;
  v7 = 10485760;
  v4 = 0;
  v5 = 0;
  v9 = &cam_common_mini_dump_handler;
  v0 = qcom_va_md_add_region(&v2);
  if ( v0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_md_notify_handler",
      249,
      "Va Region add falied %d",
      v0);
    result = 0x8000;
  }
  else
  {
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
