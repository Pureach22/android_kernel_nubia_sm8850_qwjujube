void qdf_mem_dp_tx_skb_cnt_dec()
{
  unsigned int v6; // w10

  _X9 = &dword_7169A4;
  __asm { PRFM            #0x11, [X9] }
  do
    v6 = __ldxr((unsigned int *)&dword_7169A4);
  while ( __stxr(v6 - 1, (unsigned int *)&dword_7169A4) );
}
