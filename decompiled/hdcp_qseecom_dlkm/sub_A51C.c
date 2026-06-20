void sub_A51C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  void *(*v2)(void *, const void *, size_t); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = memcpy;
  *(_QWORD *)(StatusReg + 80) = &hdcp2_init_smcinvoke__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 128);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA508);
  JUMPOUT(0xA504);
}
