__int64 __fastcall hdd_sysfs_apfmode_create(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int file_ns; // w19
  const char *v10; // x2

  if ( !a1 )
  {
    file_ns = -22;
    v10 = "%s: could not get driver kobject!";
    goto LABEL_5;
  }
  file_ns = sysfs_create_file_ns(a1, &apfmode_attribute, 0);
  if ( file_ns )
  {
    v10 = "%s: could not create apfmode sysfs file";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sysfs_apfmode_create");
  }
  return file_ns;
}
