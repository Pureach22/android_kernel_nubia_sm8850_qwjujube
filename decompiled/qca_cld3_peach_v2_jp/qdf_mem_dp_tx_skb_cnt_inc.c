void qdf_mem_dp_tx_skb_cnt_inc()
{
  unsigned int v6; // w9

  _X8 = &dword_7169A4;
  __asm { PRFM            #0x11, [X8] }
  do
    v6 = __ldxr((unsigned int *)&dword_7169A4);
  while ( __stxr(v6 + 1, (unsigned int *)&dword_7169A4) );
  if ( dword_7169A8 < dword_7169A4 )
    dword_7169A8 = dword_7169A4;
}
