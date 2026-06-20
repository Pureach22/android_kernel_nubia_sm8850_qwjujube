void sub_249F0()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _list_del_entry_valid_or_report;
  *(_QWORD *)(StatusReg + 80) = &synx_init__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 440);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x24534);
}
