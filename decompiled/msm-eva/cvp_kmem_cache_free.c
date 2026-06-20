__int64 __fastcall cvp_kmem_cache_free(_QWORD *a1)
{
  unsigned int v8; // w10

  _X8 = (unsigned int *)(a1 + 1);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 - 1, _X8) );
  return kmem_cache_free(*a1);
}
