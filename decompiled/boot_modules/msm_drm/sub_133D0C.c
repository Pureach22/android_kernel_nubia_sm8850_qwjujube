void sub_133D0C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x25
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = msleep;
  *(_QWORD *)(StatusReg + 80) = &sde_cp_crtc_install_properties__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 416);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1337AC);
}
