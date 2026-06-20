__int64 dp_allocate_ctx()
{
  __int64 v0; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20

  v0 = _qdf_mem_malloc(0xBD0u, "dp_allocate_ctx", 80);
  if ( v0 )
  {
    *(_DWORD *)(v0 + 264) = 0;
    v9 = v0;
    *(_QWORD *)(v0 + 272) = 0;
    *(_DWORD *)(v0 + 1536) = 0;
    *(_QWORD *)(v0 + 1544) = 0;
    *(_QWORD *)(v0 + 280) = v0 + 280;
    *(_QWORD *)(v0 + 288) = v0 + 280;
    *(_QWORD *)(v0 + 296) = 0;
    *(_QWORD *)(v0 + 1520) = 0;
    *(_QWORD *)(v0 + 1528) = v0 + 1520;
    wlan_dp_spm_flow_table_attach();
    *(_DWORD *)(v9 + 3008) = 0;
    if ( gp_dp_ctx )
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: already attached global dp ctx",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "dp_attach_ctx");
    v18 = 0;
    gp_dp_ctx = v9;
  }
  else
  {
    v18 = 2;
    qdf_trace_msg(0x45u, 2u, "%s: Failed to create DP context", v1, v2, v3, v4, v5, v6, v7, v8, "dp_allocate_ctx");
  }
  return v18;
}
