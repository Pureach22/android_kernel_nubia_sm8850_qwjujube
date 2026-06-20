void sub_A290()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_tlb_stress_sweep__alloc_tag;
  get_free_pages_noprof(3264, 1);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x9BAC);
}
