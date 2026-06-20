__int64 __fastcall hdd_init_station_mode(__int64 *a1)
{
  __int64 v2; // x21
  __int64 *v3; // x23
  __int64 v4; // x22
  __int64 vdev_by_user; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x20
  __int64 v16; // x0
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int roaming_triggers; // w0
  unsigned __int64 v52; // x9
  char v53[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v3 = *(__int64 **)(*a1 + 24);
  v4 = v3[2];
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 36, "hdd_init_station_mode");
  if ( vdev_by_user )
  {
    v14 = *(_QWORD *)(vdev_by_user + 152);
    v15 = vdev_by_user;
    v53[0] = 0;
    if ( v14 )
      v16 = *(_QWORD *)(v14 + 80);
    else
      v16 = 0;
    if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(v16, v53) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to get vht_enable2x2",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "hdd_vdev_set_ht_vht_ies");
    sme_set_pdev_ht_vht_ies(v4, v53[0] != 0);
    sme_set_vdev_ies_per_band(v4, *(unsigned __int8 *)(v15 + 104), *(unsigned int *)(v15 + 16));
    v26 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*a1 + 24) + 104LL) + 60LL);
    *((_DWORD *)a1 + 167) = 1;
    *((_DWORD *)a1 + 173) = v26;
    hdd_roam_profile_init(a1, v27, v28, v29, v30, v31, v32, v33, v34);
    v35 = hdd_wmm_adapter_init(v2);
    if ( v35 )
    {
      v17 = v35;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_wmm_adapter_init() failed, status code %08d [x%08x]",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_init_station_mode",
        v17,
        v17);
    }
    else
    {
      _X8 = (unsigned __int64 *)(v2 + 1624);
      __asm { PRFM            #0x11, [X8] }
      do
        v52 = __ldxr(_X8);
      while ( __stxr(v52 | 2, _X8) );
      qdf_mem_set((void *)(v2 + 52196), 0xCu, 0);
      if ( *(_DWORD *)(v2 + 40)
        || (roaming_triggers = wlan_mlme_get_roaming_triggers(*v3),
            mlme_set_roam_trigger_bitmap(*v3, *((unsigned __int8 *)a1 + 8), roaming_triggers),
            mlme_set_roam_policy(*v3, *((unsigned __int8 *)a1 + 8), 1),
            (v17 = hdd_vdev_configure_rtt_params(v15)) == 0) )
      {
        hdd_tsf_auto_report_init(v2);
        _hdd_objmgr_put_vdev_by_user(v15, 36, "hdd_init_station_mode");
        v17 = 0;
        goto LABEL_12;
      }
    }
    _hdd_objmgr_put_vdev_by_user(v15, 36, "hdd_init_station_mode");
  }
  else
  {
    v17 = 29;
  }
  hdd_vdev_destroy((__int64)a1, v6, v7, v8, v9, v10, v11, v12, v13);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v17;
}
