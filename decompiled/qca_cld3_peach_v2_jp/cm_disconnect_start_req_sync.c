__int64 __fastcall cm_disconnect_start_req_sync(__int64 a1, __int64 *a2)
{
  unsigned int v2; // w19
  __int64 cm_ctx_fl; // x0
  __int64 v6; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  __int64 v16; // x9
  __int64 v17; // x10
  int v18; // w8
  __int64 v19; // x21
  unsigned int v20; // w0
  unsigned int v21; // w20
  const char *v22; // x2

  v2 = *(unsigned __int8 *)(a1 + 104);
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_disconnect_start_req_sync", 867);
  if ( cm_ctx_fl )
  {
    v6 = cm_ctx_fl;
    qdf_event_reset(cm_ctx_fl + 208);
    if ( cm_get_cm_ctx_fl(a1, "cm_disconnect_start_req", 829) )
    {
      v15 = _qdf_mem_malloc(0x380u, "cm_disconnect_start_req", 837);
      if ( v15 )
      {
        v17 = *a2;
        v16 = a2[1];
        v18 = *((_DWORD *)a2 + 4);
        v19 = v15;
        *(_DWORD *)(v15 + 44) = v18;
        *(_QWORD *)(v15 + 36) = v16;
        *(_QWORD *)(v15 + 28) = v17;
        v20 = cm_sm_deliver_event(a1, 13, 24, v15 + 24);
        if ( !v20 )
        {
          v21 = qdf_wait_single_event(v6 + 208, 0x7D00u);
          if ( !v21 )
            return v21;
          v22 = "%s: vdev %d: Disconnect timeout with status %d";
          goto LABEL_10;
        }
        v21 = v20;
        _qdf_mem_free(v19);
      }
      else
      {
        v21 = 2;
      }
    }
    else
    {
      v21 = 4;
    }
    v22 = "%s: vdev %d: Disconnect failed with status %d";
LABEL_10:
    qdf_trace_msg(0x68u, 2u, v22, v7, v8, v9, v10, v11, v12, v13, v14, "cm_disconnect_start_req_sync", v2, v21);
    return v21;
  }
  return 4;
}
