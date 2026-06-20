void sub_EE914()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_qmi_ul_filter_request_send__alloc_tag;
  vmalloc_noprof(12044);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xEE43C);
}
