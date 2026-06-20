void sub_1A7F98()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  double (*v2)(_QWORD, _QWORD, _QWORD, const char *, ...); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _drm_dev_dbg;
  *(_QWORD *)(StatusReg + 80) = &sde_cp_crtc_install_blob_property__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 104);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x1A7F58);
  JUMPOUT(0x1A7EA4);
}
