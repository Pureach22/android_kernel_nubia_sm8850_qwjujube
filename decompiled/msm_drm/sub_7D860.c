void sub_7D860()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dp_debug_read_dpcd__alloc_tag_114;
  v2 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x7D7F8);
  JUMPOUT(0x7D638);
}
