void __usercall sub_270410(__int64 a1@<X8>)
{
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &tpg_hw_create_request__alloc_tag_52;
  _kvmalloc_node_noprof(32 * a1, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x270284);
}
