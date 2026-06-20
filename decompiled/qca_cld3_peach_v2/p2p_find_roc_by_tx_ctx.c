_QWORD *__fastcall p2p_find_roc_by_tx_ctx(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w0
  _QWORD *v13; // x1
  _QWORD *v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p soc obj:%pK, cookie:%llx",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "p2p_find_roc_by_tx_ctx",
    a1,
    a2);
  v12 = qdf_list_peek_front((_QWORD *)(a1 + 8), v15);
  v13 = nullptr;
  if ( !v12 )
  {
    while ( 1 )
    {
      v13 = v15[0];
      if ( v15[0][4] == a2 )
        break;
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 8), v15[0], v15) )
      {
        v13 = nullptr;
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
