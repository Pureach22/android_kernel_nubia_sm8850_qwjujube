__int64 __fastcall cam_v4l2_event_queue_notify_error(__int64 a1)
{
  int v1; // w6
  __int64 v3; // x0
  __int64 v5; // x8
  const char *v6; // x9
  const char *v7; // x6
  int v8; // w0
  int v9; // w9
  __int64 v10; // x0
  const char *v11; // x8
  const char *v12; // x6
  __int64 v13; // x0

  v1 = *(_DWORD *)(a1 + 96);
  if ( v1 > 1 )
  {
    if ( v1 != 5 )
    {
      if ( v1 == 4 )
      {
        if ( (unsigned int)__ratelimit(&cam_v4l2_event_queue_notify_error__rs_47, "cam_v4l2_event_queue_notify_error") )
          v13 = 3;
        else
          v13 = 2;
        return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, _DWORD, _DWORD))cam_print_log)(
                 v13,
                 16,
                 1,
                 "cam_v4l2_event_queue_notify_error",
                 321,
                 "Failed to notify node event. Sess 0x%x ReqId %d Lnk 0x%x dev_hdl: %d evt_type: %u evt_cause: %u",
                 *(unsigned int *)(a1 + 8),
                 *(_QWORD *)(a1 + 32),
                 *(_DWORD *)(a1 + 20),
                 *(_DWORD *)(a1 + 16),
                 *(_DWORD *)(a1 + 24),
                 *(_DWORD *)(a1 + 28));
      }
      if ( v1 != 2 )
        return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 16,
                 1,
                 "cam_v4l2_event_queue_notify_error",
                 325,
                 "Failed to notify crm event id %d",
                 v1);
    }
    goto LABEL_12;
  }
  if ( !v1 )
  {
LABEL_12:
    v5 = *(_QWORD *)(a1 + 16);
    if ( v5 )
    {
      v6 = "UNIFIED_TS";
      if ( v1 == 2 )
        v6 = "BOOT_TS";
      if ( v1 )
        v7 = v6;
      else
        v7 = "SOF_TS";
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, _QWORD, _DWORD, __int64, _DWORD))cam_print_log)(
               3,
               16,
               1,
               "cam_v4l2_event_queue_notify_error",
               291,
               "Failed to notify %s Sess %X FrameId %lld FrameMeta %d ReqId %lld link %X",
               v7,
               *(unsigned int *)(a1 + 8),
               *(_QWORD *)(a1 + 24),
               *(_DWORD *)(a1 + 48),
               v5,
               *(_DWORD *)(a1 + 40));
    }
    else
    {
      v8 = __ratelimit(&cam_v4l2_event_queue_notify_error__rs, "cam_v4l2_event_queue_notify_error");
      v9 = *(_DWORD *)(a1 + 96);
      if ( v8 )
        v10 = 3;
      else
        v10 = 2;
      v11 = "BOOT_TS";
      if ( v9 != 2 )
        v11 = "UNIFIED_TS";
      if ( v9 )
        v12 = v11;
      else
        v12 = "SOF_TS";
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD))cam_print_log)(
               v10,
               16,
               2,
               "cam_v4l2_event_queue_notify_error",
               302,
               "Failed to notify %s Sess %X FrameId %lld FrameMeta %d ReqId %lld link %X",
               v12,
               *(unsigned int *)(a1 + 8),
               *(_QWORD *)(a1 + 24),
               *(_DWORD *)(a1 + 48),
               *(_QWORD *)(a1 + 16),
               *(_DWORD *)(a1 + 40));
    }
  }
  if ( v1 != 1 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             16,
             1,
             "cam_v4l2_event_queue_notify_error",
             325,
             "Failed to notify crm event id %d",
             v1);
  if ( (unsigned int)__ratelimit(&cam_v4l2_event_queue_notify_error__rs_45, "cam_v4l2_event_queue_notify_error") )
    v3 = 3;
  else
    v3 = 2;
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, _DWORD))cam_print_log)(
           v3,
           16,
           1,
           "cam_v4l2_event_queue_notify_error",
           311,
           "Failed to notify ERROR Sess %X ReqId %d Link %X Type %d ERR_code: %u",
           *(unsigned int *)(a1 + 8),
           *(unsigned int *)(a1 + 20),
           *(_DWORD *)(a1 + 28),
           *(_DWORD *)(a1 + 16),
           *(_DWORD *)(a1 + 36));
}
