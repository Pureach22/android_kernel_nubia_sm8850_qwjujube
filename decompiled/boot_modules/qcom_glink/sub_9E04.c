void sub_9E04()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qcom_glink_create_chrdev__alloc_tag;
  v2 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 992);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x9DA4);
  JUMPOUT(0x9D38);
}
