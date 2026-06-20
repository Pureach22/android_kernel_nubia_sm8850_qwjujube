__int64 __fastcall wlan_cp_stats_get_rx_clear_count(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 v4; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  __int64 v16; // x19
  unsigned int macid_by_vdev_id; // w21
  const char *v18; // x2
  unsigned int v19; // w1
  __int64 v20; // x4
  unsigned int v21; // w21
  const char *v22; // x2
  __int64 comp_private_obj; // x0
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x9
  _DWORD *v27; // x8
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w1

  v4 = a2;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 38);
  if ( v6 )
  {
    v15 = *(_QWORD *)(v6 + 152);
    v16 = v6;
    if ( v15 )
    {
      macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(a1, v4);
      if ( macid_by_vdev_id >= 2 )
      {
        v18 = "%s: invalid mac_id %d";
        v19 = 2;
        v20 = macid_by_vdev_id;
LABEL_13:
        qdf_trace_msg(0x62u, v19, v18, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_cp_stats_get_rx_clear_count", v20);
LABEL_17:
        v21 = 0;
LABEL_18:
        wlan_objmgr_vdev_release_ref(v16, 0x26u, v28, v29, v30, v31, v32, v33, v34, v35, v36);
        return v21;
      }
      comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v15, 0x1Bu);
      if ( comp_private_obj )
      {
        v24 = *(_QWORD *)(comp_private_obj + 8);
        v25 = v24 + 12672LL * macid_by_vdev_id;
        if ( !*(_BYTE *)(v25 + 20) )
        {
LABEL_12:
          v18 = "%s: no channel found for freq:%d";
          v19 = 8;
          v20 = a3;
          goto LABEL_13;
        }
        v26 = *(unsigned __int8 *)(v25 + 20);
        v27 = (_DWORD *)(v24 + 12672LL * macid_by_vdev_id + 36);
        while ( *(v27 - 3) != a3 )
        {
          --v26;
          v27 += 31;
          if ( !v26 )
            goto LABEL_12;
        }
        if ( *v27 )
        {
          v21 = (unsigned int)(255 * *(v27 - 1)) / *v27;
          qdf_trace_msg(
            0x62u,
            8u,
            "%s: t_chan:%d, freq:%d, rcc:%u, cc:%u, chan_load:%d",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "wlan_cp_stats_get_rx_clear_count",
            (unsigned __int8)v21);
          goto LABEL_18;
        }
        v22 = "%s: cycle_count is zero";
        v37 = 8;
LABEL_16:
        qdf_trace_msg(0x62u, v37, v22, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_cp_stats_get_rx_clear_count");
        goto LABEL_17;
      }
      v22 = "%s: pdev cp stats object is null";
    }
    else
    {
      v22 = "%s: pdev object is null";
    }
    v37 = 2;
    goto LABEL_16;
  }
  return 0;
}
