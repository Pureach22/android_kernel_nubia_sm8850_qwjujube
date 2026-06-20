__int64 __fastcall dsp_debug_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, dsp_dbg_get, dsp_dbg_set, "%llu\n", a6);
}
