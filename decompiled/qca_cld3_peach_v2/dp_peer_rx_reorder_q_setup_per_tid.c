__int64 __fastcall dp_peer_rx_reorder_q_setup_per_tid(
        __int64 a1,
        unsigned int a2,
        __int16 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w20
  __int64 v13; // x19
  __int64 v17; // x25
  __int64 i; // x23
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x2
  unsigned int (__fastcall *v22)(__int64, __int64, __int64, __int64); // x10
  __int64 v23; // x1
  __int64 v24; // x9

  v12 = a2;
  v13 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL) + 8LL);
  if ( *(_QWORD *)(*(_QWORD *)(v13 + 8) + 8LL) )
  {
    v17 = 0;
    for ( i = 0; i != 17; ++i )
    {
      if ( ((1LL << i) & v12) != 0 )
      {
        v24 = *(_QWORD *)(a1 + 88);
        if ( *(_QWORD *)(v24 + v17 + 56) )
        {
          if ( (a4 & 1) != 0 )
          {
            if ( *(_DWORD *)(v24 + v17 + 68) == 1 )
              a3 = *(_WORD *)(v24 + v17 + 72);
            else
              a3 = 1;
          }
          v19 = *(_QWORD *)(a1 + 24);
          v20 = *(_QWORD *)(v13 + 16);
          v21 = *(unsigned __int8 *)(v19 + 59);
          v22 = *(unsigned int (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v13 + 8) + 8LL);
          v23 = **(unsigned __int8 **)(v19 + 24);
          if ( *((_DWORD *)v22 - 1) != 121683115 )
            __break(0x822Au);
          if ( v22(v20, v23, v21, a1 + 44) )
          {
            qdf_trace_msg(
              0x81u,
              2u,
              "%s: %pK: Fail to send reo q to FW. tid %d",
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              "dp_peer_rx_reorder_q_setup_per_tid",
              v13,
              (unsigned int)i,
              a3);
            return 16;
          }
        }
        else
        {
          v12 &= ~(unsigned int)(1LL << i);
        }
      }
      v17 += 144;
    }
    if ( v12 )
      return 0;
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: tid_bitmap=0. All tids setup fail",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_peer_rx_reorder_q_setup_per_tid");
    return 16;
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: rx_reorder_queue_setup NULL bitmap 0x%x",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_peer_rx_reorder_q_setup_per_tid",
      v13,
      a2);
    return 0;
  }
}
