__int64 __fastcall kgsl_device_events_probe(_QWORD *a1)
{
  __int64 v1; // x2

  a1[1644] = a1 + 1644;
  a1[1645] = a1 + 1644;
  v1 = a1[1397];
  a1[1646] = 0;
  return debugfs_create_file("events", 292, v1, a1, &events_fops);
}
