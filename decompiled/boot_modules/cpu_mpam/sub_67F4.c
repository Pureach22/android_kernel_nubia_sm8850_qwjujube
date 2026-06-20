void sub_67F4()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = (unsigned int)mpam_msc_cnt;
  *(_QWORD *)(StatusReg + 80) = &cpu_mpam_make_group__alloc_tag_27;
  if ( (v2 & 0x80000000) == 0 )
    _kmalloc_noprof(16 * v2, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x66B4);
}
