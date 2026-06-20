void sub_7AD4()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = kfree_sensitive;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v3 = _kmalloc_cache_noprof(v2, 3520, 48);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x7AC4);
  JUMPOUT(0x7AB8);
}
