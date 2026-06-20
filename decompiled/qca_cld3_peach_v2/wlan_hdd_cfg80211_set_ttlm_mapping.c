__int64 __fastcall wlan_hdd_cfg80211_set_ttlm_mapping(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w21
  __int64 vdev_by_user; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  int v50; // w11
  int v51; // w10
  int v52; // w9
  int v53; // w11
  int v54; // w10
  int v55; // w11
  int v56; // w10
  int v57; // w11
  int v58; // w10
  int v59; // w11
  int v60; // w10
  int v61; // w11
  int v62; // w10
  int v63; // w10
  int v64; // w9
  bool v65; // zf
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x8
  unsigned __int8 *v75; // x8
  __int64 v76; // x9
  __int64 v77; // x11
  __int64 v78; // x8
  __int64 v79; // x12
  __int64 v80; // x9
  __int16 v81; // w10
  __int16 v82; // w9
  __int64 i; // x8
  unsigned __int16 v84; // w10
  int v85; // w8
  unsigned __int16 v86; // w9
  __int64 v87; // x8
  int v88; // w10
  __int64 v89; // x4
  __int64 v90; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v91[2]; // [xsp+10h] [xbp-40h] BYREF
  __int128 v92; // [xsp+20h] [xbp-30h]
  __int64 v93; // [xsp+30h] [xbp-20h]
  __int64 v94; // [xsp+38h] [xbp-18h]
  int v95; // [xsp+40h] [xbp-10h]
  __int64 v96; // [xsp+48h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  result = _osif_vdev_sync_op_start(a2, &v90, "wlan_hdd_cfg80211_set_ttlm_mapping");
  if ( (_DWORD)result )
    goto LABEL_45;
  v95 = 0;
  v93 = 0;
  v94 = 0;
  v92 = 0u;
  v91[0] = 0;
  v91[1] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "__wlan_hdd_cfg80211_set_ttlm_mapping");
  if ( (unsigned int)_hdd_validate_adapter(a2 + 2688, "__wlan_hdd_cfg80211_set_ttlm_mapping") )
  {
    v14 = -22;
    goto LABEL_44;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55520), 6, "__wlan_hdd_cfg80211_set_ttlm_mapping");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Vdev is null return",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "__wlan_hdd_cfg80211_set_ttlm_mapping");
    v14 = -107;
    goto LABEL_44;
  }
  v24 = vdev_by_user;
  if ( !wlan_cm_is_vdev_connected(vdev_by_user, v16, v17, v18, v19, v20, v21, v22, v23) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Not associated!, vdev %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "__wlan_hdd_cfg80211_set_ttlm_mapping",
      *(unsigned __int8 *)(v24 + 168));
    v14 = -107;
    goto LABEL_43;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v24, v25, v26, v27, v28, v29, v30, v31, v32) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed due to non-ML connection",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "__wlan_hdd_cfg80211_set_ttlm_mapping");
    v14 = -95;
    goto LABEL_43;
  }
  if ( (mlo_is_link_recfg_in_progress(v24) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed due to link recfg in progress",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "__wlan_hdd_cfg80211_set_ttlm_mapping");
    v14 = -16;
    goto LABEL_43;
  }
  v49 = *a3;
  if ( a3[8] != v49 )
    goto LABEL_41;
  v50 = a3[9];
  v51 = a3[1];
  v52 = -22;
  if ( v50 != v51 )
    goto LABEL_42;
  if ( v50 != v49 )
    goto LABEL_42;
  if ( v51 != v49 )
    goto LABEL_42;
  v53 = a3[10];
  v54 = a3[2];
  if ( v53 != v54 )
    goto LABEL_42;
  if ( v53 != v49 )
    goto LABEL_42;
  if ( v54 != v49 )
    goto LABEL_42;
  v55 = a3[11];
  v56 = a3[3];
  if ( v55 != v56 )
    goto LABEL_42;
  if ( v55 != v49 )
    goto LABEL_42;
  if ( v56 != v49 )
    goto LABEL_42;
  v57 = a3[12];
  v58 = a3[4];
  if ( v57 != v58 )
    goto LABEL_42;
  if ( v57 != v49 )
    goto LABEL_42;
  if ( v58 != v49 )
    goto LABEL_42;
  v59 = a3[13];
  v60 = a3[5];
  if ( v59 != v60 )
    goto LABEL_42;
  if ( v59 != v49 )
    goto LABEL_42;
  if ( v60 != v49 )
    goto LABEL_42;
  v61 = a3[14];
  v62 = a3[6];
  if ( v61 != v62 || v61 != v49 || v62 != v49 )
    goto LABEL_42;
  v63 = a3[15];
  v64 = a3[7];
  if ( v63 != v64 || v63 != v49 )
  {
LABEL_41:
    v52 = -22;
LABEL_42:
    v14 = v52;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TTLM parameters are not valid",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "__wlan_hdd_cfg80211_set_ttlm_mapping");
    goto LABEL_43;
  }
  v65 = v64 == v49;
  v52 = -22;
  if ( !v65 )
    goto LABEL_42;
  if ( v49 == 0x7FFF )
  {
    LODWORD(v91[0]) = 2;
LABEL_37:
    BYTE4(v91[0]) = 1;
    goto LABEL_38;
  }
  v74 = *(_QWORD *)(v24 + 1360);
  if ( v74 )
  {
    v75 = *(unsigned __int8 **)(v74 + 3880);
    v76 = v75[6];
    v77 = v75[54];
    v78 = v75[102];
    v79 = 1LL << v76;
    v65 = v76 == 255;
    v80 = 1LL << v77;
    if ( v65 )
      v81 = 0;
    else
      v81 = v79;
    if ( v77 == 255 )
      LOWORD(v80) = 0;
    v82 = v80 | v81;
    if ( v78 != 255 )
      v82 |= 1LL << v78;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: MLO dev context failed",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "hdd_get_connected_link_id");
    v82 = 0;
  }
  for ( i = 0; i != 8; ++i )
  {
    v84 = a3[i];
    if ( (v84 & 1) != 0 && (v82 & 1) == 0 )
    {
      v89 = 0;
LABEL_107:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TTLM mapping link_id: %d is not connected",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hdd_validate_ttlm_params",
        v89);
      v52 = -107;
      goto LABEL_42;
    }
    if ( (v84 & 2) != 0 && (v82 & 2) == 0 )
    {
      v89 = 1;
      goto LABEL_107;
    }
    if ( (v84 & 4) != 0 && (v82 & 4) == 0 )
    {
      v89 = 2;
      goto LABEL_107;
    }
    if ( (v84 & 8) != 0 && (v82 & 8) == 0 )
    {
      v89 = 3;
      goto LABEL_107;
    }
    if ( (v84 & 0x10) != 0 && (v82 & 0x10) == 0 )
    {
      v89 = 4;
      goto LABEL_107;
    }
    if ( (v84 & 0x20) != 0 && (v82 & 0x20) == 0 )
    {
      v89 = 5;
      goto LABEL_107;
    }
    if ( (v84 & 0x40) != 0 && (v82 & 0x40) == 0 )
    {
      v89 = 6;
      goto LABEL_107;
    }
    if ( (v84 & 0x80) != 0 && (v82 & 0x80) == 0 )
    {
      v89 = 7;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x100) != 0 && (v82 & 0x100) == 0 )
    {
      v89 = 8;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x200) != 0 && (v82 & 0x200) == 0 )
    {
      v89 = 9;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x400) != 0 && (v82 & 0x400) == 0 )
    {
      v89 = 10;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x800) != 0 && (v82 & 0x800) == 0 )
    {
      v89 = 11;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x1000) != 0 && (v82 & 0x1000) == 0 )
    {
      v89 = 12;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x2000) != 0 && (v82 & 0x2000) == 0 )
    {
      v89 = 13;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x4000) != 0 && (v82 & 0x4000) == 0 )
    {
      v89 = 14;
      goto LABEL_107;
    }
    if ( (a3[i] & 0x8000) != 0 && (v82 & 0x80000000) == 0 )
    {
      v89 = 15;
      goto LABEL_107;
    }
  }
  v85 = *a3;
  LODWORD(v91[0]) = 2;
  if ( v85 == 0x7FFF )
    goto LABEL_37;
  v86 = a3[1];
  LOWORD(v92) = v85;
  v87 = *(_QWORD *)(a3 + 2);
  v88 = *((_DWORD *)a3 + 3);
  WORD1(v92) = v86;
  *(_QWORD *)((char *)&v92 + 4) = v87;
  HIDWORD(v92) = v88;
LABEL_38:
  hdd_print_ttlm_params(v91);
  if ( (unsigned int)hdd_mlo_set_ttlm_mapping(v24, v91) )
    v14 = -16;
  else
    v14 = 0;
LABEL_43:
  _hdd_objmgr_put_vdev_by_user(v24, 6, "__wlan_hdd_cfg80211_set_ttlm_mapping");
  qdf_trace_msg(0x33u, 8u, "%s: exit", v66, v67, v68, v69, v70, v71, v72, v73, "__wlan_hdd_cfg80211_set_ttlm_mapping");
LABEL_44:
  _osif_vdev_sync_op_stop(v90, "wlan_hdd_cfg80211_set_ttlm_mapping");
  result = v14;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
