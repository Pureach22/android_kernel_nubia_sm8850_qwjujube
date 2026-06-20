__int64 pld_init()
{
  __int64 v0; // x0
  unsigned int v1; // w8

  v0 = _kmalloc_cache_noprof(wcnss_check_pool_lists, 3520, 40);
  if ( v0 )
  {
    v1 = 0;
    *(_DWORD *)(v0 + 8) = 0;
    *(_QWORD *)(v0 + 16) = v0 + 16;
    *(_QWORD *)(v0 + 24) = v0 + 16;
    pld_ctx = v0;
  }
  else
  {
    return (unsigned int)-12;
  }
  return v1;
}
