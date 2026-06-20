__int64 __fastcall _cam_jpeg_ctx_acquire_dev_in_available(__int64 a1, _DWORD *a2)
{
  unsigned int v3; // w19

  v3 = cam_context_acquire_dev_to_hw(a1, a2);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "__cam_jpeg_ctx_acquire_dev_in_available",
      87,
      "Unable to Acquire device %d",
      v3);
  else
    *(_DWORD *)(a1 + 240) = 2;
  return v3;
}
