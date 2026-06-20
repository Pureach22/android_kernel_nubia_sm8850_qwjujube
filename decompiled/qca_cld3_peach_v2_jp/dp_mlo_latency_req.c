__int64 __fastcall dp_mlo_latency_req(__int64 a1, unsigned __int8 a2)
{
  __int64 ref_by_id_1; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 0xDu);
  if ( !ref_by_id_1 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable find vdev for id: %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "dp_mlo_latency_req",
             a2);
  v13 = ref_by_id_1;
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable find peer for vdev: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "dp_mlo_latency_req",
    a2);
  return dp_vdev_unref_delete(a1, v13, 0xDu, v14, v15, v16, v17, v18, v19, v20, v21, v22);
}
