void sub_11440()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = down;
  *(_QWORD *)(StatusReg + 80) = &qtee_shmbridge_list_add_locked__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 40);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x11320);
  JUMPOUT(0x112F0);
}
