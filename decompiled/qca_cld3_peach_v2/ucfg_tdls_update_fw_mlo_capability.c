__int64 __fastcall ucfg_tdls_update_fw_mlo_capability(__int64 a1, char a2)
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
             "ucfg_tdls_update_fw_mlo_capability");
  *(_BYTE *)(result + 584) = a2 & 1;
  return result;
}
