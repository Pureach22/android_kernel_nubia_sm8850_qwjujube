__int64 __fastcall _cam_jpeg_ctx_release_dev_in_acquired(__int64 a1)
{
  unsigned int v2; // w20

  cam_common_release_evt_params((_QWORD *)*(unsigned int *)(a1 + 60));
  v2 = cam_context_release_dev_to_hw(a1);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "__cam_jpeg_ctx_release_dev_in_acquired",
      103,
      "Unable to release device %d",
      v2);
  *(_DWORD *)(a1 + 240) = 1;
  return v2;
}
