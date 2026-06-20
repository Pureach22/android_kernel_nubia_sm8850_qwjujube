__int64 __fastcall lim_handle_param_update(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v21, 0, 48);
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: Handling CFG parameter id %X update",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_handle_param_update",
             a2);
  if ( a2 == 1 )
  {
    LOWORD(v21[0]) = 5059;
    result = lim_post_msg_api(a1, (unsigned __int16 *)v21);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed lim_post_msg_api %u",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "lim_handle_param_update",
                 (unsigned int)result);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
