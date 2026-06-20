__int64 __fastcall cm_bss_peer_create_rsp(__int64 a1, int a2, unsigned __int8 *a3)
{
  __int64 *cm_ctx_fl; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  __int64 *v16; // x20
  __int64 v17; // x0
  __int64 v18; // x22
  char v19; // w8
  unsigned int v20; // w21
  unsigned int v21; // w22
  __int64 result; // x0
  __int64 v23; // x0
  __int64 v24; // x21
  char v25; // w8
  unsigned int v26; // w19
  unsigned int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  cm_ctx_fl = (__int64 *)cm_get_cm_ctx_fl(a1, "cm_bss_peer_create_rsp", 3421);
  if ( !cm_ctx_fl )
  {
    result = 4;
    goto LABEL_15;
  }
  v16 = cm_ctx_fl;
  v27 = *((_DWORD *)cm_ctx_fl + 22);
  v15 = v27;
  if ( (v27 & 0xF000000) != 0xC000000 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: active req is not connect req",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_bss_peer_create_rsp",
      *(unsigned __int8 *)(*cm_ctx_fl + 168),
      v27);
    mlme_cm_bss_peer_delete_req(a1);
    result = 4;
    goto LABEL_15;
  }
  if ( !a2 )
  {
    if ( !(unsigned int)cm_bss_peer_create_resp_mlo_attach(a1, a3, v7, v8, v9, v10, v11, v12, v13, v14) )
    {
      result = cm_sm_deliver_event(a1, 10, 4, &v27);
      if ( (_DWORD)result )
      {
        v26 = result;
        mlme_cm_force_bss_peer_delete_req(a1);
        result = v26;
      }
      goto LABEL_15;
    }
    mlme_cm_bss_peer_delete_req(a1);
  }
  v17 = _qdf_mem_malloc(0x150u, "cm_bss_peer_create_rsp", 3455);
  if ( v17 )
  {
    *(_DWORD *)(v17 + 4) = v27;
    *(_DWORD *)(v17 + 52) = 16;
    v18 = v17;
    v19 = *(_BYTE *)(*v16 + 168);
    *(_DWORD *)(v17 + 56) = 4;
    *(_BYTE *)v17 = v19;
    cm_fill_bss_info_in_connect_rsp_by_cm_id(v16, v15, v17);
    v20 = cm_sm_deliver_event(a1, 11, 336, v18);
    _qdf_mem_free(v18);
    v21 = v20;
    if ( !v20 )
    {
      result = 0;
      goto LABEL_15;
    }
  }
  else
  {
    v21 = 2;
  }
  v23 = _qdf_mem_malloc(0x150u, "cm_connect_handle_event_post_fail", 304);
  if ( v23 )
  {
    *(_DWORD *)(v23 + 4) = v15;
    *(_DWORD *)(v23 + 52) = 16;
    v24 = v23;
    v25 = *(_BYTE *)(*v16 + 168);
    *(_DWORD *)(v23 + 56) = 2;
    *(_BYTE *)v23 = v25;
    cm_fill_bss_info_in_connect_rsp_by_cm_id(v16, v15, v23);
    cm_connect_complete(v16, v24);
    _qdf_mem_free(v24);
  }
  result = v21;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
