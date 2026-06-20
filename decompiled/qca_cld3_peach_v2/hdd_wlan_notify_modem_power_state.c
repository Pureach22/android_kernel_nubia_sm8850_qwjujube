__int64 __fastcall hdd_wlan_notify_modem_power_state(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  context = _cds_get_context(51, (__int64)"hdd_wlan_notify_modem_power_state", a2, a3, a4, a5, a6, a7, a8, a9);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_wlan_notify_modem_power_state",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18);
  if ( !(_DWORD)result )
  {
    v20 = context[2];
    if ( v20 )
    {
      result = sme_notify_modem_power_state(v20, a1);
      if ( !(_DWORD)result )
        return result;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Fail to send notification with modem power state %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "hdd_wlan_notify_modem_power_state",
        a1);
    }
    return 4294967274LL;
  }
  return result;
}
