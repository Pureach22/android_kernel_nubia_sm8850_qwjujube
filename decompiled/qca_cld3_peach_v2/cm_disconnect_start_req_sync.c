__int64 __fastcall cm_disconnect_start_req_sync(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 cm_ctx_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  unsigned int v15; // w23
  unsigned int started; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  const char *v26; // x2

  v2 = *(unsigned __int8 *)(a1 + 168);
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_disconnect_start_req_sync", 867);
  if ( cm_ctx_fl )
  {
    v14 = cm_ctx_fl;
    if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v6, v7, v8, v9, v10, v11, v12, v13) & 1) == 0 || (*(_BYTE *)(a1 + 60) & 2) != 0 )
    {
      v15 = 32000;
    }
    else
    {
      v15 = 48000;
      *(_BYTE *)(a2 + 18) = 1;
    }
    qdf_event_reset(v14 + 208);
    started = cm_disconnect_start_req(a1, (__int64 *)a2);
    if ( started )
    {
      v25 = started;
      v26 = "%s: vdev %d: Disconnect failed with status %d";
LABEL_11:
      qdf_trace_msg(0x68u, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "cm_disconnect_start_req_sync", v2, v25);
      return v25;
    }
    v25 = qdf_wait_single_event(v14 + 208, v15);
    if ( v25 )
    {
      v26 = "%s: vdev %d: Disconnect timeout with status %d";
      goto LABEL_11;
    }
  }
  else
  {
    return 4;
  }
  return v25;
}
