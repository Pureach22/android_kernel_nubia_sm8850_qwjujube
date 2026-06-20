__int64 __fastcall dp_sysfs_initialize_stats(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  __int64 v20; // x8
  __int64 v21; // x8

  v2 = _qdf_mem_malloc(0xA8u, "dp_sysfs_initialize_stats", 12031);
  *(_QWORD *)(a1 + 17584) = v2;
  if ( v2 )
  {
    if ( (unsigned int)qdf_event_create((_DWORD *)(v2 + 96)) )
    {
      qdf_trace_msg(
        0x89u,
        2u,
        "%s: failed to create event sysfs_txrx_fw_request_done",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "dp_sysfs_initialize_stats");
      _qdf_mem_free(*(_QWORD *)(a1 + 17584));
      *(_QWORD *)(a1 + 17584) = 0;
      return 16;
    }
    else
    {
      v20 = *(_QWORD *)(a1 + 17584);
      *(_DWORD *)v20 = 0;
      *(_QWORD *)(v20 + 8) = 0;
      qdf_mutex_create(*(_QWORD *)(a1 + 17584) + 16LL);
      v21 = *(_QWORD *)(a1 + 17584);
      v19 = 0;
      *(_DWORD *)(v21 + 80) = 0;
      *(_QWORD *)(v21 + 88) = 0;
    }
  }
  else
  {
    v19 = 2;
    qdf_trace_msg(
      0x89u,
      2u,
      "%s: failed to allocate memory for sysfs_config no memory",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_sysfs_initialize_stats");
  }
  return v19;
}
