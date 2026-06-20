_QWORD *__fastcall _cam_dma_fence_free(_QWORD *a1)
{
  _QWORD *v2; // x0

  if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x400000000LL,
      4,
      "__cam_dma_fence_free",
      59,
      "Free memory for dma fence context: %llu seqno: %llu",
      a1[4],
      a1[5]);
  v2 = (_QWORD *)*a1;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(a1, 0);
  else
    return (_QWORD *)kvfree(a1);
}
