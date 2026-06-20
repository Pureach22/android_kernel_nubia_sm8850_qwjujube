__int64 __fastcall wlan_policy_mgr_get_ll_lt_sap_vdev_id(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x0
  unsigned __int8 v22[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v23; // [xsp+10h] [xbp-10h] BYREF
  char v24; // [xsp+14h] [xbp-Ch]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v23 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    if ( (unsigned __int8)policy_mgr_get_mode_specific_conn_info(a1, 0, (unsigned __int64)&v23, 6u) )
    {
      result = (unsigned __int8)v23;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        4u,
        "%s: Get ll lt sap vdev from vdev list, as its not yet added in connection table",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_policy_mgr_get_ll_lt_sap_vdev_id");
      v21 = *(_QWORD *)(v11 + 8);
      v22[0] = -1;
      wlan_objmgr_pdev_iterate_obj_list(
        v21,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))policy_mgr_is_vdev_active_ll_sap,
        (__int64)v22,
        0,
        0x18u);
      result = v22[0];
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_policy_mgr_get_ll_lt_sap_vdev_id");
    result = 255;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
