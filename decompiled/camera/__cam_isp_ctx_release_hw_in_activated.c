__int64 __fastcall _cam_isp_ctx_release_hw_in_activated(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w20

  v2 = _cam_isp_ctx_stop_dev_in_activated_unlock(a1, 0);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_hw_in_activated",
      9809,
      "Stop device failed rc=%d, ctx %u link: 0x%x",
      v2,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  v3 = _cam_isp_ctx_release_hw_in_top_state(a1);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_hw_in_activated",
      9814,
      "Release hw failed rc=%d, ctx %u link: 0x%x",
      v3,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  return v3;
}
