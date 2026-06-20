__int64 __fastcall target_if_cfr_stop_lut_age_timer(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !result )
    return qdf_trace_msg(
             0x6Au,
             2u,
             "%s: pdev object for CFR is null",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "target_if_cfr_stop_lut_age_timer");
  if ( *(_BYTE *)(result + 1384) )
    return timer_delete((timer_t)(result + 1328));
  return result;
}
