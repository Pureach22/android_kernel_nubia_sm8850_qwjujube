void sub_E64C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(rfkill_init_sw_state, 3520, 808);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xE078);
}
