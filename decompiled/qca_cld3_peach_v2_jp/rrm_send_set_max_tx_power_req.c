__int64 __fastcall rrm_send_set_max_tx_power_req(
        __int64 a1,
        char a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _BYTE *v14; // x0
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  _QWORD v34[7]; // [xsp+8h] [xbp-38h] BYREF

  v34[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v34[2], 0, 32);
  if ( a3 )
  {
    v14 = (_BYTE *)_qdf_mem_malloc(0x14u, "rrm_send_set_max_tx_power_req", 122);
    if ( v14 )
    {
      v15 = (__int64)v14;
      v14[12] = a2;
      qdf_mem_copy(v14, a3 + 24, 6u);
      qdf_mem_copy((void *)(v15 + 6), a3 + 30, 6u);
      v34[0] = 4226;
      v34[1] = v15;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Sending WMA_SET_MAX_TX_POWER_REQ with power(%d) to HAL",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "rrm_send_set_max_tx_power_req",
        (unsigned int)a2);
      mac_trace_msg_tx(a1, a3[8], 4226);
      result = wma_post_ctrl_msg(a1, v34);
      if ( (_DWORD)result )
      {
        v33 = result;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Posting WMA_SET_MAX_TX_POWER_REQ to HAL failed, reason=%X",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "rrm_send_set_max_tx_power_req",
          (unsigned int)result);
        _qdf_mem_free(v15);
        result = v33;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid parameters",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "rrm_send_set_max_tx_power_req");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
