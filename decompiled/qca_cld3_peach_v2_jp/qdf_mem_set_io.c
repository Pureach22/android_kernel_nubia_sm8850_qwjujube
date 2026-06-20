__int64 __fastcall qdf_mem_set_io(__int64 a1, unsigned int a2, unsigned int a3)
{
  if ( a1 )
    return _memset_io(a1, a3, a2);
  else
    return qdf_trace_msg(56, 2, "%s: %s called with NULL parameter ptr", "qdf_mem_set_io", "qdf_mem_set_io");
}
