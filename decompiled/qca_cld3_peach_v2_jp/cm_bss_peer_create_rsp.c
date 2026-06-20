__int64 __fastcall cm_bss_peer_create_rsp(__int64 a1, int a2)
{
  __int64 *cm_ctx_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  __int64 *v14; // x22
  __int64 v15; // x0
  __int64 v16; // x21
  char v17; // w9
  unsigned int v18; // w20
  unsigned int v19; // w23
  __int64 result; // x0
  unsigned int v21; // w19
  __int64 v22; // x0
  __int64 v23; // x21
  char v24; // w8
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  cm_ctx_fl = (__int64 *)cm_get_cm_ctx_fl(a1, "cm_bss_peer_create_rsp", 3421);
  if ( !cm_ctx_fl )
  {
    result = 4;
    goto LABEL_15;
  }
  v25 = *((_DWORD *)cm_ctx_fl + 22);
  v13 = v25;
  if ( (v25 & 0xF000000) != 0xC000000 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: active req is not connect req",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_bss_peer_create_rsp",
      *(unsigned __int8 *)(*cm_ctx_fl + 104),
      v25);
    mlme_cm_bss_peer_delete_req(a1);
    result = 4;
    goto LABEL_15;
  }
  if ( a2 )
  {
    v14 = cm_ctx_fl;
    v15 = _qdf_mem_malloc(0xA0u, "cm_bss_peer_create_rsp", 3455);
    if ( v15 )
    {
      *(_DWORD *)(v15 + 4) = v25;
      *(_DWORD *)(v15 + 52) = 16;
      v16 = v15;
      v17 = *(_BYTE *)(*v14 + 104);
      *(_DWORD *)(v15 + 56) = 4;
      *(_BYTE *)v15 = v17;
      cm_fill_bss_info_in_connect_rsp_by_cm_id(v14, v13, v15);
      v18 = cm_sm_deliver_event(a1, 11, 160, v16);
      _qdf_mem_free(v16);
      v19 = v18;
      if ( !v18 )
      {
        result = 0;
        goto LABEL_15;
      }
    }
    else
    {
      v19 = 2;
    }
    v22 = _qdf_mem_malloc(0xA0u, "cm_connect_handle_event_post_fail", 304);
    if ( v22 )
    {
      *(_DWORD *)(v22 + 4) = v13;
      *(_DWORD *)(v22 + 52) = 16;
      v23 = v22;
      v24 = *(_BYTE *)(*v14 + 104);
      *(_DWORD *)(v22 + 56) = 2;
      *(_BYTE *)v22 = v24;
      cm_fill_bss_info_in_connect_rsp_by_cm_id(v14, v13, v22);
      cm_connect_complete(v14, v23);
      _qdf_mem_free(v23);
    }
    result = v19;
  }
  else
  {
    result = cm_sm_deliver_event(a1, 10, 4, &v25);
    if ( (_DWORD)result )
    {
      v21 = result;
      mlme_cm_force_bss_peer_delete_req(a1);
      result = v21;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
