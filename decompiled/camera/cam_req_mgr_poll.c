__int64 __fastcall cam_req_mgr_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x19
  void (*v3)(void); // x8

  v2 = *(_QWORD *)(a1 + 32);
  if ( v2 )
  {
    if ( a2 )
    {
      v3 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v3 - 1) != -442429149 )
          __break(0x8228u);
        v3();
        __dmb(0xBu);
      }
    }
    return 2 * (unsigned int)((unsigned int)v4l2_event_pending(v2) != 0);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_poll",
      193,
      "v4l2_fh_poll with unexpected input eventq");
    return 0;
  }
}
