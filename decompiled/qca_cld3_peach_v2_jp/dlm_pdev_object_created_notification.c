__int64 __fastcall dlm_pdev_object_created_notification(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x19
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
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v2 = _qdf_mem_malloc(0x60u, "dlm_pdev_object_created_notification", 63);
  if ( !v2 )
    return 16;
  v3 = (_QWORD *)v2;
  v4 = qdf_mutex_create(v2);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: Failed to create mutex",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "dlm_pdev_object_created_notification");
  }
  else
  {
    v3[8] = v3 + 8;
    v3[9] = v3 + 8;
    v3[10] = 0x1600000000LL;
    v15 = target_if_dlm_register_tx_ops(v3 + 11);
    result = wlan_objmgr_pdev_component_obj_attach(a1, 0x20u, (__int64)v3, 0, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( !(_DWORD)result )
      return result;
    v13 = result;
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: Failed to attach pdev_ctx with pdev",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "dlm_pdev_object_created_notification");
    if ( *((_DWORD *)v3 + 20) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "qdf_list_destroy");
    qdf_mutex_destroy((__int64)v3);
  }
  _qdf_mem_free((__int64)v3);
  return v13;
}
