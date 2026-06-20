__int64 __fastcall csr_set_pmk_cache_ft(
        _QWORD *a1,
        unsigned int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  unsigned int param; // w21
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  const char *v44; // x2
  __int64 v45; // x0
  __int64 v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _QWORD *scan_result; // x21
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  __int64 v65; // x22
  __int64 v66; // x0
  __int64 v67; // [xsp+0h] [xbp-30h] BYREF
  __int64 v68; // [xsp+8h] [xbp-28h] BYREF
  __int64 v69; // [xsp+10h] [xbp-20h]
  __int64 v70; // [xsp+18h] [xbp-18h]
  __int64 v71; // [xsp+20h] [xbp-10h]
  __int64 v72; // [xsp+28h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1
    || (unsigned __int8)a2 > 5u
    || (v11 = a1[2153]) == 0
    || (*(_BYTE *)(v11 + 96LL * (unsigned __int8)a2 + 1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: session %d not found",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "csr_set_pmk_cache_ft",
      (unsigned __int8)a2);
    result = 4;
    goto LABEL_10;
  }
  v15 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1[2694], a2, 11);
  if ( !v15 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: vdev is NULL", v16, v17, v18, v19, v20, v21, v22, v23, "csr_set_pmk_cache_ft");
    result = 16;
    goto LABEL_10;
  }
  v24 = v15;
  param = wlan_crypto_get_param(v15, 7u);
  wlan_objmgr_vdev_release_ref(v24, 0xBu, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( (param & 0x4000) != 0 )
  {
    v44 = "%s: PMK update is not required for ESE";
LABEL_13:
    qdf_trace_msg(
      0x34u,
      8u,
      v44,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "csr_set_pmk_cache_ft",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72);
    result = 0;
    goto LABEL_10;
  }
  if ( (param & 0x1180020) != 0 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Auth type: %x update the MDID in cache",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "csr_set_pmk_cache_ft",
      param);
    cm_update_pmk_cache_ft(a1[2694], a2, (__int64)a3);
    result = 0;
    goto LABEL_10;
  }
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v67 = 0;
  v45 = _qdf_mem_malloc(0x2D0u, "csr_set_pmk_cache_ft", 5166);
  if ( !v45 )
  {
    result = 2;
    goto LABEL_10;
  }
  v46 = v45;
  *(_BYTE *)(v45 + 16) = 1;
  qdf_mem_copy((void *)(v45 + 70), a3, 6u);
  scan_result = scm_get_scan_result(a1[2695], v46, v47, v48, v49, v50, v51, v52, v53, v54);
  _qdf_mem_free(v46);
  if ( !scan_result )
  {
    v44 = "%s: Scan list is empty";
    goto LABEL_13;
  }
  if ( *((_DWORD *)scan_result + 4) )
  {
    qdf_list_peek_front(scan_result, &v67);
    if ( v67 )
    {
      v64 = *(_QWORD *)(v67 + 24);
      if ( v64 )
      {
        v65 = *(_QWORD *)(v64 + 1560);
        if ( v65 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Update MDID in cache from scan_res",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "csr_set_pmk_cache_ft");
          v66 = a1[2694];
          LOBYTE(v69) = 1;
          LODWORD(v68) = *(unsigned __int16 *)(v65 + 2);
          wlan_cm_roam_cfg_set_value(v66, a2, 0x14u, (unsigned int *)&v68);
          cm_update_pmk_cache_ft(a1[2694], a2, (__int64)a3);
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 8u, "%s: Scan list is empty", v35, v36, v37, v38, v39, v40, v41, v42, "csr_set_pmk_cache_ft");
  }
  scm_purge_scan_results((__int64)scan_result, v56, v57, v58, v59, v60, v61, v62, v63);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
