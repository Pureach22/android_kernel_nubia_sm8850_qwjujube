__int64 __fastcall ois_debugfs_cal_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, ois_debugfs_cal_g, 0, "%llx\n", a6);
}
