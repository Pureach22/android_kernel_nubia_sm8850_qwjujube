void sub_A8248()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = kthread_create_on_node;
  *(_QWORD *)(StatusReg + 80) = &edp_pll_clock_register_4nm__alloc_tag_5;
  _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xA8014);
}
