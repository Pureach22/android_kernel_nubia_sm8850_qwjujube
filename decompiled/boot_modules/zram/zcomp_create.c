__int64 __fastcall zcomp_create(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  __int64 v4; // x8
  _QWORD *v5; // x0
  int v6; // w0
  __int64 v8; // x19

  if ( (unsigned int)crypto_has_alg(a1, 2, 15) != 1 )
    return -22;
  v2 = _kmalloc_cache_noprof(qpace_queue_compress, 3520, 32);
  if ( !v2 )
    return -12;
  v3 = (_QWORD *)v2;
  *(_QWORD *)(v2 + 8) = a1;
  v4 = pcpu_alloc_noprof(16, 8, 0, 3264);
  v5 = v3;
  *v3 = v4;
  if ( v4 )
  {
    v6 = _cpuhp_state_add_instance(61, v3 + 2, 1);
    if ( (v6 & 0x80000000) == 0 )
      return (__int64)v3;
    LODWORD(v8) = v6;
    free_percpu(*v3);
    v8 = (int)v8;
    v5 = v3;
  }
  else
  {
    v8 = -12;
  }
  kfree(v5);
  return v8;
}
