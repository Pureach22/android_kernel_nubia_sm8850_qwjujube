bool __fastcall policy_mgr_is_ap_start_in_progress(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _BOOL8 result; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 255;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    wlan_objmgr_pdev_iterate_obj_list(
      *(_QWORD *)(context + 8),
      2,
      (void (__fastcall *)(__int64, __int64, __int64))_policy_mgr_is_ap_start_in_progress,
      (__int64)&v11,
      0,
      0x18u);
    result = v11 != 255;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm context",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_is_ap_start_in_progress");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
