void sub_79F2C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_active_clients_log_init__alloc_tag;
  _kmalloc_large_noprof(11520, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x77C5C);
}
