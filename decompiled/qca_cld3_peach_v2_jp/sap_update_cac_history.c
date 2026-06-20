_QWORD *__fastcall sap_update_cac_history(
        _QWORD *result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  _QWORD *v12; // x19
  _QWORD *v13; // x20
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x4
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  const char *v38; // x3
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // [xsp+8h] [xbp-48h]
  __int64 v48; // [xsp+18h] [xbp-38h]

  if ( a2 > 0x18 )
    return result;
  v48 = v11;
  v12 = result;
  v13 = result + 195;
  if ( ((1 << a2) & 0x1004001) != 0 )
  {
    v26 = result[2];
    if ( v26 )
    {
      result = (_QWORD *)wlan_vdev_get_active_channel(v26);
      if ( result )
      {
        if ( (*((_WORD *)result + 3) & 6) == 0 )
          return result;
        qdf_mem_set(v13, 0x28u, 0);
        if ( *((_DWORD *)v12 + 377) )
        {
          v27 = ktime_get_with_offset(1);
          v28 = *(_QWORD *)((char *)v12 + 1508);
          *(_QWORD *)((char *)v12 + 1580) = *(_QWORD *)((char *)v12 + 1500);
          *(_QWORD *)((char *)v12 + 1588) = v28;
          v12[195] = v27 / 1000;
          return (_QWORD *)qdf_trace_msg(
                             0x39u,
                             8u,
                             "%s: ap start(CAC) (%d, %d) bw %d",
                             v29,
                             v30,
                             v31,
                             v32,
                             v33,
                             v34,
                             v35,
                             v36,
                             "sap_update_cac_history");
        }
        v37 = "%s: invalid seq0";
        v38 = "sap_update_cac_history";
        return (_QWORD *)qdf_trace_msg(0x39u, 8u, v37, a3, a4, a5, a6, a7, a8, a9, a10, v38);
      }
      v37 = "%s: Couldn't get vdev active channel";
    }
    else
    {
      v37 = "%s: vdev invalid";
    }
    v38 = "sap_operating_on_dfs";
    return (_QWORD *)qdf_trace_msg(0x39u, 8u, v37, a3, a4, a5, a6, a7, a8, a9, a10, v38);
  }
  if ( ((1 << a2) & 0x10002) == 0 )
  {
    if ( a2 != 17 )
      return result;
    return qdf_mem_set(v13, 0x28u, 0);
  }
  if ( !*v13 )
    return result;
  v15 = ktime_get_with_offset(1);
  v24 = v15 / 1000 - v12[195];
  v12[196] = v15 / 1000;
  v25 = v24 / 0x3E8;
  if ( v24 > 0x3473BBF )
  {
    *((_BYTE *)v12 + 1576) = 1;
    qdf_mem_copy(&prev_cac_history, v13, 0x28u);
    result = (_QWORD *)qdf_trace_msg(
                         0x39u,
                         8u,
                         "%s: ap cac saved %llu ms %llu (%d, %d) bw %d",
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         "sap_update_cac_history",
                         v25,
                         v12[196],
                         *((unsigned int *)v12 + 397),
                         *((unsigned int *)v12 + 398),
                         *((_DWORD *)v12 + 395),
                         v47,
                         v10,
                         v48);
    if ( a2 != 1 )
      return result;
    return qdf_mem_set(v13, 0x28u, 0);
  }
  if ( a2 == 1 )
    qdf_mem_set(v13, 0x28u, 0);
  return (_QWORD *)qdf_trace_msg(
                     0x39u,
                     8u,
                     "%s: ap cac dur %llu ms",
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     "sap_update_cac_history",
                     v25);
}
