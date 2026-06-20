_DWORD *__fastcall qcedev_mem_new_client(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  _DWORD *result; // x0

  if ( a1 )
  {
    printk(&unk_1233D, "qcedev_mem_new_client", a3, a4);
    return nullptr;
  }
  else
  {
    result = (_DWORD *)_kmalloc_cache_noprof(alt_cb_patch_nops, 3520, 4);
    if ( result )
      *result = 0;
  }
  return result;
}
