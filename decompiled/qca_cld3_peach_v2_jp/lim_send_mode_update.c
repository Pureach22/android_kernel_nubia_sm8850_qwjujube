__int64 __fastcall lim_send_mode_update(__int64 a1, const void *a2, __int64 a3)
{
  unsigned int *v6; // x0
  unsigned int *v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x1
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _QWORD v27[7]; // [xsp+8h] [xbp-38h] BYREF

  v27[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v27[2], 0, 32);
  v6 = (unsigned int *)_qdf_mem_malloc(0xCu, "lim_send_mode_update", 307);
  if ( v6 )
  {
    v7 = v6;
    qdf_mem_copy(v6, a2, 0xCu);
    v27[0] = 4263;
    v27[1] = v7;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending WMA_UPDATE_OP_MODE, op_mode chwidth %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_send_mode_update",
      *v7);
    if ( a3 )
      v16 = *(unsigned __int8 *)(a3 + 8);
    else
      v16 = 255;
    mac_trace_msg_tx(a1, v16, 4263);
    v17 = wma_post_ctrl_msg(a1, v27);
    if ( v17 )
    {
      _qdf_mem_free((__int64)v7);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting WMA_UPDATE_OP_MODE failed, reason=%X",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "lim_send_mode_update",
        v17);
    }
  }
  else
  {
    v17 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
