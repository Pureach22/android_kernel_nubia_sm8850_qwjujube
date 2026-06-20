__int64 __fastcall cam_sync_signal_validate_util(unsigned int a1, int a2)
{
  __int64 v2; // x6
  int v3; // w8
  const char *v4; // x5
  __int64 v5; // x4

  v2 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
  v3 = *(_DWORD *)(v2 + 104);
  if ( !v3 )
  {
    v4 = "Error: accessing an uninitialized sync obj = %s[%d]";
    v5 = 368;
    goto LABEL_5;
  }
  if ( *(_DWORD *)(v2 + 64) == 1 )
  {
    v4 = "Error: Signaling a GROUP sync object = %s[%d]";
    v5 = 375;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_signal_validate_util",
      v5,
      v4);
    return 4294967274LL;
  }
  if ( v3 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_signal_validate_util",
      382,
      "Error: Sync object already signaled sync_obj = %s[%d]",
      (const char *)v2,
      a1);
    return 4294967182LL;
  }
  if ( (unsigned int)(a2 - 5) > 0xFFFFFFFC )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    128,
    1,
    "cam_sync_signal_validate_util",
    390,
    "Error: signaling with undefined status = %d",
    a2);
  return 4294967274LL;
}
