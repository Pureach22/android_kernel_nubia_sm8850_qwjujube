__int64 cam_jpeg_dev_component_unbind()
{
  int v0; // w0
  int v1; // w0
  int v2; // w0
  int v3; // w0
  int v4; // w0
  int v5; // w0
  int v6; // w0
  int v7; // w0
  __int64 result; // x0

  v0 = cam_jpeg_context_deinit(&unk_3AECF0);
  if ( v0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      0,
      v0);
  v1 = cam_jpeg_context_deinit(&unk_3AFAB8);
  if ( v1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      1,
      v1);
  v2 = cam_jpeg_context_deinit(&unk_3B0880);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      2,
      v2);
  v3 = cam_jpeg_context_deinit(&unk_3B1648);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      3,
      v3);
  v4 = cam_jpeg_context_deinit(&unk_3B2410);
  if ( v4 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      4,
      v4);
  v5 = cam_jpeg_context_deinit(&unk_3B31D8);
  if ( v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      5,
      v5);
  v6 = cam_jpeg_context_deinit(&unk_3B3FA0);
  if ( v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      6,
      v6);
  v7 = cam_jpeg_context_deinit(&unk_3B4D68);
  if ( v7 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_dev_component_unbind",
      246,
      "JPEG context %d deinit failed %d",
      7,
      v7);
  result = cam_subdev_remove((void **)&g_jpeg_dev);
  if ( (_DWORD)result )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_dev_component_unbind",
             251,
             "Unregister failed %d",
             result);
  return result;
}
