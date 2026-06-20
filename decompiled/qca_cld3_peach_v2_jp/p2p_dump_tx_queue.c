__int64 __fastcall p2p_dump_tx_queue(
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
  __int64 v10; // x5
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-48h]
  __int64 v29; // [xsp+18h] [xbp-38h]
  __int64 v30; // [xsp+20h] [xbp-30h]
  __int64 v31; // [xsp+28h] [xbp-28h]
  __int64 v32; // [xsp+30h] [xbp-20h]
  __int64 v33; // [xsp+38h] [xbp-18h]
  _QWORD *v34[2]; // [xsp+40h] [xbp-10h] BYREF

  v34[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned int *)(a1 + 48);
  v34[0] = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: dump tx queue wait for roc, p2p soc obj:%pK, size:%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_dump_tx_queue",
    a1,
    v10);
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 32), v34) )
  {
    do
    {
      LODWORD(v31) = *((unsigned __int8 *)v34[0] + 61);
      LODWORD(v33) = *((_DWORD *)v34[0] + 16);
      LODWORD(v32) = *((unsigned __int8 *)v34[0] + 62);
      LODWORD(v30) = *((unsigned __int8 *)v34[0] + 60);
      LODWORD(v29) = *((_DWORD *)v34[0] + 14);
      LODWORD(v28) = *((_DWORD *)v34[0] + 11);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: p2p soc object:%pK, tx ctx:%pK, vdev_id:%d, scan_id:%d, roc_cookie:%llx, freq:%d, buf:%pK, len:%d, off_chan:"
        "%d, cck:%d, ack:%d, duration:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_dump_tx_queue",
        a1,
        v34[0],
        *((unsigned int *)v34[0] + 6),
        *((unsigned int *)v34[0] + 7),
        v34[0][4],
        v28,
        v34[0][6],
        v29,
        v30,
        v31,
        v32,
        v33);
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 32), v34[0], v34) );
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: dump tx queue wait for ack, size:%d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "p2p_dump_tx_queue",
    *(unsigned int *)(a1 + 72));
  for ( result = qdf_list_peek_front((_QWORD *)(a1 + 56), v34);
        !(_DWORD)result;
        result = qdf_list_peek_next((_QWORD *)(a1 + 56), v34[0], v34) )
  {
    LODWORD(v31) = *((unsigned __int8 *)v34[0] + 61);
    LODWORD(v33) = *((_DWORD *)v34[0] + 16);
    LODWORD(v32) = *((unsigned __int8 *)v34[0] + 62);
    LODWORD(v30) = *((unsigned __int8 *)v34[0] + 60);
    LODWORD(v29) = *((_DWORD *)v34[0] + 14);
    LODWORD(v28) = *((_DWORD *)v34[0] + 11);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: p2p soc object:%pK, tx_ctx:%pK, vdev_id:%d, scan_id:%d, roc_cookie:%llx, freq:%d, buf:%pK, len:%d, off_chan:%d"
      ", cck:%d, ack:%d, duration:%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "p2p_dump_tx_queue",
      a1,
      v34[0],
      *((unsigned int *)v34[0] + 6),
      *((unsigned int *)v34[0] + 7),
      v34[0][4],
      v28,
      v34[0][6],
      v29,
      v30,
      v31,
      v32,
      v33);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
