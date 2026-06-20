__int64 __fastcall kzalloc_noprof(int a1)
{
  __int64 v1; // x9
  __int64 v2; // x8

  v1 = 1;
  if ( (a1 & 0x10) == 0 )
    v1 = 2;
  if ( (a1 & 0x400010) != 0 )
    v2 = v1;
  else
    v2 = 0;
  return _kmalloc_cache_noprof(kmalloc_caches[14 * v2 + 12], a1 | 0x100u, 4096);
}
