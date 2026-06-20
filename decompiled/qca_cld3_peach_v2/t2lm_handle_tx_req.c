__int64 __fastcall t2lm_handle_tx_req(
        __int64 a1,
        __int64 a2,
        const void *a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v13; // w4
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  __int64 result; // x0
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  __int64 v27; // [xsp+8h] [xbp-18h]
  __int64 v28; // [xsp+10h] [xbp-10h]
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v27 = 0;
    v28 = 0;
    v26 = 0;
    if ( a3 )
    {
      v13 = *a4;
      LOBYTE(v26) = 37;
      HIDWORD(v26) = v13;
      v15 = lim_send_t2lm_action_req_frame(a1, (unsigned __int8 *)(a2 + 48), (__int16 *)&v26, (__int64)a3);
      if ( v15 )
      {
        v24 = v15;
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: Failed to send T2LM action request frame",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "t2lm_handle_tx_req");
        result = v24;
      }
      else
      {
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Copy the ongoing neg to peer",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "t2lm_handle_tx_req");
        qdf_mem_copy((void *)(*(_QWORD *)(a2 + 784) + 376LL), a3, 0xACu);
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: Null event data ptr",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "t2lm_handle_tx_req",
        v26,
        v27,
        v28,
        v29);
      result = 29;
    }
  }
  else
  {
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
