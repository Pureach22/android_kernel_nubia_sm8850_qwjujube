__int64 __fastcall qdf_mem_dp_tx_skb_inc(__int64 result)
{
  unsigned int v7; // w9

  _X8 = &dword_716990;
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr((unsigned int *)&dword_716990);
  while ( __stxr(v7 + result, (unsigned int *)&dword_716990) );
  if ( SHIDWORD(qword_716998) < dword_716990 )
    HIDWORD(qword_716998) = dword_716990;
  return result;
}
