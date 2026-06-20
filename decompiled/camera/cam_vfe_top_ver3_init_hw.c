__int64 __fastcall cam_vfe_top_ver3_init_hw(__int64 a1)
{
  unsigned int *v1; // x20
  char v3; // w8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8

  v1 = *(unsigned int **)(a1 + 16);
  v3 = debug_mdl;
  *(_QWORD *)(a1 + 10440) = 0;
  if ( (v3 & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v3 & 8,
      4,
      "cam_vfe_top_ver3_init_hw",
      347,
      "Enabling clock gating at IFE top");
    v4 = *(_QWORD *)(a1 + 10432);
    if ( !v4 )
      goto LABEL_9;
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 10432);
    if ( !v4 )
      goto LABEL_9;
  }
  if ( *(_DWORD *)(v4 + 480) )
  {
    v5 = *(_QWORD *)(v4 + 288);
    if ( v5 )
    {
      cam_io_w_mb(0, v5 + v1[8]);
      v6 = *(_QWORD *)(a1 + 10432);
      if ( !v6 )
        goto LABEL_14;
      goto LABEL_10;
    }
  }
LABEL_9:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_w_mb",
    831,
    "No valid mapped starting address found");
  v6 = *(_QWORD *)(a1 + 10432);
  if ( !v6 )
    goto LABEL_14;
LABEL_10:
  if ( *(_DWORD *)(v6 + 480) )
  {
    v7 = *(_QWORD *)(v6 + 288);
    if ( v7 )
    {
      cam_io_w_mb(0, v7 + v1[9]);
      v8 = *(_QWORD *)(a1 + 10432);
      if ( !v8 )
        goto LABEL_19;
      goto LABEL_15;
    }
  }
LABEL_14:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_w_mb",
    831,
    "No valid mapped starting address found");
  v8 = *(_QWORD *)(a1 + 10432);
  if ( !v8 )
    goto LABEL_19;
LABEL_15:
  if ( *(_DWORD *)(v8 + 480) )
  {
    v9 = *(_QWORD *)(v8 + 288);
    if ( v9 )
    {
      cam_io_w_mb(0, v9 + v1[10]);
      v10 = *(_QWORD *)(a1 + 10432);
      if ( !v10 )
        goto LABEL_23;
      goto LABEL_20;
    }
  }
LABEL_19:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_w_mb",
    831,
    "No valid mapped starting address found");
  v10 = *(_QWORD *)(a1 + 10432);
  if ( !v10 )
  {
LABEL_23:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_w_mb",
      831,
      "No valid mapped starting address found");
    goto LABEL_24;
  }
LABEL_20:
  if ( !*(_DWORD *)(v10 + 480) )
    goto LABEL_23;
  v11 = *(_QWORD *)(v10 + 288);
  if ( !v11 )
    goto LABEL_23;
  cam_io_w_mb(0, v11 + v1[11]);
LABEL_24:
  *(_DWORD *)(a1 + 10400) = cam_io_r_mb(*(_QWORD *)(*(_QWORD *)(a1 + 10432) + 288LL) + *v1);
  return 0;
}
