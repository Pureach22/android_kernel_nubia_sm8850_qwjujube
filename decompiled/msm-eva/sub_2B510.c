void __usercall sub_2B510(__int64 a1@<X0>, __int64 a2@<X8>)
{
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x23
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_vote_buses__alloc_tag;
  v4 = kmemdup_noprof(a1, 20 * a2, 3264);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v4 )
    JUMPOUT(0x2AF50);
  JUMPOUT(0x2AF9C);
}
