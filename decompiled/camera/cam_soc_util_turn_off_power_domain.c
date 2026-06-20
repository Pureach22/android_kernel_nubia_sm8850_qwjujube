__int64 __fastcall cam_soc_util_turn_off_power_domain(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  int v4; // w0
  const char *v6; // x6
  const char *v7; // x5
  __int64 v8; // x4
  const char *v9; // x6
  unsigned int v10; // w19

  if ( !a1 )
  {
    v6 = "soc_info";
LABEL_8:
    v7 = "%s is NULL";
    v8 = 3618;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_turn_off_power_domain",
      v8,
      v7,
      v6);
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
  {
    v6 = "soc_info->dev";
    goto LABEL_8;
  }
  v2 = *(_QWORD *)(v1 + 592);
  if ( v2 == 912 )
  {
    v6 = *(const char **)(a1 + 24);
    v7 = "%s: Failed to get power domain";
    v8 = 3624;
    goto LABEL_9;
  }
  *(_DWORD *)(v2 + 520) &= ~4u;
  v4 = _pm_runtime_idle(*(_QWORD *)(a1 + 8), 4);
  if ( (v4 & 0x80000000) == 0 )
    return 0;
  v9 = *(const char **)(a1 + 24);
  v10 = v4;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_turn_off_power_domain",
    3633,
    "%s: Failed to turn off the power domain: %d",
    v9,
    v4);
  return v10;
}
