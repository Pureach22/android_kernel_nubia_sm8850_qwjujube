void sub_BC968()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &hfi_msm_dbg_init__alloc_tag;
  _kvmalloc_node_noprof(392, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xBC4C4);
}
