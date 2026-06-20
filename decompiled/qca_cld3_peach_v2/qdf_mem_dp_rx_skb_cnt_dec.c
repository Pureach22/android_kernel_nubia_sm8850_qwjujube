void qdf_mem_dp_rx_skb_cnt_dec()
{
  unsigned int v6; // w10

  _X9 = &dword_7CF3DC;
  __asm { PRFM            #0x11, [X9] }
  do
    v6 = __ldxr((unsigned int *)&dword_7CF3DC);
  while ( __stxr(v6 - 1, (unsigned int *)&dword_7CF3DC) );
}
