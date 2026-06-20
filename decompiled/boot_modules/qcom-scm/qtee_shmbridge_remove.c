__int64 __fastcall qtee_shmbridge_remove(__int64 a1)
{
  unsigned int v2; // w9
  __int64 v3; // x1

  qtee_shmbridge_deregister(qword_13970);
  gen_pool_destroy(qword_13980);
  dma_unmap_page_attrs(a1 + 16, default_bridge, qword_13968, 1, 0);
  v2 = 64 - __clz((unsigned __int64)(qword_13968 - 1) >> 12);
  if ( (unsigned __int64)(qword_13968 - 1) >= 0x1000 )
    v3 = v2;
  else
    v3 = 0;
  return free_pages(qword_13960, v3);
}
