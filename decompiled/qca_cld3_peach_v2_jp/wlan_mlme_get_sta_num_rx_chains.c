__int64 __fastcall wlan_mlme_get_sta_num_rx_chains(__int64 a1, __int64 a2, _BYTE *a3)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 ext_hdl; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x21
  unsigned int connected_band; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w8
  _BYTE v43[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43[0] = 0;
  if ( (unsigned int)wlan_mlme_cfg_get_dynamic_nss_chains_support(a1, v43) )
  {
    v13 = "%s: Failed to get dynamic_nss_chains_support";
  }
  else
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a2, 0);
    if ( !result )
      goto LABEL_5;
    if ( v43[0] != 1 )
    {
      result = 0;
      goto LABEL_5;
    }
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(a2, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( ext_hdl )
    {
      v32 = ext_hdl;
      connected_band = ucfg_cm_get_connected_band(a2, v24, v25, v26, v27, v28, v29, v30, v31);
      if ( connected_band == 2 )
      {
        v42 = *(_DWORD *)(v32 + 24);
      }
      else
      {
        if ( connected_band != 1 )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Band %d Not 2G or 5G",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "wlan_mlme_get_sta_num_rx_chains",
            connected_band);
          goto LABEL_4;
        }
        v42 = *(_DWORD *)(v32 + 20);
      }
      result = 0;
      *a3 = v42;
      goto LABEL_5;
    }
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "mlme_get_dynamic_vdev_config");
    v13 = "%s: nss chain dynamic config NULL";
  }
  qdf_trace_msg(0x68u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlme_get_sta_num_rx_chains");
LABEL_4:
  result = 4;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
