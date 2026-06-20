__int64 kgsl_eventlog_exit()
{
  __int64 v0; // x8
  unsigned __int64 v1; // x9
  __int64 v2; // x8
  unsigned __int64 v3; // x12
  unsigned __int64 v4; // x9
  __int64 v5; // x2
  __int64 result; // x0

  v0 = kgsl_eventlog << 8 >> 8;
  v1 = v0 + 0x8000000000LL;
  v2 = v0 - kimage_voffset;
  v3 = v1 >> 38;
  v4 = v1 + memstart_addr;
  if ( v3 )
    v5 = v2;
  else
    v5 = v4;
  kgsl_remove_from_minidump("KGSL_EVENTLOG", kgsl_eventlog, v5, 98304);
  result = kfree(kgsl_eventlog);
  kgsl_eventlog = 0;
  eventlog_wptr = 0;
  return result;
}
