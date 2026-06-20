__int64 kgsl_eventlog_init()
{
  __int64 v0; // x1
  __int64 v1; // x9
  unsigned __int64 v2; // x13
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x2

  v0 = _kmalloc_large_noprof(98304, 3520);
  v1 = v0 << 8 >> 8;
  kgsl_eventlog = v0;
  v2 = (unsigned __int64)(v1 + 0x8000000000LL) >> 38;
  v3 = v1 + 0x8000000000LL + memstart_addr;
  v4 = v1 - kimage_voffset;
  if ( v2 )
    v5 = v4;
  else
    v5 = v3;
  eventlog_wptr = 0;
  lock = 0;
  return kgsl_add_to_minidump("KGSL_EVENTLOG", v0, v5, 98304);
}
