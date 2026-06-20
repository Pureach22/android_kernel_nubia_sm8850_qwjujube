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
  __int64 v28; // x9
  __int64 v29; // x6
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  const char *v39; // x3
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // [xsp+8h] [xbp-48h]
  __int64 v49; // [xsp+18h] [xbp-38h]

  if ( a2 > 0x18 )
    return result;
  v49 = v11;
  v12 = result;
  v13 = result + 196;
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
        qdf_mem_set(v13, 0x30u, 0);
        if ( *((_DWORD *)v12 + 377) )
        {
          v27 = ktime_get_with_offset(1);
          v28 = *(_QWORD *)((char *)v12 + 1516);
          v29 = *(_QWORD *)((char *)v12 + 1500);
          *(_QWORD *)((char *)v12 + 1596) = *(_QWORD *)((char *)v12 + 1508);
          *(_QWORD *)((char *)v12 + 1604) = v28;
          *(_QWORD *)((char *)v12 + 1588) = v29;
          v12[196] = v27 / 1000;
          return (_QWORD *)qdf_trace_msg(
                             0x39u,
                             8u,
                             "%s: ap start(CAC) (%d, %d) bw %d",
                             v30,
                             v31,
                             v32,
                             v33,
                             v34,
                             v35,
                             v36,
                             v37,
                             "sap_update_cac_history");
        }
        v38 = "%s: invalid seq0";
        v39 = "sap_update_cac_history";
        return (_QWORD *)qdf_trace_msg(0x39u, 8u, v38, a3, a4, a5, a6, a7, a8, a9, a10, v39);
      }
      v38 = "%s: Couldn't get vdev active channel";
    }
    else
    {
      v38 = "%s: vdev invalid";
    }
    v39 = "sap_operating_on_dfs";
    return (_QWORD *)qdf_trace_msg(0x39u, 8u, v38, a3, a4, a5, a6, a7, a8, a9, a10, v39);
  }
  if ( ((1 << a2) & 0x10002) == 0 )
  {
    if ( a2 != 17 )
      return result;
    return qdf_mem_set(v13, 0x30u, 0);
  }
  if ( !*v13 )
    return result;
  v15 = ktime_get_with_offset(1);
  v24 = v15 / 1000 - v12[196];
  v12[197] = v15 / 1000;
  v25 = v24 / 0x3E8;
  if ( v24 > 0x3473BBF )
  {
    *((_BYTE *)v12 + 1584) = 1;
    qdf_mem_copy(&prev_cac_history, v13, 0x30u);
    result = (_QWORD *)qdf_trace_msg(
                         0x39u,
                         8u,
                         "%s: ap cac saved %llu ms %llu (%d, %d) bw %d",
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         "sap_update_cac_history",
                         v25,
                         v12[197],
                         *((unsigned int *)v12 + 399),
                         *((unsigned int *)v12 + 400),
                         *((_DWORD *)v12 + 397),
                         v48,
                         v10,
                         v49);
    if ( a2 != 1 )
      return result;
    return qdf_mem_set(v13, 0x30u, 0);
  }
  if ( a2 == 1 )
    qdf_mem_set(v13, 0x30u, 0);
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
