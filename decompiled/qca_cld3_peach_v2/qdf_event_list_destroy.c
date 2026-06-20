__int64 qdf_event_list_destroy()
{
  __int64 result; // x0

  if ( (_DWORD)qword_7CF320 )
    return qdf_trace_msg(51, 2, "%s: list length not equal to zero", "qdf_list_destroy");
  return result;
}
