__int64 __fastcall ucfg_dp_get_disable_rx_ol_val(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DP context",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "ucfg_dp_get_disable_rx_ol_val");
  *a2 = *(_DWORD *)(result + 1128);
  *a3 = *(_DWORD *)(result + 1132);
  return result;
}
