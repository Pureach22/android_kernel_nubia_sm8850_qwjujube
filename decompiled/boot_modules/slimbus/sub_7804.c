void sub_7804()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = alt_cb_patch_nops;
  *(_QWORD *)(StatusReg + 80) = &slim_stream_allocate__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 64);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x77DC);
  JUMPOUT(0x776C);
}
