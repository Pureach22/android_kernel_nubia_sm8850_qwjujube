__int64 __fastcall wlan_serialization_generic_timer_cb(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v11; // x8
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double (__fastcall *v29)(unsigned int *, __int64); // x8
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x4Cu,
             2u,
             "%s: cmd_info not found",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_serialization_generic_timer_cb");
  v9 = *((_QWORD *)a1 + 4);
  if ( v9 )
  {
    v11 = *(_QWORD *)(v9 + 152);
    if ( v11 && (v12 = *(_QWORD *)(v11 + 80)) != 0 )
    {
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: Active cmd timeout for cmd_type[%d] vdev[%d] cmd_id[%d]",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_serialization_generic_timer_cb",
        *a1,
        *(unsigned __int8 *)(v9 + 104),
        a1[1]);
      if ( (wlan_serialization_is_cmd_present_in_active_queue(v13, v14, v15, v16, v17, v18, v19, v20, v12, a1) & 1) != 0 )
      {
        v29 = *((double (__fastcall **)(unsigned int *, __int64))a1 + 1);
        if ( v29 )
        {
          if ( *((_DWORD *)v29 - 1) != -1491618541 )
            __break(0x8228u);
          v21 = v29(a1, 3);
        }
        wlan_serialization_dequeue_cmd(a1, 3u, 1u, v21, v22, v23, v24, v25, v26, v27, v28);
      }
      else
      {
        qdf_trace_msg(
          0x4Cu,
          2u,
          "%s: cmd_type %d vdev %d not in active queue",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "wlan_serialization_generic_timer_cb",
          *a1,
          *(unsigned __int8 *)(v9 + 104));
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: Psoc is NULL",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_serialization_generic_timer_cb");
    }
    wlan_objmgr_vdev_release_ref(*((_QWORD *)a1 + 4), 9u, v30, v31, v32, v33, v34, v35, v36, v37, v38);
  }
  else
  {
    qdf_trace_msg(0x4Cu, 2u, "%s: Invalid vdev", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_generic_timer_cb");
  }
  return _qdf_mem_free((__int64)a1);
}
