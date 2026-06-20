__int64 __fastcall wlan_hdd_resume_pmo_twt(__int64 *a1)
{
  char pmo_allowed; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0

  pmo_allowed = ucfg_twt_get_pmo_allowed(*a1);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: twt_disabled_allowed %d ",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "wlan_hdd_is_twt_pmo_allowed",
             pmo_allowed & 1);
  if ( (pmo_allowed & 1) != 0 )
    return queue_work_on(32, system_wq, a1 + 880);
  return result;
}
