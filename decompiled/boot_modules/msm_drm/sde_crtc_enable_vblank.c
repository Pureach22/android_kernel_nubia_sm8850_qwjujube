__int64 __fastcall sde_crtc_enable_vblank(const void **a1)
{
  __int64 v1; // x20
  unsigned int v2; // w19
  __int64 v3; // x1
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x22
  __int64 v7; // x0

  v1 = *((_QWORD *)*a1 + 7);
  if ( !*(_QWORD *)(v1 + 8) )
    return 4294967290LL;
  v2 = *((_DWORD *)a1 + 40);
  _drm_dev_dbg(0, 0, 1, "dev=%pK, crtc=%u\n", *a1, v2);
  if ( !v1 || *(_DWORD *)(v1 + 992) <= v2 )
    return 4294967274LL;
  v3 = _kmalloc_cache_noprof(_drm_debug, 2336, 56);
  if ( !v3 )
    return 4294967284LL;
  while ( v2 >= 0x10 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = *(_QWORD *)(StatusReg + 80);
    v7 = _drm_debug;
    *(_QWORD *)(StatusReg + 80) = &vblank_ctrl_queue_work__alloc_tag;
    v3 = _kmalloc_cache_noprof(v7, 2336, 56);
    *(_QWORD *)(StatusReg + 80) = v6;
    if ( !v3 )
      return 4294967284LL;
  }
  *(_QWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = 0;
  *(_QWORD *)v3 = v3;
  *(_QWORD *)(v3 + 8) = v3;
  *(_QWORD *)(v3 + 16) = &vblank_ctrl_worker;
  *(_DWORD *)(v3 + 40) = v2;
  *(_BYTE *)(v3 + 44) = 1;
  *(_QWORD *)(v3 + 48) = v1;
  kthread_queue_work(v1 + 80LL * v2 + 2432, v3);
  return 0;
}
