void sub_841C()
{
  int v0; // w19
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qcom_sg_do_vmap__alloc_tag;
  vmalloc_noprof(8LL * v0);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x82EC);
}
