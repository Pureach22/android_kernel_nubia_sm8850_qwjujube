void __fastcall lim_process_sme_update_session_edca_txq_params(
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
  __int64 session_by_vdev_id; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  unsigned __int64 v22; // x22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x4
  __int64 v32; // x2
  __int64 v33; // x8
  char v34; // w9
  int v35; // w10

  if ( a2 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
    if ( session_by_vdev_id )
    {
      v21 = session_by_vdev_id;
      v22 = ((unsigned __int64)*(unsigned __int8 *)(a2 + 5) >> 5) & 3;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: received SME Session tx queue update for vdev %d queue %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_process_sme_update_session_edca_txq_params",
        *(unsigned __int8 *)(a2 + 4),
        v22);
      v31 = *(unsigned int *)(v21 + 80);
      if ( *(_DWORD *)(v21 + 88) == 1 && (_DWORD)v31 == 16 )
      {
        v32 = *(unsigned __int8 *)(v21 + 10);
        v33 = v21 + 7096 + (v22 | (4 * v22));
        v34 = *(_BYTE *)(a2 + 6);
        *(_BYTE *)(v33 + 1) = *(_BYTE *)(v33 + 1) & 0xF0 | v34 & 0xF;
        *(_BYTE *)(v33 + 1) = *(_BYTE *)(a2 + 6) & 0xF0 | v34 & 0xF;
        v35 = *(_BYTE *)v33 & 0x9F | (32 * ((*(unsigned __int8 *)(a2 + 5) >> 5) & 3));
        *(_BYTE *)v33 = v35;
        *(_BYTE *)v33 = v35 & 0xF0 | *(_BYTE *)(a2 + 5) & 0xF;
        *(_WORD *)(v33 + 2) = *(_WORD *)(a2 + 7);
        lim_send_edca_params(a1, v21 + 7096, v32, 0);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Rcvd edca update req in state %X, in role %X",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lim_process_sme_update_session_edca_txq_params",
          v31);
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Session does not exist for given vdev_id %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_process_sme_update_session_edca_txq_params",
        *(unsigned __int8 *)(a2 + 4));
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Buffer is Pointing to NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_sme_update_session_edca_txq_params");
  }
}
