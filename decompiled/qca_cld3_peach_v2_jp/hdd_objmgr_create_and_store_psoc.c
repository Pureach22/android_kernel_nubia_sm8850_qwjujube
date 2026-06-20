__int64 __fastcall hdd_objmgr_create_and_store_psoc(__int64 *a1, unsigned __int8 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  unsigned int ref; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *context; // x0

  v3 = wlan_objmgr_psoc_obj_create(a2, 1);
  if ( !v3 )
    return 4294967284LL;
  v12 = v3;
  ref = wlan_objmgr_psoc_try_get_ref(v3, 5u, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( ref )
  {
    v22 = ref;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to acquire psoc ref; status:%d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_objmgr_create_and_store_psoc",
      ref);
    wlan_objmgr_psoc_obj_delete(v12, v23, v24, v25, v26, v27, v28, v29, v30);
    return qdf_status_to_os_return(v22);
  }
  else
  {
    context = _cds_get_context(64, (__int64)"hdd_init_psoc_qdf_ctx", v14, v15, v16, v17, v18, v19, v20, v21);
    if ( context )
      *(_QWORD *)(v12 + 2120) = context;
    *a1 = v12;
    return 0;
  }
}
