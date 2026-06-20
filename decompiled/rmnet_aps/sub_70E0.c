void sub_70E0()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = mod_timer;
  *(_QWORD *)(StatusReg + 80) = &rmnet_aps_genl_data_report_hdlr__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 104);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x6FA4);
  JUMPOUT(0x7028);
}
