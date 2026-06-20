__int64 __fastcall wma_unified_bcn_tmpl_send(
        __int64 *a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *v12; // x25
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int64 v33; // x8
  __int64 v34; // x9
  unsigned int v35; // w4
  unsigned int v36; // w5
  unsigned int v37; // w4
  __int64 result; // x0
  __int64 v39; // x8
  const char *v40; // x2
  __int64 v41; // x11
  char bigtk_support; // w0
  unsigned int v43; // w8
  bool v44; // cf
  unsigned int v45; // w8
  unsigned int v46; // w8
  unsigned int v47; // w8
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v49; // x23
  __int64 v50; // x24
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w19
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned __int64 is_mlo_vdev; // x8
  __int64 v78; // x19
  __int64 v79; // [xsp+8h] [xbp-98h]
  __int64 v80; // [xsp+10h] [xbp-90h]
  __int64 v81; // [xsp+18h] [xbp-88h]
  __int64 v82; // [xsp+20h] [xbp-80h]
  __int64 v83; // [xsp+30h] [xbp-70h]
  __int64 v84; // [xsp+38h] [xbp-68h]
  unsigned __int8 v85; // [xsp+40h] [xbp-60h]

  _ReadStatusReg(SP_EL0);
  v84 = 0;
  v83 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  if ( (wma_is_vdev_valid(a2, a5, a6, a7, a8, a9, a10, a11, a12) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id:%d is not active ",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wma_unified_bcn_tmpl_send",
      a2);
    result = 4;
    goto LABEL_51;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "vdev %d: bcn update reason %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    a2,
    *(unsigned int *)(a3 + 540));
  v33 = *(unsigned __int16 *)(a3 + 528);
  if ( *(_WORD *)(a3 + 528) )
  {
    if ( (unsigned int)v33 >= 0x201 )
      goto LABEL_40;
    v34 = 7;
    if ( !(_BYTE)a4 )
      v34 = 520;
    v35 = *(_DWORD *)(a3 + v34);
    if ( v35 <= 0x2DC )
    {
      v36 = *(unsigned __int8 *)(a3 + v33 + 8) + 2;
      if ( v35 > v36 )
      {
        v37 = v35 - v36;
        goto LABEL_14;
      }
      v40 = "%s: tmpl_len %d <= p2p_ie_len %d, Invalid";
LABEL_36:
      qdf_trace_msg(0x36u, 2u, v40, v25, v26, v27, v28, v29, v30, v31, v32, "wma_unified_bcn_tmpl_send");
      result = 4294967274LL;
      goto LABEL_51;
    }
LABEL_13:
    v40 = "%s: tmpl_len: %d > %d. Invalid tmpl len";
    goto LABEL_36;
  }
  v39 = 7;
  if ( !(_BYTE)a4 )
    v39 = 520;
  v37 = *(_DWORD *)(a3 + v39);
  if ( v37 >= 0x2DD )
    goto LABEL_13;
LABEL_14:
  v41 = a3 + (unsigned __int8)a4;
  LOBYTE(v79) = a2;
  HIDWORD(v79) = *(_DWORD *)(a3 + 524) - (unsigned __int8)a4;
  *(_QWORD *)(v41 + 31) = -*(_QWORD *)(a1[65] + 488LL * a2 + 192);
  v84 = v41 + 7;
  HIDWORD(v80) = v37;
  LODWORD(v81) = (v37 + 3) & 0xFFFFFFFC;
  bigtk_support = mlme_get_bigtk_support(*(_QWORD *)(a1[65] + 488LL * a2), v25, v26, v27, v28, v29, v30, v31, v32);
  v43 = *(_DWORD *)(a3 + 532);
  BYTE4(v83) = bigtk_support & 1;
  if ( v43 )
  {
    v44 = v43 >= (unsigned __int8)a4;
    v45 = v43 - (unsigned __int8)a4;
    if ( v45 != 0 && v44 )
      HIDWORD(v81) = v45;
  }
  v46 = *(_DWORD *)(a3 + 536);
  if ( v46 )
  {
    v44 = v46 >= (unsigned __int8)a4;
    v47 = v46 - (unsigned __int8)a4;
    if ( v47 != 0 && v44 )
      LODWORD(v82) = v47;
  }
  v85 = *(_BYTE *)(a3 + 548);
  v33 = v85;
  if ( !v85 || v85 == 1 || v85 == 2 )
  {
    a4 = 0;
    goto LABEL_26;
  }
  a4 = *(_DWORD *)(a3 + 616);
  if ( v85 != 3 )
  {
LABEL_40:
    __break(0x5512u);
    goto LABEL_41;
  }
LABEL_26:
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1[4], a2, 2u);
  if ( vdev_by_id_from_pdev )
  {
    v33 = *((unsigned int *)vdev_by_id_from_pdev + 4);
    if ( (_DWORD)v33 != 1 )
    {
      v49 = 0;
      v50 = 0;
      goto LABEL_42;
    }
    v12 = vdev_by_id_from_pdev;
    if ( (wlan_vdev_mlme_is_mlo_vdev((__int64)vdev_by_id_from_pdev, v25, v26, v27, v28, v29, v30, v31, v32) & 1) != 0 )
    {
      v33 = *((unsigned int *)v12 + 16);
      vdev_by_id_from_pdev = v12;
      if ( (v33 & 0x80000) != 0 )
        v49 = 1LL << a2;
      else
        v49 = 0;
      if ( (v33 & 0x100000) != 0 )
        v50 = 1LL << a2;
      else
        v50 = 0;
LABEL_42:
      wlan_objmgr_vdev_release_ref(
        (__int64)vdev_by_id_from_pdev,
        2u,
        (unsigned int *)v33,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32);
      if ( v49 | v50 )
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: hw_link_id:%d cat1 lo:0x%x hi:0x%x cat2 lo:0x%x hi:0x%x",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wma_critical_update_set_notify_bcn_tmpl",
          a4,
          (unsigned int)v49,
          HIDWORD(v50),
          v79,
          v80,
          v81,
          v82,
          0,
          v83,
          v84);
      goto LABEL_44;
    }
LABEL_41:
    v49 = 0;
    v50 = 0;
    vdev_by_id_from_pdev = v12;
    goto LABEL_42;
  }
LABEL_44:
  v59 = wmi_unified_beacon_tmpl_send_cmd(*a1);
  if ( v59 )
  {
    v68 = v59;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send bcn tmpl: %d",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "wma_unified_bcn_tmpl_send",
      v59);
    result = v68;
  }
  else
  {
    result = (__int64)wlan_objmgr_get_vdev_by_id_from_pdev(a1[4], a2, 2u);
    if ( result )
    {
      is_mlo_vdev = *(unsigned int *)(result + 16);
      if ( (_DWORD)is_mlo_vdev == 1 )
      {
        v78 = result;
        is_mlo_vdev = (unsigned int)wlan_vdev_mlme_is_mlo_vdev(result, v69, v70, v71, v72, v73, v74, v75, v76);
        result = v78;
        if ( (is_mlo_vdev & 1) != 0 )
        {
          is_mlo_vdev = *(_DWORD *)(v78 + 64) & 0xFFE7FFFF;
          *(_DWORD *)(v78 + 64) = is_mlo_vdev;
        }
      }
      wlan_objmgr_vdev_release_ref(result, 2u, (unsigned int *)is_mlo_vdev, v69, v70, v71, v72, v73, v74, v75, v76);
      result = 0;
    }
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
