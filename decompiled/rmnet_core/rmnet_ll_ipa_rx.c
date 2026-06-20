_QWORD *__fastcall rmnet_ll_ipa_rx(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  _QWORD *result; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned __int64 v14; // x8

  v4 = rmnet_ll_ipa_ep;
  result = rmnet_ll_get_stats();
  if ( a1 == 2 )
  {
    ++result[12];
    _X9 = &qword_6678;
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr((unsigned __int64 *)&qword_6678);
    while ( __stlxr(v14 | 1, (unsigned __int64 *)&qword_6678) );
    __dmb(0xBu);
    if ( (v14 & 1) == 0 )
      return (_QWORD *)_tasklet_schedule(&tx_pending_task);
  }
  else if ( a1 == 1 )
  {
    v6 = *(_QWORD *)(v4 + 40);
    *(_WORD *)(a2 + 180) = -1792;
    *(_QWORD *)(a2 + 16) = v6;
    *(_WORD *)(a2 + 124) = 2;
    if ( a2 )
    {
      v7 = a2;
      do
      {
        *(_DWORD *)(v7 + 144) = 55834;
        if ( v7 == a2 )
          v7 = *(_QWORD *)(v7 + 216) + *(unsigned int *)(v7 + 212) + 8LL;
        v7 = *(_QWORD *)v7;
      }
      while ( v7 );
    }
    ++result[9];
    return (_QWORD *)netif_rx(a2);
  }
  else
  {
    return (_QWORD *)printk(&unk_2CDAA, "rmnet_ll_ipa_rx");
  }
  return result;
}
