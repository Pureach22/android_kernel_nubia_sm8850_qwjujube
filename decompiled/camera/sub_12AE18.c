void sub_12AE18()
{
  unsigned int v0; // w27
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_context_flush_ctx_to_hw__alloc_tag_42;
  v3 = _kvmalloc_node_noprof(8LL * v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x12ACDC);
  JUMPOUT(0x12A6E8);
}
