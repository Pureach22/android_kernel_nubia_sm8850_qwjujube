__int64 __fastcall hdd_config_guard_time(unsigned __int8 *a1, __int64 a2)
{
  unsigned int v2; // w0

  v2 = sme_configure_guard_time(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL), a1[8], *(unsigned int *)(a2 + 4));
  return qdf_status_to_os_return(v2);
}
