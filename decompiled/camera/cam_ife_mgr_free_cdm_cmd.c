_QWORD *__fastcall cam_ife_mgr_free_cdm_cmd(_QWORD **a1)
{
  _QWORD *v2; // x0
  _QWORD *result; // x0

  v2 = *a1;
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(v2, 0);
  else
    result = (_QWORD *)kvfree(v2);
  *a1 = nullptr;
  return result;
}
