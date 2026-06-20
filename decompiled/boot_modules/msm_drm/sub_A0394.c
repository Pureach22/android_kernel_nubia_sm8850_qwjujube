void sub_A0394()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = kthread_create_on_node;
  *(_QWORD *)(StatusReg + 80) = &dp_pll_clock_register_3nm__alloc_tag_19;
  _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xA0154);
}
