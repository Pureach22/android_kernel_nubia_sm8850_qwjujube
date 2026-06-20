__int64 cam_mem_trace_overview()
{
  __int64 v0; // x19
  _BYTE *v1; // x8
  __int64 v2; // x9
  __int64 v3; // x21

  v0 = 0;
  v1 = &unk_2FDD43;
  v2 = 2047;
  do
  {
    if ( *(v1 - 3) == 1 && *v1 == 1 )
      v0 += *(_QWORD *)(v1 - 43);
    --v2;
    v1 += 296;
  }
  while ( v2 );
  v3 = raw_spin_lock_irqsave(&dword_2FDB40);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    3,
    "cam_mem_trace_overview",
    524,
    "Total heap mem: %zu bytes, total dma mem: %zu bytes",
    qword_2FDB48,
    v0);
  raw_spin_unlock_irqrestore(&dword_2FDB40, v3);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, void *))cam_print_log)(
           3,
           0x400000,
           3,
           "cam_mem_trace_overview",
           528,
           &unk_3E455A);
}
