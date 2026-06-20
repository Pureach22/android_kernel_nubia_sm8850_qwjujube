__int64 __fastcall hdd_set_tx_rx_nss_per_band(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5)
{
  __int64 v10; // x8
  __int64 v11; // x25
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  __int64 result; // x0
  __int64 v22; // x20
  __int64 vdev_by_user; // x0
  unsigned int v24; // w25
  __int64 v25; // x23
  __int64 cmpt_obj; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w8
  __int64 v36; // x0
  unsigned int v37; // w8
  __int64 v38; // x0
  unsigned int v39; // w8
  __int64 v40; // x0
  unsigned int v41; // w8
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  __int64 v52; // [xsp+0h] [xbp-40h] BYREF
  __int64 v53; // [xsp+8h] [xbp-38h]
  __int64 v54; // [xsp+10h] [xbp-30h]
  __int64 v55; // [xsp+18h] [xbp-28h]
  __int64 v56; // [xsp+20h] [xbp-20h]
  __int64 v57; // [xsp+28h] [xbp-18h]
  __int64 v58; // [xsp+30h] [xbp-10h]
  __int64 v59; // [xsp+38h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v11 = *(_QWORD *)(v10 + 24);
  v53 = 0;
  v54 = 0;
  v52 = 0;
  if ( (unsigned int)_wlan_hdd_validate_context(v11, "hdd_set_tx_rx_nss_per_band") )
  {
    v20 = "%s: Invalid hdd_ctx";
LABEL_3:
    qdf_trace_msg(
      0x33u,
      2u,
      v20,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_set_tx_rx_nss_per_band",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59);
    goto LABEL_4;
  }
  v22 = *(_QWORD *)(v11 + 16);
  if ( !v22 )
  {
    v20 = "%s: NULL MAC handle";
    goto LABEL_3;
  }
  if ( (*(_BYTE *)(v11 + 3744) & 1) == 0 )
  {
    v20 = "%s: Dynamic nss chain update is not supported";
    goto LABEL_3;
  }
  if ( (hdd_is_vdev_in_conn_state(a1) & 1) == 0 )
  {
    v20 = "%s: Can't update nss values in disconnected state";
    goto LABEL_3;
  }
  qdf_mem_set(&v52, 0x38u, 0);
  LODWORD(v55) = a3;
  HIDWORD(v55) = a5;
  LODWORD(v54) = a2;
  HIDWORD(v54) = a4;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_set_tx_rx_nss_per_band");
  if ( !vdev_by_user )
  {
    v20 = "%s: vdev is NULL";
    goto LABEL_3;
  }
  if ( (*(_DWORD *)(*(_QWORD *)a1 + 40LL) | 2) == 3 )
    goto LABEL_11;
  v24 = a2;
  v25 = vdev_by_user;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(vdev_by_user, v12, v13, v14, v15, v16, v17, v18, v19);
  v35 = cmpt_obj ? *(unsigned __int8 *)(cmpt_obj + 23) : 0;
  vdev_by_user = v25;
  if ( v35 < v24 )
    goto LABEL_33;
  v36 = wlan_vdev_mlme_get_cmpt_obj(v25, v27, v28, v29, v30, v31, v32, v33, v34);
  v37 = v36 ? *(unsigned __int8 *)(v36 + 23) : 0;
  vdev_by_user = v25;
  if ( v37 >= a3
    && ((v38 = wlan_vdev_mlme_get_cmpt_obj(v25, v27, v28, v29, v30, v31, v32, v33, v34)) == 0
      ? (v39 = 0)
      : (v39 = *(unsigned __int8 *)(v38 + 23)),
        (vdev_by_user = v25, v39 >= a4)
     && ((v40 = wlan_vdev_mlme_get_cmpt_obj(v25, v27, v28, v29, v30, v31, v32, v33, v34)) == 0
       ? (v41 = 0)
       : (v41 = *(unsigned __int8 *)(v40 + 23)),
         vdev_by_user = v25,
         v41 >= a5)) )
  {
LABEL_11:
    _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "hdd_set_tx_rx_nss_per_band");
    if ( !(unsigned int)sme_nss_chains_update(v22, &v52, a1[8]) )
    {
      hdd_update_vdev_nss_chains_config(a1);
      result = 0;
      goto LABEL_5;
    }
  }
  else
  {
LABEL_33:
    v42 = wlan_vdev_mlme_get_cmpt_obj(vdev_by_user, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( v42 )
      v51 = *(unsigned __int8 *)(v42 + 23);
    else
      v51 = 0;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Given tx nss/rx nss is greater than intersected nss = %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "hdd_set_tx_rx_nss_per_band",
      v51,
      v52,
      v53);
    _hdd_objmgr_put_vdev_by_user(v25, 6, "hdd_set_tx_rx_nss_per_band");
  }
LABEL_4:
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
