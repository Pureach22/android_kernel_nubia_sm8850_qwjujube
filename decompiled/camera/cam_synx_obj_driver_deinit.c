_QWORD *cam_synx_obj_driver_deinit()
{
  int v0; // w0
  _QWORD *result; // x0

  if ( *(_QWORD *)(g_cam_synx_obj_dev + 23552) )
  {
    v0 = synx_uninitialize();
    if ( v0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x1000000000LL,
        1,
        "cam_synx_obj_driver_deinit",
        902,
        "Synx failed to uninitialize session: %p, rc: %d",
        *(const void **)(g_cam_synx_obj_dev + 23552),
        v0);
  }
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free((_QWORD *)g_cam_synx_obj_dev, 0);
  else
    result = (_QWORD *)kvfree(g_cam_synx_obj_dev);
  g_cam_synx_obj_dev = 0;
  if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       debug_mdl & 0x1000000000LL,
                       4,
                       "cam_synx_obj_driver_deinit",
                       908,
                       "Camera synx obj driver deinitialized");
  return result;
}
