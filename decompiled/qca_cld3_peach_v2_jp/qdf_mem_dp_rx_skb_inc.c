__int64 __fastcall qdf_mem_dp_rx_skb_inc(__int64 result)
{
  unsigned int v7; // w9

  _X8 = &dword_716994;
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr((unsigned int *)&dword_716994);
  while ( __stxr(v7 + result, (unsigned int *)&dword_716994) );
  if ( dword_7169A0 < dword_716994 )
    dword_7169A0 = dword_716994;
  return result;
}
