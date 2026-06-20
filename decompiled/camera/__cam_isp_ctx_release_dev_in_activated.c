__int64 __fastcall _cam_isp_ctx_release_dev_in_activated(__int64 a1, __int64 a2)
{
  int v4; // w0
  unsigned int v5; // w20

  v4 = _cam_isp_ctx_stop_dev_in_activated_unlock(a1, 0);
  if ( v4 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_dev_in_activated",
      9791,
      "Stop device failed rc=%d, ctx %u link: 0x%x",
      v4,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  v5 = _cam_isp_ctx_release_dev_in_top_state(a1, a2);
  if ( v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_release_dev_in_activated",
      9796,
      "Release device failed rc=%d ctx %u link: 0x%x",
      v5,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  return v5;
}
