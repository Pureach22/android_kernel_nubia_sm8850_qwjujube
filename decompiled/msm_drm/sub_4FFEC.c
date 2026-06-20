void sub_4FFEC()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_hdcp_1x_init__alloc_tag;
  v2 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1456);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x4FFB8);
  JUMPOUT(0x4FD40);
}
