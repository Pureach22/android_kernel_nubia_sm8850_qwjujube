__int64 __fastcall tdls_psoc_obj_create_notification(__int64 a1)
{
  _QWORD *v2; // x0
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

  v2 = (_QWORD *)_qdf_mem_malloc(0x288u, "tdls_psoc_obj_create_notification", 132);
  if ( !v2 )
    return 2;
  v3 = (__int64)v2;
  *v2 = a1;
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 0xAu, (__int64)v2, 0);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to attach psoc tdls component",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tdls_psoc_obj_create_notification");
    _qdf_mem_free(v3);
    return v13;
  }
  else
  {
    tdls_soc_global = v3;
    qdf_trace_msg(
      0,
      4u,
      "%s: TDLS obj attach to psoc successfully",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tdls_psoc_obj_create_notification");
    return 0;
  }
}
