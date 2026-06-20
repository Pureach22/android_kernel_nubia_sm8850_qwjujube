__int64 __fastcall kgsl_snapshot_eventlog_buffer(_QWORD *a1, _QWORD *a2, unsigned __int64 a3)
{
  __int64 v3; // x19

  if ( !kgsl_eventlog )
    return 0;
  v3 = 98312;
  if ( a3 < 0x18008 )
  {
    dev_err(*a1, "snapshot: Not enough memory for eventlog\n");
    return 0;
  }
  *a2 = 0x1800000000001LL;
  memcpy(a2 + 1, (const void *)kgsl_eventlog, 0x18000u);
  return v3;
}
