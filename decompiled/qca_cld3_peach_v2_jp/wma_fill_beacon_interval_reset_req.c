__int64 __fastcall wma_fill_beacon_interval_reset_req(__int64 a1, unsigned __int8 a2, __int16 a3, unsigned int a4)
{
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 v17; // x22
  unsigned int multiplier; // w21

  v7 = _qdf_mem_malloc(0x40u, "wma_fill_beacon_interval_reset_req", 6862);
  if ( !v7 )
    return 4294967284LL;
  v16 = v7;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id %d ",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "wma_fill_beacon_interval_reset_req",
    a2);
  *(_BYTE *)(v16 + 56) = a2;
  *(_WORD *)(v16 + 58) = a3;
  *(_QWORD *)(v16 + 40) = wma_vdev_reset_beacon_interval_timer;
  *(_QWORD *)(v16 + 48) = v16;
  init_timer_key(v16, _os_timer_shim_7, 0x80000, 0, 0);
  v17 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  *(_QWORD *)(v16 + 16) = v17 + _msecs_to_jiffies(a4) * multiplier;
  add_timer(v16);
  return 0;
}
