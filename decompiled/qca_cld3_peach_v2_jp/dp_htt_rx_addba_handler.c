__int64 __fastcall dp_htt_rx_addba_handler(__int64 a1, unsigned __int16 a2, unsigned int a3, unsigned int a4)
{
  __int64 ref_by_id_0; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  unsigned __int16 v18; // w24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  ref_by_id_0 = dp_peer_get_ref_by_id_0();
  if ( !ref_by_id_0 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Peer not found peer id %d",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             "dp_htt_rx_addba_handler",
             a2);
  v17 = ref_by_id_0;
  v18 = dp_addba_requestprocess_wifi3(
          a1,
          ref_by_id_0 + 44,
          *(unsigned __int8 *)(*(_QWORD *)(ref_by_id_0 + 24) + 59LL),
          0,
          (unsigned __int8)a3,
          0,
          a4,
          0xFFFF);
  dp_addba_resp_tx_completion_wifi3(a1, v17 + 44, *(unsigned __int8 *)(*(_QWORD *)(v17 + 24) + 59LL), a3, v18);
  dp_peer_unref_delete(v17, 13);
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: PeerID %d BAW %d TID %d stat %d",
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           "dp_htt_rx_addba_handler",
           a2,
           (unsigned __int16)a4,
           (unsigned __int8)a3,
           v18);
}
