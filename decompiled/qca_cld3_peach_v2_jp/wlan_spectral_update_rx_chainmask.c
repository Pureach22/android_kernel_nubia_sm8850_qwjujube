__int64 __fastcall wlan_spectral_update_rx_chainmask(_DWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned int link_info_home_channel; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 vdev_by_user; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 cmpt_obj; // x0
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 result; // x0
  _QWORD v43[2]; // [xsp+0h] [xbp-10h] BYREF

  v43[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v43[0] = 0;
  v3 = *(_QWORD *)(v2 + 24);
  link_info_home_channel = hdd_get_link_info_home_channel(a1);
  wma_get_rx_chainmask(
    *(_BYTE *)(*(_QWORD *)(v3 + 8) + 40LL),
    (unsigned int *)v43 + 1,
    (unsigned int *)v43,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12);
  v13 = v43[0];
  if ( wlan_reg_is_24ghz_ch_freq(link_info_home_channel) )
    v13 = HIDWORD(v43[0]);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: chan freq %d chainmask %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_spectral_update_rx_chainmask",
    link_info_home_channel,
    v13);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user((__int64)a1, 0x55u, (__int64)"wlan_spectral_update_rx_chainmask");
  if ( vdev_by_user )
  {
    v31 = vdev_by_user;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(vdev_by_user, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( cmpt_obj )
      *(_BYTE *)(cmpt_obj + 401) = v13;
    _hdd_objmgr_put_vdev_by_user(
      v31,
      0x55u,
      (__int64)"wlan_spectral_update_rx_chainmask",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41);
    result = 0;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
