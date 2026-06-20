void sub_7344()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &f_cdev_alloc__alloc_tag;
  v2 = _kmalloc_cache_noprof(strnchr, 3520, 1616);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x72A0);
  JUMPOUT(0x6F30);
}
