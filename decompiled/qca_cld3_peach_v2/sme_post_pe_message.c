__int64 __fastcall sme_post_pe_message(__int64 a1, unsigned __int16 *a2)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = scheduler_post_message_debug(0x34u, 0x35u, 53, a2, 0x383u, (__int64)"sme_post_pe_message");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: scheduler_post_msg failed with status: %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "sme_post_pe_message",
      (unsigned int)result);
    return 16;
  }
  return result;
}
