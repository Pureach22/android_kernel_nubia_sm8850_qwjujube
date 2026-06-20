__int64 __fastcall hdd_init_channel_avoidance(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  __int64 v21; // x24
  __int64 v22; // x25

  cnss_utils_get_wlan_unsafe_channel(*(_QWORD *)(a1 + 96), a1 + 642, a1 + 640, 204);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: num of unsafe channels is %d",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "hdd_init_channel_avoidance",
             *(unsigned __int16 *)(a1 + 640));
  if ( *(unsigned __int16 *)(a1 + 640) >= 0x66u )
    v11 = 102;
  else
    v11 = *(unsigned __int16 *)(a1 + 640);
  if ( *(_WORD *)(a1 + 640) )
  {
    result = _qdf_mem_malloc(4 * (v11 & 0x3FFF), "hdd_init_channel_avoidance", 14796);
    if ( result )
    {
      v20 = result;
      v21 = 0;
      do
      {
        v22 = a1 + 2 * v21;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: channel frequency %d is not safe",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "hdd_init_channel_avoidance",
          *(unsigned __int16 *)(v22 + 642));
        *(_DWORD *)(v20 + 4 * v21++) = *(unsigned __int16 *)(v22 + 642);
      }
      while ( v11 != v21 );
      ucfg_policy_mgr_init_chan_avoidance(*(_QWORD *)a1, v20, v11);
      return _qdf_mem_free(v20);
    }
  }
  return result;
}
