__int64 __fastcall hdd_sysfs_create_dump_in_progress_interface(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: could not get wifi kobject!";
    return qdf_trace_msg(0x33u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_sysfs_create_dump_in_progress_interface");
  }
  result = sysfs_create_file_ns(a1, &dump_in_progress_attribute, 0);
  if ( (_DWORD)result )
  {
    v12 = "%s: could not create dump in progress sysfs file";
    return qdf_trace_msg(0x33u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_sysfs_create_dump_in_progress_interface");
  }
  *(_BYTE *)(a2 + 7114) = 1;
  return result;
}
