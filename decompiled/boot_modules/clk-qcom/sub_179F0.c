void sub_179F0()
{
  unsigned int v0; // w26
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x24
  __int64 v3; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &clk_hw_populate_clock_opp_table__alloc_tag;
  if ( (v0 & 0x80000000) != 0 )
    v3 = 0;
  else
    v3 = _kmalloc_noprof(8LL * v0, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x17968);
  JUMPOUT(0x176E4);
}
