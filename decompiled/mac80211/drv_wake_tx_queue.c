__int64 __fastcall drv_wake_tx_queue(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  int v3; // w2
  __int64 (*v4)(void); // x8
  __int64 v5; // x9
  const char *v6; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // [xsp+18h] [xbp+18h]

  if ( *(_BYTE *)(result + 1470) == 1 )
  {
    _X8 = (unsigned __int64 *)(a2 + 224);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 | 8, _X8) );
  }
  else
  {
    v2 = *(_QWORD *)(a2 + 232);
    if ( (*(_BYTE *)(*(_QWORD *)(v2 - 3104) + 1471LL) & 1) == 0 )
    {
      v3 = *(_DWORD *)(v2 - 3096);
      if ( (v3 & 0x20) == 0 && (drv_wake_tx_queue___already_done_2 & 1) == 0 )
      {
        v5 = *(_QWORD *)(v2 - 3112);
        drv_wake_tx_queue___already_done_2 = 1;
        v14 = result;
        if ( v5 )
          v6 = (const char *)(v5 + 296);
        else
          v6 = (const char *)(v2 - 3080);
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v6, v3);
        result = v14;
        __break(0x800u);
      }
    }
    if ( (*(_BYTE *)(v2 - 3096) & 0x20) != 0 )
    {
      v4 = *(__int64 (**)(void))(*(_QWORD *)(result + 464) + 752LL);
      if ( *((_DWORD *)v4 - 1) != -1212882962 )
        __break(0x8228u);
      return v4();
    }
  }
  return result;
}
