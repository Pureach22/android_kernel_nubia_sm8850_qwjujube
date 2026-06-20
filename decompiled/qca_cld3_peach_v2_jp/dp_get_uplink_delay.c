__int64 __fastcall dp_get_uplink_delay(__int64 a1, unsigned __int8 a2, unsigned int *a3)
{
  __int64 ref_by_id_1; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  unsigned int *v16; // x8
  unsigned int v17; // w10
  unsigned int v18; // w9
  unsigned int v19; // w11
  int v20; // w11
  unsigned int v21; // w11
  unsigned int v22; // w12
  int v23; // w12
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // x20

  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 7u);
  if ( !ref_by_id_1 )
  {
    v34 = jiffies;
    if ( dp_get_uplink_delay___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: vdev %d does not exist",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_get_uplink_delay",
        a2);
      dp_get_uplink_delay___last_ticks = v34;
    }
    return 16;
  }
  v15 = ref_by_id_1;
  v16 = (unsigned int *)(ref_by_id_1 + 42732);
  if ( !*(_DWORD *)(ref_by_id_1 + 42744) )
  {
    dp_vdev_unref_delete(a1, ref_by_id_1, 7u, v16, v7, v8, v9, v10, v11, v12, v13, v14);
    return 16;
  }
  v17 = *v16;
  v18 = *(_DWORD *)(ref_by_id_1 + 42736);
  v19 = *(_DWORD *)(ref_by_id_1 + 45408);
  if ( v18 < v19 )
    v20 = ~v19;
  else
    v20 = -v19;
  v21 = v20 + v18;
  if ( v21 )
  {
    v22 = *(_DWORD *)(ref_by_id_1 + 45404);
    if ( v17 < v22 )
      v23 = ~v22;
    else
      v23 = -v22;
    v21 = (v23 + v17) / v21;
  }
  *a3 = v21;
  *(_DWORD *)(ref_by_id_1 + 45404) = v17;
  *(_DWORD *)(ref_by_id_1 + 45408) = v18;
  dp_print_tsf_tx_delay_hist((__int64 *)(ref_by_id_1 + 4648), 0);
  qdf_mem_set((void *)(v15 + 4648), 0x80u, 0);
  dp_vdev_unref_delete(a1, v15, 7u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
  return 0;
}
