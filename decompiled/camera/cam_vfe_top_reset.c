__int64 __fastcall cam_vfe_top_reset(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w19
  __int64 v3; // x23
  __int64 v4; // x22
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x22

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_reset",
      457,
      "Invalid arguments");
    return 4294967274LL;
  }
  if ( *a2 )
    v2 = 16263;
  else
    v2 = 16287;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v8 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_reset",
      470,
      "reset reg value: %x",
      v2);
    a1 = v8;
  }
  v3 = *(_QWORD *)(a1 + 10432);
  v4 = *(_QWORD *)(a1 + 8);
  if ( v3 )
  {
    if ( *(_DWORD *)(v3 + 480) )
      v5 = *(_QWORD *)(v3 + 288);
    else
      v5 = 0;
    cam_io_w_mb(0x80000000LL, v5 + 92);
    if ( *(_DWORD *)(v3 + 480) )
    {
      v7 = *(_QWORD *)(v3 + 288);
      goto LABEL_18;
    }
  }
  else
  {
    cam_io_w_mb(0x80000000LL, 92);
  }
  v7 = 0;
LABEL_18:
  cam_io_w_mb(v2, v7 + *(unsigned int *)(v4 + 24));
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_reset",
      483,
      "Reset HW exit");
    return 0;
  }
  return result;
}
