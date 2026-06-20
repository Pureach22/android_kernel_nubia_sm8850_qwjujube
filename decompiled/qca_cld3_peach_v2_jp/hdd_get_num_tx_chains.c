__int64 __fastcall hdd_get_num_tx_chains(
        _DWORD *a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v12; // x22
  unsigned int sap_operating_band_by_link_info; // w20
  __int64 vdev_by_user; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  _DWORD *dynamic_vdev_config; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 *v34; // x21
  __int64 v35; // x0
  __int64 v36; // x20
  unsigned int sta_num_tx_chains; // w19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  const char *v47; // x2

  v10 = *(_QWORD *)a1;
  if ( (*(_DWORD *)(*(_QWORD *)a1 + 40LL) | 2) == 3 )
  {
    v12 = *(_QWORD *)(v10 + 24);
    if ( !*(_QWORD *)(v12 + 16) )
    {
      v47 = "%s: NULL MAC handle";
      goto LABEL_16;
    }
    sap_operating_band_by_link_info = (unsigned __int8)hdd_get_sap_operating_band_by_link_info(a1);
    if ( sap_operating_band_by_link_info != 3 )
    {
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_sap_num_tx_chains");
      if ( vdev_by_user )
      {
        if ( *(_BYTE *)(v12 + 3744) != 1 )
        {
LABEL_21:
          _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "hdd_get_sap_num_tx_chains");
          return 0;
        }
        v24 = vdev_by_user;
        dynamic_vdev_config = (_DWORD *)mlme_get_dynamic_vdev_config(
                                          vdev_by_user,
                                          v16,
                                          v17,
                                          v18,
                                          v19,
                                          v20,
                                          v21,
                                          v22,
                                          v23);
        if ( dynamic_vdev_config )
        {
          if ( sap_operating_band_by_link_info == 2 )
          {
            *a2 = dynamic_vdev_config[1];
          }
          else if ( sap_operating_band_by_link_info == 1 )
          {
            *a2 = *dynamic_vdev_config;
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Band %d Not 2G or 5G",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "hdd_get_sap_num_tx_chains",
              sap_operating_band_by_link_info);
          }
          vdev_by_user = v24;
          goto LABEL_21;
        }
        _hdd_objmgr_put_vdev_by_user(v24, 6, "hdd_get_sap_num_tx_chains");
        v47 = "%s: nss chain dynamic config NULL";
LABEL_16:
        qdf_trace_msg(0x33u, 8u, v47, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_sap_num_tx_chains");
        return 4;
      }
    }
    return 4;
  }
  v34 = *(__int64 **)(v10 + 24);
  v35 = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_sta_num_tx_chains");
  if ( !v35 )
    return 4;
  v36 = v35;
  sta_num_tx_chains = wlan_mlme_get_sta_num_tx_chains(*v34, v35, a2);
  if ( sta_num_tx_chains )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get sta_tx_nss",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "hdd_get_sta_num_tx_chains");
  _hdd_objmgr_put_vdev_by_user(v36, 6, "hdd_get_sta_num_tx_chains");
  return sta_num_tx_chains;
}
