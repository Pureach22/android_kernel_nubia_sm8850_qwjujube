__int64 __fastcall _cam_jpeg_ctx_dump_dev_in_acquired(__int64 a1, __int64 *a2)
{
  unsigned int v2; // w19

  v2 = cam_context_dump_dev_to_hw(a1, a2);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "__cam_jpeg_ctx_dump_dev_in_acquired",
      118,
      "Failed to dump device, rc=%d",
      v2);
  return v2;
}
