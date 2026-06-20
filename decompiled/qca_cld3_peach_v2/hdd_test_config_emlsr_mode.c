__int64 __fastcall hdd_test_config_emlsr_mode(__int64 *a1, char a2)
{
  char is_hw_emlsr_capable; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0

  is_hw_emlsr_capable = policy_mgr_is_hw_emlsr_capable(*a1);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: eMLSR - Config : %d,  HW support : %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "hdd_test_config_emlsr_mode",
             a2 & 1,
             is_hw_emlsr_capable & 1);
  if ( (is_hw_emlsr_capable & 1) != 0 )
    return wlan_mlme_set_emlsr_mode_enabled(*a1, a2 & 1);
  return result;
}
