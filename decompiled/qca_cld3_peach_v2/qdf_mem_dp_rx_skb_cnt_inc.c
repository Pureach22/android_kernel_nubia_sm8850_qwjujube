void qdf_mem_dp_rx_skb_cnt_inc()
{
  unsigned int v6; // w9

  _X8 = &dword_7CF3DC;
  __asm { PRFM            #0x11, [X8] }
  do
    v6 = __ldxr((unsigned int *)&dword_7CF3DC);
  while ( __stxr(v6 + 1, (unsigned int *)&dword_7CF3DC) );
  if ( dword_7CF3E0 < dword_7CF3DC )
    dword_7CF3E0 = dword_7CF3DC;
}
