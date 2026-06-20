void sub_A324()
{
  __int64 v0; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &lt9611uxc_connector_get_modes__alloc_tag;
  kmemdup_noprof(v0, 128, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xA004);
}
