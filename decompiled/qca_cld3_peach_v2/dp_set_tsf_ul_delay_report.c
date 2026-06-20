__int64 __fastcall dp_set_tsf_ul_delay_report(__int64 a1, unsigned __int8 a2, char a3)
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
  __int64 v16; // x24
  int v17; // w8
  __int64 v18; // x20
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 7u);
  if ( ref_by_id_1 )
  {
    v15 = ref_by_id_1;
    v16 = ref_by_id_1 + 40960;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: vdev: %u enable: %u",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_set_tsf_ul_delay_report",
      a2,
      a3 & 1);
    raw_spin_lock(v15 + 43536);
    *(_BYTE *)(v16 + 2604) = a3 & 1;
    if ( (a3 & 1) != 0 )
    {
      v17 = 1;
    }
    else
    {
      if ( (*(_BYTE *)(v16 + 2605) & 1) != 0 || (*(_BYTE *)(v16 + 2606) & 1) != 0 )
        goto LABEL_10;
      v17 = 0;
    }
    *(_DWORD *)(v16 + 2592) = v17;
LABEL_10:
    raw_spin_unlock(v15 + 43536);
    *(_DWORD *)(v16 + 2608) = a3 & 1;
    dp_vdev_unref_delete(a1, v15, 7u, v20, v21, v22, v23, v24, v25, v26, v27, v28);
    return 0;
  }
  v18 = jiffies;
  if ( dp_set_tsf_ul_delay_report___last_ticks - jiffies + 125 < 0 )
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
      "dp_set_tsf_ul_delay_report",
      a2);
    dp_set_tsf_ul_delay_report___last_ticks = v18;
  }
  return 16;
}
