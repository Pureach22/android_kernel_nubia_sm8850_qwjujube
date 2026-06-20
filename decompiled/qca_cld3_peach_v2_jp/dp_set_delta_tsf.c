__int64 __fastcall dp_set_delta_tsf(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4
  __int64 v16; // x19
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x21

  result = dp_vdev_get_ref_by_id_1(a1, a2, 7u);
  if ( result )
  {
    *(_DWORD *)(result + 42704) = a3;
    v15 = a2;
    v16 = result;
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: vdev id %u delta_tsf %u",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_set_delta_tsf",
      v15,
      a3);
    return dp_vdev_unref_delete(a1, v16, 7u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  else
  {
    v26 = jiffies;
    if ( dp_set_delta_tsf___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
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
                 "dp_set_delta_tsf",
                 a2);
      dp_set_delta_tsf___last_ticks = v26;
    }
  }
  return result;
}
