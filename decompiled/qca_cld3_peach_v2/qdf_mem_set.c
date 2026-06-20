void *__fastcall qdf_mem_set(void *result, size_t n, int c)
{
  if ( result )
    return memset(result, c, (unsigned int)n);
  return result;
}
