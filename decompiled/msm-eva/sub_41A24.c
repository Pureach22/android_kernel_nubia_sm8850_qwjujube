void sub_41A24()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x28

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &msm_cvp_map_buf_wncc__alloc_tag;
  _kmalloc_large_noprof(28800, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x417CC);
}
