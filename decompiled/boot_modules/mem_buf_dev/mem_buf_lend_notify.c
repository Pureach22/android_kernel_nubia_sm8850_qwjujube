_WORD *__fastcall mem_buf_lend_notify(__int64 a1)
{
  _WORD *result; // x0
  _WORD *v3; // x20
  int v4; // w8
  int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x23

  result = (_WORD *)_kmalloc_cache_noprof(xa_destroy, 3520, 8);
  v3 = result;
  if ( result )
  {
    v4 = *(_DWORD *)(a1 + 48);
    *result = 1;
    if ( v4 )
    {
      v5 = 0;
      do
      {
        v6 = *(unsigned int *)(a1 + 80);
        v7 = v5;
        v3[2] = *(_DWORD *)(*(_QWORD *)(a1 + 32) + 4LL * v5);
        if ( (unsigned int)gh_rm_mem_notify(v6, 1, 8, v3) )
          printk(&unk_13A4E, "mem_buf_lend_notify", *(unsigned int *)(*(_QWORD *)(a1 + 32) + 4 * v7));
        v5 = v7 + 1;
      }
      while ( (unsigned int)(v7 + 1) < *(_DWORD *)(a1 + 48) );
    }
    return (_WORD *)kfree(v3);
  }
  return result;
}
