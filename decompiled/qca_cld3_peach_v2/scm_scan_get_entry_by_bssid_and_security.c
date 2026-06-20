__int64 __fastcall scm_scan_get_entry_by_bssid_and_security(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  int v8; // w9
  _QWORD *vdev_by_id_from_pdev; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 cmpt_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  size_t v28; // x2
  int param; // w0
  __int16 v30; // w8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD *scan_result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  __int64 v58; // x21
  __int64 v59; // x6
  __int64 v60; // x7
  int v61; // w8
  int v62; // w9
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  _QWORD v72[2]; // [xsp+10h] [xbp-10h] BYREF

  v72[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v72[0] = 0;
  result = _qdf_mem_malloc(0x2D8u, "scm_scan_get_entry_by_bssid_and_security", 2350);
  if ( result )
  {
    v7 = result;
    *(_BYTE *)(result + 16) = 1;
    v8 = *(_DWORD *)a2;
    *(_WORD *)(result + 74) = *((_WORD *)a2 + 2);
    *(_DWORD *)(result + 70) = v8;
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a3, 0xCu);
    if ( vdev_by_id_from_pdev )
    {
      v18 = (__int64)vdev_by_id_from_pdev;
      if ( (*((_DWORD *)vdev_by_id_from_pdev + 4) | 2) != 2 )
      {
LABEL_12:
        *(_DWORD *)(v7 + 40) = wlan_crypto_get_param(v18, 0);
        *(_DWORD *)(v7 + 48) = wlan_crypto_get_param(v18, 1u);
        *(_DWORD *)(v7 + 44) = wlan_crypto_get_param(v18, 7u);
        *(_DWORD *)(v7 + 52) = wlan_crypto_get_param(v18, 2u);
        param = wlan_crypto_get_param(v18, 3u);
        v30 = *(_WORD *)v7;
        *(_DWORD *)(v7 + 56) = param;
        *(_WORD *)v7 = v30 | 4;
        *(_BYTE *)(v7 + 723) = *(_BYTE *)(v18 + 160);
        scan_result = scm_get_scan_result(a1, v7, v31, v32, v33, v34, v35, v36, v37, v38);
        v48 = (__int64)scan_result;
        if ( scan_result && *((_DWORD *)scan_result + 4) )
        {
          qdf_list_peek_front(scan_result, v72);
          if ( v72[0] && (v57 = *(_QWORD *)(v72[0] + 24LL)) != 0 )
            v58 = util_scan_copy_cache_entry_0(v57);
          else
            v58 = 0;
        }
        else
        {
          if ( a2 )
          {
            v59 = *a2;
            v60 = a2[1];
            v61 = a2[2];
            v62 = a2[5];
          }
          else
          {
            v61 = 0;
            v59 = 0;
            v60 = 0;
            v62 = 0;
          }
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: Scan entry for ssid:%.*s bssid:%02x:%02x:%02x:**:**:%02xnot found",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "scm_scan_get_entry_by_bssid_and_security",
            *(unsigned __int8 *)(v7 + 100),
            v7 + 101,
            v59,
            v60,
            v61,
            v62);
          v58 = 0;
          if ( !v48 )
            goto LABEL_23;
        }
        scm_purge_scan_results(v48, v49, v50, v51, v52, v53, v54, v55, v56);
LABEL_23:
        _qdf_mem_free(v7);
        wlan_objmgr_vdev_release_ref(v18, 0xCu, v63, v64, v65, v66, v67, v68, v69, v70, v71);
        result = v58;
        goto LABEL_24;
      }
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)vdev_by_id_from_pdev, v10, v11, v12, v13, v14, v15, v16, v17);
      if ( cmpt_obj )
      {
        v28 = *(unsigned __int8 *)(cmpt_obj + 178);
        if ( !*(_BYTE *)(cmpt_obj + 178) )
        {
          *(_BYTE *)(v7 + 100) = 0;
          goto LABEL_11;
        }
        *(_BYTE *)(v7 + 100) = v28;
        qdf_mem_copy((void *)(v7 + 101), (const void *)(cmpt_obj + 145), v28);
      }
      if ( *(_BYTE *)(v7 + 100) )
      {
        *(_BYTE *)(v7 + 17) = 1;
        goto LABEL_12;
      }
LABEL_11:
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: no ssid configured on vdev %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "scm_scan_get_entry_by_bssid_and_security",
        a3);
      goto LABEL_12;
    }
    _qdf_mem_free(v7);
    result = 0;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
