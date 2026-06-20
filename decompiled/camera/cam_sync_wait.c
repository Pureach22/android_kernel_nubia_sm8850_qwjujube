__int64 __fastcall cam_sync_wait(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // w20
  __int64 v4; // x19
  unsigned int v5; // w6

  if ( a1 - 2048 >= 0xFFFFF801 )
  {
    v4 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
    if ( *(_DWORD *)(v4 + 104) )
    {
      _msecs_to_jiffies(a2);
      if ( !cam_common_wait_for_completion_timeout(v4 + 112) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_wait",
          652,
          "Error: timed out for sync obj = %s[%d]",
          (const char *)v4,
          a1);
        v2 = -110;
        goto LABEL_11;
      }
      v5 = *(_DWORD *)(v4 + 104);
      if ( v5 <= 4 )
      {
        if ( v5 == 2 )
          return 0;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_wait",
          663,
          "Error: Wait on invalid state = %d, obj = %d, name = %s",
          v5,
          a1,
          (const char *)v4);
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_wait",
        642,
        "Error: accessing an uninitialized sync obj = %s[%d]",
        (const char *)v4,
        a1);
    }
    v2 = -22;
LABEL_11:
    cam_sync_dump_monitor_array(v4);
    return v2;
  }
  return (unsigned int)-22;
}
