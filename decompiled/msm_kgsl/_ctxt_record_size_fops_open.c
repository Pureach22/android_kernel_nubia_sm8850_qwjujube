__int64 __fastcall ctxt_record_size_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, ctxt_record_size_get, ctxt_record_size_set, "%llu\n", a6);
}
