__int64 __fastcall wlan_twt_set_requestor_enable_cmd_in_progress(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v11; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    if ( *(_DWORD *)(comp_private_obj + 84) )
    {
      qdf_trace_msg(0x96u, 8u, "Previous TWT requestor enable is in progress", v2, v3, v4, v5, v6, v7, v8, v9);
      return 6;
    }
    else
    {
      v11 = comp_private_obj;
      *(_DWORD *)(v11 + 84) = 1;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
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
      "wlan_twt_set_requestor_enable_cmd_in_progress");
    return 4;
  }
}
