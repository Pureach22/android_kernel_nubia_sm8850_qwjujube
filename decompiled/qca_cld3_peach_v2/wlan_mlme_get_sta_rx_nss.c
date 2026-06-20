__int64 __fastcall wlan_mlme_get_sta_rx_nss(__int64 a1, __int64 a2, _BYTE *a3)
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
  __int64 cmpt_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w22
  __int64 ext_hdl; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  unsigned int connected_band; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  int v45; // w8
  _BYTE v46[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46[0] = 0;
  if ( (unsigned int)wlan_mlme_cfg_get_dynamic_nss_chains_support(a1, v46) )
  {
    v13 = "%s: Failed to get dynamic_nss_chains_support";
LABEL_3:
    qdf_trace_msg(0x68u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlme_get_sta_rx_nss");
LABEL_4:
    result = 4;
    goto LABEL_19;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( cmpt_obj )
    v24 = *(unsigned __int8 *)(cmpt_obj + 23);
  else
    v24 = 0;
  if ( v46[0] != 1 )
  {
    result = 0;
    *a3 = v24;
    goto LABEL_19;
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a2, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "mlme_get_dynamic_vdev_config");
    v13 = "%s: nss chain dynamic config NULL";
    goto LABEL_3;
  }
  v34 = ext_hdl;
  connected_band = ucfg_cm_get_connected_band(a2, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( connected_band == 1 )
  {
    v44 = 36;
  }
  else
  {
    if ( connected_band != 2 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Band %d Not 2G or 5G",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "wlan_mlme_get_sta_rx_nss",
        connected_band);
      goto LABEL_4;
    }
    v44 = 40;
  }
  v45 = *(_DWORD *)(v34 + v44);
  result = 0;
  if ( v24 < (unsigned __int8)v45 )
    LOBYTE(v45) = v24;
  *a3 = v45;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
