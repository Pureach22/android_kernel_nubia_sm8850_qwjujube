__int64 __fastcall cam_sync_check_valid(unsigned int a1)
{
  unsigned int v1; // w19
  unsigned __int64 v3; // x21
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x20
  const char *v7; // x5
  __int64 v8; // x4

  if ( a1 - 2048 >= 0xFFFFF801 )
  {
    v3 = a1;
    raw_spin_lock_bh(sync_dev + 4LL * a1 + 136);
    v4 = sync_dev;
    v5 = *(_QWORD *)(sync_dev + 128);
    v6 = v5 + 216LL * a1;
    if ( ((*(_QWORD *)(sync_dev + ((v3 >> 3) & 0x1FFFFFF8) + 8416) >> v3) & 1) != 0 )
    {
      if ( *(_DWORD *)(v6 + 104) )
      {
        v1 = 0;
LABEL_9:
        raw_spin_unlock_bh(v4 + 4 * v3 + 136);
        return v1;
      }
      v7 = "Error: accessing an uninitialized sync obj = %s[%d]";
      v8 = 615;
    }
    else
    {
      v7 = "Error: Released sync obj received %s[%d]";
      v8 = 607;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_check_valid",
      v8,
      v7,
      v5 + 216LL * a1,
      a1);
    cam_sync_dump_monitor_array(v6);
    v4 = sync_dev;
    v1 = -22;
    goto LABEL_9;
  }
  return (unsigned int)-22;
}
