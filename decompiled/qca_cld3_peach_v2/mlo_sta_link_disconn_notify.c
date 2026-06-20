__int64 __fastcall mlo_sta_link_disconn_notify(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *v10; // x21
  __int64 v11; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _QWORD *v30; // x9
  __int64 v31; // x8
  __int64 v32; // x10
  unsigned __int64 v33; // x10
  __int64 v34; // x9
  __int64 v35; // x23
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w21
  __int64 v49; // x20
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x20
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x0
  unsigned __int16 v78; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v79; // [xsp+8h] [xbp-18h] BYREF
  __int64 v80; // [xsp+10h] [xbp-10h]
  __int64 v81; // [xsp+18h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD **)(result + 1360);
  if ( !v10 )
    goto LABEL_39;
  v11 = result;
  result = wlan_vdev_mlme_is_mlo_vdev(result, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) == 0 )
    goto LABEL_39;
  v21 = v10[278];
  if ( !v21 )
    goto LABEL_39;
  result = wlan_cm_is_vdev_disconnected(v11, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (result & 1) == 0 )
    goto LABEL_39;
  v30 = *(_QWORD **)(v11 + 1360);
  if ( !v30 )
  {
LABEL_21:
    if ( !*(_QWORD *)(v21 + 24) )
      goto LABEL_29;
    if ( (v38 = v10[3]) != 0
      && (result = wlan_vdev_mlme_is_mlo_vdev(v38, v22, v23, v24, v25, v26, v27, v28, v29), (result & 1) != 0)
      && (v39 = v10[3], (*(_BYTE *)(v39 + 60) & 2) == 0)
      || (result = v10[4]) != 0
      && (result = wlan_vdev_mlme_is_mlo_vdev(result, v22, v23, v24, v25, v26, v27, v28, v29), (result & 1) != 0)
      && (v39 = v10[4], (*(_BYTE *)(v39 + 60) & 2) == 0) )
    {
      if ( v39 )
        goto LABEL_29;
    }
LABEL_39:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v31 = v30[278];
  if ( v31 )
  {
    v32 = v30[3];
    if ( v32 && v32 == v11 )
    {
      v33 = *(_QWORD *)(v31 + 8) & 0xFFFFFFFFFFFFFFFELL;
      *(_QWORD *)(v31 + 8) = v33;
      if ( v30[4] != v11 )
        goto LABEL_15;
    }
    else
    {
      v34 = v30[4];
      if ( !v34 || v34 != v11 )
        goto LABEL_15;
      v33 = *(_QWORD *)(v31 + 8);
    }
    *(_QWORD *)(v31 + 8) = v33 & 0xFFFFFFFFFFFFFFFDLL;
  }
LABEL_15:
  v35 = *(_QWORD *)(v11 + 1360);
  if ( !v35 || (wlan_vdev_mlme_is_mlo_vdev(v11, v22, v23, v24, v25, v26, v27, v28, v29) & 1) == 0 )
    goto LABEL_21;
  v36 = *(_QWORD *)(v35 + 24);
  if ( !v36 || wlan_cm_is_vdev_disconnected(v36, v22, v23, v24, v25, v26, v27, v28, v29) )
  {
    v37 = *(_QWORD *)(v35 + 32);
    if ( !v37 || wlan_cm_is_vdev_disconnected(v37, v22, v23, v24, v25, v26, v27, v28, v29) )
      goto LABEL_21;
  }
LABEL_29:
  result = wlan_cm_is_link_switch_disconnect_resp(a2);
  if ( (result & 1) != 0 )
    goto LABEL_39;
  v79 = 0;
  v80 = 0;
  v78 = 0;
  result = mlo_sta_get_vdev_list(v11, &v78, &v79);
  v48 = v78;
  if ( !v78 )
    goto LABEL_39;
  v49 = v79;
  if ( wlan_cm_is_vdev_connected(v79, v40, v41, v42, v43, v44, v45, v46, v47) )
  {
    v50 = (unsigned int *)*(unsigned __int8 *)(v49 + 60);
    if ( ((unsigned __int8)v50 & 2) != 0 )
    {
      wlan_cm_disconnect(v49, *(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 12), nullptr);
      v49 = v79;
      v48 = v78;
    }
  }
  result = mlo_release_vdev_ref(v49, v50, v51, v52, v53, v54, v55, v56, v57, v58);
  if ( v48 < 2 )
    goto LABEL_39;
  v67 = v80;
  if ( wlan_cm_is_vdev_connected(v80, v59, v60, v61, v62, v63, v64, v65, v66) )
  {
    v68 = (unsigned int *)*(unsigned __int8 *)(v67 + 60);
    if ( ((unsigned __int8)v68 & 2) != 0 )
    {
      wlan_cm_disconnect(v67, *(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 12), nullptr);
      v67 = v80;
      v48 = v78;
    }
  }
  result = mlo_release_vdev_ref(v67, v68, v69, v70, v71, v72, v73, v74, v75, v76);
  if ( v48 <= 2 )
    goto LABEL_39;
  __break(0x5512u);
  v77 = ((__int64 (__fastcall *)(__int64))unk_7996F4)(result);
  return mlo_is_mld_sta(v77);
}
