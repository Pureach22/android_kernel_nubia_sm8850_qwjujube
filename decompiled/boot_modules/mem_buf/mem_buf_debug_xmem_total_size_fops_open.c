__int64 __fastcall mem_buf_debug_xmem_total_size_fops_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, mem_buf_debug_xmem_total_size_get, 0, "%llu\n", a6);
}
