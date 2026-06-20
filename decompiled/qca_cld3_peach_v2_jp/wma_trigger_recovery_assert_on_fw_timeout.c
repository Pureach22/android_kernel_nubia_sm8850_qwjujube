__int64 __fastcall wma_trigger_recovery_assert_on_fw_timeout(unsigned __int16 a1)
{
  const char *wma_msg_string; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  wma_msg_string = mac_trace_get_wma_msg_string(a1);
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: %s timed out, triggering recovery",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "wma_trigger_recovery_assert_on_fw_timeout",
    wma_msg_string);
  return _qdf_trigger_self_recovery();
}
