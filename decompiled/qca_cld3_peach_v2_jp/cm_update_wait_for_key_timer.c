__int64 __fastcall cm_update_wait_for_key_timer(__int64 a1, unsigned int a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v6 = cm_csr_set_ss_wait_for_key(a2);
  result = cm_start_wait_for_key_timer(a1, a3, v6, v7, v8, v9, v10, v11, v12, v13);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed wait for key timer start",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_update_wait_for_key_timer");
    return cm_csr_set_ss_none(a2);
  }
  return result;
}
