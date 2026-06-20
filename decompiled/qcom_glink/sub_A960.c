void sub_A960()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (*v2)(_QWORD, const char *, ...); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = ipc_log_string;
  *(_QWORD *)(StatusReg + 80) = &qcom_glink_alloc_channel__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 456);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA940);
  JUMPOUT(0xA85C);
}
