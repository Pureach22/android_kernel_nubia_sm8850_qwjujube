void sub_9070()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &msm_pinctrl_probe__alloc_tag;
  _kmalloc_large_noprof(30000, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x8FBC);
}
