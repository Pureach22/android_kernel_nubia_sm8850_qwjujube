__int64 __fastcall dp_try_set_rps_cpu_mask(__int64 a1)
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

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
    return qdf_trace_msg(0x45u, 2u, "%s: dp context is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "dp_try_set_rps_cpu_mask");
  if ( *(_BYTE *)(result + 369) == 1 )
    return dp_set_rps_cpu_mask(result);
  return result;
}
