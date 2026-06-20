__int64 __fastcall wlan_ipa_msg_free_fn(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  qdf_trace_msg(0x61u, 8u, "%s: msg type:%d, len:%d", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_ipa_msg_free_fn", a3, a2);
  return _qdf_mem_free(a1);
}
