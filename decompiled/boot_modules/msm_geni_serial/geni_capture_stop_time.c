__int64 __fastcall geni_capture_stop_time(__int64 result, const char *a2, int a3, __int64 a4, int a5, int a6)
{
  __int64 v8; // x22
  unsigned __int64 v10; // x3
  unsigned __int64 v11; // x4

  if ( result && a3 && a4 )
  {
    v8 = result;
    v10 = sched_clock() - a4;
    v11 = v10 / 0x3E8;
    if ( a5 )
    {
      if ( a6 )
        return ipc_log_string(v8, "%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n", a2, v10, v11, a5, a6);
      else
        return ipc_log_string(v8, "%s:took %llu nsec(%llu usec) for %u bytes\n", a2, v10, v11, a5);
    }
    else
    {
      return ipc_log_string(v8, "%s:took %llu nsec(%llu usec)\n", a2, v10, v11);
    }
  }
  return result;
}
