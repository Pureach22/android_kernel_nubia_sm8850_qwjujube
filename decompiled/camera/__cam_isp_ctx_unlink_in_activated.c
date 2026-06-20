__int64 __fastcall _cam_isp_ctx_unlink_in_activated(__int64 a1)
{
  int v2; // w0

  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    2,
    "__cam_isp_ctx_unlink_in_activated",
    10166,
    "Received unlink in activated state. It's unexpected, ctx: %u link: 0x%x",
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 64));
  v2 = _cam_isp_ctx_stop_dev_in_activated_unlock(a1, 0);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_unlink_in_activated",
      10171,
      "Stop device failed rc=%d, ctx: %u link: 0x%x",
      v2,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  *(_QWORD *)(a1 + 216) = 0;
  *(_DWORD *)(a1 + 64) = -1;
  *(_DWORD *)(a1 + 240) = 2;
  return 0;
}
