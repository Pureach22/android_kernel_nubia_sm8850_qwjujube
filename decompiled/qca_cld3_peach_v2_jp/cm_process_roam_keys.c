__int64 __fastcall cm_process_roam_keys(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x23
  unsigned int v13; // w19
  __int64 v14; // x25
  __int64 psoc_ext_obj_fl; // x0
  __int64 v18; // x24
  __int64 v19; // x27
  int param; // w26
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  unsigned __int8 *v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  char v39; // w26
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  _BYTE *v49; // x24
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w3
  const char *v59; // x2
  __int64 result; // x0
  __int64 v61; // x0
  _BYTE *v62; // x22
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // [xsp+0h] [xbp-40h]
  __int64 v80; // [xsp+8h] [xbp-38h]
  __int64 v81; // [xsp+10h] [xbp-30h]
  __int64 v82; // [xsp+18h] [xbp-28h] BYREF
  __int64 v83; // [xsp+20h] [xbp-20h]
  __int64 v84; // [xsp+28h] [xbp-18h]
  __int64 v85; // [xsp+30h] [xbp-10h]
  __int64 v86; // [xsp+38h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 152);
  v13 = *(unsigned __int8 *)(a1 + 104);
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  if ( !v12 )
  {
    v59 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_17:
    result = qdf_trace_msg(0x68u, 2u, v59, a4, a5, a6, a7, a8, a9, a10, a11, "cm_process_roam_keys", v13, a3);
    goto LABEL_18;
  }
  v14 = *(_QWORD *)(v12 + 80);
  if ( !v14 )
  {
    v59 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_17;
  }
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(v12 + 80));
  if ( !psoc_ext_obj_fl )
  {
    v59 = "%s: vdev %d cm_id 0x%x: Failed to mlme psoc obj";
    goto LABEL_17;
  }
  v18 = psoc_ext_obj_fl;
  v19 = *(_QWORD *)(a2 + 152);
  param = wlan_crypto_get_param(a1, 7u);
  if ( *(_BYTE *)v19 != 2 && (param & 0x18400C00) == 0 )
    goto LABEL_27;
  cm_csr_set_ss_none(v13, v21, v22, v23, v24, v25, v26, v27, v28);
  v29 = _qdf_mem_malloc(0x98u, "cm_process_roam_keys", 983);
  if ( !v29 )
  {
    v59 = "%s: vdev %d cm_id 0x%x: Mem alloc failed";
    goto LABEL_17;
  }
  v30 = (unsigned __int8 *)v29;
  wlan_vdev_get_bss_peer_mac_for_pmksa();
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: Trying to find PMKID for %02x:%02x:%02x:**:**:%02x AKM Type:%d",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "cm_process_roam_keys",
    v13,
    a3,
    *v30,
    v30[1],
    v30[2],
    v30[5],
    param,
    v82);
  wlan_cm_roam_cfg_get_value(v14, v13, 0x14u, &v82);
  v39 = v83;
  if ( (cm_lookup_pmkid_using_bssid(v14, v13, (__int64)v30) & 1) != 0 )
  {
    if ( !*(_DWORD *)(v19 + 112) )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: PMK not received from fw",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "cm_process_roam_keys");
      LOBYTE(v58) = v30[86];
LABEL_25:
      wlan_cm_set_psk_pmk(v12, v13, v30 + 22, v58);
      LODWORD(v81) = v30[86];
      LODWORD(v80) = v30[5];
      LODWORD(v79) = v30[2];
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: pmkid found for %02x:%02x:%02x:**:**:%02x len %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "cm_process_roam_keys",
        v13,
        a3,
        *v30,
        v30[1],
        v79,
        v80,
        v81);
      goto LABEL_26;
    }
    v48 = _qdf_mem_malloc(0x98u, "cm_process_roam_keys", 1049);
    if ( v48 )
    {
      v49 = (_BYTE *)v48;
      wlan_vdev_get_bss_peer_mac_for_pmksa();
      qdf_mem_copy(v49 + 6, (const void *)(v19 + 180), 0x10u);
      qdf_mem_copy(v49 + 22, (const void *)(v19 + 116), *(unsigned int *)(v19 + 112));
      v49[86] = *(_DWORD *)(v19 + 112);
      if ( (unsigned int)wlan_crypto_set_del_pmksa(a1, (__int64)v49, 1, v50, v51, v52, v53, v54, v55, v56, v57) )
      {
        qdf_mem_set(v49, 0x98u, 0);
        _qdf_mem_free((__int64)v49);
      }
      qdf_mem_copy(v30 + 6, (const void *)(v19 + 180), 0x10u);
      qdf_mem_copy(v30 + 22, (const void *)(v19 + 116), *(unsigned int *)(v19 + 112));
      v58 = *(_DWORD *)(v19 + 112);
      v30[86] = v58;
      goto LABEL_25;
    }
LABEL_28:
    qdf_mem_set(v30, 0x98u, 0);
    result = _qdf_mem_free((__int64)v30);
    goto LABEL_18;
  }
  LODWORD(v80) = v30[5];
  LODWORD(v79) = v30[2];
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: PMKID Not found in cache for %02x:%02x:%02x:**:**:%02x",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "cm_process_roam_keys",
    v13,
    a3,
    *v30,
    v30[1],
    v79,
    v80);
  if ( (cm_is_auth_type_11r(v18, a1, v39) & 1) == 0 && *(_DWORD *)(v19 + 112) )
  {
    v61 = _qdf_mem_malloc(0x98u, "cm_process_roam_keys", 1117);
    if ( !v61 )
      goto LABEL_28;
    v62 = (_BYTE *)v61;
    wlan_cm_set_psk_pmk(v12, v13, (const void *)(v19 + 116), *(_DWORD *)(v19 + 112));
    wlan_vdev_get_bss_peer_mac_for_pmksa();
    qdf_mem_copy(v62 + 6, (const void *)(v19 + 180), 0x10u);
    qdf_mem_copy(v62 + 22, (const void *)(v19 + 116), *(unsigned int *)(v19 + 112));
    v62[86] = *(_DWORD *)(v19 + 112);
    if ( (unsigned int)wlan_crypto_set_del_pmksa(a1, (__int64)v62, 1, v63, v64, v65, v66, v67, v68, v69, v70) )
    {
      qdf_mem_set(v62, 0x98u, 0);
      _qdf_mem_free((__int64)v62);
    }
  }
LABEL_26:
  qdf_mem_set(v30, 0x98u, 0);
  result = _qdf_mem_free((__int64)v30);
  if ( *(_BYTE *)v19 != 2 )
LABEL_27:
    result = cm_update_wait_for_key_timer(a1, v13, 0x42C1D80u);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
