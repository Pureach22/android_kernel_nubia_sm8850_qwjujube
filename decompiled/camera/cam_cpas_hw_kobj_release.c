_QWORD *__fastcall cam_cpas_hw_kobj_release(_QWORD *a1)
{
  _QWORD *v2; // x19

  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v2 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_hw_kobj_release",
      5160,
      "Release kobj");
    a1 = v2;
  }
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(a1, 0);
  else
    return (_QWORD *)kvfree(a1);
}
