__int64 __fastcall lim_post_mlm_message(__int64 a1, unsigned __int16 a2, __int64 a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[1] = a3;
  v13[0] = a2;
  memset(&v13[2], 0, 32);
  mac_trace_msg_rx(a1, 255, a2);
  result = lim_process_mlm_req_messages(a1, (unsigned __int16 *)v13, v4, v5, v6, v7, v8, v9, v10, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
