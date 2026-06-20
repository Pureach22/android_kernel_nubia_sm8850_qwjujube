__int64 __fastcall cm_roam_result_info_event(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int64 v18; // x25
  _BOOL4 v19; // w24
  _BOOL4 v20; // w8
  int v21; // w5
  __int16 v22; // w20
  unsigned int v23; // w26
  __int64 v24; // x0
  unsigned int v25; // w9
  int v26; // w12
  char v27; // w8
  unsigned __int64 v28; // x25
  int v29; // w8
  unsigned __int16 *v30; // x23
  __int64 v31; // x8
  unsigned __int64 v32; // x23
  unsigned int v33; // w21
  __int64 v34; // x0
  __int64 result; // x0
  int v36; // w28
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x24
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 assoc_link_vdev; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x25
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w24
  __int64 v75; // x0
  int v76; // w10
  int v77; // w24
  char v78; // w22
  int v79; // w21
  unsigned int v80; // w10
  char v81; // w9
  _BOOL4 v82; // [xsp+Ch] [xbp-64h]
  __int64 v83; // [xsp+10h] [xbp-60h] BYREF
  unsigned __int64 v84; // [xsp+18h] [xbp-58h]
  __int64 v85; // [xsp+20h] [xbp-50h]
  __int64 v86; // [xsp+28h] [xbp-48h]
  int v87; // [xsp+30h] [xbp-40h]
  __int64 v88; // [xsp+38h] [xbp-38h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+40h] [xbp-30h]
  __int64 v90; // [xsp+48h] [xbp-28h]
  __int64 v91; // [xsp+50h] [xbp-20h]
  int v92; // [xsp+58h] [xbp-18h]
  __int64 v93; // [xsp+68h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(unsigned int *)(a3 + 12);
  v19 = v18 < 0x21;
  v20 = *(_BYTE *)a4 == 1 && *(unsigned __int16 *)(a4 + 2) == 1;
  v87 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  if ( (_DWORD)v18 == 36 )
  {
    v21 = *(_DWORD *)(a3 + 16);
    if ( v21 == 5 )
    {
      v22 = 37;
    }
    else
    {
      if ( v21 != 6 )
      {
        result = qdf_trace_msg(
                   0x68u,
                   8u,
                   "%s: vdev:%d Unsupported abort reason:%d",
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   "cm_roam_result_info_event",
                   (unsigned __int8)a5);
        goto LABEL_49;
      }
      v22 = 38;
    }
    v33 = *(_DWORD *)(a3 + 4);
    v92 = 0;
    v90 = 0;
    v91 = 0;
    v88 = 0;
    time_of_the_day_us = 0;
    qdf_mem_set(&v88, 0x24u, 0);
    HIWORD(v88) = (unsigned __int8)a5;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v34 = ktime_get();
    LOBYTE(v92) = 2;
    HIWORD(v92) = v22;
    v90 = 1000LL * v33;
    v91 = v34 / 1000;
    result = host_diag_event_report_payload(3360, 36, &v88);
  }
  else
  {
    v82 = v20;
    qdf_mem_set(&v83, 0x24u, 0);
    v23 = *(_DWORD *)(a3 + 4);
    HIWORD(v83) = (unsigned __int8)a5;
    v84 = qdf_get_time_of_the_day_us();
    v24 = ktime_get();
    LOBYTE(v87) = 2;
    v26 = *(_DWORD *)(a3 + 8);
    v25 = *(_DWORD *)(a3 + 12);
    HIWORD(v87) = v25;
    v27 = BYTE1(v87);
    v85 = 1000LL * v23;
    v86 = v24 / 1000;
    BYTE1(v87) |= 1u;
    if ( v26 == 2 || v25 <= 0x2A && ((1LL << v25) & 0x70E0000000CLL) != 0 )
      BYTE1(v87) = v27 & 0xFE;
    v28 = 0x118002010uLL >> v18;
    if ( *(_WORD *)(a4 + 4) )
    {
      LOWORD(v29) = *(_WORD *)(a4 + 4) - 1;
      v30 = (unsigned __int16 *)(a4 + 97);
      if ( (v29 & 0xFFF8) != 0 )
        v29 = 8;
      else
        v29 = (unsigned __int16)v29;
      v31 = (unsigned int)(v29 + 1);
      while ( *((_BYTE *)v30 - 1) != 1 )
      {
        --v31;
        v30 += 30;
        if ( !v31 )
          goto LABEL_19;
      }
      qdf_mem_copy(&v83, v30, 6u);
      v32 = *(unsigned int *)v30 | ((unsigned __int64)v30[2] << 32);
    }
    else
    {
LABEL_19:
      v32 = 0;
    }
    if ( *(_DWORD *)(a3 + 20) | *(unsigned __int16 *)(a3 + 24) )
      qdf_mem_copy(&v83, (const void *)(a3 + 20), 6u);
    v36 = v19 & v28;
    if ( (v87 & 0x100) == 0 )
    {
      WORD2(v88) = 0;
      LODWORD(v88) = 0;
      v37 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a5, 77);
      if ( v37 )
      {
        v46 = v37;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v37, v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0 )
        {
          BYTE1(v87) |= 2u;
          assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v46);
          if ( assoc_link_vdev )
          {
            v65 = assoc_link_vdev;
            if ( (unsigned int)wlan_vdev_get_bss_peer_mac(assoc_link_vdev, &v88, v57, v58, v59, v60, v61, v62, v63, v64) )
              qdf_trace_msg(
                0x68u,
                2u,
                "%s: vdev: %d bss peer not found",
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                "cm_populate_roam_success_mlo_param",
                *(unsigned __int8 *)(v65 + 168));
            else
              qdf_mem_copy(&v83, &v88, 6u);
          }
          else
          {
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: assoc vdev not found",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "cm_populate_roam_success_mlo_param");
          }
        }
        wlan_objmgr_vdev_release_ref(v46, 0x4Du, v47, v48, v49, v50, v51, v52, v53, v54, v55);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev: %d not found",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "cm_populate_roam_success_mlo_param",
          (unsigned __int8)a5);
      }
    }
    host_diag_event_report_payload(3359, 36, &v83);
    qdf_mem_set(&v83, 0x24u, 0);
    if ( v36 )
    {
      v74 = *(_DWORD *)(a3 + 4);
      HIWORD(v83) = (unsigned __int8)a5;
      v84 = qdf_get_time_of_the_day_us();
      v75 = ktime_get();
      v76 = *(_DWORD *)(a3 + 12);
      v85 = 1000LL * v74;
      v86 = v75 / 1000;
      HIWORD(v87) = v76;
      host_diag_event_report_payload(3360, 36, &v83);
    }
    v77 = *(unsigned __int8 *)(a2 + 4);
    v78 = BYTE1(v87);
    v79 = *(_DWORD *)(a3 + 12);
    LOBYTE(v88) = 0;
    result = wlan_mlme_get_bmiss_skip_full_scan_value(a1, &v88);
    if ( v77 == 2 && (v78 & 1) == 0 )
    {
      v80 = (unsigned __int8)v79 - 33;
      if ( !v82 || (_BYTE)v88 )
      {
        v81 = v82;
        if ( v80 > 1 )
          v81 = 1;
        if ( (v81 & 1) != 0 || (v88 & 1) == 0 )
          goto LABEL_49;
      }
      else if ( v80 > 1 )
      {
        goto LABEL_49;
      }
      result = cm_roam_beacon_loss_disconnect_event(a1, v32, a5);
    }
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
