__int64 __fastcall pe_drop_pending_rx_mgmt_frames(__int64 a1, _WORD *a2, __int64 a3)
{
  unsigned int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w5
  unsigned __int64 v26; // t2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w4
  unsigned __int64 v36; // t2

  raw_spin_lock(a1 + 12816);
  v6 = *(_DWORD *)(a1 + 12796);
  if ( v6 < 0xC8 )
  {
    if ( v6 >= 0x65 && (v16 = (unsigned __int8)*a2 >> 4, v16 <= 8) && ((1 << v16) & 0x130) != 0 )
    {
      raw_spin_unlock(a1 + 12816);
      v25 = *(_DWORD *)(a1 + 21656);
      HIDWORD(v26) = -1030792151 * v25;
      LODWORD(v26) = -1030792151 * v25;
      if ( (unsigned int)(v26 >> 2) <= 0x28F5C28 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: No.of pending RX mgmt frames reaches 1/2 thresh, dropping frame subtype: %d rx_packet_drop_counter: %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "pe_drop_pending_rx_mgmt_frames",
          (unsigned __int8)*a2 >> 4);
        v25 = *(_DWORD *)(a1 + 21656);
      }
      *(_DWORD *)(a1 + 21656) = v25 + 1;
      cds_pkt_return_packet(a3);
      return 16;
    }
    else
    {
      *(_DWORD *)(a1 + 12796) = v6 + 1;
      raw_spin_unlock(a1 + 12816);
      if ( *(_DWORD *)(a1 + 12796) == 50 )
      {
        v35 = *(_DWORD *)(a1 + 21656);
        HIDWORD(v36) = -1030792151 * v35;
        LODWORD(v36) = -1030792151 * v35;
        if ( (unsigned int)(v36 >> 2) <= 0x28F5C28 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: No.of pending RX management frames reaches to 1/4th of threshold, rx_packet_drop_counter: %d",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "pe_drop_pending_rx_mgmt_frames");
          v35 = *(_DWORD *)(a1 + 21656);
        }
        *(_DWORD *)(a1 + 21656) = v35 + 1;
        return 0;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    raw_spin_unlock(a1 + 12816);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: No.of pending RX management frames reaches to threshold, dropping management frames",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "pe_drop_pending_rx_mgmt_frames");
    cds_pkt_return_packet(a3);
    ++*(_DWORD *)(a1 + 21656);
    return 16;
  }
}
