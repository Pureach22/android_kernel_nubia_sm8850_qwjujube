const void **__fastcall sde_crtc_disable_vblank(const void **result)
{
  __int64 v1; // x20
  unsigned int v2; // w19
  const void **v3; // x1
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x22
  __int64 v6; // x0

  v1 = *((_QWORD *)*result + 7);
  if ( *(_QWORD *)(v1 + 8) )
  {
    v2 = *((_DWORD *)result + 40);
    result = (const void **)_drm_dev_dbg(0, 0, 1, "dev=%pK, crtc=%u\n", *result, v2);
    if ( v1 )
    {
      if ( *(_DWORD *)(v1 + 992) > v2 )
      {
        result = (const void **)_kmalloc_cache_noprof(_drm_debug, 2336, 56);
        v3 = result;
        if ( result )
        {
          while ( v2 >= 0x10 )
          {
            __break(0x5512u);
            StatusReg = _ReadStatusReg(SP_EL0);
            v5 = *(_QWORD *)(StatusReg + 80);
            v6 = _drm_debug;
            *(_QWORD *)(StatusReg + 80) = &vblank_ctrl_queue_work__alloc_tag;
            result = (const void **)_kmalloc_cache_noprof(v6, 2336, 56);
            v3 = result;
            *(_QWORD *)(StatusReg + 80) = v5;
            if ( !result )
              return result;
          }
          v3[3] = nullptr;
          v3[4] = nullptr;
          *v3 = v3;
          v3[1] = v3;
          v3[2] = &vblank_ctrl_worker;
          *((_DWORD *)v3 + 10) = v2;
          *((_BYTE *)v3 + 44) = 0;
          v3[6] = (const void *)v1;
          return (const void **)kthread_queue_work(v1 + 80LL * v2 + 2432, v3);
        }
      }
    }
  }
  return result;
}
