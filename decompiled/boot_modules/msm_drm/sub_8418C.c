void sub_8418C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _drm_debug;
  *(_QWORD *)(StatusReg + 80) = &dp_mst_sim_reset__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 48);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x84174);
  JUMPOUT(0x84148);
}
