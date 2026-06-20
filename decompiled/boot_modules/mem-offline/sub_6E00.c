void sub_6E00()
{
  __int64 v0; // x23
  unsigned __int64 v1; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x21

  v1 = *(int *)(v0 + 920);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &get_ddr_regions_info__alloc_tag;
  if ( is_mul_ok(v1, 0x28u) )
    _kmalloc_noprof(40 * v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x663C);
}
