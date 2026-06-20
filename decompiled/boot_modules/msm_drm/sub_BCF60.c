void sub_BCF60()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &hfi_dbg_recovery_reg_open__alloc_tag;
  _kvmalloc_node_noprof(4096, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xBCEF8);
}
