__int64 __fastcall wlan_cm_update_offload_ssid_from_candidate(__int64 a1, __int64 a2, void *a3)
{
  __int64 v4; // x0
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 ext_hdl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  __int64 v36; // x22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _QWORD *scan_result; // x21
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x23
  unsigned int v63; // w22
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x24
  void *v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v92; // [xsp+8h] [xbp-18h] BYREF
  int v93; // [xsp+10h] [xbp-10h] BYREF
  __int16 v94; // [xsp+14h] [xbp-Ch]
  __int64 v95; // [xsp+18h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 80);
  v92 = 0;
  if ( v4
    && (v94 = 0,
        v93 = 0,
        (v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v4, a2, 67)) != 0) )
  {
    v15 = v6;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v6, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( ext_hdl )
      qdf_mem_copy(&v93, (const void *)(ext_hdl + 329), 6u);
    else
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev legacy private object is NULL",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_cm_get_roam_offload_bssid");
    if ( (unsigned int)qdf_mem_cmp(&v93, a3, 6u) )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Update the roam offload ssid from scan cache",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wlan_cm_update_offload_ssid_from_candidate");
      v35 = _qdf_mem_malloc(0x2D8u, "wlan_cm_update_offload_ssid_from_candidate", 5909);
      if ( v35 )
      {
        v36 = v35;
        *(_BYTE *)(v35 + 16) = 1;
        qdf_mem_copy((void *)(v35 + 70), a3, 6u);
        scan_result = scm_get_scan_result(a1, v36, v37, v38, v39, v40, v41, v42, v43, v44);
        _qdf_mem_free(v36);
        if ( scan_result )
        {
          if ( *((_DWORD *)scan_result + 4) )
          {
            qdf_list_peek_front(scan_result, &v92);
            if ( v92 )
            {
              v62 = *(_QWORD *)(v92 + 24);
              if ( v62 )
              {
                v63 = *(unsigned __int8 *)(v62 + 13);
                v64 = wlan_vdev_mlme_get_ext_hdl(v15, v54, v55, v56, v57, v58, v59, v60, v61);
                if ( v64 )
                {
                  v73 = v64;
                  v74 = (void *)(v64 + 296);
                  if ( v63 >= 0x20 )
                    v63 = 32;
                  qdf_mem_set(v74, 0x21u, 0);
                  qdf_mem_copy((void *)(v73 + 297), (const void *)(v62 + 14), v63);
                  *(_BYTE *)(v73 + 296) = v63;
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: Set roam offload ssid: %.*s",
                    v75,
                    v76,
                    v77,
                    v78,
                    v79,
                    v80,
                    v81,
                    v82,
                    "wlan_cm_set_roam_offload_ssid",
                    v63,
                    v73 + 297);
                }
                else
                {
                  qdf_trace_msg(
                    0x68u,
                    2u,
                    "%s: vdev legacy private object is NULL",
                    v65,
                    v66,
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    "wlan_cm_set_roam_offload_ssid");
                }
                wlan_cm_set_roam_offload_bssid(v15, (unsigned __int16 *)a3, v83, v84, v85, v86, v87, v88, v89, v90);
              }
            }
            v25 = 0;
          }
          else
          {
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: Scan result is empty, candidate entry not found",
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              "wlan_cm_update_offload_ssid_from_candidate");
            v25 = 16;
          }
          scm_purge_scan_results((__int64)scan_result, v54, v55, v56, v57, v58, v59, v60, v61);
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Scan result is empty, candidate entry not found",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "wlan_cm_update_offload_ssid_from_candidate");
          v25 = 16;
        }
      }
      else
      {
        v25 = 2;
      }
    }
    else
    {
      v25 = 0;
    }
    wlan_objmgr_vdev_release_ref(v15, 0x43u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  }
  else
  {
    v25 = 29;
  }
  _ReadStatusReg(SP_EL0);
  return v25;
}
