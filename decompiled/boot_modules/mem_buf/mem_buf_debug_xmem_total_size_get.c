__int64 __fastcall mem_buf_debug_xmem_total_size_get(__int64 a1, __int64 *a2)
{
  __int64 v3; // x8

  v3 = mem_buf_account_all_mem();
  *a2 = v3;
  return 0;
}
