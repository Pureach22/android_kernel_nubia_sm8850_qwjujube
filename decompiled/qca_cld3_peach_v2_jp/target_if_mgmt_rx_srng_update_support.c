__int64 __fastcall target_if_mgmt_rx_srng_update_support(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x21
  int v15; // w22
  const char *v16; // x2
  unsigned int v17; // w1

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x35u);
  if ( !comp_private_obj )
  {
    v16 = "%s: mgmt rx srng psoc priv is NULL";
    goto LABEL_9;
  }
  if ( !a1 || (v13 = *(_QWORD *)(a1 + 2800)) == 0 )
  {
    v16 = "%s: target_psoc_info is null in mgmt_rx_srng";
LABEL_9:
    v17 = 2;
    return qdf_trace_msg(0x49u, v17, v16, v5, v6, v7, v8, v9, v10, v11, v12, "target_if_mgmt_rx_srng_update_support");
  }
  v14 = comp_private_obj;
  v15 = *(unsigned __int8 *)(comp_private_obj + 8);
  if ( (wmi_service_enabled(a2, 0x13Cu, v5, v6, v7, v8, v9, v10, v11, v12) & 1) != 0 && v15 )
  {
    v16 = "%s: mgmt_rx_srng_support is enabled";
    *(_BYTE *)(v14 + 8) = 1;
    *(_BYTE *)(v13 + 440) = 1;
  }
  else
  {
    v16 = "%s: mgmt_rx_srng_support is not enabled";
    *(_BYTE *)(v14 + 8) = 0;
  }
  v17 = 8;
  return qdf_trace_msg(0x49u, v17, v16, v5, v6, v7, v8, v9, v10, v11, v12, "target_if_mgmt_rx_srng_update_support");
}
