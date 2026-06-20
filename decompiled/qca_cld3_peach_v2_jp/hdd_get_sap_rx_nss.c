__int64 __fastcall hdd_get_sap_rx_nss(
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
  __int64 v11; // x23
  __int64 v12; // x22
  unsigned int sap_operating_band_by_link_info; // w21
  __int64 vdev_by_user; // x0
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 dynamic_vdev_config; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w8
  __int64 result; // x0
  const char *v37; // x2
  _BYTE v38[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v38[0] = 0;
  v11 = *(_QWORD *)(v10 + 24);
  v12 = *(_QWORD *)(v11 + 16);
  if ( !v12 )
  {
    v37 = "%s: NULL MAC handle";
LABEL_11:
    qdf_trace_msg(0x33u, 8u, v37, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_sap_rx_nss");
    result = 4;
    goto LABEL_15;
  }
  sap_operating_band_by_link_info = (unsigned __int8)hdd_get_sap_operating_band_by_link_info(a1);
  if ( sap_operating_band_by_link_info != 3 )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_sap_rx_nss");
    if ( vdev_by_user )
    {
      v17 = vdev_by_user;
      sme_get_sap_vdev_type_nss(v12, v38, sap_operating_band_by_link_info);
      if ( *(_BYTE *)(v11 + 3744) != 1 )
      {
        LOBYTE(v35) = v38[0];
        goto LABEL_13;
      }
      dynamic_vdev_config = mlme_get_dynamic_vdev_config(v17, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( dynamic_vdev_config )
      {
        if ( sap_operating_band_by_link_info == 2 )
        {
          v35 = *(_DWORD *)(dynamic_vdev_config + 28);
        }
        else
        {
          if ( sap_operating_band_by_link_info != 1 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Band %d Not 2G or 5G",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "hdd_get_sap_rx_nss",
              sap_operating_band_by_link_info);
            goto LABEL_14;
          }
          v35 = *(_DWORD *)(dynamic_vdev_config + 24);
        }
LABEL_13:
        *a2 = v35;
LABEL_14:
        _hdd_objmgr_put_vdev_by_user(v17, 6, "hdd_get_sap_rx_nss");
        result = 0;
        goto LABEL_15;
      }
      _hdd_objmgr_put_vdev_by_user(v17, 6, "hdd_get_sap_rx_nss");
      v37 = "%s: nss chain dynamic config NULL";
      goto LABEL_11;
    }
  }
  result = 4;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
