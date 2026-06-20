void sub_D44C()
{
  unsigned __int64 StatusReg; // x25
  __int64 v1; // x26
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = vunmap;
  *(_QWORD *)(StatusReg + 80) = &tmc_init_etr_sg_table__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xD410);
  JUMPOUT(0xD248);
}
