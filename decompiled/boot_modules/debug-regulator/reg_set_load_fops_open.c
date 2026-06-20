__int64 __fastcall reg_set_load_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, reg_debug_mode_get, reg_debug_set_load, "%llu\n", a6);
}
