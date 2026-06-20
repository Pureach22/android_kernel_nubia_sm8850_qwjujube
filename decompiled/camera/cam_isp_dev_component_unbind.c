void *__fastcall cam_isp_dev_component_unbind(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x23
  __int64 v3; // x19
  void *result; // x0
  int v5; // w0
  const char *v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 744);
  v6[0] = nullptr;
  if ( (of_property_read_string_helper(v1, "arch-compat", v6, 1, 0) & 0x80000000) != 0 )
  {
    result = (void *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_isp_dev_component_unbind",
                       332,
                       "Failed at reading arch-compat");
  }
  else
  {
    cam_isp_hw_mgr_deinit(v6[0]);
    if ( dword_3A8B70 >= 1 )
    {
      v2 = 0;
      v3 = 0;
      do
      {
        if ( (unsigned int)cam_isp_context_deinit((void *)(qword_3A8B30 + v2)) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_dev_component_unbind",
            341,
            "ISP context %d deinit failed",
            v3);
        ++v3;
        v2 += 45768;
      }
      while ( v3 < dword_3A8B70 );
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)qword_3A8B28, 0);
    else
      kvfree(qword_3A8B28);
    qword_3A8B28 = 0;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)qword_3A8B30, 0);
    else
      kvfree(qword_3A8B30);
    qword_3A8B30 = 0;
    v5 = cam_subdev_remove((void **)&g_isp_dev);
    if ( v5 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_dev_component_unbind",
        351,
        "Unregister failed rc: %d",
        v5);
    result = memset(&g_isp_dev, 0, 0x228u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
