__int64 __fastcall qcrypto_cipher_alg_alloc(const void *a1)
{
  __int64 v2; // x0
  __int64 v3; // x20

  v2 = _kmalloc_cache_noprof(dev_err, 3520, 1432);
  if ( !v2 )
    return -12;
  *(_DWORD *)(v2 + 1416) = 0;
  v3 = v2;
  memcpy((void *)(v2 + 16), a1, 0x1D8u);
  *(_QWORD *)(v3 + 1424) = &qcrypto_dev;
  return v3;
}
