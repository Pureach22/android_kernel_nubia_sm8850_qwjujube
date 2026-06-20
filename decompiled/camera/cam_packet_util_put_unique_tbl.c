_QWORD *__fastcall cam_packet_util_put_unique_tbl(_QWORD *a1, _QWORD *a2)
{
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(a1, 0);
  else
    kvfree(a1);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(a2, 0);
  else
    return (_QWORD *)kvfree(a2);
}
