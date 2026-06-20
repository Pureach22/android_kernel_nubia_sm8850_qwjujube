void sub_7E528()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sta_info_alloc_link__alloc_tag;
  pcpu_alloc_noprof(200, 8, 0, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x7E440);
}
