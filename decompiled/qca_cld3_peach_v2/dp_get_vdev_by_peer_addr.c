__int64 __fastcall dp_get_vdev_by_peer_addr(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  int v21; // [xsp+0h] [xbp-10h] BYREF
  __int16 v22; // [xsp+4h] [xbp-Ch]
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = a2;
  v22 = WORD2(a2);
  if ( !a1 )
  {
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: PDEV not found for peer_addr: %02x:%02x:%02x:**:**:%02x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_get_vdev_by_peer_addr",
      (unsigned __int8)a2,
      BYTE1(a2),
      BYTE2(a2),
      BYTE5(a2));
LABEL_6:
    v19 = 0;
    goto LABEL_7;
  }
  v10 = dp_peer_find_hash_find(*(_QWORD *)(a1 + 8), (unsigned __int16 *)&v21, 0, 0xFFu, 7u);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x3Fu,
      5u,
      "PDEV not found for peer_addr: %02x:%02x:%02x:**:**:%02x",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      (unsigned __int8)v21,
      BYTE1(v21),
      BYTE2(v21),
      HIBYTE(v22));
    goto LABEL_6;
  }
  v19 = *(_QWORD *)(v10 + 24);
  dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v19;
}
