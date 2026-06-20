__int64 __fastcall sme_get_bss_transition_status(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        __int16 a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x23
  unsigned __int8 *v17; // x19
  unsigned int result_for_bssid; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w21
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x26
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
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
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  char *v70; // x21
  __int64 v71; // x24
  __int64 v72; // x9
  int v73; // w8
  __int64 v74; // x4
  __int64 v75; // x5
  __int64 v76; // x6
  __int64 v77; // x7
  __int64 v78; // x22
  unsigned int v79; // w26
  unsigned int v80; // w28
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v89; // w8
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  char v98; // w28
  char v99; // w0
  _QWORD *v100; // x0
  __int64 v102; // x4
  __int64 v103; // x5
  __int64 v104; // x6
  __int64 v105; // x7
  __int64 v106; // [xsp+0h] [xbp-30h]
  int v108; // [xsp+Ch] [xbp-24h]
  __int64 v109; // [xsp+10h] [xbp-20h] BYREF
  _QWORD *v110; // [xsp+18h] [xbp-18h] BYREF
  _QWORD *v111[2]; // [xsp+20h] [xbp-10h] BYREF

  v111[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v111[0] = nullptr;
  v109 = 0;
  v110 = nullptr;
  if ( !a4 || (LOWORD(v14) = a5) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: No candidate info available",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "sme_get_bss_transition_status");
    v28 = 4;
    goto LABEL_47;
  }
  v17 = a4;
  result_for_bssid = csr_scan_get_result_for_bssid(a1, a3, v111);
  if ( result_for_bssid )
  {
    v28 = result_for_bssid;
    if ( a3 )
    {
      v29 = *a3;
      v30 = a3[1];
      v31 = a3[2];
      v32 = a3[5];
    }
    else
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: connected BSS: %02x:%02x:%02x:**:**:%02x not present in scan db",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "sme_get_bss_transition_status",
      v29,
      v30,
      v31,
      v32);
    v100 = v111[0];
    if ( !v111[0] )
      goto LABEL_45;
    goto LABEL_44;
  }
  qdf_list_peek_front(v111[0], &v109);
  v41 = v109;
  if ( v109 )
  {
    v14 = (unsigned __int16)v14;
    v108 = a2;
    while ( 1 )
    {
      if ( (unsigned int)csr_scan_get_result_for_bssid(a1, v17, &v110) )
      {
        if ( v17 )
        {
          v42 = *v17;
          v43 = v17[1];
          v44 = v17[2];
          v45 = v17[5];
        }
        else
        {
          v44 = 0;
          v42 = 0;
          v43 = 0;
          v45 = 0;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: BSS %02x:%02x:%02x:**:**:%02x not present in scan db",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "sme_get_bss_transition_status",
          v42,
          v43,
          v44,
          v45);
        *((_DWORD *)v17 + 2) = 6;
        goto LABEL_11;
      }
      v109 = 0;
      qdf_list_peek_front(v110, &v109);
      if ( !v109 )
      {
        if ( v17 )
        {
          v74 = *v17;
          v75 = v17[1];
          v76 = v17[2];
          v77 = v17[5];
        }
        else
        {
          v76 = 0;
          v74 = 0;
          v75 = 0;
          v77 = 0;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Failed to peek candidate: %02x:%02x:%02x:**:**:%02x",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "sme_get_bss_transition_status",
          v74,
          v75,
          v76,
          v77);
        goto LABEL_41;
      }
      v70 = *(char **)(a1 + 8);
      if ( v70 )
      {
        v71 = *(__int64 *)((char *)&off_18 + v109);
        v72 = *(_QWORD *)(v41 + 24);
        if ( *(char *)(v71 + 60) < v70[2816] && *(char *)(v72 + 60) > v70[2817] )
        {
          LODWORD(v106) = *(char *)(v71 + 60);
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Candidate BSS %02x:%02x:%02x:**:**:%02x has LOW RSSI(%d), hence reject",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            "sme_get_status_for_candidate",
            *(unsigned __int8 *)(v71 + 1),
            *(unsigned __int8 *)(v71 + 2),
            *(unsigned __int8 *)(v71 + 3),
            *(unsigned __int8 *)(v71 + 6),
            v106);
          v73 = 4;
LABEL_40:
          *((_DWORD *)v17 + 2) = v73;
          goto LABEL_41;
        }
        if ( v108 == 9 || v108 == 4 )
        {
          v78 = v41;
          v79 = *(_DWORD *)(v71 + 1192);
          v80 = *(_DWORD *)(v72 + 1192);
          if ( *(char *)(v72 + 60) > v70[2818] && (csr_is_mcc_channel(a1, v79) & 1) != 0 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Candidate BSS %02x:%02x:%02x:**:**:%02x causes MCC, hence reject",
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              "sme_get_status_for_candidate",
              *(unsigned __int8 *)(v71 + 1),
              *(unsigned __int8 *)(v71 + 2),
              *(unsigned __int8 *)(v71 + 3),
              *(unsigned __int8 *)(v71 + 6));
            v89 = 3;
LABEL_34:
            *((_DWORD *)v17 + 2) = v89;
            v41 = v78;
            goto LABEL_41;
          }
          if ( wlan_reg_is_5ghz_ch_freq(v80)
            && wlan_reg_is_24ghz_ch_freq(v79)
            && (a6 & 1) != 0
            && *(char *)(v71 + 60) < v70[2819] )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Candidate BSS %02x:%02x:%02x:**:**:%02x causes BT coex, hence reject",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "sme_get_status_for_candidate",
              *(unsigned __int8 *)(v71 + 1),
              *(unsigned __int8 *)(v71 + 2),
              *(unsigned __int8 *)(v71 + 3),
              *(unsigned __int8 *)(v71 + 6));
            v89 = 2;
            goto LABEL_34;
          }
          v98 = ((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*(_QWORD *)(a1 + 21624), v80);
          v99 = ((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*(_QWORD *)(a1 + 21624), v79);
          v41 = v78;
          if ( (v98 & 1) != 0 && (v99 & 1) == 0 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: High interference expected if transitioned to BSS %02x:%02x:%02x:**:**:%02x hence reject",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "sme_get_status_for_candidate",
              *(unsigned __int8 *)(v71 + 1),
              *(unsigned __int8 *)(v71 + 2),
              *(unsigned __int8 *)(v71 + 3),
              *(unsigned __int8 *)(v71 + 6));
            v73 = 5;
            goto LABEL_40;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: mlme cfg is NULL",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "sme_get_status_for_candidate");
      }
      *((_DWORD *)v17 + 2) = 0;
LABEL_41:
      scm_purge_scan_results((__int64)v110, v62, v63, v64, v65, v66, v67, v68, v69);
      v110 = nullptr;
LABEL_11:
      --v14;
      v17 += 12;
      if ( !v14 )
        goto LABEL_52;
    }
  }
  if ( a3 )
  {
    v102 = *a3;
    v103 = a3[1];
    v104 = a3[2];
    v105 = a3[5];
  }
  else
  {
    v104 = 0;
    v102 = 0;
    v103 = 0;
    v105 = 0;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Failed to peek connected BSS : %02x:%02x:%02x:**:**:%02x",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "sme_get_bss_transition_status",
    v102,
    v103,
    v104,
    v105);
LABEL_52:
  v28 = 0;
  v100 = v111[0];
  if ( !v111[0] )
    goto LABEL_45;
LABEL_44:
  scm_purge_scan_results((__int64)v100, v46, v47, v48, v49, v50, v51, v52, v53);
LABEL_45:
  if ( v110 )
    scm_purge_scan_results((__int64)v110, v46, v47, v48, v49, v50, v51, v52, v53);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v28;
}
