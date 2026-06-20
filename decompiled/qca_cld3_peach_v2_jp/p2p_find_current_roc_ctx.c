_QWORD *__fastcall p2p_find_current_roc_ctx(__int64 a1)
{
  int v2; // w8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *result; // x0
  _QWORD *v12; // x19
  _QWORD *v13[2]; // [xsp+30h] [xbp-10h] BYREF

  v13[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = nullptr;
  v2 = qdf_list_peek_front((_QWORD *)(a1 + 8), v13);
  result = nullptr;
  if ( !v2 )
  {
    do
    {
      if ( *((_DWORD *)v13[0] + 56) )
      {
        v12 = v13[0];
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc_t"
          "ype:%d, roc_state:%d",
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          "p2p_find_current_roc_ctx",
          v13[0][2],
          v13[0],
          *((unsigned int *)v13[0] + 6),
          *((unsigned int *)v13[0] + 7),
          v13[0][4],
          *((_DWORD *)v13[0] + 10),
          *((unsigned __int8 *)v13[0] + 44),
          *((_DWORD *)v13[0] + 12),
          *((_DWORD *)v13[0] + 13),
          *((_DWORD *)v13[0] + 56));
        result = v12;
        goto LABEL_7;
      }
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 8), v13[0], v13) );
    result = nullptr;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
