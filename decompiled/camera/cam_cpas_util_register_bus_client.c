__int64 __fastcall cam_cpas_util_register_bus_client(_QWORD *a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w19

  v4 = cam_soc_bus_client_register(*a1, a2, a3 + 232, a3 + 64, *(unsigned __int8 *)(a1[412] + 10LL));
  if ( v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_register_bus_client",
      466,
      "Bus client: %s registertion failed ,rc: %d",
      *(const char **)(a3 + 64),
      v4);
  }
  else
  {
    *(_DWORD *)(a3 + 56) = 0;
    *(_BYTE *)a3 = 1;
    _mutex_init(a3 + 8, "&bus_client->lock", &cam_cpas_util_register_bus_client___key);
  }
  return v4;
}
