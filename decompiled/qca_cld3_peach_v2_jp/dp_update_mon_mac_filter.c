__int64 __fastcall dp_update_mon_mac_filter(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 ref_by_id_4; // x0
  unsigned int *v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x20
  unsigned int v17; // w21

  ref_by_id_4 = dp_vdev_get_ref_by_id_4(a1, a2);
  if ( ref_by_id_4 )
  {
    v15 = *(_QWORD *)(ref_by_id_4 + 24);
    v16 = ref_by_id_4;
    if ( !v15 )
      goto LABEL_8;
    if ( a3 == 2 )
    {
      dp_mon_filter_set_reset_mon_mac_filter(*(_QWORD *)(ref_by_id_4 + 24), 0);
      v17 = dp_mon_filter_update(v15);
      if ( v17 )
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: Mon mac filter reset failed",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "dp_update_mon_mac_filter",
          a1);
      goto LABEL_9;
    }
    if ( a3 == 1 )
    {
      dp_mon_filter_set_reset_mon_mac_filter(*(_QWORD *)(ref_by_id_4 + 24), 1);
      v17 = dp_mon_filter_update(v15);
      if ( v17 )
      {
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: Mon mac filter set failed",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "dp_update_mon_mac_filter",
          a1);
        dp_mon_filter_set_reset_mon_mac_filter(v15, 0);
      }
    }
    else
    {
LABEL_8:
      v17 = 16;
    }
LABEL_9:
    dp_vdev_unref_delete(a1, v16, 7u, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    return v17;
  }
  return 16;
}
