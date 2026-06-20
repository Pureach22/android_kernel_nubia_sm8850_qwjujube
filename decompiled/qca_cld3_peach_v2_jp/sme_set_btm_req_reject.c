__int64 __fastcall sme_set_btm_req_reject(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19

  result = cm_roam_send_disable_config(*(_QWORD *)(a1 + 21552), a2, 8 * (a3 != 0));
  if ( (_DWORD)result )
  {
    v12 = result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Unable to send BTM request reject config",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "sme_set_btm_req_reject");
    return v12;
  }
  return result;
}
