__int64 __fastcall cm_ser_connect_cb(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x22
  __int64 cm_ctx_fl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x19
  __int64 result; // x0
  unsigned int v24; // w20
  __int64 v25; // x21
  char v26; // w8
  int v27; // w22
  __int64 v28; // x21
  char v29; // w8
  double v30; // d0
  unsigned int *v31; // x8
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w22
  unsigned int v40; // w20
  __int64 v41; // x0
  __int64 v42; // x21
  char v43; // w8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: cmd is NULL, reason: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_ser_connect_cb",
      (unsigned int)a2);
    return 29;
  }
  v11 = *(_QWORD *)(a1 + 32);
  cm_ctx_fl = cm_get_cm_ctx_fl(v11, "cm_ser_connect_cb", 190);
  if ( !cm_ctx_fl )
    return 29;
  v22 = (__int64 *)cm_ctx_fl;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v30 = cm_reset_active_cm_id(v11, *(unsigned int *)(a1 + 4));
      wlan_objmgr_vdev_release_ref(v11, 0x4Du, v31, v30, v32, v33, v34, v35, v36, v37, v38);
      return 0;
    }
    else
    {
      if ( a2 != 3 )
        return 4;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: Active command timeout",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "cm_ser_connect_cb",
        *(unsigned __int8 *)(v11 + 168),
        *(unsigned int *)(a1 + 4));
      cm_trigger_panic_on_cmd_timeout(*v22, 38);
      v24 = *(_DWORD *)(a1 + 4);
      result = _qdf_mem_malloc(0x150u, "cm_connect_cmd_timeout", 73);
      if ( result )
      {
        *(_DWORD *)(result + 4) = v24;
        *(_DWORD *)(result + 52) = 16;
        v25 = result;
        v26 = *(_BYTE *)(*v22 + 168);
        *(_DWORD *)(result + 56) = 13;
        *(_BYTE *)result = v26;
        cm_fill_bss_info_in_connect_rsp_by_cm_id(v22, v24, result);
        v27 = cm_sm_deliver_event(*v22, 12, 336, v25);
        _qdf_mem_free(v25);
        if ( !v27 )
          return 0;
        result = _qdf_mem_malloc(0x150u, "cm_connect_handle_event_post_fail", 304);
        if ( result )
        {
          *(_DWORD *)(result + 4) = v24;
          *(_DWORD *)(result + 52) = 16;
          v28 = result;
          v29 = *(_BYTE *)(*v22 + 168);
          *(_DWORD *)(result + 56) = 2;
          *(_BYTE *)result = v29;
          cm_fill_bss_info_in_connect_rsp_by_cm_id(v22, v24, result);
          cm_connect_complete(v22, v28);
          _qdf_mem_free(v28);
          return 0;
        }
      }
    }
  }
  else
  {
    if ( a2 )
    {
      if ( a2 == 1 )
        return 0;
      return 4;
    }
    if ( (*(_BYTE *)(a1 + 20) & 0x38) == 0x28 )
      result = cm_sm_deliver_event(*(_QWORD *)(a1 + 32), 7, 4, a1 + 4);
    else
      result = wlan_sm_dispatch(*(_QWORD *)(cm_ctx_fl + 72), 7u, 4u, a1 + 4, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( (_DWORD)result )
    {
      v39 = result;
      v40 = *(_DWORD *)(a1 + 4);
      v41 = _qdf_mem_malloc(0x150u, "cm_connect_handle_event_post_fail", 304);
      if ( v41 )
      {
        *(_DWORD *)(v41 + 4) = v40;
        *(_DWORD *)(v41 + 52) = 16;
        v42 = v41;
        v43 = *(_BYTE *)(*v22 + 168);
        *(_DWORD *)(v41 + 56) = 2;
        *(_BYTE *)v41 = v43;
        cm_fill_bss_info_in_connect_rsp_by_cm_id(v22, v40, v41);
        cm_connect_complete(v22, v42);
        _qdf_mem_free(v42);
      }
      return v39;
    }
  }
  return result;
}
