__int64 __fastcall lim_mgmt_t2lm_req_tx_complete(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v8; // x23
  unsigned int v9; // w24
  int v10; // w8
  __int64 session_by_vdev_id; // x0
  __int64 v12; // x25
  unsigned int v13; // w0
  __int64 v14; // x7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w8
  __int64 v24; // x3
  unsigned int v25; // w20
  _QWORD v27[66]; // [xsp+0h] [xbp-210h] BYREF

  v27[65] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v27, 0, 0x208u);
  if ( a4 )
  {
    v8 = *(_QWORD *)(a2 + 224);
    v9 = (*(_BYTE *)(v8 + 1) & 0x40) != 0 ? 32 : 24;
    v10 = (*(_BYTE *)(a2 + 68) & 4) != 0 ? *(unsigned __int16 *)(a2 + 66) : 0;
    if ( *(_DWORD *)(a2 + 112) + v10 >= (v9 | 2) )
    {
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a4 + 10));
      if ( session_by_vdev_id )
      {
        if ( !*(_DWORD *)(session_by_vdev_id + 7036) )
        {
          v12 = session_by_vdev_id;
          v13 = dot11f_unpack_t2lm_neg_req(a1, v8 + v9, 520, v27, 0);
          if ( (v13 & 0x10000000) == 0 )
          {
            if ( a3 == 1 )
              v23 = 2;
            else
              v23 = 3;
            if ( a3 )
              v24 = v23;
            else
              v24 = 1;
            wlan_connectivity_t2lm_req_resp_event(
              *(_QWORD *)(v12 + 16),
              BYTE2(v27[0]),
              0,
              v24,
              *(unsigned __int8 *)(a4 + 58),
              0,
              45,
              v14,
              v27[0],
              v27[1]);
            v25 = 0;
            goto LABEL_21;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to unpack T2LM negotiation request (0x%08x)",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "lim_mgmt_t2lm_req_tx_complete",
            v13);
        }
      }
    }
  }
  v25 = 16;
LABEL_21:
  if ( a2 )
    _qdf_nbuf_free(a2);
  _ReadStatusReg(SP_EL0);
  return v25;
}
