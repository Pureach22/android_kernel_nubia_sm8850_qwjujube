void sub_BB18()
{
  unsigned int v0; // w19
  unsigned int v1; // w20
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gsi_ctrl_pkt_alloc__alloc_tag_231;
  _kmalloc_noprof(v0, v1);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0xBA90);
}
