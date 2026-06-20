__int64 __fastcall mlo_process_ml_reconfig_ie(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x1
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  unsigned int *v44; // x8
  const char *v45; // x2
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w8
  unsigned int v55; // w9
  __int64 v56; // x12
  int v57; // w10
  __int64 v58; // x22
  int v59; // w20
  __int64 v60; // x28
  unsigned __int64 v61; // x27
  __int64 v62; // x25
  __int64 v63; // x23
  __int64 v64; // x24
  int v65; // w21
  __int64 v66; // x26
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  _QWORD *scan_result; // x25
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x8
  unsigned int v93; // w24
  __int64 v94; // x9
  __int64 v95; // x8
  _DWORD *v96; // x9
  __int64 v97; // x26
  __int64 v98; // x25
  unsigned int multiplier; // w23
  __int64 v100; // x0
  __int64 v101; // [xsp+0h] [xbp-60h]
  unsigned __int64 v102; // [xsp+8h] [xbp-58h] BYREF
  unsigned __int8 *v103; // [xsp+10h] [xbp-50h] BYREF
  unsigned __int16 v104[2]; // [xsp+18h] [xbp-48h] BYREF
  unsigned __int16 v105; // [xsp+1Ch] [xbp-44h] BYREF
  __int64 v106; // [xsp+20h] [xbp-40h] BYREF
  _QWORD v107[3]; // [xsp+28h] [xbp-38h] BYREF
  int v108; // [xsp+40h] [xbp-20h]
  __int64 v109; // [xsp+48h] [xbp-18h] BYREF
  __int64 v110; // [xsp+50h] [xbp-10h]
  __int64 v111; // [xsp+58h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v109 = 0;
  v110 = 0;
  v104[0] = 0;
  v108 = 0;
  memset(v107, 0, sizeof(v107));
  v102 = 0;
  v103 = nullptr;
  if ( !result )
    goto LABEL_24;
  v12 = result;
  if ( *(_DWORD *)(result + 16) )
    goto LABEL_24;
  result = wlan_vdev_mlme_is_mlo_vdev(result, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (result & 1) == 0 )
    goto LABEL_24;
  v24 = *(_QWORD *)(v12 + 216);
  if ( !v24 || !*(_QWORD *)(v24 + 80) )
    goto LABEL_24;
  result = mlo_get_ml_vdev_list(v12, v104, (__int64)&v109, v16, v17, v18, v19, v20, v21, v22, v23);
  v34 = v104[0];
  if ( !v104[0] )
  {
    result = qdf_trace_msg(
               0x8Fu,
               8u,
               "%s: Number of VDEVs under MLD is reported as 0",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               "mlo_process_ml_reconfig_ie");
    goto LABEL_24;
  }
  if ( a2 )
  {
    if ( (unsigned int)*(unsigned __int8 *)(a2 + 1918) - 1 < 3 )
      goto LABEL_11;
    if ( *(_BYTE *)(a2 + 1918) )
      goto LABEL_63;
  }
  result = qdf_trace_msg(
             0x8Fu,
             8u,
             "%s: Unable to fetch the partner info in scan db",
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             "mlo_process_ml_reconfig_ie");
  v34 = v104[0];
LABEL_11:
  if ( v34 != 1 )
  {
    if ( (unsigned int)util_find_mlie_by_variant(a3, a4, &v103, &v102, 2) || !v103 )
    {
      v45 = "%s: ML IE for reconfig variant not found";
    }
    else
    {
      result = util_get_rvmlie_persta_link_info(v103, v102, v107, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( (_DWORD)result )
      {
        v43 = "%s: Unable to get persta link info from ML RV IE";
        goto LABEL_16;
      }
      v54 = BYTE6(v107[0]);
      if ( !BYTE6(v107[0]) )
      {
        v43 = "%s: No. of links is 0 in ML reconfig IE";
LABEL_16:
        result = qdf_trace_msg(0x8Fu, 2u, v43, v35, v36, v37, v38, v39, v40, v41, v42, "mlo_process_ml_reconfig_ie");
        v44 = (unsigned int *)v104[0];
        if ( !v104[0] )
          goto LABEL_24;
        goto LABEL_22;
      }
      v55 = v104[0];
      if ( !v104[0] )
      {
LABEL_58:
        result = mlo_sta_handle_link_reconfig_standby_link(v12, v107);
        v44 = (unsigned int *)v104[0];
        if ( !v104[0] )
          goto LABEL_24;
        goto LABEL_22;
      }
      v56 = 0;
      v57 = 1;
      while ( 1 )
      {
        v101 = v56;
        if ( v56 == 2 )
          goto LABEL_63;
        if ( (v56 & 0x1FFFFFFFFFFFFFFFLL) == 2 )
        {
LABEL_62:
          __break(1u);
          goto LABEL_63;
        }
        v58 = *(&v109 + v56);
        if ( !v58 )
          break;
        if ( v57 )
        {
          v59 = *(unsigned __int8 *)(v58 + 93);
          v60 = 0;
          v61 = 0;
          while ( 1 )
          {
            if ( v60 == 20 )
              goto LABEL_63;
            if ( v59 == *((unsigned __int8 *)&v107[1] + v60) )
              break;
LABEL_37:
            ++v61;
            v60 += 10;
            if ( v61 >= v54 )
            {
              v55 = v104[0];
              v56 = v101;
              v57 = v54;
              goto LABEL_29;
            }
          }
          result = wlan_vdev_mlme_get_cmpt_obj(v58, v35, v36, v37, v38, v39, v40, v41, v42);
          if ( !result )
            goto LABEL_36;
          v62 = *(_QWORD *)(v58 + 184);
          if ( !v62 )
            goto LABEL_36;
          if ( (unsigned __int64)(v60 - 12) < 0xFFFFFFFFFFFFFFE4LL )
            goto LABEL_62;
          v63 = result;
          v64 = *(_QWORD *)(v58 + 216);
          v65 = *(unsigned __int16 *)((char *)&v107[2] + v60);
          v106 = 0;
          v105 = v65;
          result = _qdf_mem_malloc(0x2D8u, "mlo_get_bcn_interval_by_bssid", 3095);
          if ( !result )
            goto LABEL_36;
          v66 = result;
          *(_BYTE *)(result + 16) = 1;
          qdf_mem_copy((void *)(result + 70), (const void *)(v62 + 48), 6u);
          scan_result = scm_get_scan_result(v64, v66, v67, v68, v69, v70, v71, v72, v73, v74);
          _qdf_mem_free(v66);
          if ( !scan_result )
          {
            result = qdf_trace_msg(
                       0x8Fu,
                       8u,
                       "%s: scan list empty",
                       v76,
                       v77,
                       v78,
                       v79,
                       v80,
                       v81,
                       v82,
                       v83,
                       "mlo_get_bcn_interval_by_bssid");
            goto LABEL_36;
          }
          if ( *((_DWORD *)scan_result + 4) )
          {
            qdf_list_peek_front(scan_result, &v106);
            if ( v106 )
            {
              v92 = *(_QWORD *)(v106 + 24);
              if ( v92 )
              {
                v93 = *(unsigned __int16 *)(v92 + 68);
                result = scm_purge_scan_results((__int64)scan_result, v84, v85, v86, v87, v88, v89, v90, v91);
                if ( v93 )
                {
                  v94 = *(_QWORD *)(v63 + 528);
                  v95 = v63;
                  if ( v94 && (v96 = *(_DWORD **)(v94 + 208)) != nullptr )
                  {
                    if ( *(v96 - 1) != 736215401 )
                      __break(0x8229u);
                    result = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, _QWORD))v96)(v63, &v105, v93);
                    if ( !(_DWORD)result )
                    {
                      v65 = v105;
                      v95 = v63;
                      goto LABEL_55;
                    }
                  }
                  else
                  {
LABEL_55:
                    v97 = v95;
                    *(_BYTE *)(v95 + 1008) = 1;
                    v98 = jiffies;
                    multiplier = qdf_timer_get_multiplier();
                    v100 = _msecs_to_jiffies((unsigned int)((int)((v93 * v65) << 10) / 1000));
                    result = mod_timer(v97 + 952, v98 + v100 * multiplier);
                  }
                }
LABEL_36:
                v54 = BYTE6(v107[0]);
                goto LABEL_37;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: scan list empty",
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              "mlo_get_bcn_interval_by_bssid");
          }
          result = scm_purge_scan_results((__int64)scan_result, v84, v85, v86, v87, v88, v89, v90, v91);
          goto LABEL_36;
        }
LABEL_29:
        if ( v55 <= (unsigned __int16)++v56 )
          goto LABEL_58;
      }
      v45 = "%s: VDEV in MLD VDEV list is NULL";
    }
    result = qdf_trace_msg(0x8Fu, 8u, v45, v35, v36, v37, v38, v39, v40, v41, v42, "mlo_process_ml_reconfig_ie", v101);
  }
  v44 = (unsigned int *)v104[0];
  if ( !v104[0] )
  {
LABEL_24:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_22:
  result = mlo_release_vdev_ref(v109, v44, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( v104[0] < 2u )
    goto LABEL_24;
  result = mlo_release_vdev_ref(v110, (unsigned int *)v104[0], v46, v47, v48, v49, v50, v51, v52, v53);
  if ( v104[0] <= 2u )
    goto LABEL_24;
LABEL_63:
  __break(0x5512u);
  return mlo_sta_handle_link_reconfig_standby_link(result, v25);
}
