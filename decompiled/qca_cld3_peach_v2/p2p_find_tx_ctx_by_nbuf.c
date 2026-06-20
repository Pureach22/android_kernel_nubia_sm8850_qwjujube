_QWORD *__fastcall p2p_find_tx_ctx_by_nbuf(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x20
  _QWORD *result; // x0
  _QWORD *v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = nullptr;
  if ( !a1 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: invalid p2p soc object", a3, a4, a5, a6, a7, a8, a9, a10, "p2p_find_tx_ctx_by_nbuf");
    goto LABEL_8;
  }
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 56), v22) )
  {
LABEL_8:
    result = nullptr;
    goto LABEL_9;
  }
  while ( v22[0][32] != a2 )
  {
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 56), v22[0], v22) )
      goto LABEL_8;
  }
  v20 = v22[0];
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: find tx ctx, nbuf:%pK",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "p2p_find_tx_ctx_by_nbuf",
    a2);
  result = v20;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
