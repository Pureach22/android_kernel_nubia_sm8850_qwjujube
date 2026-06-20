__int64 __fastcall p2p_process_cmd(
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
  void (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x2
  __int64 v26; // x1
  __int64 v27; // x0
  unsigned int v28; // w19
  unsigned __int8 *v29; // x8

  v9 = *a1;
  if ( (unsigned int)v9 > 7 )
    v11 = "Invalid P2P command";
  else
    v11 = off_9FDBE0[*a1];
  qdf_trace_msg(0x4Eu, 8u, "%s: msg type %d, %s", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_process_cmd", v9, v11);
  v20 = *((unsigned __int8 **)a1 + 1);
  if ( !v20 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: Invalid message body", v12, v13, v14, v15, v16, v17, v18, v19, "p2p_process_cmd");
    return 4;
  }
  v21 = *a1;
  if ( v21 <= 3 )
  {
    if ( *a1 <= 1u )
    {
      if ( !*a1 )
        return p2p_process_roc_req();
      v22 = p2p_process_cancel_roc_req();
      goto LABEL_30;
    }
    if ( v21 == 2 )
      return p2p_process_mgmt_tx();
    if ( v21 == 3 )
    {
      v22 = p2p_process_mgmt_tx_cancel();
      goto LABEL_30;
    }
    goto LABEL_32;
  }
  if ( *a1 > 5u )
  {
    if ( v21 == 6 )
    {
      v22 = p2p_process_set_rand_mac();
      goto LABEL_30;
    }
    if ( v21 == 7 )
    {
      if ( *(_QWORD *)v20 )
      {
        v24 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v20 + 200LL);
        if ( v24 )
        {
          v25 = v20[10];
          v26 = v20[9];
          v27 = v20[8];
          if ( *((_DWORD *)v24 - 1) != -1255532124 )
            __break(0x8228u);
          v24(v27, v26, v25);
          v20 = *((unsigned __int8 **)a1 + 1);
        }
        v28 = 0;
      }
      else
      {
        v28 = 4;
      }
      goto LABEL_31;
    }
LABEL_32:
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: drop unexpected message received %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_process_cmd");
    return 4;
  }
  if ( v21 == 4 )
  {
    v22 = p2p_process_cleanup_roc_queue();
    goto LABEL_30;
  }
  if ( v21 != 5 )
    goto LABEL_32;
  v22 = p2p_process_cleanup_tx_queue();
LABEL_30:
  v29 = *((unsigned __int8 **)a1 + 1);
  v28 = v22;
  v20 = v29;
LABEL_31:
  _qdf_mem_free((__int64)v20);
  return v28;
}
