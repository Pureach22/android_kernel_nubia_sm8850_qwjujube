__int64 __fastcall lim_send_set_max_tx_power_req(
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
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  if ( a3 )
  {
    v14 = (_BYTE *)_qdf_mem_malloc(0x14u, "lim_send_set_max_tx_power_req", 9190);
    if ( v14 )
    {
      v15 = (__int64)v14;
      v14[12] = a2;
      qdf_mem_copy(v14, a3 + 24, 6u);
      qdf_mem_copy((void *)(v15 + 6), a3 + 30, 6u);
      v35 = v15;
      LOWORD(v34) = 4226;
      HIDWORD(v34) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Post WMA_SET_MAX_TX_POWER_REQ to WMA",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "lim_send_set_max_tx_power_req");
      mac_trace_msg_tx(a1, a3[8], 4226);
      result = wma_post_ctrl_msg(a1, &v34);
      if ( (_DWORD)result )
      {
        v33 = result;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: wma_post_ctrl_msg() failed",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "lim_send_set_max_tx_power_req");
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
      "lim_send_set_max_tx_power_req");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
