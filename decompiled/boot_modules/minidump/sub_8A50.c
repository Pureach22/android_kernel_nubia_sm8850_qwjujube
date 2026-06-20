void sub_8A50()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &register_cpufreq_log__alloc_tag;
  _kmalloc_noprof(v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x876C);
}
