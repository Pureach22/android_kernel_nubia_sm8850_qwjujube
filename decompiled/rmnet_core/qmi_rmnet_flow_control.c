__int64 __fastcall qmi_rmnet_flow_control(__int64 a1, unsigned int a2, int a3)
{
  __int64 v3; // x0
  unsigned __int64 v11; // x9

  if ( *(_DWORD *)(a1 + 1096) > a2 )
  {
    v3 = *(_QWORD *)(a1 + 24) + 384LL * a2;
    if ( v3 )
    {
      if ( a3 )
      {
        netif_tx_wake_queue(v3);
      }
      else
      {
        *(_QWORD *)(v3 + 328) = jiffies;
        __dmb(0xBu);
        _X8 = (unsigned __int64 *)(v3 + 336);
        __asm { PRFM            #0x11, [X8] }
        do
          v11 = __ldxr(_X8);
        while ( __stxr(v11 | 1, _X8) );
      }
    }
  }
  return 0;
}
