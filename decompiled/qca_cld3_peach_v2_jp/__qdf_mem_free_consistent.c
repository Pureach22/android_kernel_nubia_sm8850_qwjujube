__int64 __fastcall _qdf_mem_free_consistent(__int64 a1, __int64 a2, int a3)
{
  unsigned int v10; // w9

  _X8 = &dword_716984;
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr((unsigned int *)&dword_716984);
  while ( __stxr(v10 - a3, (unsigned int *)&dword_716984) );
  return dma_free_attrs();
}
