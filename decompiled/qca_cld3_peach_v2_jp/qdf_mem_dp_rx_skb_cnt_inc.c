void qdf_mem_dp_rx_skb_cnt_inc()
{
  unsigned int v6; // w9

  _X8 = &dword_7169AC;
  __asm { PRFM            #0x11, [X8] }
  do
    v6 = __ldxr((unsigned int *)&dword_7169AC);
  while ( __stxr(v6 + 1, (unsigned int *)&dword_7169AC) );
  if ( dword_7169B0 < dword_7169AC )
    dword_7169B0 = dword_7169AC;
}
