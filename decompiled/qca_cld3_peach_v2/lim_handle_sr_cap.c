__int64 __fastcall lim_handle_sr_cap(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  unsigned int v22; // w22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 cmpt_obj; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w25
  const char *v50; // x2
  __int64 result; // x0
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w24
  int v62; // w26
  __int64 v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w22
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w23
  __int64 v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x1
  __int64 v112; // x2
  __int64 v113; // x3
  __int64 v114; // x4
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x0
  __int64 v142; // x0
  __int64 v143; // x1
  unsigned int v144; // w23
  _BYTE v145[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v146; // [xsp+28h] [xbp-8h]

  v146 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v145[0] = 0;
  context = _cds_get_context(53, (__int64)"lim_handle_sr_cap", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v50 = "%s: mac ctx is null";
LABEL_10:
    result = qdf_trace_msg(0x35u, 2u, v50, v13, v14, v15, v16, v17, v18, v19, v20, "lim_handle_sr_cap");
    goto LABEL_13;
  }
  v21 = *(_QWORD *)(a1 + 216);
  if ( !v21 )
  {
    v50 = "%s: invalid pdev";
    goto LABEL_10;
  }
  v22 = *(_DWORD *)(a1 + 16);
  wlan_mlme_get_sr_enable_modes(context[2703], v145);
  if ( ((v145[0] >> v22) & 1) == 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: SR is disabled in INI for mode: %d",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "lim_handle_sr_cap",
               v22);
    goto LABEL_13;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( !cmpt_obj || (*(_BYTE *)(cmpt_obj + 202) & 1) == 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: SR is not enabled",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "lim_handle_sr_cap");
    goto LABEL_13;
  }
  v40 = wlan_vdev_mlme_get_cmpt_obj(a1, v32, v33, v34, v35, v36, v37, v38, v39);
  if ( v40 )
    v49 = *(unsigned __int8 *)(v40 + 199);
  else
    v49 = 0;
  v52 = wlan_vdev_mlme_get_cmpt_obj(a1, v41, v42, v43, v44, v45, v46, v47, v48);
  if ( v52 )
  {
    v61 = *(unsigned __int8 *)(v52 + 200);
    v62 = *(unsigned __int8 *)(v52 + 201);
  }
  else
  {
    v61 = 0;
    v62 = 0;
  }
  v63 = wlan_vdev_mlme_get_cmpt_obj(a1, v53, v54, v55, v56, v57, v58, v59, v60);
  if ( v63 )
    v72 = *(_DWORD *)(v63 + 224);
  else
    v72 = 0;
  v73 = wlan_vdev_mlme_get_cmpt_obj(a1, v64, v65, v66, v67, v68, v69, v70, v71);
  if ( v73 )
    v82 = *(_DWORD *)(v73 + 228);
  else
    v82 = 0;
  v83 = wlan_vdev_mlme_get_cmpt_obj(a1, v74, v75, v76, v77, v78, v79, v80, v81);
  if ( !v83 )
  {
    if ( (int)v72 <= v49 - 82 )
    {
LABEL_51:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: sr status %d reason %d existing thresholds srg: %d non-srg: %d New: sr offset srg: max %d min %d non-srg: %d",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "lim_handle_sr_cap",
        1,
        a2,
        v82,
        v72,
        v61,
        v62,
        v49);
      v110 = a1;
      v111 = v21;
      v112 = 1;
      v113 = v82;
      v114 = v72;
      goto LABEL_52;
    }
LABEL_36:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: sr status %d reason %d existing thresholds srg: %d non-srg: %d New: sr offset srg: max %d min %d non-srg: %d",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "lim_handle_sr_cap",
      2,
      a2,
      v82,
      v72,
      v61,
      v62,
      v49);
    v123 = wlan_vdev_mlme_get_cmpt_obj(a1, v115, v116, v117, v118, v119, v120, v121, v122);
    if ( v123 && *(_BYTE *)(v123 + 232) == 1 )
    {
      v132 = wlan_vdev_mlme_get_cmpt_obj(a1, v124, v125, v126, v127, v128, v129, v130, v131);
      if ( v132 )
        *(_DWORD *)(v132 + 224) = 0;
      v141 = wlan_vdev_mlme_get_cmpt_obj(a1, v133, v134, v135, v136, v137, v138, v139, v140);
      if ( v141 )
        *(_DWORD *)(v141 + 228) = 0;
      v142 = a1;
      v143 = 0;
    }
    else
    {
      if ( a2 )
        v144 = 2;
      else
        v144 = 1;
      wlan_sr_setup_req(a1, v21, 1, (unsigned int)(v61 - 82), v72 - 82);
      v142 = a1;
      v143 = v144;
    }
    result = wlan_spatial_reuse_osif_event(v142, v143, a2);
    goto LABEL_13;
  }
  if ( (*(_BYTE *)(v83 + 198) & 0xA) != 2 )
  {
    if ( ((*(_BYTE *)(v83 + 198) & 2) != 0 || (int)v72 <= v49 - 82)
      && ((*(_BYTE *)(v83 + 198) & 8) == 0 || (int)v82 <= v61 - 82 && (int)v82 >= v62 - 82) )
    {
      goto LABEL_51;
    }
    goto LABEL_36;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: sr status %d reason %d existing thresholds srg: %d non-srg: %d New: sr offset srg: max %d min %d non-srg: %d",
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    "lim_handle_sr_cap",
    0,
    a2,
    v82,
    v72,
    v61,
    v62,
    v49);
  v100 = wlan_vdev_mlme_get_cmpt_obj(a1, v92, v93, v94, v95, v96, v97, v98, v99);
  if ( v100 )
    *(_DWORD *)(v100 + 224) = 0;
  v109 = wlan_vdev_mlme_get_cmpt_obj(a1, v101, v102, v103, v104, v105, v106, v107, v108);
  if ( v109 )
    *(_DWORD *)(v109 + 228) = 0;
  result = wlan_spatial_reuse_osif_event(a1, 0, a2);
  if ( a2 == 2 )
  {
    v110 = a1;
    v111 = v21;
    v112 = 0;
    v113 = 0;
    v114 = 0;
LABEL_52:
    result = wlan_sr_setup_req(v110, v111, v112, v113, v114);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
