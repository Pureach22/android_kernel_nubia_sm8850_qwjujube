__int64 __fastcall cam_sync_event_queue_notify_error(unsigned int *a1)
{
  __int64 v1; // x6
  __int64 v2; // x7
  unsigned int v3; // w8

  v1 = a1[24];
  v2 = a1[2];
  v3 = a1[3];
  if ( *(_DWORD *)(sync_dev + 8680) == 134217729 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))cam_print_log)(
             3,
             16,
             1,
             "cam_sync_event_queue_notify_error",
             2541,
             "Failed to notify event id %d fence %d statue %d reason %u %u %u %u",
             v1,
             v2,
             v3,
             a1[5],
             a1[6],
             a1[7],
             a1[8]);
  else
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
             3,
             16,
             1,
             "cam_sync_event_queue_notify_error",
             2549,
             "Failed to notify event id %d fence %d statue %d",
             v1,
             v2,
             v3);
}
