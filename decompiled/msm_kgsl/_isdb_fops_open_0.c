__int64 __fastcall isdb_fops_open_0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, isdb_get_0, isdb_set_0, "%llu\n", a6);
}
