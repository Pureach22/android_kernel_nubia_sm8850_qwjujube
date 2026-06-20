void sub_BC998()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &hfi_msm_dbg_init__alloc_tag_37;
  _kvmalloc_node_noprof(2883584, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xBC4F0);
}
