__int64 __fastcall wlan_twt_reset_requestor_enable_cmd_in_progress(__int64 a1)
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

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( !result )
    return qdf_trace_msg(
             0x96u,
             2u,
             "%s: null twt psoc priv obj",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wlan_twt_reset_requestor_enable_cmd_in_progress");
  *(_DWORD *)(result + 84) = 0;
  return result;
}
