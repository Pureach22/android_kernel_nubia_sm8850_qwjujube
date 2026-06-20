__int64 __fastcall rmnet_vnd_do_flow_control(__int64 a1, int a2)
{
  __int64 v2; // x0
  unsigned __int64 v10; // x9

  v2 = *(_QWORD *)(a1 + 24);
  if ( a2 )
  {
    netif_tx_wake_queue(v2);
  }
  else
  {
    *(_QWORD *)(v2 + 328) = jiffies;
    __dmb(0xBu);
    _X8 = (unsigned __int64 *)(v2 + 336);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 | 1, _X8) );
  }
  return 0;
}
