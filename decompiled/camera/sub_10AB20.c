void sub_10AB20()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_mem_trace_query_mass_mem__alloc_tag;
  vzalloc_noprof(0x2000);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x10A910);
}
