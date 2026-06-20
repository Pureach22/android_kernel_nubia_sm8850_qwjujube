__int64 __fastcall sensor_debugfs_value_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, sensor_debugfs_getvalue, sensor_debugfs_setvalue, "%llx\n", a6);
}
