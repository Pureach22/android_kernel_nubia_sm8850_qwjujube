__int64 __fastcall cam_vfe_camif_lite_ver2_acquire_resource(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x10
  char v5; // w9

  if ( a1 )
  {
    result = 0;
    v4 = *(_QWORD *)(a1 + 24);
    *(_DWORD *)(v4 + 48) = *(_DWORD *)(a2 + 80);
    *(_QWORD *)(v4 + 56) = *(_QWORD *)(a2 + 24);
    v5 = debug_mdl;
    *(_QWORD *)(v4 + 64) = *(_QWORD *)(a2 + 16);
    if ( (v5 & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v5 & 8,
        4,
        "cam_vfe_camif_lite_ver2_acquire_resource",
        232,
        "hw id:%d sync_mode=%d",
        *(unsigned int *)(*(_QWORD *)(a1 + 16) + 4LL));
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_ver2_acquire_resource",
      218,
      "Error Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
