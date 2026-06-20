__int64 cam_synx_obj_driver_init()
{
  __int64 v0; // x0
  const void *v1; // x0
  __int64 v2; // x8
  unsigned __int64 *v3; // x19
  __int64 result; // x0
  unsigned __int64 v11; // x9
  _QWORD v12[3]; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v13[7]; // [xsp+18h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( mem_trace_en == 1 )
    v0 = cam_mem_trace_alloc(23648, 0xCC0u, 0, "cam_synx_obj_driver_init", 0x361u);
  else
    v0 = _kvmalloc_node_noprof(23648, 0, 3520, 0xFFFFFFFFLL);
  g_cam_synx_obj_dev = v0;
  if ( v0 )
  {
    v12[0] = cam_synx_session_name;
    v12[1] = v13;
    memset(v13, 0, 48);
    v12[2] = 0x100000000LL;
    v1 = (const void *)synx_initialize(v12);
    v2 = g_cam_synx_obj_dev;
    *(_QWORD *)(g_cam_synx_obj_dev + 23552) = v1;
    if ( v1 )
    {
      if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000000000LL,
          4,
          "__cam_synx_init_session",
          777,
          "Synx session initialized: %p",
          v1);
        v2 = g_cam_synx_obj_dev;
      }
      _mutex_init(v2 + 23560, "&g_cam_synx_obj_dev->dev_lock", &cam_synx_obj_driver_init___key);
      v3 = (unsigned __int64 *)g_cam_synx_obj_dev;
      memset((void *)(g_cam_synx_obj_dev + 22528), 0, 0x400u);
      memset(v3, 0, 0x5800u);
      v3[2951] = 0;
      _X8 = v3 + 2951;
      v3[2952] = 0;
      v3[2953] = 0;
      v3[2954] = 0;
      __asm { PRFM            #0x11, [X8] }
      do
        v11 = __ldxr(_X8);
      while ( __stxr(v11 | 1, _X8) );
      result = 0;
      if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x1000000000LL,
          4,
          "cam_synx_obj_driver_init",
          883,
          "Camera synx obj driver initialized");
        result = 0;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x1000000000LL,
        1,
        "__cam_synx_init_session",
        772,
        "Synx session initialization failed");
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x1000000000LL,
        1,
        "cam_synx_obj_driver_init",
        887,
        "Camera synx obj driver initialization failed");
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)g_cam_synx_obj_dev, 0);
      else
        kvfree(g_cam_synx_obj_dev);
      result = 4294967274LL;
      g_cam_synx_obj_dev = 0;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
