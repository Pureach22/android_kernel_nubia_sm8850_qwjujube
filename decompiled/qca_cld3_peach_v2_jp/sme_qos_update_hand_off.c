__int64 __fastcall sme_qos_update_hand_off(
        __int64 result,
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
  __int64 v10; // x20
  char v11; // w19
  __int64 v12; // x4

  v10 = qword_856120 + 3040LL * (unsigned __int8)result;
  v11 = a2 & 1;
  v12 = *(unsigned __int8 *)(v10 + 2940);
  if ( (_DWORD)v12 != (a2 & 1) )
    result = qdf_trace_msg(
               0x34u,
               8u,
               "%s: handoffRequested %d updateHandOff %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "sme_qos_update_hand_off",
               v12,
               a2 & 1);
  *(_BYTE *)(v10 + 2940) = v11;
  return result;
}
