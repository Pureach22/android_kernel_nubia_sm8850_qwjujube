__int64 __fastcall qdf_mem_kmalloc_dec(__int64 result)
{
  unsigned int v7; // w9

  _X8 = &qdf_mem_stat;
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr((unsigned int *)&qdf_mem_stat);
  while ( __stxr(v7 - result, (unsigned int *)&qdf_mem_stat) );
  return result;
}
