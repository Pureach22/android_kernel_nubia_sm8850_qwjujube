void __usercall ipa3_tx_client_rx_pkt_status(unsigned int a1@<W1>, unsigned int a2@<W8>)
{
  _UNKNOWN **v2; // x9
  __int64 v4; // x8
  unsigned int v10; // w11

  if ( a1 >= 0x24 )
  {
    __break(0x5512u);
  }
  else
  {
    a2 = a1;
    v2 = &off_1F7000;
    _X10 = (unsigned int *)(ipa3_ctx + 480LL * (int)a1 + 552);
  }
  __asm { PRFM            #0x11, [X10] }
  do
    v10 = __ldxr(_X10);
  while ( __stxr(v10 + 1, _X10) );
  v4 = (__int64)v2[257] + 480 * (int)a2;
  ++*(_DWORD *)(v4 + 580);
}
