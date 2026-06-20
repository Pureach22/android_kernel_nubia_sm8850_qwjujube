void sub_24D58()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &icnss_wlfw_process_twt_cfg_ind__alloc_tag;
  v3 = kmemdup_noprof(v0, 40, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x24D00);
  JUMPOUT(0x24CF0);
}
