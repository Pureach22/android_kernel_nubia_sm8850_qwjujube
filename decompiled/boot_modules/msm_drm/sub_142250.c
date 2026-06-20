void sub_142250()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x26
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &sde_dbg_reg_register_dump_range__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 80);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x1421EC);
  JUMPOUT(0x1420F4);
}
