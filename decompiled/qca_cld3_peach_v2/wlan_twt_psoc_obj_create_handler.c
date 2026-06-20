__int64 __fastcall wlan_twt_psoc_obj_create_handler(__int64 a1)
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v2 = _qdf_mem_malloc(0x60u, "wlan_twt_psoc_obj_create_handler", 34);
  if ( !v2 )
    return 2;
  v3 = v2;
  *(_QWORD *)(v2 + 56) = 0;
  *(_QWORD *)(v2 + 72) = 0;
  *(_DWORD *)(v2 + 80) = 0;
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 0x2Cu, v2, 0);
  if ( v4 )
  {
    v13 = v4;
    _qdf_mem_free(v3);
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: Failed to attach twt psoc priv object",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_twt_psoc_obj_create_handler");
    return v13;
  }
  else
  {
    *(_DWORD *)(v3 + 84) = 0;
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: twt psoc priv obj attach successful",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_twt_psoc_obj_create_handler");
    return 0;
  }
}
