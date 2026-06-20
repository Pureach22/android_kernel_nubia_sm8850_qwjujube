void sub_10B74()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = alt_cb_patch_nops;
  *(_QWORD *)(StatusReg + 80) = &qcedev_mem_new_client__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 4);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x10B48);
  JUMPOUT(0x10B44);
}
