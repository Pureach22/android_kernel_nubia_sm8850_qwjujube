__int64 __fastcall cam_cpas_soc_enable_resources(__int64 a1)
{
  unsigned int v1; // w19

  *(_BYTE *)(a1 + 3200) = *(_BYTE *)(*(_QWORD *)(a1 + 3296) + 1610LL);
  v1 = ((__int64 (*)(void))cam_soc_util_enable_platform_resource)();
  if ( v1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_soc_enable_resources",
      2034,
      "enable platform resource failed, rc=%d",
      v1);
  return v1;
}
