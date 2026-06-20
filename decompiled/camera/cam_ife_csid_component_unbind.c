_QWORD *__fastcall cam_ife_csid_component_unbind(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  __int64 matched; // x0
  __int64 v5; // x21

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_ife_csid_component_unbind",
                       139,
                       "Error No data in hw_intf");
  v2 = *(_QWORD **)(v1 + 112);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v5 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_component_unbind",
      146,
      "CSID:%d component unbind",
      *(_DWORD *)(v1 + 4));
    a1 = v5;
  }
  matched = of_match_device(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 40LL), a1);
  if ( matched )
    cam_ife_csid_hw_deinit(v1, *(_QWORD *)(matched + 192));
  else
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_component_unbind",
      151,
      "No matching table for the IFE CSID HW!");
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free((_QWORD *)v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
