void sub_A5D4()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &rmnet_shs_freq_init__alloc_tag_4;
  pcpu_alloc_noprof(8, 4, 0, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xA2D8);
}
