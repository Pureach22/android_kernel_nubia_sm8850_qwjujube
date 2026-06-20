void sub_672C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x22
  __int64 (*v2)(void); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _list_del_entry_valid_or_report;
  *(_QWORD *)(StatusReg + 80) = &altmode_register_client__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 112);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x6664);
  JUMPOUT(0x6590);
}
