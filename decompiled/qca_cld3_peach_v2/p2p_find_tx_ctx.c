_QWORD *__fastcall p2p_find_tx_ctx(
        __int64 a1,
        _QWORD *a2,
        _BYTE *a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _BYTE *v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *result; // x0
  _QWORD *v25; // x21
  _QWORD *v26[2]; // [xsp+0h] [xbp-10h] BYREF

  v15 = a3;
  v26[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  *a3 = 0;
  *a4 = 0;
  v26[0] = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: Start to find tx ctx, p2p soc_obj:%pK, cookie:%llx",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "p2p_find_tx_ctx",
    a1,
    a2);
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 32), v26) )
  {
    while ( v26[0] != a2 )
    {
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 32), v26[0], v26) )
        goto LABEL_2;
    }
    v25 = v26[0];
    goto LABEL_10;
  }
LABEL_2:
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 56), v26) )
  {
    while ( v26[0] != a2 )
    {
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 56), v26[0], v26) )
        goto LABEL_3;
    }
    v25 = v26[0];
    v15 = a4;
LABEL_10:
    *v15 = 1;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: find tx ctx, cookie:%llx",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "p2p_find_tx_ctx",
      a2);
    result = v25;
    goto LABEL_11;
  }
LABEL_3:
  result = nullptr;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
