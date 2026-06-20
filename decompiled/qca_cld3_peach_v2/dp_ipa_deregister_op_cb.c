__int64 __fastcall dp_ipa_deregister_op_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  result = qdf_trace_msg(
             0x45u,
             8u,
             "%s: Deregister OP handler callback",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_ipa_deregister_op_cb");
  *(_QWORD *)(a1 + 18512) = 0;
  *(_QWORD *)(a1 + 18504) = 0;
  return result;
}
