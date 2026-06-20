__int64 __fastcall dp_rx_intrabss_mcast_handler_be(__int64 a1, _WORD *a2, __int64 a3, __int64 a4, unsigned __int8 a5)
{
  unsigned int v5; // w19
  __int16 v7; // w9
  __int64 v9; // x1
  __int64 v11; // x21
  _WORD *v14; // x8
  __int64 v15; // x10
  _WORD *v16; // x8
  __int64 v17; // x10
  __int64 v18; // [xsp+8h] [xbp-18h]
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int8 *)(*(_QWORD *)a2 + 56LL);
  if ( v5 == 1 )
  {
    v7 = a2[4];
    v9 = *(unsigned __int8 *)(*(_QWORD *)a2 + 59LL);
    v18 = 0;
    v19 = 0;
    v11 = *(unsigned __int16 *)(a3 + 60);
    LOWORD(v18) = v7;
    BYTE4(v19) = 2;
    BYTE2(v18) = 31;
    if ( dp_tx_send_exception(a1, v9) )
    {
      if ( a2 )
      {
        v14 = &a2[1628 * a5];
        v15 = *((_QWORD *)v14 + 391) + v11;
        ++*((_QWORD *)v14 + 390);
        *((_QWORD *)v14 + 391) = v15;
      }
      ++*(_QWORD *)(a4 + 296);
      if ( a3 )
        _qdf_nbuf_free(a3);
    }
    else
    {
      if ( a2 )
      {
        v16 = &a2[1628 * a5];
        v17 = *((_QWORD *)v16 + 389) + v11;
        ++*((_QWORD *)v16 + 388);
        *((_QWORD *)v16 + 389) = v17;
      }
      ++*(_QWORD *)(a4 + 264);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
