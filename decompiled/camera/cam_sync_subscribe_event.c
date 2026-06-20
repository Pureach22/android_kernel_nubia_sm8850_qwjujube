__int64 __fastcall cam_sync_subscribe_event(__int64 a1, int *a2)
{
  int v2; // w6
  char v3; // w8
  __int64 v5; // [xsp+0h] [xbp-10h]
  int *v6; // [xsp+8h] [xbp-8h]

  v2 = *a2;
  if ( (unsigned int)*a2 >> 1 == 0x4000000 )
  {
    v3 = debug_mdl;
    *(_DWORD *)(sync_dev + 8680) = v2;
    if ( v3 < 0 && !debug_priority )
    {
      v5 = a1;
      v6 = a2;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v3 & 0x80,
        4,
        "cam_sync_subscribe_event",
        2567,
        "Sync event verion type 0x%x",
        v2);
      a1 = v5;
      a2 = v6;
    }
    return v4l2_event_subscribe(a1, a2, 250, &cam_sync_v4l2_ops);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_subscribe_event",
      2562,
      "Non supported event type 0x%x",
      v2);
    return 4294967274LL;
  }
}
