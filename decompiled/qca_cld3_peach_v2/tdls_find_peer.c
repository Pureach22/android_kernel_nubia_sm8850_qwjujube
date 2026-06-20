_QWORD *__fastcall tdls_find_peer(__int64 a1, unsigned __int8 *a2)
{
  unsigned __int8 v4; // w10
  unsigned __int8 v5; // w11
  unsigned __int8 v6; // w12
  unsigned __int8 v7; // w13
  char v8; // w8
  __int64 v9; // x22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  _QWORD *v22; // x21
  _QWORD *v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2[2];
  v5 = a2[3];
  v6 = a2[4];
  v7 = a2[5];
  v8 = a2[1] ^ *a2;
  v24[0] = nullptr;
  v9 = a1 + 24LL * (((unsigned __int8)(v8 ^ v4 ^ v5) ^ (unsigned __int8)(v6 ^ v7)) & 0xF);
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v9 + 8), v24) )
  {
LABEL_2:
    if ( a2 )
    {
      v18 = *a2;
      v19 = a2[1];
      v20 = a2[2];
      v21 = a2[5];
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v19 = 0;
      v21 = 0;
    }
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev %d no tdls peer %02x:%02x:%02x:**:**:%02x",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "tdls_find_peer",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 168LL),
      v18,
      v19,
      v20,
      v21);
    v22 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v22 = v24[0];
      if ( !(unsigned int)qdf_mem_cmp(v24[0] + 3, a2, 6u) )
        break;
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v9 + 8), v24[0], v24) )
        goto LABEL_2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v22;
}
