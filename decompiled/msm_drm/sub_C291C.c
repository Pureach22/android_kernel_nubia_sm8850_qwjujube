void sub_C291C()
{
  unsigned int v0; // w24
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dsi_hfi_panel_init__alloc_tag_37;
  v3 = _kmalloc_noprof(300LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0xC2690);
  JUMPOUT(0xC1DB0);
}
