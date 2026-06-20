__int64 __fastcall hdd_get_mlo_max_band_info(__int64 *a1, __int64 a2)
{
  __int64 vdev_by_user; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x23
  __int64 v24; // x28
  __int64 v25; // x22
  int v26; // w27
  unsigned int v27; // w20
  const char *v28; // x2
  unsigned int v29; // w25
  __int64 v30; // x24
  __int64 v31; // x26
  int v32; // w23
  _WORD *v33; // x27
  __int64 vdev_by_link_id; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x24
  __int64 v44; // x26
  __int64 ext_hdl; // x0
  unsigned int v46; // w26
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _WORD *v56; // [xsp+8h] [xbp-18h]
  _BYTE v57[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v58[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  wma_cli_get_command(*((unsigned __int8 *)a1 + 8), 21, 1);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_get_mlo_max_band_info");
  if ( !vdev_by_user )
  {
    v27 = -22;
    goto LABEL_31;
  }
  v13 = vdev_by_user;
  if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v5, v6, v7, v8, v9, v10, v11, v12) & 1) == 0 )
  {
    v28 = "%s: not mlo vdev";
LABEL_29:
    qdf_trace_msg(0x33u, 2u, v28, v14, v15, v16, v17, v18, v19, v20, v21, "hdd_get_mlo_max_band_info");
    v27 = -22;
LABEL_30:
    _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_get_mlo_max_band_info");
    goto LABEL_31;
  }
  v22 = *(_QWORD *)(a2 + 216);
  v23 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32868, 0, 0) & 0x80000000) != 0 || !(v22 + v23) )
  {
    v28 = "%s: nla_nest_start error";
    goto LABEL_29;
  }
  v24 = *a1;
  v56 = (_WORD *)(v22 + v23);
  if ( !*a1 || (v25 = v24 + 52840, v24 == -52840) )
  {
LABEL_32:
    v27 = 0;
    *v56 = *(_WORD *)(a2 + 216) + *(_WORD *)(a2 + 208) - (_WORD)v56;
    goto LABEL_30;
  }
  v26 = 0;
  while ( 1 )
  {
    if ( (unsigned __int64)(0x71B3F945A27B1F49LL * ((v24 - *a1) >> 3)) > 2 )
      goto LABEL_32;
    v29 = *(_DWORD *)(v25 + 976);
    if ( v29 != 255 )
      break;
LABEL_10:
    v25 += 6088;
    v24 += 6088;
    if ( !v25 )
      goto LABEL_32;
  }
  v30 = *(_QWORD *)(a2 + 216);
  v31 = *(unsigned int *)(a2 + 208);
  v32 = v26;
  if ( (nla_put(a2, v26 | 0x8000u, 0, 0) & 0x80000000) != 0 || (v33 = (_WORD *)(v30 + v31)) == nullptr )
  {
    v28 = "%s: nla_nest_start fail";
    goto LABEL_29;
  }
  v57[0] = v29;
  if ( (unsigned int)nla_put(a2, 99, 1, v57) )
  {
    v28 = "%s: nla_put failure";
    goto LABEL_29;
  }
  vdev_by_link_id = mlo_get_vdev_by_link_id(v13, v29, 6);
  v43 = vdev_by_link_id;
  if ( vdev_by_link_id )
  {
    v44 = *(_QWORD *)(vdev_by_link_id + 32);
    if ( v44 )
    {
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(vdev_by_link_id, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( ext_hdl )
      {
        if ( *(_BYTE *)(ext_hdl + 24256) == 1 )
          v46 = *(unsigned __int8 *)(ext_hdl + 24252);
        else
          v46 = *(unsigned __int8 *)(v44 + 24);
        goto LABEL_25;
      }
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev legacy private object is NULL",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "hdd_get_mlo_max_band_info");
      v27 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to get bss_chan info",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "hdd_get_mlo_max_band_info");
      v27 = -22;
    }
    _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_get_mlo_max_band_info");
    v13 = v43;
    goto LABEL_30;
  }
  if ( *(unsigned __int8 *)(v25 + 8) == 255 )
    v46 = *(unsigned __int8 *)(v25 + 1697);
  else
    v46 = 8;
LABEL_25:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: get link_id:%u ch width:%u",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "hdd_get_mlo_max_band_info",
    v29,
    v46);
  v58[0] = hdd_phy_chwidth_to_nl80211_chwidth(v46);
  if ( !(unsigned int)nla_put(a2, 63, 1, v58) )
  {
    *v33 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v33;
    v26 = v32 + 1;
    if ( v43 )
      _hdd_objmgr_put_vdev_by_user(v43, 6, "hdd_get_mlo_max_band_info");
    goto LABEL_10;
  }
  qdf_trace_msg(0x33u, 2u, "%s: nla_put failure", v47, v48, v49, v50, v51, v52, v53, v54, "hdd_get_mlo_max_band_info");
  _hdd_objmgr_put_vdev_by_user(v13, 6, "hdd_get_mlo_max_band_info");
  v27 = -22;
  v13 = v43;
  if ( v43 )
    goto LABEL_30;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v27;
}
