_QWORD *__fastcall cam_jpeg_dma_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x20
  __int64 v3; // x21
  int v4; // w0
  int v5; // w22
  int v7; // w0

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       512,
                       1,
                       "cam_jpeg_dma_component_unbind",
                       191,
                       "error No data in pdev");
  v2 = (_QWORD *)v1[14];
  if ( v2 )
  {
    v3 = v2[460];
    if ( v3 )
    {
      v4 = cam_cpas_unregister_client(*(_DWORD *)(v3 + 16));
      if ( v4 )
      {
        v5 = v4;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dma_unregister_cpas",
          62,
          "cpas unregister failed: %d",
          v4);
        *(_DWORD *)(v3 + 16) = 0;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_dma_component_unbind",
          210,
          " unreg failed to reg cpas %d",
          v5);
      }
      else
      {
        *(_DWORD *)(v3 + 16) = 0;
      }
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v3, 0);
      else
        kvfree(v3);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_component_unbind",
        204,
        "error core data NULL");
    }
    v7 = cam_soc_util_release_platform_resource((__int64)(v2 + 12));
    if ( v7 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_dma_component_unbind",
        218,
        "Failed to deinit soc rc=%d",
        v7);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v2, 0);
    else
      kvfree(v2);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dma_component_unbind",
      197,
      "error HW data is NULL");
  }
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
