void __usercall sub_3B638(int a1@<W8>)
{
  __int64 v1; // x23
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v4; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_QWORD *)(v2 - 16) = v1;
  v4 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ieee80211_set_ftm_responder_params__alloc_tag;
  _kmalloc_noprof(a1 + 32LL, 3520);
  *(_QWORD *)(StatusReg + 80) = v4;
  JUMPOUT(0x3B3BC);
}
