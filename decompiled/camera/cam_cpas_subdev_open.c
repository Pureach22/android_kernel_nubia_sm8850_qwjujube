__int64 __fastcall cam_cpas_subdev_open(__int64 a1)
{
  __int64 v1; // x19
  char v2; // w8
  int v3; // w6

  v1 = *(_QWORD *)(a1 + 240);
  if ( v1 && (*(_BYTE *)(v1 + 852) & 1) != 0 )
  {
    mutex_lock(v1 + 800);
    v2 = debug_mdl;
    v3 = *(_DWORD *)(v1 + 848) + 1;
    *(_DWORD *)(v1 + 848) = v3;
    if ( (v2 & 4) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v2 & 4,
        4,
        "cam_cpas_subdev_open",
        1903,
        "CPAS Subdev open count %d",
        v3);
    mutex_unlock(v1 + 800);
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_subdev_open",
      1897,
      "CPAS not initialized");
    return 4294967277LL;
  }
}
