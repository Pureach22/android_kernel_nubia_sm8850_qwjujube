__int64 __fastcall sensor_debugfs_address_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, sensor_debugfs_getaddr, sensor_debugfs_setaddr, "%llx\n", a6);
}
