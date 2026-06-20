void __fastcall sub_1400A4(unsigned int a1)
{
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sync_handle_merge__alloc_tag;
  v3 = _kvmalloc_node_noprof(a1, 0, 2336, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x13FFEC);
  JUMPOUT(0x13FF74);
}
