__int64 __fastcall policy_mgr_get_user_config_sap_freq(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  double sap_user_config_freq; // d0
  unsigned int v13; // w0
  unsigned int v14; // w19
  unsigned int *v15; // x8
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v2 )
  {
    v11 = v2;
    sap_user_config_freq = wlan_get_sap_user_config_freq();
    v14 = v13;
    wlan_objmgr_vdev_release_ref(v11, 0x18u, v15, sap_user_config_freq, v16, v17, v18, v19, v20, v21, v22);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: vdev is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_get_user_config_sap_freq");
    return 0;
  }
  return v14;
}
