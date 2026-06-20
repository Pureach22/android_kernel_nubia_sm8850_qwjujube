__int64 __fastcall wlan_dcs_psoc_obj_create_notification(__int64 a1)
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

  v2 = _qdf_mem_malloc(0x4A8u, "wlan_dcs_psoc_obj_create_notification", 43);
  if ( !v2 )
    return 2;
  v3 = v2;
  *(_DWORD *)(v2 + 352) = 0;
  *(_QWORD *)(v2 + 360) = 0;
  *(_QWORD *)(v2 + 320) = &wlan_dcs_disable_timer_fn;
  *(_QWORD *)(v2 + 328) = v2 + 336;
  init_timer_key(v2 + 280, _os_timer_shim_9, 0, 0, 0);
  *(_DWORD *)(v3 + 736) = 0;
  *(_QWORD *)(v3 + 744) = 0;
  *(_QWORD *)(v3 + 704) = &wlan_dcs_disable_timer_fn;
  *(_QWORD *)(v3 + 712) = v3 + 720;
  init_timer_key(v3 + 664, _os_timer_shim_9, 0, 0, 0);
  *(_DWORD *)(v3 + 1120) = 0;
  *(_QWORD *)(v3 + 1128) = 0;
  *(_QWORD *)(v3 + 1088) = &wlan_dcs_disable_timer_fn;
  *(_QWORD *)(v3 + 1096) = v3 + 1104;
  init_timer_key(v3 + 1048, _os_timer_shim_9, 0, 0, 0);
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 0x24u, v3, 0);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: dcs pdev obj attach failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_dcs_psoc_obj_create_notification");
    _qdf_mem_free(v3);
    return v13;
  }
  else
  {
    qdf_trace_msg(
      0x74u,
      4u,
      "%s: dcs psoc object attached",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_dcs_psoc_obj_create_notification");
    return 0;
  }
}
