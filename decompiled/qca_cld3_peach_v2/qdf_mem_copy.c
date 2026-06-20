void *__fastcall qdf_mem_copy(void *result, const void *a2, size_t n)
{
  if ( (_DWORD)n && result )
  {
    if ( a2 )
      return memcpy(result, a2, (unsigned int)n);
  }
  return result;
}
