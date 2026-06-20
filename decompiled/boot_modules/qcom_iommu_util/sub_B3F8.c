void sub_B3F8()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &av8l_fast_prepopulate_pgtables__alloc_tag_6;
  v2 = vmalloc_noprof(16424);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0xB3C4);
  JUMPOUT(0xADC4);
}
