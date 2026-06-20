void sub_12AD0()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _rcu_read_lock;
  *(_QWORD *)(StatusReg + 80) = &rmnet_shs_wq_init__alloc_tag;
  _kmalloc_cache_noprof(v2, 2080, 104);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x12964);
}
