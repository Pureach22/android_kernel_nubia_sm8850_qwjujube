const void *__fastcall qdf_mem_copy_toio(const void *result, const void *a2, unsigned int a3)
{
  if ( a3 )
  {
    if ( result && a2 )
      return (const void *)_memcpy_toio(result, a2, a3);
    else
      return (const void *)qdf_trace_msg(
                             56,
                             2,
                             "%s called with NULL parameter, source:%pK destination:%pK",
                             "qdf_mem_copy_toio",
                             a2,
                             result);
  }
  return result;
}
