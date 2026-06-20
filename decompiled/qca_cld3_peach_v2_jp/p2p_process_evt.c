__int64 __fastcall p2p_process_evt(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  const char *v11; // x5
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 *v20; // x0
  unsigned int v21; // w4
  unsigned int v22; // w0
  unsigned int v23; // w20
  void (__fastcall *v24)(_QWORD); // x8
  __int64 v25; // x0

  v9 = *a1;
  if ( (unsigned int)v9 > 6 )
    v11 = "Invalid P2P event";
  else
    v11 = off_9FDC20[*a1];
  qdf_trace_msg(0x4Eu, 8u, "%s: msg type %d, %s", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_process_evt", v9, v11);
  v20 = *((unsigned __int8 **)a1 + 1);
  if ( v20 )
  {
    v21 = *a1;
    if ( v21 > 3 )
    {
      switch ( v21 )
      {
        case 4u:
          v22 = p2p_process_noa();
          goto LABEL_25;
        case 5u:
          v22 = p2p_process_set_rand_mac_rsp();
          goto LABEL_25;
        case 6u:
          if ( *(_QWORD *)v20 )
          {
            v24 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v20 + 192LL);
            if ( v24 )
            {
              v25 = v20[8];
              if ( *((_DWORD *)v24 - 1) != -1560483463 )
                __break(0x8228u);
              v24(v25);
              v23 = 0;
            }
            else
            {
              v23 = 0;
            }
            goto LABEL_26;
          }
          goto LABEL_22;
      }
    }
    else
    {
      switch ( v21 )
      {
        case 1u:
          v22 = p2p_process_mgmt_tx_ack_cnf();
          goto LABEL_25;
        case 2u:
          v22 = p2p_process_rx_mgmt();
          goto LABEL_25;
        case 3u:
          v22 = p2p_process_lo_stop();
LABEL_25:
          v23 = v22;
          goto LABEL_26;
      }
    }
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Drop unexpected message received %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_process_evt");
LABEL_22:
    v23 = 4;
LABEL_26:
    _qdf_mem_free(*((_QWORD *)a1 + 1));
    *((_QWORD *)a1 + 1) = 0;
    return v23;
  }
  qdf_trace_msg(0x4Eu, 2u, "%s: Invalid message body", v12, v13, v14, v15, v16, v17, v18, v19, "p2p_process_evt");
  return 4;
}
