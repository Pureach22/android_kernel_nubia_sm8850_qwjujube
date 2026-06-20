__int64 __fastcall qdf_mem_skb_total_dec(__int64 result)
{
  unsigned int v7; // w9

  _X8 = &dword_71698C;
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr((unsigned int *)&dword_71698C);
  while ( __stxr(v7 - result, (unsigned int *)&dword_71698C) );
  return result;
}
