__int64 __fastcall sme_process_channel_change_resp(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  unsigned int v14; // w20
  __int64 v15; // x22
  const char *v16; // x2
  unsigned int v17; // w21

  v4 = _qdf_mem_malloc(0x180u, "sme_process_channel_change_resp", 8994);
  if ( !v4 )
    return 2;
  *(_QWORD *)(v4 + 128) = a2;
  v13 = a2[8];
  v14 = *a2;
  v15 = v4;
  if ( v13 )
    v16 = "%s: sapdfs: Received failure for vdev %d";
  else
    v16 = "%s: sapdfs: Received success for vdev %d";
  if ( v13 )
    v17 = 16;
  else
    v17 = 15;
  qdf_trace_msg(0x34u, 8u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "sme_process_channel_change_resp", v14);
  csr_roam_call_callback(a1, v14, v15, 39, v17);
  _qdf_mem_free(v15);
  return 0;
}
