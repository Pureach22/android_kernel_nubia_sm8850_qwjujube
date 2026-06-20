__int64 __fastcall _qdf_nbuf_dmamap_create(__int64 a1, __int64 *a2)
{
  __int64 v3; // x8

  v3 = _kmalloc_cache_noprof(wcnss_prealloc_put, 3520, 32);
  *a2 = v3;
  return 2 * (unsigned int)(v3 == 0);
}
