void sub_C510()
{
  int v0; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &tp_alloc_tp_firmware_data__alloc_tag_28;
  vmalloc_noprof(v0 + 24LL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xC464);
}
