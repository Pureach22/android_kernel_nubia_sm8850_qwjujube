__int64 __fastcall sme_set_he_tx_bf_cbf_rates(unsigned __int8 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD v20[3]; // [xsp+8h] [xbp-48h] BYREF
  int v21; // [xsp+20h] [xbp-30h]
  _QWORD v22[3]; // [xsp+28h] [xbp-28h] BYREF
  int v23; // [xsp+40h] [xbp-10h]
  __int64 v24; // [xsp+48h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v22[1] = 0x300000000LL;
  v22[2] = 0x400000002LL;
  v21 = 0;
  v22[0] = 0x10000005BLL;
  v20[1] = 0x300000001LL;
  v20[2] = 0x300000001LL;
  v20[0] = 0x10000005BLL;
  v2 = wma_form_unit_test_cmd_and_send(a1, 72, 7, v22);
  if ( v2 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: send_unit_test_cmd returned %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "sme_set_he_tx_bf_cbf_rates",
      v2);
  result = wma_form_unit_test_cmd_and_send(a1, 72, 7, v20);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: send_unit_test_cmd returned %d",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "sme_set_he_tx_bf_cbf_rates",
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
