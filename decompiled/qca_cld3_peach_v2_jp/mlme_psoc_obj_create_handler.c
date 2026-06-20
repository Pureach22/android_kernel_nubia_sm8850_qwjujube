__int64 __fastcall mlme_psoc_obj_create_handler(__int64 a1)
{
  _QWORD *v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  const char *v22; // x2

  v2 = (_QWORD *)_qdf_mem_malloc(0x7E8u, "mlme_psoc_obj_create_handler", 54);
  if ( v2 )
  {
    v11 = (__int64)v2;
    *v2 = a1;
    v12 = mlme_psoc_ops_ext_hdl_create();
    if ( v12 )
    {
      v21 = v12;
      v22 = "%s: Failed to allocate psoc ext handle";
LABEL_7:
      qdf_trace_msg(0x68u, 2u, v22, v13, v14, v15, v16, v17, v18, v19, v20, "mlme_psoc_obj_create_handler");
      _qdf_mem_free(v11);
      return v21;
    }
    v21 = wlan_objmgr_psoc_component_obj_attach(a1, 0, v11, 0);
    if ( v21 )
    {
      v22 = "%s: Failed to attach psoc_ctx with psoc";
      goto LABEL_7;
    }
  }
  else
  {
    v21 = 2;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to allocate PSOS mlme Object",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "mlme_psoc_obj_create_handler");
  }
  return v21;
}
