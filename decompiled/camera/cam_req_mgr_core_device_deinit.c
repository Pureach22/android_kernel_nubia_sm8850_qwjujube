__int64 cam_req_mgr_core_device_deinit()
{
  if ( g_crm_core_dev )
  {
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_core_device_deinit",
        6308,
        "g_crm_core_dev %pK",
        (const void *)g_crm_core_dev);
    cam_req_mgr_debug_unregister();
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(g_crm_core_dev, 0);
    else
      kvfree(g_crm_core_dev);
    g_crm_core_dev = 0;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_core_device_deinit",
      6304,
      "NULL pointer");
    return 4294967274LL;
  }
}
