void sub_E55C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &md_smem_init_md_table__alloc_tag;
  _kmalloc_cache_noprof(_tracepoint_android_vh_ftrace_oops_enter, 3520, 8040);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xE4AC);
}
