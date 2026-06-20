__int64 __fastcall kgsl_process_event_groups(__int64 a1)
{
  _QWORD *i; // x21

  raw_read_lock(a1 + 13168);
  for ( i = *(_QWORD **)(a1 + 13152); i != (_QWORD *)(a1 + 13152); i = (_QWORD *)*i )
    process_event_group(a1, (__int64)(i - 4), 0);
  return raw_read_unlock(a1 + 13168);
}
