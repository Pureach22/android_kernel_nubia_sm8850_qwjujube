void sub_B72C()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qcrypto_sha_alg_alloc__alloc_tag;
  v2 = _kmalloc_cache_noprof(dev_err, 3520, 1432);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0xB720);
  JUMPOUT(0xAE90);
}
