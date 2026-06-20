__int64 __fastcall sme_config_su_ppdu_queue(
        unsigned __int8 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v11; // x2
  _QWORD *v12; // x20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD v22[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v23[3]; // [xsp+18h] [xbp-18h] BYREF

  v23[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0x100000045LL;
  v23[1] = 0x100000001LL;
  if ( (a2 & 1) != 0 )
    v11 = "%s: Send Tx SU PPDU queue ENABLE cmd to FW";
  else
    v11 = "%s: Send Tx SU PPDU queue DISABLE cmd to FW";
  v22[0] = 0x100000045LL;
  v22[1] = 1;
  if ( (a2 & 1) != 0 )
    v12 = v23;
  else
    v12 = v22;
  qdf_trace_msg(0x34u, 8u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "sme_config_su_ppdu_queue");
  result = wma_form_unit_test_cmd_and_send(a1, 72, 4, v12);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: send_unit_test_cmd returned %d",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "sme_config_su_ppdu_queue",
               (unsigned int)result);
  _ReadStatusReg(SP_EL0);
  return result;
}
