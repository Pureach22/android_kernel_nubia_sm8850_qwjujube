__int64 __fastcall sap_channel_sel(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x26
  __int64 result; // x0
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w21
  __int64 v31; // x25
  __int64 v32; // x0
  unsigned int v33; // w23
  __int64 v34; // x22
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int scan_id; // w0
  int v53; // w9
  unsigned int v54; // w20
  unsigned __int8 v55; // w8
  unsigned int *v56; // x27
  int v57; // w11
  __int64 v58; // x8
  __int64 v59; // x24
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x9
  unsigned __int64 v69; // x25
  unsigned int v70; // w26
  unsigned int *v71; // x20
  unsigned int v72; // w24
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w23
  unsigned __int64 time_of_the_day_ms; // x0
  int v83; // w0
  __int64 v84; // x10
  _DWORD *v85; // x9
  signed __int64 v86; // x8
  int v87; // w8
  int v88; // w9
  unsigned int v89; // w11
  unsigned int v90; // w13
  __int64 v91; // x14
  __int64 v92; // x15
  unsigned int v93; // w16
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned int v102; // w0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x21
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  unsigned int v120; // w0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned int *v129; // x8
  unsigned int v130; // w20
  _QWORD *v131; // [xsp+8h] [xbp-48h]
  unsigned int v132; // [xsp+10h] [xbp-40h]
  unsigned int v133; // [xsp+14h] [xbp-3Ch]
  __int64 v134; // [xsp+18h] [xbp-38h]
  _DWORD *v135; // [xsp+20h] [xbp-30h]
  unsigned int v136; // [xsp+2Ch] [xbp-24h]
  __int64 v137; // [xsp+30h] [xbp-20h]
  unsigned __int16 v138; // [xsp+3Ch] [xbp-14h] BYREF
  _QWORD v139[2]; // [xsp+40h] [xbp-10h] BYREF

  v139[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v139[0] = 0;
  v138 = 0;
  context = _cds_get_context(52, (__int64)"sap_channel_sel", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    if ( a1[182] == 2 || !*a1 )
    {
      if ( policy_mgr_concurrent_beaconing_sessions_running(context[2703])
        || *((_BYTE *)a1 + 1560) == 5
        && ((unsigned int)policy_mgr_mode_specific_connection_count(v19[2703], 1, nullptr)
         || (unsigned int)policy_mgr_mode_specific_connection_count(v19[2703], 3, nullptr)) )
      {
        sme_get_beaconing_concurrent_operation_channel(v19, *((unsigned __int8 *)a1 + 12));
      }
      if ( (unsigned int)policy_mgr_get_concurrency_mode(v19[2703]) != 3 && *((_BYTE *)a1 + 1560) == 5 )
        policy_mgr_get_concurrency_mode(v19[2703]);
      v21 = *((_QWORD *)a1 + 186);
      if ( v21 )
      {
        _qdf_mem_free(v21);
        *((_QWORD *)a1 + 186) = 0;
        *((_BYTE *)a1 + 1496) = 0;
      }
      sap_get_freq_list(a1, v139, &v138);
      v30 = v138;
      if ( v138 && (v31 = v139[0]) != 0 )
      {
        v32 = _qdf_mem_malloc(0x8F0u, "sap_channel_sel", 1697);
        if ( v32 )
        {
          v33 = *((unsigned __int8 *)a1 + 12);
          v34 = v32;
          v35 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                  v19[2703],
                  *((unsigned __int8 *)a1 + 12),
                  11);
          if ( v35 )
          {
            v134 = v35;
            wlan_scan_init_default_params(v35, (__int64 *)v34, v36, v37, v38, v39, v40, v41, v42, v43);
            scan_id = wlan_scan_get_scan_id(v19[2703], v44, v45, v46, v47, v48, v49, v50, v51);
            v53 = *(_DWORD *)(v34 + 92);
            *(_DWORD *)(v34 + 16) = v33;
            v54 = 0;
            *(_DWORD *)(v34 + 8) = scan_id;
            v55 = 0;
            v53 &= ~1u;
            v132 = scan_id;
            v133 = v33;
            v56 = (unsigned int *)(v34 + 124);
            *(_DWORD *)(v34 + 92) = v53;
            v57 = *((unsigned __int16 *)a1 + 820);
            *(_DWORD *)(v34 + 24) = 3;
            *(_DWORD *)(v34 + 92) = v53 | 2;
            *(_DWORD *)(v34 + 12) = v57;
            do
            {
              v59 = v55;
              if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v31 + 4LL * v55))
                || (wlan_reg_is_6ghz_psc_chan_freq(*(_DWORD *)(v31 + 4 * v59), v60, v61, v62, v63, v64, v65, v66, v67)
                  & 1) != 0 )
              {
                if ( v54 >= 0x66 )
                  goto LABEL_69;
                v58 = 3LL * v54++;
                v56[v58] = *(_DWORD *)(v31 + 4 * v59);
              }
              v55 = v59 + 1;
            }
            while ( v30 > (unsigned __int8)(v59 + 1) );
            *(_BYTE *)(v34 + 120) = v54;
            v68 = *((_QWORD *)a1 + 193);
            *((_QWORD *)a1 + 186) = v31;
            *((_BYTE *)a1 + 1496) = v30;
            *((_BYTE *)a1 + 1778) = 0;
            *(_QWORD *)((char *)a1 + 1779) = 0;
            *(_QWORD *)((char *)a1 + 1787) = 0;
            *(_QWORD *)((char *)a1 + 1795) = 0;
            *(_QWORD *)((char *)a1 + 1803) = 0;
            *(_QWORD *)((char *)a1 + 1811) = 0;
            *(_QWORD *)((char *)a1 + 1819) = 0;
            *(_QWORD *)((char *)a1 + 1827) = 0;
            *(_QWORD *)((char *)a1 + 1835) = 0;
            *(_QWORD *)((char *)a1 + 1843) = 0;
            *(_QWORD *)((char *)a1 + 1851) = 0;
            *(_QWORD *)((char *)a1 + 1859) = 0;
            *(_QWORD *)((char *)a1 + 1867) = 0;
            *(_QWORD *)((char *)a1 + 1873) = 0;
            if ( *(_DWORD *)(v68 + 592) )
            {
              *((_BYTE *)a1 + 1777) = 0;
              v137 = _qdf_mem_malloc(0x96u, "sap_acs_scan_freq_list_optimize", 1539);
              if ( v137 )
              {
                v131 = v19;
                if ( *(_BYTE *)(v34 + 120) )
                {
                  v69 = 0;
                  v70 = 0;
                  v135 = (_DWORD *)(v34 + 124);
                  v136 = *(_DWORD *)(*((_QWORD *)a1 + 193) + 592LL);
                  do
                  {
                    if ( v69 == 102 )
                      goto LABEL_69;
                    v71 = &v56[3 * v69];
                    while ( 1 )
                    {
                      v72 = ((__int64 (__fastcall *)(_QWORD, _QWORD))scm_get_last_scan_time_per_channel)(
                              *((_QWORD *)a1 + 2),
                              *v71);
                      if ( (__int64)(qdf_get_time_of_the_day_ms() - (v72 + v136)) >= 0 )
                        break;
                      v81 = *v71;
                      time_of_the_day_ms = qdf_get_time_of_the_day_ms();
                      v73 = scnprintf(v137 + v70, 150 - v70, "%d[%lu] ", v81, time_of_the_day_ms - v72);
                      v70 += v83;
                      if ( v70 >= 0x78 )
                      {
                        qdf_trace_msg(
                          0x39u,
                          8u,
                          "ACS Skip scan freq with age less than %d: %s",
                          v73,
                          v74,
                          v75,
                          v76,
                          v77,
                          v78,
                          v79,
                          v80,
                          v136,
                          v137);
                        v70 = 0;
                      }
                      v84 = *(unsigned __int8 *)(v34 + 120);
                      if ( (__int64)v69 < v84 - 1 )
                      {
                        v85 = v135;
                        v86 = v69;
                        while ( v86 != 101 )
                        {
                          ++v86;
                          *v85 = v85[3];
                          v84 = *(unsigned __int8 *)(v34 + 120);
                          v85 += 3;
                          if ( v86 >= v84 - 1 )
                            goto LABEL_34;
                        }
LABEL_69:
                        __break(0x5512u);
                      }
LABEL_34:
                      *(_BYTE *)(v34 + 120) = v84 - 1;
                      *((_BYTE *)a1 + 1777) = 1;
                      if ( *(unsigned __int8 *)(v34 + 120) <= (unsigned int)(unsigned __int8)v69 )
                        goto LABEL_44;
                    }
                    ++v69;
                    v135 += 3;
                  }
                  while ( v69 < *(unsigned __int8 *)(v34 + 120) );
LABEL_44:
                  if ( v70 )
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "ACS Skip scan freq with age time %d: %s",
                      v73,
                      v74,
                      v75,
                      v76,
                      v77,
                      v78,
                      v79,
                      v80,
                      v136,
                      v137);
                }
                _qdf_mem_free(v137);
                if ( *(_BYTE *)(v34 + 120) )
                {
                  v19 = v131;
                  v87 = *(unsigned __int8 *)(v34 + 120) - 1;
                  if ( *(_BYTE *)(v34 + 120) != 1 )
                  {
                    v88 = 0;
                    v89 = *(unsigned __int8 *)(v34 + 120) - 1;
                    while ( v88 >= v87 )
                    {
LABEL_49:
                      ++v88;
                      --v89;
                      if ( v88 == v87 )
                        goto LABEL_60;
                    }
                    v90 = *v56;
                    v91 = 0;
                    while ( v91 != 1212 )
                    {
                      v92 = v34 + v91;
                      v93 = *(_DWORD *)(v34 + v91 + 136);
                      if ( v90 < v93 )
                      {
                        *(_DWORD *)(v92 + 124) = v93;
                        *(_DWORD *)(v92 + 136) = v90;
                      }
                      else
                      {
                        v90 = *(_DWORD *)(v34 + v91 + 136);
                      }
                      v91 += 12;
                      if ( 12LL * v89 == v91 )
                        goto LABEL_49;
                    }
                    goto LABEL_69;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x39u,
                    4u,
                    "%s: All ACS freq channels are scanned recently, skip ACS scan",
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    "sap_acs_scan_freq_list_optimize");
                  v19 = v131;
                }
              }
            }
LABEL_60:
            if ( *(_BYTE *)(v34 + 120) )
            {
              *(_BYTE *)(*((_QWORD *)a1 + 193) + 588LL) = 0;
              *((_QWORD *)a1 + 194) = qdf_get_time_of_the_day_ms();
              v102 = wlan_scan_start((__int64 *)v34, v94, v95, v96, v97, v98, v99, v100, v101);
              v111 = v134;
              if ( v102 )
              {
                qdf_trace_msg(
                  0x39u,
                  4u,
                  "%s: scan request fail %d SAP Configuring default ch, Ch_freq=%d",
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  "sap_channel_sel",
                  v102,
                  *a1);
                v120 = sap_select_default_oper_chan(v19, (__int64)a1, v112, v113, v114, v115, v116, v117, v118, v119);
                wlansap_set_acs_ch_freq(v19, a1, v120);
                v129 = *((unsigned int **)a1 + 186);
                if ( v129 )
                {
                  wlansap_set_acs_ch_freq(v19, a1, *v129);
                  _qdf_mem_free(*((_QWORD *)a1 + 186));
                  *((_QWORD *)a1 + 186) = 0;
                  v130 = 16;
                  *((_BYTE *)a1 + 1496) = 0;
                }
                else
                {
                  v130 = 16;
                }
              }
              else
              {
                host_log_acs_scan_start(v132, v133);
                v130 = 0;
              }
            }
            else
            {
              qdf_trace_msg(
                0x39u,
                4u,
                "%s: ## SKIPPED ACS SCAN",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "sap_channel_sel");
              *(_BYTE *)(*((_QWORD *)a1 + 193) + 588LL) = 1;
              wlansap_pre_start_bss_acs_scan_callback((__int64)v19, a1, *((unsigned __int8 *)a1 + 12), 0, 0);
              _qdf_mem_free(v34);
              v111 = v134;
              v130 = 0;
            }
            wlan_objmgr_vdev_release_ref(v111, 0xBu, v129, v121, v122, v123, v124, v125, v126, v127, v128);
            result = v130;
          }
          else
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: Invalid vdev objmgr",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "sap_channel_sel");
            _qdf_mem_free(v31);
            _qdf_mem_free(v34);
            result = 4;
          }
        }
        else
        {
          _qdf_mem_free(v31);
          result = 2;
        }
      }
      else
      {
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: No freq sutiable for SAP in current list, SAP failed",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "sap_channel_sel");
        result = 16;
      }
    }
    else
    {
      result = sap_validate_chan(a1, 1, 0, v11, v12, v13, v14, v15, v16, v17, v18);
    }
  }
  else
  {
    result = 5;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
