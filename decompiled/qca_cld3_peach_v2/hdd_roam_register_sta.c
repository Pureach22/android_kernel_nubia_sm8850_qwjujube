__int64 __fastcall hdd_roam_register_sta(
        __int64 *a1,
        unsigned __int8 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  int v15; // w8
  __int64 v16; // x22
  unsigned __int8 *v17; // x1
  _QWORD *v18; // x21
  char is_active; // w0
  __int64 v20; // x4
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 vdev_by_user; // x0
  __int64 v30; // x24
  unsigned int v31; // w23
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  unsigned int vdev_phy_mode; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int ch_width_from_phymode; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v60; // x22
  __int64 v61; // x8
  __int64 v62; // x9
  int *v63; // x10
  int v64; // w11
  int v65; // w10
  _DWORD **v67; // x8
  _DWORD *v68; // x8
  int v70; // w23
  __int64 v71; // x8
  __int64 v72; // x8
  __int64 v73; // x9
  __int64 v74; // [xsp+10h] [xbp-20h] BYREF
  int v75; // [xsp+18h] [xbp-18h]
  __int64 v76; // [xsp+28h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v74 = 0;
  context = _cds_get_context(71, (__int64)"hdd_roam_register_sta", a4, a5, a6, a7, a8, a9, a10, a11);
  v15 = *a2;
  v16 = *a1;
  v17 = a2;
  v18 = context;
  if ( v15 == 255 && v17[1] == 255 && v17[2] == 255 && v17[3] == 255 && v17[4] == 255 && v17[5] == 255 )
    v17 = (unsigned __int8 *)(v16 + 1617);
  qdf_mem_copy((char *)&v74 + 2, v17, 6u);
  is_active = hdd_wmm_is_active(v16);
  v20 = *(unsigned __int8 *)(v16 + 38933);
  LOBYTE(v74) = is_active & 1;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: WAPI STA Registered: %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hdd_roam_register_sta",
    v20);
  BYTE1(v74) = *(_BYTE *)(v16 + 38933);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 97, "hdd_roam_register_sta");
  if ( !vdev_by_user )
  {
    v31 = 4;
    goto LABEL_39;
  }
  v30 = vdev_by_user;
  v31 = ucfg_dp_sta_register_txrx_ops(vdev_by_user);
  _hdd_objmgr_put_vdev_by_user(v30, 97, "hdd_roam_register_sta");
  if ( !v31 )
  {
    v40 = **(_QWORD **)(v16 + 24);
    if ( *(_DWORD *)(v16 + 40) == 11 )
    {
      vdev_phy_mode = ucfg_mlme_get_vdev_phy_mode(v40, *((unsigned __int8 *)a1 + 8));
      ch_width_from_phymode = wlan_mlme_get_ch_width_from_phymode(vdev_phy_mode, v42, v43, v44, v45, v46, v47, v48, v49);
      if ( *(_DWORD *)((char *)&v74 + 2) != -1 || SHIWORD(v74) != -1 )
      {
        v60 = 0;
        v61 = (__int64)a1 + 548;
        v62 = -192;
        do
        {
          v63 = (int *)(v61 + v62);
          if ( !(*(_DWORD *)(v61 + v62) | *(unsigned __int16 *)(v61 + v62 + 4)) )
            break;
          v64 = *v63;
          v65 = *((unsigned __int16 *)v63 + 2);
          if ( v64 == *(_DWORD *)((char *)&v74 + 2) && v65 == HIWORD(v74) )
          {
            v70 = ch_width_from_phymode;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Set NDP peer %02x:%02x:%02x:**:**:%02x bandwidth:%u",
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              "hdd_ndp_set_peer_bw",
              BYTE2(v74),
              BYTE3(v74),
              BYTE4(v74),
              HIBYTE(v74),
              ch_width_from_phymode);
            ch_width_from_phymode = v70;
            *((_DWORD *)a1 + v60 + 137) = v70;
            if ( (unsigned int)(v70 - 1) > 6 )
              v71 = 0;
            else
              v71 = qword_AF12E0[v70 - 1];
            v72 = *a1 + v71;
            v73 = 1LL << ((unsigned __int8)v60 - 1);
            if ( !v60 )
              LOBYTE(v73) = 1;
            *(_BYTE *)(v72 + 52032) |= v73;
            break;
          }
          ++v60;
          v62 += 6;
        }
        while ( v60 != 32 );
      }
    }
    else
    {
      ch_width_from_phymode = wlan_mlme_get_peer_ch_width(v40, (unsigned __int8 *)&v74 + 2);
    }
    if ( (unsigned int)(ch_width_from_phymode - 1) > 6 )
    {
      v75 = 0;
      if ( !v18 )
        goto LABEL_37;
    }
    else
    {
      v75 = dword_AF1318[ch_width_from_phymode - 1];
      if ( !v18 )
        goto LABEL_37;
    }
    if ( *v18 )
    {
      v67 = *(_DWORD ***)(*v18 + 72LL);
      if ( v67 )
      {
        v68 = *v67;
        if ( v68 )
        {
          if ( *(v68 - 1) != -974215578 )
            __break(0x8228u);
          v31 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64 *))v68)(v18, 0, &v74);
          if ( !v31 )
          {
            hdd_cm_set_peer_authenticate(a1, (char *)&v74 + 2, a3 & 1);
            goto LABEL_39;
          }
        }
        else
        {
          v31 = 11;
        }
LABEL_38:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: cdp_peer_register() failed Status: %d [0x%08X]",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "hdd_roam_register_sta",
          v31,
          v31);
        goto LABEL_39;
      }
    }
LABEL_37:
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v51, v52, v53, v54, v55, v56, v57, v58, "cdp_peer_register");
    v31 = 4;
    goto LABEL_38;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: DP tx/rx ops register failed Status: %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "hdd_roam_register_sta",
    v31);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v31;
}
