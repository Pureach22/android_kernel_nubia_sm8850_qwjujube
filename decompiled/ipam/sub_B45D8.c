void __usercall sub_B45D8(int a1@<W8>)
{
  unsigned int v1; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_alloc_page__alloc_tag;
  _alloc_pages_noprof((unsigned int)(a1 + 368640), v1, 0, 0);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0xB4404);
}
