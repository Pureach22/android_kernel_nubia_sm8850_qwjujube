__int64 __fastcall lim_rx_invalid_peer_process(
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
  unsigned __int8 *v10; // x19
  __int64 session_by_vdev_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x22
  __int64 result; // x0
  __int64 v34; // x21
  __int16 v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 **)(a2 + 8);
  v35 = 0;
  if ( v10 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *v10);
    if ( session_by_vdev_id )
    {
      if ( *(_DWORD *)(session_by_vdev_id + 92) == 1 )
      {
        v22 = session_by_vdev_id;
        v23 = dph_lookup_hash_entry(v14, v15, v16, v17, v18, v19, v20, v21, a1, v10 + 7, &v35, session_by_vdev_id + 360);
        if ( v23 && *(_BYTE *)(v23 + 641) )
        {
          v32 = jiffies;
          if ( lim_rx_invalid_peer_process___last_ticks_15 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Received Invalid rx peer indication for an associated STA %02x:%02x:%02x:**:**:%02x",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "lim_rx_invalid_peer_process",
              v10[7],
              v10[8],
              v10[9],
              v10[12]);
            lim_rx_invalid_peer_process___last_ticks_15 = v32;
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: send deauth frame to non-assoc STA",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "lim_rx_invalid_peer_process");
          lim_send_deauth_mgmt_frame(a1, 7, v10 + 7, v22, 0);
        }
      }
      result = _qdf_mem_free((__int64)v10);
      *(_QWORD *)(a2 + 8) = 0;
    }
    else
    {
      v34 = jiffies;
      if ( lim_rx_invalid_peer_process___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: session not found for given sme session",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_rx_invalid_peer_process");
        lim_rx_invalid_peer_process___last_ticks = v34;
      }
      result = _qdf_mem_free((__int64)v10);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Invalid body pointer in message",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_rx_invalid_peer_process");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
