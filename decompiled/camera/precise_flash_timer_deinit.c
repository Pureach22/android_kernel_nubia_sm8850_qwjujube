__int64 __fastcall precise_flash_timer_deinit(__int64 a1)
{
  unsigned int v2; // w19
  int v3; // w20

  *(_DWORD *)(a1 + 6900) = 0;
  *(_BYTE *)(a1 + 6896) = 0;
  cam_req_mgr_workq_destroy((_QWORD *)(a1 + 6904));
  v2 = hrtimer_cancel(a1 + 6752);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "precise_flash_timer_deinit",
      306,
      "The HR ON Timer was still in use...rc: %d",
      v2);
  v3 = hrtimer_cancel(a1 + 6816);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "precise_flash_timer_deinit",
      310,
      "The HR OFF Timer was still in use...rc: %d",
      v2);
  return v3 | v2;
}
