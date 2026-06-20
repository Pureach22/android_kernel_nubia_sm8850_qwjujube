void sub_13F09C()
{
  __int64 v0; // x21
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sync_open__alloc_tag;
  v3 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 8672) = v3;
  if ( !v3 )
    JUMPOUT(0x13F050);
  JUMPOUT(0x13F078);
}
