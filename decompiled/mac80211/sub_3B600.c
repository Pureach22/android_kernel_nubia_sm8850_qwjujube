void sub_3B600()
{
  __int64 v0; // x28
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ieee80211_set_probe_resp__alloc_tag;
  _kmalloc_noprof(v0 + 24, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x3B27C);
}
