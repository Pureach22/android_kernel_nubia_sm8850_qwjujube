__int64 __fastcall mlo_link_recfg_update_scan_mlme(
        __int64 a1,
        unsigned __int8 *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 assoc_link_vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 ap_link_info; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  __int64 cmpt_obj; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  size_t v43; // x2
  __int16 v44; // w8
  int v45; // w9
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 result; // x0
  __int64 v56; // x4
  __int64 v57; // x5
  __int64 v58; // x6
  __int64 v59; // x7
  _QWORD v60[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v61; // [xsp+18h] [xbp-48h]
  __int64 v62; // [xsp+20h] [xbp-40h]
  _QWORD v63[7]; // [xsp+28h] [xbp-38h] BYREF

  v63[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62 = 0;
  v60[0] = 0;
  v60[1] = 0;
  memset(v63, 0, 44);
  assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( assoc_link_vdev )
  {
    v23 = assoc_link_vdev;
    ap_link_info = mlo_mgr_get_ap_link_info(a1, (__int64)a2);
    if ( ap_link_info )
    {
      v33 = ap_link_info;
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v25, v26, v27, v28, v29, v30, v31, v32);
      if ( cmpt_obj && (v43 = *(unsigned __int8 *)(cmpt_obj + 178), *(_BYTE *)(cmpt_obj + 178)) )
      {
        BYTE4(v63[0]) = *(_BYTE *)(cmpt_obj + 178);
        qdf_mem_copy((char *)v63 + 5, (const void *)(cmpt_obj + 145), v43);
        v44 = *((_WORD *)a2 + 2);
        v45 = *(_DWORD *)a2;
        HIDWORD(v61) = a3;
        v46 = *(_QWORD *)(a1 + 216);
        *(_WORD *)((char *)&v63[5] + 1) = v44;
        *(_DWORD *)((char *)&v63[4] + 5) = v45;
        LODWORD(v63[0]) = **(unsigned __int16 **)(v33 + 32);
        result = scm_scan_update_mlme_by_bssinfo(v46, (__int64)v63, v60, v47, v48, v49, v50, v51, v52, v53, v54);
      }
      else
      {
        result = qdf_trace_msg(
                   0x8Fu,
                   8u,
                   "%s: vdev %d failed to get ssid",
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   "mlo_link_recfg_update_scan_mlme",
                   *(unsigned __int8 *)(v23 + 168));
      }
    }
    else
    {
      if ( a2 )
      {
        v56 = *a2;
        v57 = a2[1];
        v58 = a2[2];
        v59 = a2[5];
      }
      else
      {
        v58 = 0;
        v56 = 0;
        v57 = 0;
        v59 = 0;
      }
      result = qdf_trace_msg(
                 0x8Fu,
                 8u,
                 "%s: link info null ap link addr %02x:%02x:%02x:**:**:%02x",
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 "mlo_link_recfg_update_scan_mlme",
                 v56,
                 v57,
                 v58,
                 v59);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x8Fu,
               8u,
               "%s: assoc vdev null",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "mlo_link_recfg_update_scan_mlme");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
