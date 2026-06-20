_QWORD *__fastcall cam_common_release_evt_params(_QWORD *result)
{
  __int64 *v1; // x22
  int v2; // w19
  __int64 *v3; // x26
  __int64 **v4; // x8
  __int64 *v5; // x9

  if ( byte_394041 == 1 )
  {
    v1 = (__int64 *)qword_394030;
    if ( (__int64 *)qword_394030 == &qword_394030 )
    {
      if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
        return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                           3,
                           debug_mdl & 0x20000,
                           4,
                           "cam_common_release_evt_params",
                           428,
                           "Event injection list is initialized but empty");
    }
    else
    {
      v2 = (int)result;
      do
      {
        v3 = (__int64 *)*v1;
        if ( *((_DWORD *)v1 + 12) == v2 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x20000,
            3,
            "cam_common_release_evt_params",
            435,
            "entry deleted for %d dev hdl",
            v2);
          v4 = (__int64 **)v1[1];
          if ( *v4 == v1 && (v5 = (__int64 *)*v1, *(__int64 **)(*v1 + 8) == v1) )
          {
            v5[1] = (__int64)v4;
            *v4 = v5;
          }
          else
          {
            _list_del_entry_valid_or_report(v1);
          }
          *v1 = 0xDEAD000000000100LL;
          v1[1] = 0xDEAD000000000122LL;
          if ( mem_trace_en == 1 )
            result = cam_mem_trace_free(v1, 0);
          else
            result = (_QWORD *)kvfree(v1);
        }
        v1 = v3;
      }
      while ( v3 != &qword_394030 );
    }
  }
  return result;
}
