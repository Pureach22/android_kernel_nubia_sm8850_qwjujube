void sub_103D8()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  void *(*v2)(void *, int, size_t); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = memset;
  *(_QWORD *)(StatusReg + 80) = &arm_lpae_alloc_pgtable__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3264, 256);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x1039C);
  JUMPOUT(0x10308);
}
