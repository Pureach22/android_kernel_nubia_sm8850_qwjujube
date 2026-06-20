__int64 __fastcall ipa_disable_register_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0

  result = qdf_trace_msg(
             0x61u,
             8u,
             "%s: Don't register ready cb with IPA driver",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "ipa_disable_register_cb");
  g_ipa_is_ready = 0;
  return result;
}
