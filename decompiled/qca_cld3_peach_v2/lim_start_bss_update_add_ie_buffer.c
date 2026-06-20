_QWORD *__fastcall lim_start_bss_update_add_ie_buffer(
        _QWORD *result,
        unsigned __int16 *a2,
        const void *a3,
        unsigned __int16 a4)
{
  _QWORD *v5; // x21

  v5 = result;
  if ( a3 && a4 )
  {
    *a2 = a4;
    result = (_QWORD *)_qdf_mem_malloc(a4, "lim_start_bss_update_add_ie_buffer", 10673);
    *v5 = result;
    if ( result )
      return qdf_mem_copy(result, a3, *a2);
  }
  else
  {
    *result = 0;
    *a2 = 0;
  }
  return result;
}
