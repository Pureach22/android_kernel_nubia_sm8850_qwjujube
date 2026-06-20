void sub_252EC()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &icnss_ims_process_wfc_call_ind_cb__alloc_tag;
  v3 = kmemdup_noprof(v0, 32, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x25294);
  JUMPOUT(0x25284);
}
