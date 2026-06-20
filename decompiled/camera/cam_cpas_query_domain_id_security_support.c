__int64 cam_cpas_query_domain_id_security_support()
{
  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
    return *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL) + 3392LL) + 1644LL) & 1;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_query_domain_id_security_support",
    1258,
    "cpas intf not initialized");
  return 0;
}
