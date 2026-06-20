__int64 __fastcall _cam_jpeg_ctx_stop_dev_in_acquired(__int64 a1)
{
  unsigned int v1; // w19

  v1 = cam_context_stop_dev_to_hw(a1);
  if ( v1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "__cam_jpeg_ctx_stop_dev_in_acquired",
      191,
      "Failed in Stop dev, rc=%d",
      v1);
  return v1;
}
