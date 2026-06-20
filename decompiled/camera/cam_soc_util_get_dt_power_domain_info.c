__int64 __fastcall cam_soc_util_get_dt_power_domain_info(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 8);
  if ( v1 )
  {
    *(_BYTE *)(a1 + 3308) = 0;
    if ( *(_QWORD *)(v1 + 592) )
    {
      *(_BYTE *)(a1 + 3308) = 1;
      return 0;
    }
    else if ( (int)of_count_phandle_with_args(*(_QWORD *)(v1 + 744), "power-domains", "#power-domain-cells") < 2 )
    {
      return 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_get_dt_power_domain_info",
        3696,
        "%s: Camera devices don't support multiple PDs per device",
        *(const char **)(a1 + 24));
      return 4294967201LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_dt_power_domain_info",
      3678,
      "%s is NULL",
      "soc_info->dev");
    return 4294967274LL;
  }
}
