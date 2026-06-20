void sub_88B4()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &rtc6226_ev_ert__alloc_tag;
  v3 = _kmalloc_noprof(*(unsigned __int8 *)(v0 + 1058) + 3LL, 2080);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x85E4);
  JUMPOUT(0x8530);
}
