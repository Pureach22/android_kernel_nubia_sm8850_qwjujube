void __fastcall sub_18FD0(__int64 a1)
{
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &hw_fence_utils_parse_dt_props__alloc_tag;
  _kmalloc_noprof(a1, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x18AE4);
}
