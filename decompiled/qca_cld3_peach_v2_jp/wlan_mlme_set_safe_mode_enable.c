__int64 __fastcall wlan_mlme_set_safe_mode_enable(__int64 a1, char a2)
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

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( !result )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: invalid mlme obj",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wlan_mlme_set_safe_mode_enable");
  *(_BYTE *)(result + 1124) = a2 & 1;
  return result;
}
