__int64 __fastcall cam_vfe_get_hw_caps(__int64 a1)
{
  __int64 *v1; // x9
  void (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x22

  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v5 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_get_hw_caps",
      49,
      "Enter");
    a1 = v5;
    if ( v5 )
      goto LABEL_4;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_get_hw_caps",
      51,
      "Invalid arguments");
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_12;
LABEL_4:
  v1 = *(__int64 **)(*(_QWORD *)(a1 + 3680) + 16LL);
  v2 = (void (__fastcall *)(_QWORD))v1[1];
  if ( v2 )
  {
    v3 = *v1;
    if ( *((_DWORD *)v2 - 1) != 1989616049 )
      __break(0x8228u);
    v2(v3);
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_get_hw_caps",
      62,
      "Exit");
    return 0;
  }
  return result;
}
