void sub_A034()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _list_del_entry_valid_or_report;
  *(_QWORD *)(StatusReg + 80) = &mmrm_sw_throttle_low_priority_client__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 32);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x9D7C);
}
