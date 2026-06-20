__int64 __fastcall trace_raw_output_msm_v4l2_vidc_buffer_events(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "%s: %s: %s: idx %2d fd %3d off %d daddr %#llx inode %8lu ref %2ld size %8d filled %8d flags %#x ts %8lld attr %#x "
      "counts(etb ebd ftb fbd) %4llu %4llu %4llu %4llu\n"
      "\n",
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 8)),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 12)),
      (const char *)(v1 + *(unsigned __int16 *)(v1 + 16)),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 24),
      *(_DWORD *)(v1 + 28),
      *(_QWORD *)(v1 + 32),
      *(_QWORD *)(v1 + 40),
      *(_QWORD *)(v1 + 48),
      *(_DWORD *)(v1 + 56),
      *(_DWORD *)(v1 + 60),
      *(_DWORD *)(v1 + 64),
      *(_QWORD *)(v1 + 72),
      *(_DWORD *)(v1 + 80),
      *(_QWORD *)(v1 + 88),
      *(_QWORD *)(v1 + 96),
      *(_QWORD *)(v1 + 104),
      *(_QWORD *)(v1 + 112));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
