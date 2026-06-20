__int64 *__fastcall dp_tx_send_ipa_data_frame(__int64 a1, unsigned __int8 a2, __int64 *a3)
{
  __int64 *result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x19

  *a3 = 0;
  result = dp_tx_send(a1, a2, a3);
  if ( result )
  {
    v12 = result;
    qdf_trace_msg(0x3Fu, 2u, "%s: Failed to tx", v4, v5, v6, v7, v8, v9, v10, v11, "dp_tx_send_ipa_data_frame");
    return v12;
  }
  return result;
}
