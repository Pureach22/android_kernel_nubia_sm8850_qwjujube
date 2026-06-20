__int64 __fastcall interop_issues_ap_psoc_obj_created_notification(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20

  v2 = _qdf_mem_malloc(0x28u, "interop_issues_ap_psoc_obj_created_notification", 43);
  if ( !v2 )
    return 2;
  v3 = v2;
  *(_DWORD *)v2 = 0;
  *(_QWORD *)(v2 + 8) = 0;
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 0x1Fu, v2, 0);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0x6Cu,
      2u,
      "%s: obj attach with psoc failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "interop_issues_ap_psoc_obj_created_notification");
    _qdf_mem_free(v3);
    return v13;
  }
  else
  {
    target_if_interop_issues_ap_register_tx_ops(a1, v3 + 32);
    return 0;
  }
}
