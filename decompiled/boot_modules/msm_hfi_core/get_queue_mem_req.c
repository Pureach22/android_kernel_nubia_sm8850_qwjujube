__int64 __fastcall get_queue_mem_req(int a1, int a2)
{
  __int64 v2; // x30

  if ( a1 )
    return ((a2 + 18 * a1 + 5) & (unsigned int)-a2) + 8 * a1 + 6;
  printk(&unk_1EAB8, "get_queue_mem_req", 86, v2, 0);
  return 4294967274LL;
}
