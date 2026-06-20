void sub_7198()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (*v2)(void); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = powercap_unregister_control_type;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 3520, 32);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x6EA0);
}
