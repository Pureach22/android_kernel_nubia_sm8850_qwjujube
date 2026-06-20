_QWORD *__fastcall p2p_find_roc_by_chan_freq(__int64 a1, int a2)
{
  int v4; // w8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *result; // x0
  _QWORD *v14; // x19
  int v15; // [xsp+8h] [xbp-38h]
  _QWORD *v16[2]; // [xsp+30h] [xbp-10h] BYREF

  v16[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = nullptr;
  v4 = qdf_list_peek_front((_QWORD *)(a1 + 8), v16);
  result = nullptr;
  if ( !v4 )
  {
    do
    {
      if ( *((_DWORD *)v16[0] + 10) == a2 )
      {
        v15 = a2;
        v14 = v16[0];
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: p2p soc obj:%pK, roc ctx:%pK, vdev_id:%d, scan_id:%d, tx ctx:%pK, freq:%d, phy_mode:%d, duration:%d, roc_t"
          "ype:%d, roc_state:%d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "p2p_find_roc_by_chan_freq",
          v16[0][2],
          v16[0],
          *((unsigned int *)v16[0] + 6),
          *((unsigned int *)v16[0] + 7),
          v16[0][4],
          v15,
          *((unsigned __int8 *)v16[0] + 44),
          *((_DWORD *)v16[0] + 12),
          *((_DWORD *)v16[0] + 13),
          *((_DWORD *)v16[0] + 56));
        result = v14;
        goto LABEL_7;
      }
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 8), v16[0], v16) );
    result = nullptr;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
