void *__fastcall syna_pal_mem_cpy(void *result, unsigned int a2, void *src, unsigned int a4, size_t n)
{
  if ( result && src )
  {
    if ( (unsigned int)n > a2 || (unsigned int)n > a4 )
    {
      printk(unk_3944E, "syna_pal_mem_cpy", a4);
      return NULL;
    }
    else
      return memcpy(result, src, (unsigned int)n);
  }
  return result;
}
