void sub_BE278()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = wake_up_process;
  *(_QWORD *)(StatusReg + 80) = &hfi_dbg_reg_base_reg_read__alloc_tag;
  _kmalloc_cache_noprof(v2, 3264, 32);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xBDE50);
}
