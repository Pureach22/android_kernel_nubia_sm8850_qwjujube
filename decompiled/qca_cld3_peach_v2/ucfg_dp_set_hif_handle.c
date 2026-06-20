__int64 __fastcall ucfg_dp_set_hif_handle(__int64 a1, __int64 a2)
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

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DP context",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "ucfg_dp_set_hif_handle");
  *(_QWORD *)(result + 248) = a2;
  return result;
}
