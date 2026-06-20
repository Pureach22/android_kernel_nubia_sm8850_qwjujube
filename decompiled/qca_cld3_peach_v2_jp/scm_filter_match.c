__int64 __fastcall scm_filter_match(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  size_t v24; // x2
  unsigned int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  size_t v34; // x2
  size_t v35; // x2
  size_t v36; // x2
  size_t v37; // x2
  size_t v38; // x2
  bool v39; // zf
  bool v40; // zf
  int v41; // w8
  __int64 v42; // x9
  unsigned __int16 *v43; // x11
  unsigned __int16 *v44; // x12
  int v46; // w13
  int v47; // w12
  __int64 v49; // x4
  __int64 v50; // x5
  const char *v51; // x2
  __int64 v52; // x6
  __int64 v53; // x7
  __int64 result; // x0
  unsigned __int64 v55; // x23
  __int64 v56; // x24
  unsigned int v57; // w21
  unsigned int v58; // w22
  unsigned int v59; // w23
  unsigned int v60; // w24
  __int64 v61; // x19
  __int64 system_time; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w9
  unsigned int v72; // w1
  __int64 pdev_by_id; // x0
  unsigned __int64 is_freq_in_nol; // x8
  __int64 v75; // x23
  __int64 v76; // x9
  int v77; // w12
  __int64 (__fastcall *v78)(__int64, __int64); // x8
  __int64 v79; // x0
  _DWORD *v80; // x8
  __int64 v81; // x0
  __int64 v82; // x9
  __int64 v83; // x0
  unsigned int *v84; // x8
  __int64 v85; // [xsp+0h] [xbp-50h]
  __int64 v86; // [xsp+8h] [xbp-48h]

  _ReadStatusReg(SP_EL0);
  if ( (*a3 & 0x100) != 0 )
  {
    result = *(_DWORD *)(a2 + 1116) != 2;
LABEL_139:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( !a1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_scan_psoc_get_def_params");
    goto LABEL_138;
  }
  if ( !wlan_objmgr_psoc_get_comp_private_obj(a1, 3u) )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_scan_psoc_get_def_params",
      878);
    goto LABEL_138;
  }
  v24 = *(unsigned __int8 *)(a2 + 13);
  if ( !*(_BYTE *)(a2 + 13) )
    goto LABEL_30;
  v25 = *((unsigned __int8 *)a3 + 17);
  if ( !*((_BYTE *)a3 + 17) )
    goto LABEL_30;
  if ( *((unsigned __int8 *)a3 + 100) == (_DWORD)v24 )
  {
    if ( !(unsigned int)qdf_mem_cmp((char *)a3 + 101, (const void *)(a2 + 14), v24) )
      goto LABEL_45;
    v25 = *((unsigned __int8 *)a3 + 17);
  }
  if ( v25 < 2 )
    goto LABEL_30;
  v34 = *((unsigned __int8 *)a3 + 133);
  if ( (_DWORD)v34 == *(unsigned __int8 *)(a2 + 13) )
  {
    if ( !(unsigned int)qdf_mem_cmp(a3 + 67, (const void *)(a2 + 14), v34) )
      goto LABEL_45;
    v25 = *((unsigned __int8 *)a3 + 17);
  }
  if ( v25 < 3 )
    goto LABEL_30;
  v35 = *((unsigned __int8 *)a3 + 166);
  if ( (_DWORD)v35 == *(unsigned __int8 *)(a2 + 13) )
  {
    if ( !(unsigned int)qdf_mem_cmp((char *)a3 + 167, (const void *)(a2 + 14), v35) )
      goto LABEL_45;
    v25 = *((unsigned __int8 *)a3 + 17);
  }
  if ( v25 < 4 )
    goto LABEL_30;
  v36 = *((unsigned __int8 *)a3 + 199);
  if ( (_DWORD)v36 == *(unsigned __int8 *)(a2 + 13) )
  {
    if ( !(unsigned int)qdf_mem_cmp(a3 + 100, (const void *)(a2 + 14), v36) )
      goto LABEL_45;
    v25 = *((unsigned __int8 *)a3 + 17);
  }
  if ( v25 < 5 )
    goto LABEL_30;
  v37 = *((unsigned __int8 *)a3 + 232);
  if ( (_DWORD)v37 == *(unsigned __int8 *)(a2 + 13) )
  {
    if ( !(unsigned int)qdf_mem_cmp((char *)a3 + 233, (const void *)(a2 + 14), v37) )
      goto LABEL_45;
    v25 = *((unsigned __int8 *)a3 + 17);
  }
  if ( v25 < 6 )
    goto LABEL_30;
  v38 = *((unsigned __int8 *)a3 + 265);
  if ( (_DWORD)v38 == *(unsigned __int8 *)(a2 + 13) )
  {
    if ( !(unsigned int)qdf_mem_cmp(a3 + 133, (const void *)(a2 + 14), v38) )
      goto LABEL_45;
    v25 = *((unsigned __int8 *)a3 + 17);
  }
  if ( v25 <= 6 )
  {
LABEL_30:
    if ( (((__int64 (__fastcall *)(_QWORD))util_scan_is_hidden_ssid)(*(_QWORD *)(a2 + 1216)) & 1) != 0 )
    {
      if ( *((_DWORD *)a3 + 16) | a3[34] || (a3[23] & 0x40) != 0 )
      {
        if ( !(*((_DWORD *)a3 + 16) | a3[34])
          || (*((_DWORD *)a3 + 16) == -1 ? (v39 = (__int16)a3[34] == -1) : (v39 = 0),
              v39
           || (*((_DWORD *)a3 + 16) == *(_DWORD *)(a2 + 1) ? (v40 = a3[34] == *(unsigned __int16 *)(a2 + 5)) : (v40 = 0),
               v40)) )
        {
LABEL_45:
          v41 = *((unsigned __int8 *)a3 + 16);
          if ( *((_BYTE *)a3 + 16) )
          {
            v42 = 0;
            v43 = a3 + 35;
            while ( v42 != 18 )
            {
              v44 = &v43[v42];
              if ( !(*(_DWORD *)&v43[v42] | v43[v42 + 2]) )
                goto LABEL_64;
              if ( *(_DWORD *)v44 == -1 && (__int16)v44[2] == -1 )
                goto LABEL_64;
              v46 = *(_DWORD *)v44;
              v47 = v44[2];
              if ( v46 == *(_DWORD *)(a2 + 1) && v47 == *(unsigned __int16 *)(a2 + 5) )
                goto LABEL_64;
              v42 += 3;
              if ( 3LL * *((unsigned __int8 *)a3 + 16) == v42 )
              {
                if ( !*((_BYTE *)a3 + 16) )
                  goto LABEL_64;
                if ( *((_BYTE *)a3 + 17) )
                {
                  v49 = *(unsigned __int8 *)(a2 + 1);
                  v50 = *(unsigned __int8 *)(a2 + 2);
                  v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as BSSID not in list (no. of BSSID in list %d)";
                  v52 = *(unsigned __int8 *)(a2 + 3);
                  v53 = *(unsigned __int8 *)(a2 + 6);
                  goto LABEL_90;
                }
                goto LABEL_138;
              }
            }
            goto LABEL_140;
          }
LABEL_64:
          v55 = *((_QWORD *)a3 + 1);
          if ( v55 )
          {
            v56 = *(_QWORD *)(a2 + 88);
            if ( v55 < qdf_mc_timer_get_system_time() - v56 )
            {
              if ( *((_BYTE *)a3 + 16) || *((_BYTE *)a3 + 17) )
              {
                v57 = *(unsigned __int8 *)(a2 + 1);
                v58 = *(unsigned __int8 *)(a2 + 2);
                v59 = *(unsigned __int8 *)(a2 + 3);
                v60 = *(unsigned __int8 *)(a2 + 6);
                v61 = *(_QWORD *)(a2 + 88);
                system_time = qdf_mc_timer_get_system_time();
                qdf_trace_msg(
                  0x15u,
                  8u,
                  "%s: %02x:%02x:%02x:**:**:%02x: Ignore as age %lu ms is greater than threshold %lu ms",
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  "scm_filter_match",
                  v57,
                  v58,
                  v59,
                  v60,
                  system_time - v61,
                  *((_QWORD *)a3 + 1));
              }
              goto LABEL_138;
            }
          }
          v41 = *((_DWORD *)a3 + 7);
          if ( v41 <= 1 )
          {
            if ( !v41 )
              goto LABEL_84;
            if ( v41 != 1 )
              goto LABEL_83;
            if ( *(_QWORD *)(a2 + 1328) )
              goto LABEL_84;
          }
          else
          {
            switch ( v41 )
            {
              case 2:
                if ( *(_QWORD *)(a2 + 1432) )
                  goto LABEL_84;
                break;
              case 3:
                if ( *(_QWORD *)(a2 + 1568) )
                  goto LABEL_84;
                break;
              case 4:
                break;
              default:
LABEL_83:
                qdf_trace_msg(
                  0x15u,
                  8u,
                  "%s: Invalid dot11mode filter passed %d",
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "scm_check_dot11mode",
                  (unsigned int)v41);
LABEL_84:
                if ( (*a3 & 0x20) != 0 && wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 1064)) )
                {
                  if ( !*((_BYTE *)a3 + 16) && !*((_BYTE *)a3 + 17) )
                    goto LABEL_138;
                  v49 = *(unsigned __int8 *)(a2 + 1);
                  v50 = *(unsigned __int8 *)(a2 + 2);
                  v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as its on 6Ghz freq %d";
LABEL_89:
                  v52 = *(unsigned __int8 *)(a2 + 3);
                  v53 = *(unsigned __int8 *)(a2 + 6);
                  v41 = *(_DWORD *)(a2 + 1064);
                  goto LABEL_90;
                }
                pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, *(_BYTE *)(a2 + 1720), 0xCu);
                if ( !pdev_by_id )
                  goto LABEL_128;
                is_freq_in_nol = *a3;
                if ( (is_freq_in_nol & 0x10) != 0 )
                {
                  v75 = pdev_by_id;
                  is_freq_in_nol = (unsigned int)utils_dfs_is_freq_in_nol();
                  pdev_by_id = v75;
                  if ( (is_freq_in_nol & 1) != 0 )
                  {
                    wlan_objmgr_pdev_release_ref(
                      v75,
                      0xCu,
                      (unsigned int *)is_freq_in_nol,
                      v26,
                      v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33);
                    v49 = *(unsigned __int8 *)(a2 + 1);
                    v50 = *(unsigned __int8 *)(a2 + 2);
                    v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as chan in NOL list";
LABEL_136:
                    v52 = *(unsigned __int8 *)(a2 + 3);
                    v53 = *(unsigned __int8 *)(a2 + 6);
                    v72 = 8;
                    goto LABEL_137;
                  }
                }
                wlan_objmgr_pdev_release_ref(
                  pdev_by_id,
                  0xCu,
                  (unsigned int *)is_freq_in_nol,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33);
                if ( a3[9] )
                {
                  v76 = 0;
                  while ( v76 != 204 )
                  {
                    v77 = *(_DWORD *)&a3[v76 + 134];
                    if ( !v77 || v77 == *(_DWORD *)(a2 + 1064) )
                      goto LABEL_105;
                    v76 += 2;
                    if ( 2LL * a3[9] == v76 )
                    {
                      if ( !a3[9] )
                        goto LABEL_105;
                      if ( *((_BYTE *)a3 + 16) || *((_BYTE *)a3 + 17) )
                      {
                        v49 = *(unsigned __int8 *)(a2 + 1);
                        v50 = *(unsigned __int8 *)(a2 + 2);
                        v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as AP's freq %d is not in freq list";
                        goto LABEL_89;
                      }
                      goto LABEL_138;
                    }
                  }
                  goto LABEL_140;
                }
LABEL_105:
                if ( (*a3 & 2) != 0 )
                  goto LABEL_127;
                if ( (*a3 & 8) == 0 && !*((_QWORD *)a3 + 85) && (scm_is_security_match(a3, a2, a4) & 1) == 0 )
                {
                  v49 = *(unsigned __int8 *)(a2 + 1);
                  v50 = *(unsigned __int8 *)(a2 + 2);
                  v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as security profile didn't match";
                  goto LABEL_136;
                }
                v78 = *((__int64 (__fastcall **)(__int64, __int64))a3 + 85);
                if ( v78 )
                {
                  v79 = *((_QWORD *)a3 + 86);
                  if ( *((_DWORD *)v78 - 1) != 1010608622 )
                    __break(0x8228u);
                  if ( (v78(v79, a2) & 1) == 0 )
                  {
                    v49 = *(unsigned __int8 *)(a2 + 1);
                    v50 = *(unsigned __int8 *)(a2 + 2);
                    v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as custom security match failed";
                    goto LABEL_136;
                  }
                }
                v80 = *((_DWORD **)a3 + 87);
                if ( v80 )
                {
                  v81 = *((_QWORD *)a3 + 88);
                  if ( *(v80 - 1) != 867015098 )
                    __break(0x8228u);
                  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))v80)(v81, a2, 0) & 1) == 0 )
                  {
                    v49 = *(unsigned __int8 *)(a2 + 1);
                    v50 = *(unsigned __int8 *)(a2 + 2);
                    v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as CCX validateion failed";
                    goto LABEL_136;
                  }
                }
                v71 = *((_DWORD *)a3 + 5);
                if ( !v71 )
                {
LABEL_121:
                  if ( (scm_is_fils_config_match(a3, a2) & 1) == 0 )
                  {
                    v49 = *(unsigned __int8 *)(a2 + 1);
                    v50 = *(unsigned __int8 *)(a2 + 2);
                    v51 = "%s: %02x:%02x:%02x:**:**:%02x:Ignore as fils config didn't match";
                    goto LABEL_136;
                  }
                  if ( a3[18] )
                  {
                    v82 = *(_QWORD *)(a2 + 1560);
                    if ( !v82 || *(unsigned __int16 *)(v82 + 2) != a3[18] )
                    {
                      v49 = *(unsigned __int8 *)(a2 + 1);
                      v50 = *(unsigned __int8 *)(a2 + 2);
                      v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as mdie didn't match";
                      goto LABEL_136;
                    }
                  }
                  v83 = wlan_objmgr_get_pdev_by_id(a1, *(_BYTE *)(a2 + 1720), 0xCu);
                  if ( v83 )
                  {
                    wlan_objmgr_pdev_release_ref(v83, 0xCu, v84, v26, v27, v28, v29, v30, v31, v32, v33);
LABEL_127:
                    result = 1;
                    goto LABEL_139;
                  }
LABEL_128:
                  v49 = *(unsigned __int8 *)(a2 + 1);
                  v50 = *(unsigned __int8 *)(a2 + 2);
                  v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as pdev not found";
                  v52 = *(unsigned __int8 *)(a2 + 3);
                  v53 = *(unsigned __int8 *)(a2 + 6);
                  v72 = 2;
                  goto LABEL_137;
                }
                v41 = *(unsigned __int16 *)(a2 + 70);
                if ( v71 == 1 )
                {
                  if ( (v41 & 1) != 0 )
                    goto LABEL_121;
                }
                else if ( v71 == 2 && (v41 & 2) != 0 )
                {
                  goto LABEL_121;
                }
                v49 = *(unsigned __int8 *)(a2 + 1);
                v50 = *(unsigned __int8 *)(a2 + 2);
                v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as bss type didn't match cap_info %x bss_type %d";
                v52 = *(unsigned __int8 *)(a2 + 3);
                v53 = *(unsigned __int8 *)(a2 + 6);
LABEL_82:
                LODWORD(v86) = v71;
LABEL_90:
                v72 = 8;
                LODWORD(v85) = v41;
LABEL_137:
                qdf_trace_msg(
                  0x15u,
                  v72,
                  v51,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  "scm_filter_match",
                  v49,
                  v50,
                  v52,
                  v53,
                  v85,
                  v86);
                goto LABEL_138;
            }
          }
          v49 = *(unsigned __int8 *)(a2 + 1);
          v50 = *(unsigned __int8 *)(a2 + 2);
          v51 = "%s: %02x:%02x:%02x:**:**:%02x: Ignore as dot11mode %d didn't match phymode %d";
          v52 = *(unsigned __int8 *)(a2 + 3);
          v53 = *(unsigned __int8 *)(a2 + 6);
          v71 = *(_DWORD *)(a2 + 52);
          goto LABEL_82;
        }
      }
      if ( *((_DWORD *)a3 + 16) | a3[34] )
        qdf_trace_msg(
          0x15u,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x: Ignore hidden AP as key_mgmt 0x%x is not OWE or bssid hint: %02x:%02x:%02x:**:*"
          "*:%02x does not match",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "scm_ignore_ssid_check_for_hidden_bss",
          *(unsigned __int8 *)(a2 + 1),
          *(unsigned __int8 *)(a2 + 2),
          *(unsigned __int8 *)(a2 + 3),
          *(unsigned __int8 *)(a2 + 6),
          *((_DWORD *)a3 + 11),
          *((unsigned __int8 *)a3 + 64),
          *((unsigned __int8 *)a3 + 65),
          *((unsigned __int8 *)a3 + 66),
          *((unsigned __int8 *)a3 + 69));
    }
    if ( !*((_BYTE *)a3 + 17) )
      goto LABEL_45;
LABEL_138:
    result = 0;
    goto LABEL_139;
  }
LABEL_140:
  __break(0x5512u);
  return ((__int64 (*)(void))scm_is_security_match)();
}
