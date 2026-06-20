__int64 __fastcall cam_soc_util_initialize_power_domain(__int64 a1)
{
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 592) )
      pm_runtime_enable();
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_initialize_power_domain",
      3556,
      "Invalid device");
    return 4294967274LL;
  }
}
