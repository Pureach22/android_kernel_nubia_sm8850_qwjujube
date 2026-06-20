__int64 __fastcall cam_vfe_top_ver3_reset(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x22
  __int64 v3; // x24
  __int64 v4; // x20
  int v5; // w11
  int v6; // w12
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x8

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_reset",
      379,
      "Invalid arguments");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 10432);
  v3 = *(_QWORD *)(v2 + 3296);
  if ( !v3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_reset",
      388,
      "Invalid soc_private");
    return 4294967277LL;
  }
  v4 = *(_QWORD *)(a1 + 16);
  if ( *(_BYTE *)(v3 + 24) )
    v5 = 2;
  else
    v5 = 1;
  if ( *(_BYTE *)(v3 + 24) )
    v6 = 1;
  else
    v6 = 0x10000;
  if ( *a2 )
    v7 = v6;
  else
    v7 = v5;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver3_reset",
      407,
      "reset reg value: 0x%x",
      v7);
    if ( (*(_BYTE *)(v3 + 24) & 1) != 0 )
      goto LABEL_16;
  }
  else if ( (*(_BYTE *)(v3 + 24) & 1) != 0 )
  {
LABEL_16:
    if ( v2 && *(_DWORD *)(v2 + 480) )
      v8 = *(_QWORD *)(v2 + 288);
    else
      v8 = 0;
    cam_io_w_mb(0x20000, v8 + 40);
    if ( !v2 )
      goto LABEL_32;
    goto LABEL_30;
  }
  if ( v2 && *(_DWORD *)(v2 + 480) )
    v10 = *(_QWORD *)(v2 + 288);
  else
    v10 = 0;
  cam_io_w_mb(1, v10 + 60);
  if ( !v2 )
    goto LABEL_32;
LABEL_30:
  if ( *(_DWORD *)(v2 + 480) )
  {
    v11 = *(_QWORD *)(v2 + 288);
    goto LABEL_33;
  }
LABEL_32:
  v11 = 0;
LABEL_33:
  cam_io_w_mb(v7, v11 + *(unsigned int *)(v4 + 28));
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver3_reset",
      424,
      "Reset HW exit");
    return 0;
  }
  return result;
}
