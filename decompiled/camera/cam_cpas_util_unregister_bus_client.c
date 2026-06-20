__int64 __fastcall cam_cpas_util_unregister_bus_client(__int64 a1)
{
  __int64 result; // x0

  if ( (*(_BYTE *)a1 & 1) == 0 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             4,
             1,
             "cam_cpas_util_unregister_bus_client",
             481,
             "bus client not valid");
  result = cam_soc_bus_client_unregister(a1 + 232);
  *(_DWORD *)(a1 + 56) = 0;
  *(_BYTE *)a1 = 0;
  return result;
}
