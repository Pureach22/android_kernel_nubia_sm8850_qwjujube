__int64 __fastcall debug_spmi_addr_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, debug_spmi_addr_get, debug_spmi_addr_set, "0x%05llX\n", a6);
}
