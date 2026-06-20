void __fastcall sub_5F6E0(unsigned int a1)
{
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &nl80211_nan_add_func__alloc_tag_175;
  _kmalloc_noprof(6LL * a1, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x5F580);
}
