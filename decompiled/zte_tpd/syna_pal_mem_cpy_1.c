__int64 __fastcall syna_pal_mem_cpy_1(void *a1, unsigned int a2, void *src, unsigned int a4, size_t n)
{
  if ( !a1 )
    return 4294967274LL;
  if ( (unsigned int)n > a2 || (unsigned int)n > a4 )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", a4);
    return 4294967274LL;
  }
  else
  {
    memcpy(a1, src, (unsigned int)n);
    return 0;
  }
}
