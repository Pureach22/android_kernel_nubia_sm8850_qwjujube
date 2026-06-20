__int64 __fastcall debug_soc_end_addr_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, debug_soc_end_addr_get, 0, "0x%llX\n", a6);
}
