_QWORD *__fastcall cam_req_mgr_debug_record_bind_latency(const char *a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  __int64 v6; // x0
  _QWORD *result; // x0
  _QWORD *v8; // x1

  if ( mem_trace_en == 1 )
    v4 = cam_mem_trace_alloc(32, 0xCC0u, 0, "cam_req_mgr_debug_record_bind_latency", 0xDBu);
  else
    v4 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  v5 = (_QWORD *)v4;
  if ( !v4 )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       16777232,
                       2,
                       "cam_req_mgr_debug_record_bind_latency",
                       223,
                       "%s: %u usec: Failed to allocate Bind Time node",
                       a1,
                       a2);
  if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000010,
      4,
      "cam_req_mgr_debug_record_bind_latency",
      226,
      "%s: bind latency: %u",
      a1,
      a2);
  v6 = kstrdup(a1, 3264);
  *v5 = v6;
  if ( v6 )
  {
    v5[1] = a2;
    result = v5 + 2;
    v8 = off_3EC0;
    if ( v5 + 2 == &cam_bind_latency_list || off_3EC0 == result || *off_3EC0 != (_UNKNOWN *)&cam_bind_latency_list )
    {
      return (_QWORD *)_list_add_valid_or_report(result);
    }
    else
    {
      off_3EC0 = (_UNKNOWN **)(v5 + 2);
      v5[2] = &cam_bind_latency_list;
      v5[3] = v8;
      *v8 = result;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16777232,
      2,
      "cam_req_mgr_debug_record_bind_latency",
      230,
      "%s: %u usec: Failed to create driver_name",
      a1,
      a2);
    if ( mem_trace_en == 1 )
      return cam_mem_trace_free(v5, 0);
    else
      return (_QWORD *)kvfree(v5);
  }
  return result;
}
