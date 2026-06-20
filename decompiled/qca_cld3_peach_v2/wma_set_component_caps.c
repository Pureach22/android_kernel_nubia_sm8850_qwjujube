__int64 __fastcall wma_set_component_caps(
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
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
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
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w0
  __int64 *v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 *v70; // x20
  char v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  char v80; // w21
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w21
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  int v130; // w1
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  char v139; // w0
  __int64 *v140; // x0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  char v149; // w0
  __int64 *v150; // x0
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  __int64 v159; // x21
  __int64 v160; // x21
  __int64 result; // x0
  _BYTE v162[8]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v163[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v164; // [xsp+18h] [xbp-8h]

  v164 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_set_pmo_caps", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    v162[1] = wmi_service_enabled(*context, 0x2Eu, v11, v12, v13, v14, v15, v16, v17, v18) & 1;
    v162[0] = wmi_service_enabled(*v19, 0x6Du, v20, v21, v22, v23, v24, v25, v26, v27) & 1;
    v162[2] = wmi_service_enabled(*v19, 0x59u, v28, v29, v30, v31, v32, v33, v34, v35) & 1;
    v162[3] = wmi_service_enabled(*v19, 0x6Bu, v36, v37, v38, v39, v40, v41, v42, v43) & 1;
    v162[4] = wmi_service_enabled(*v19, 0x9Cu, v44, v45, v46, v47, v48, v49, v50, v51) & 1;
    v162[5] = wmi_service_enabled(*v19, 0x9Du, v52, v53, v54, v55, v56, v57, v58, v59) & 1;
    v60 = ucfg_pmo_psoc_set_caps(a1, v162);
    if ( v60 )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to set PMO capabilities; status:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wma_set_pmo_caps",
        v60);
  }
  v61 = _cds_get_context(54, (__int64)"wma_set_mlme_caps", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( v61 )
  {
    v70 = v61;
    v71 = wmi_service_enabled(*v61, 0xB4u, v62, v63, v64, v65, v66, v67, v68, v69);
    if ( (unsigned int)ucfg_mlme_set_tgt_adaptive_11r_cap(a1, v71 & 1) )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to set adaptive 11r cap",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "wma_set_mlme_caps");
    v80 = wmi_service_enabled(*v70, 0xB1u, v72, v73, v74, v75, v76, v77, v78, v79);
    if ( (wmi_service_enabled(*v70, 0xB2u, v81, v82, v83, v84, v85, v86, v87, v88) & 1) != 0 )
      v97 = v80 & 1 | 2;
    else
      v97 = v80 & 1;
    if ( (wmi_service_enabled(*v70, 0xB3u, v89, v90, v91, v92, v93, v94, v95, v96) & 1) != 0 )
      v97 |= 4u;
    if ( (wmi_service_enabled(*v70, 0xBDu, v98, v99, v100, v101, v102, v103, v104, v105) & 1) != 0 )
      v97 |= 0x10u;
    if ( (wmi_service_enabled(*v70, 0xBCu, v106, v107, v108, v109, v110, v111, v112, v113) & 1) != 0 )
      v97 |= 8u;
    if ( (wmi_service_enabled(*v70, 0xCFu, v114, v115, v116, v117, v118, v119, v120, v121) & 1) != 0 )
      v97 |= 0x20u;
    if ( (wmi_service_enabled(*v70, 0x120u, v122, v123, v124, v125, v126, v127, v128, v129) & 1) != 0 )
      v130 = v97 | 0x40;
    else
      v130 = v97;
    if ( (unsigned int)mlme_set_tgt_wpa3_roam_cap(a1, v130) )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to set sae roam support",
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        "wma_set_mlme_caps");
    v139 = wmi_service_enabled(*v70, 0x14Bu, v131, v132, v133, v134, v135, v136, v137, v138);
    ucfg_mlme_set_mrsno_support(a1, v139 & 1);
  }
  v140 = _cds_get_context(54, (__int64)"wma_set_mc_cp_caps", v62, v63, v64, v65, v66, v67, v68, v69);
  if ( v140 )
  {
    v149 = wmi_service_enabled(*v140, 0xF5u, v141, v142, v143, v144, v145, v146, v147, v148);
    v141 = ucfg_mc_cp_set_big_data_fw_support(a1, v149 & 1);
  }
  v150 = _cds_get_context(54, (__int64)"wma_set_fwol_caps", v141, v142, v143, v144, v145, v146, v147, v148);
  if ( v150 )
  {
    if ( a1 )
    {
      v163[0] = wmi_service_enabled(*v150, 0x100u, v151, v152, v153, v154, v155, v156, v157, v158) & 1;
      ucfg_fwol_update_fw_cap_info(a1, v163);
    }
    else
    {
      v160 = jiffies;
      if ( wma_set_fwol_caps___last_ticks_219 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(0x36u, 2u, "%s: psoc Null", v151, v152, v153, v154, v155, v156, v157, v158, "wma_set_fwol_caps");
        wma_set_fwol_caps___last_ticks_219 = v160;
      }
    }
  }
  else
  {
    v159 = jiffies;
    if ( wma_set_fwol_caps___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x36u, 2u, "%s: wma Null", v151, v152, v153, v154, v155, v156, v157, v158, "wma_set_fwol_caps");
      wma_set_fwol_caps___last_ticks = v159;
    }
  }
  result = wlan_ll_lt_sap_extract_ll_sap_cap(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
