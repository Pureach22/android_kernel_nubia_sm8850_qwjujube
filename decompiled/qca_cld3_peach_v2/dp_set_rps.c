__int64 __fastcall dp_set_rps(__int64 result, char a2)
{
  __int64 v2; // x23
  unsigned __int8 v3; // w19
  __int64 v5; // x20
  __int64 comp_private_obj; // x0
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21

  v2 = gp_dp_ctx;
  if ( gp_dp_ctx )
  {
    v3 = result;
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               *(_QWORD *)gp_dp_ctx,
               (unsigned int)result,
               97);
    if ( result )
    {
      v5 = result;
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 0x2Eu);
      if ( comp_private_obj )
      {
        v16 = *(_QWORD *)(comp_private_obj + 32);
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Set RPS to %d for vdev_id %d",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "dp_set_rps",
          a2 & 1,
          v3);
        v25 = (unsigned int *)*(unsigned __int8 *)(v2 + 368);
        if ( ((unsigned __int8)v25 & 1) == 0 )
        {
          if ( (a2 & 1) != 0 )
            ((void (__fastcall *)(__int64))dp_send_rps_ind)(v16);
          else
            v17 = ((double (__fastcall *)(__int64))dp_send_rps_disable_ind)(v16);
        }
        return wlan_objmgr_vdev_release_ref(v5, 0x61u, v25, v17, v18, v19, v20, v21, v22, v23, v24);
      }
      else
      {
        result = wlan_objmgr_vdev_release_ref(v5, 0x61u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
        v34 = jiffies;
        if ( dp_set_rps___last_ticks - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: DP link not found for vdev_id: %d",
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     v32,
                     v33,
                     "dp_set_rps",
                     v3);
          dp_set_rps___last_ticks = v34;
        }
      }
    }
  }
  return result;
}
