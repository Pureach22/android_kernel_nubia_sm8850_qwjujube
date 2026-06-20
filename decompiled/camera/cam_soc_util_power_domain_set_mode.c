__int64 __fastcall cam_soc_util_power_domain_set_mode(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 result; // x0
  __int64 v9; // x6
  const char *v10; // x5
  unsigned int v11; // w19
  __int64 v12; // x4
  const char *v13; // x6

  if ( !a1 )
  {
    v13 = "soc_info";
LABEL_9:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_power_domain_set_mode",
      3646,
      "%s is NULL",
      v13);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 8) )
  {
    v13 = "soc_info->dev";
    goto LABEL_9;
  }
  if ( a2 != 1 )
  {
    if ( !a2 )
    {
      result = dev_pm_genpd_set_hwmode(*(_QWORD *)(a1 + 8), 0, a3, a4, a5, a6, a7, 0);
      if ( (_DWORD)result )
      {
        v9 = *(_QWORD *)(a1 + 24);
        v10 = "%s: Failed to set the GDSC to SW control mode";
        v11 = result;
        v12 = 3655;
LABEL_14:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_power_domain_set_mode",
          v12,
          v10,
          v9);
        return v11;
      }
      return result;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_power_domain_set_mode",
      3663,
      "%s: Invalid GDSC control mode %d",
      *(_QWORD *)(a1 + 24));
    return 4294967274LL;
  }
  result = dev_pm_genpd_set_hwmode(*(_QWORD *)(a1 + 8), 1, a3, a4, a5, a6, a7, 1);
  if ( (_DWORD)result )
  {
    v9 = *(_QWORD *)(a1 + 24);
    v10 = "%s: Failed to set the GDSC to HW control mode";
    v11 = result;
    v12 = 3660;
    goto LABEL_14;
  }
  return result;
}
