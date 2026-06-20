__int64 __fastcall cam_sync_unsubscribe_event(__int64 a1, _DWORD *a2)
{
  if ( *a2 >> 1 == 0x4000000 )
    return v4l2_event_unsubscribe(a1, a2);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    128,
    1,
    "cam_sync_unsubscribe_event",
    2577,
    "Non supported event type 0x%x",
    *a2);
  return 4294967274LL;
}
