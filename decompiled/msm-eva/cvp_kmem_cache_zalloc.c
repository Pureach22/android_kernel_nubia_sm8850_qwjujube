__int64 __fastcall cvp_kmem_cache_zalloc(_QWORD *a1, int a2)
{
  unsigned int v9; // w9

  _X8 = (unsigned int *)(a1 + 1);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 + 1, _X8) );
  return kmem_cache_alloc_noprof(*a1, a2 | 0x100u);
}
