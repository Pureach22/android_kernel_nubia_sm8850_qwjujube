__int64 __fastcall cm_update_scan_mlme_for_mlo_roam(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 v20; // x21
  __int64 cmpt_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  size_t v30; // x2
  __int64 v31; // x22
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int *v41; // x21
  int v42; // w9
  __int16 v43; // w9
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int *v60; // x21
  int v61; // w9
  __int16 v62; // w9
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
  int *v79; // x21
  int v80; // w9
  __int16 v81; // w9
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // [xsp+0h] [xbp-60h] BYREF
  __int64 v91; // [xsp+8h] [xbp-58h]
  __int64 v92; // [xsp+10h] [xbp-50h]
  __int64 v93; // [xsp+18h] [xbp-48h]
  int v94; // [xsp+20h] [xbp-40h]
  __int16 v95; // [xsp+24h] [xbp-3Ch]
  _QWORD v96[7]; // [xsp+28h] [xbp-38h] BYREF

  v96[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v96, 0, 44);
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  result = wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (result & 1) != 0 )
  {
    v19 = *(_QWORD *)(a1 + 216);
    if ( v19 )
    {
      v20 = *(_QWORD *)(a1 + 1360);
      if ( v20 )
      {
        if ( *(_QWORD *)(v20 + 3880) )
        {
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v11, v12, v13, v14, v15, v16, v17, v18);
          if ( cmpt_obj && (v30 = *(unsigned __int8 *)(cmpt_obj + 178), *(_BYTE *)(cmpt_obj + 178)) )
          {
            BYTE4(v96[0]) = *(_BYTE *)(cmpt_obj + 178);
            qdf_mem_copy((char *)v96 + 5, (const void *)(cmpt_obj + 145), v30);
            HIDWORD(v92) = 0;
            result = _qdf_mem_malloc(0x2D8u, "cm_update_scan_mlme_for_mlo_roam", 706);
            if ( result )
            {
              v31 = *(_QWORD *)(v20 + 3880);
              v32 = result;
              qdf_mem_set((void *)result, 0x2D8u, 0);
              v41 = (int *)(v31 + 24);
              if ( *(_DWORD *)(v31 + 24) | *(unsigned __int16 *)(v31 + 28) )
              {
                v42 = *v41;
                *(_WORD *)((char *)&v96[5] + 1) = *(_WORD *)(v31 + 28);
                *(_DWORD *)((char *)&v96[4] + 5) = v42;
                LODWORD(v96[0]) = *(unsigned __int16 *)(v31 + 10);
                scm_scan_update_mlme_by_bssinfo(v19, (__int64)v96, &v90, v33, v34, v35, v36, v37, v38, v39, v40);
                *(_BYTE *)(v32 + 16) = 1;
                v43 = *(_WORD *)(v31 + 28);
                *(_DWORD *)(v32 + 70) = *v41;
                *(_WORD *)(v32 + 74) = v43;
                if ( (wlan_scan_is_locally_generated_entry(v19, (unsigned __int8 *)(v31 + 24)) & 1) != 0 )
                  ucfg_scan_flush_results(v19, v32, v44, v45, v46, v47, v48, v49, v50, v51);
                v31 += 48;
              }
              qdf_mem_set((void *)v32, 0x2D8u, 0);
              v60 = (int *)(v31 + 24);
              if ( *(_DWORD *)(v31 + 24) | *(unsigned __int16 *)(v31 + 28) )
              {
                v61 = *v60;
                *(_WORD *)((char *)&v96[5] + 1) = *(_WORD *)(v31 + 28);
                *(_DWORD *)((char *)&v96[4] + 5) = v61;
                LODWORD(v96[0]) = *(unsigned __int16 *)(v31 + 10);
                scm_scan_update_mlme_by_bssinfo(v19, (__int64)v96, &v90, v52, v53, v54, v55, v56, v57, v58, v59);
                *(_BYTE *)(v32 + 16) = 1;
                v62 = *(_WORD *)(v31 + 28);
                *(_DWORD *)(v32 + 70) = *v60;
                *(_WORD *)(v32 + 74) = v62;
                if ( (wlan_scan_is_locally_generated_entry(v19, (unsigned __int8 *)(v31 + 24)) & 1) != 0 )
                  ucfg_scan_flush_results(v19, v32, v63, v64, v65, v66, v67, v68, v69, v70);
                v31 += 48;
              }
              qdf_mem_set((void *)v32, 0x2D8u, 0);
              v95 = 0;
              v94 = 0;
              v79 = (int *)(v31 + 24);
              if ( *(_DWORD *)(v31 + 24) | *(unsigned __int16 *)(v31 + 28) )
              {
                v80 = *v79;
                *(_WORD *)((char *)&v96[5] + 1) = *(_WORD *)(v31 + 28);
                *(_DWORD *)((char *)&v96[4] + 5) = v80;
                LODWORD(v96[0]) = *(unsigned __int16 *)(v31 + 10);
                scm_scan_update_mlme_by_bssinfo(v19, (__int64)v96, &v90, v71, v72, v73, v74, v75, v76, v77, v78);
                *(_BYTE *)(v32 + 16) = 1;
                v81 = *(_WORD *)(v31 + 28);
                *(_DWORD *)(v32 + 70) = *v79;
                *(_WORD *)(v32 + 74) = v81;
                if ( (wlan_scan_is_locally_generated_entry(v19, (unsigned __int8 *)(v31 + 24)) & 1) != 0 )
                  ucfg_scan_flush_results(v19, v32, v82, v83, v84, v85, v86, v87, v88, v89);
              }
              result = _qdf_mem_free(v32);
            }
          }
          else
          {
            result = qdf_trace_msg(
                       0x68u,
                       2u,
                       "%s: failed to get ssid",
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       "cm_update_scan_mlme_for_mlo_roam",
                       v90,
                       v91,
                       v92,
                       v93);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
