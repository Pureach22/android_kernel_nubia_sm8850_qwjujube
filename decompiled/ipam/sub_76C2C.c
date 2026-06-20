void sub_76C2C()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &get_ipa_dts_configuration__alloc_tag_1089;
  _kmalloc_noprof(16LL * (unsigned int)dword_1F7E14, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x74CA4);
}
