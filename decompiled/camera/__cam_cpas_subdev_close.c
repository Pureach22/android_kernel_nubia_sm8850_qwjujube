__int64 __fastcall _cam_cpas_subdev_close(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w9
  char v3; // w8
  const char *v4; // x5
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x4

  v1 = *(_QWORD *)(a1 + 240);
  if ( !v1 || (*(_BYTE *)(v1 + 852) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "__cam_cpas_subdev_close",
      1915,
      "CPAS not initialized");
    return 4294967277LL;
  }
  mutex_lock(v1 + 800);
  v2 = *(_DWORD *)(v1 + 848);
  if ( v2 )
  {
    v3 = debug_mdl;
    *(_DWORD *)(v1 + 848) = v2 - 1;
    if ( (v3 & 4) == 0 || debug_priority )
      goto LABEL_10;
    v4 = "CPAS Subdev close count %d";
    v5 = v3 & 4;
    v6 = 4;
    v7 = 1926;
  }
  else
  {
    v4 = "device already closed, open_cnt: %d";
    v5 = 4;
    v6 = 2;
    v7 = 1921;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    v5,
    v6,
    "__cam_cpas_subdev_close",
    v7,
    v4);
LABEL_10:
  mutex_unlock(v1 + 800);
  return 0;
}
