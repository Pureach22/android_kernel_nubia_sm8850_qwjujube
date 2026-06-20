void sub_F010C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_qmi_service_init_worker__alloc_tag_156;
  vzalloc_noprof(304);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xEFCDC);
}
