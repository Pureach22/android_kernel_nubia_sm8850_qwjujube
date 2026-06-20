__int64 __fastcall wlan_tdls_register_lim_callbacks(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
  if ( !result )
    return qdf_trace_msg(
             0,
             2u,
             "%s: Failed to get tdls psoc component",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wlan_tdls_register_lim_callbacks");
  *(_QWORD *)(result + 640) = *a2;
  return result;
}
