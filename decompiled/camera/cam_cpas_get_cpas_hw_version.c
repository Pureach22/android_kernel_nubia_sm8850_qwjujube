__int64 __fastcall cam_cpas_get_cpas_hw_version(_DWORD *a1)
{
  int v1; // w8
  __int64 result; // x0

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    if ( a1 )
    {
      v1 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL) + 112LL);
      *a1 = v1;
      if ( v1 )
        return 0;
      result = 0;
      if ( (debug_mdl & 4) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_get_cpas_hw_version",
          450,
          "Didn't find a valid HW Version %d",
          0);
        return 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_get_cpas_hw_version",
        440,
        "invalid input %pK",
        nullptr);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_cpas_hw_version",
      435,
      "cpas intf not initialized");
    return 4294967277LL;
  }
  return result;
}
