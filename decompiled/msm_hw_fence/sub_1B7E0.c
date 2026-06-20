void sub_1B7E0()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &msm_hw_fence_probe_init__alloc_tag;
  _kmalloc_large_noprof(33768, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1B514);
}
