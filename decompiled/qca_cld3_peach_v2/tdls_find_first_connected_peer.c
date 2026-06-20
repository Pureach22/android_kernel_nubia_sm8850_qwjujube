_QWORD *__fastcall tdls_find_first_connected_peer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x19
  _QWORD *v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = nullptr;
  if ( a1 )
  {
    v9 = 0;
    v10 = a1 + 8;
    while ( (unsigned int)qdf_list_peek_front((_QWORD *)(v10 + 24 * v9), v21) )
    {
LABEL_3:
      if ( ++v9 == 16 )
        goto LABEL_11;
    }
    while ( !v21[0] || *((_DWORD *)v21[0] + 9) != 4 )
    {
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v10 + 24 * v9), v21[0], v21) )
        goto LABEL_3;
    }
    v19 = v21[0];
    qdf_trace_msg(
      0,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x TDLS_LINK_CONNECTED",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "tdls_find_first_connected_peer",
      *((unsigned __int8 *)v21[0] + 24),
      *((unsigned __int8 *)v21[0] + 25),
      *((unsigned __int8 *)v21[0] + 26),
      *((unsigned __int8 *)v21[0] + 29));
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: invalid tdls vdev object",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tdls_find_first_connected_peer");
LABEL_11:
    v19 = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return v19;
}
