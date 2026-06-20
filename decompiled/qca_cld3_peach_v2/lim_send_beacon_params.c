__int64 __fastcall lim_send_beacon_params(__int64 a1, unsigned __int16 *a2, __int64 a3)
{
  void *v6; // x0
  __int64 v7; // x21
  __int64 v8; // x4
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD v35[7]; // [xsp+8h] [xbp-38h] BYREF

  v35[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v35[2], 0, 32);
  v6 = (void *)_qdf_mem_malloc(0x1Cu, "lim_send_beacon_params", 65);
  if ( v6 )
  {
    v7 = (__int64)v6;
    qdf_mem_copy(v6, a2, 0x1Cu);
    v8 = a2[7];
    v35[0] = 4151;
    v35[1] = v7;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending WMA_UPDATE_BEACON_IND, paramChangeBitmap in hex: %x",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_send_beacon_params",
      v8);
    if ( a3 )
    {
      mac_trace_msg_tx(a1, *(unsigned __int8 *)(a3 + 8), 4151);
      *(_BYTE *)(v7 + 16) = *(_BYTE *)(a3 + 10);
      v17 = wma_post_ctrl_msg(a1, v35);
      if ( v17 )
      {
        _qdf_mem_free(v7);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Posting WMA_UPDATE_BEACON_IND, reason=%X",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "lim_send_beacon_params",
          v17);
      }
      lim_send_beacon_ind(a1, a3, 0, v18, v19, v20, v21, v22, v23, v24, v25);
    }
    else
    {
      _qdf_mem_free(v7);
      mac_trace_msg_tx(a1, 255, 4151);
      v17 = 16;
    }
  }
  else
  {
    v17 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
