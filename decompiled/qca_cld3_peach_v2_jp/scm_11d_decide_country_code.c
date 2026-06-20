__int64 __fastcall scm_11d_decide_country_code(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21
  const char *v21; // x2
  __int64 comp_private_obj; // x0
  __int64 v23; // x25
  unsigned __int8 *v24; // x20
  unsigned int v25; // w8
  size_t v26; // x23
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  unsigned __int64 v37; // x26
  unsigned int v38; // w27
  unsigned __int8 *v39; // x28
  int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w22
  unsigned int v50; // w23
  const char *v51; // x21
  const char *v52; // x3
  unsigned int v53; // w8
  bool v54; // w28
  unsigned __int64 v55; // x24
  __int64 v56; // x26
  unsigned __int16 *v57; // x21
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x10
  unsigned __int16 v67; // w9
  unsigned __int64 v68; // x25
  unsigned __int8 *v69; // x24
  unsigned __int8 *v70; // x22
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int16 v87; // [xsp+4h] [xbp-Ch] BYREF
  char v88; // [xsp+6h] [xbp-Ah]
  __int64 v89; // [xsp+8h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  v88 = 0;
  v87 = 0;
  v2 = *(_QWORD *)(v1 + 80);
  result = wlan_reg_11d_enabled_on_host(v2);
  if ( (result & 1) == 0 )
    goto LABEL_29;
  if ( !(unsigned int)ucfg_reg_get_cc_and_src(v2, &v87, v4, v5, v6, v7, v8, v9, v10, v11) )
  {
    v21 = "%s: fail to get current country code";
LABEL_28:
    result = qdf_trace_msg(0x15u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "scm_11d_decide_country_code");
    goto LABEL_29;
  }
  if ( !v1 )
  {
    qdf_trace_msg(0x15u, 2u, "%s: pdev is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_pdev_get_cc_db");
    goto LABEL_27;
  }
  v20 = *(unsigned __int8 *)(v1 + 40);
  if ( v20 >= 2 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: invalid pdev_id %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_pdevid_get_cc_db",
      *(unsigned __int8 *)(v1 + 40));
    goto LABEL_27;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v2, 3u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdevid_get_cc_db",
      50);
    goto LABEL_27;
  }
  v23 = *(_QWORD *)(comp_private_obj + 1592);
  v24 = (unsigned __int8 *)(v23 + 604LL * v20);
  if ( !v24 )
  {
LABEL_27:
    v21 = "%s: scan_db is NULL";
    goto LABEL_28;
  }
  scm_iterate_scan_db(v1, &scm_11d_handle_country_info, v23 + 604LL * v20);
  v25 = v24[3];
  if ( v24[3] )
  {
    v26 = v25 < 0x64 ? 10 * v25 + 1 : 1001LL;
    v27 = _qdf_mem_malloc(v26, "scm_11d_dump_cc_db", 351);
    if ( v27 )
    {
      v36 = v27;
      if ( v24[3] )
      {
        v37 = 0;
        v38 = 0;
        v39 = (unsigned __int8 *)(v23 + 604LL * v20 + 7);
        do
        {
          if ( v37 == 100 )
            goto LABEL_63;
          v28 = scnprintf(
                  v36 + v38,
                  (unsigned int)v26 - v38,
                  " %c%c:%d",
                  *(v39 - 1),
                  *v39,
                  *(unsigned __int16 *)(v39 - 3));
          ++v37;
          v38 += v40;
          v39 += 6;
        }
        while ( v37 < v24[3] );
      }
      qdf_trace_msg(0x15u, 8u, "%s: %s", v28, v29, v30, v31, v32, v33, v34, v35, "scm_11d_dump_cc_db", v36);
      _qdf_mem_free(v36);
    }
  }
  if ( !wlan_reg_is_us(&v87) && !wlan_reg_is_world(&v87) )
  {
    v53 = v24[3];
    if ( v24[3] )
    {
      if ( v53 == 1 )
      {
        v50 = 0;
      }
      else
      {
        v50 = 0;
        v66 = v23 + 604LL * v20;
        v67 = v24[4];
        v68 = 1;
        v69 = (unsigned __int8 *)(v66 + 10);
        do
        {
          if ( v68 == 100 )
            goto LABEL_63;
          if ( *(unsigned __int16 *)v69 > (unsigned int)v67 )
          {
            qdf_trace_msg(
              0x15u,
              8u,
              "%s: Votes for Country %c%c : %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "scm_11d_elected_country_info",
              v69[2],
              v69[3]);
            v67 = *v69;
            v53 = v24[3];
            v50 = (unsigned __int8)v68;
          }
          ++v68;
          v69 += 6;
        }
        while ( v68 < v53 );
        if ( v50 > 0x63 )
LABEL_63:
          __break(0x5512u);
      }
      v51 = "scm_11d_elected_country_info";
LABEL_57:
      v70 = &v24[6 * v50];
      qdf_mem_copy(v24, v70 + 6, 3u);
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Selected Country is %c%c With count %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v51,
        v70[6],
        v70[7],
        *((unsigned __int16 *)v70 + 2));
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: elected country %c%c, current country %c%c",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "scm_11d_set_country_code",
        *v24,
        v24[1],
        (unsigned __int8)v87,
        HIBYTE(v87));
      if ( (unsigned int)qdf_mem_cmp(v24, &v87, 3u) )
        wlan_reg_set_11d_country();
      goto LABEL_59;
    }
    v52 = "scm_11d_elected_country_info";
LABEL_49:
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: No AP with 11d Country code is present in scan list",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v52);
    goto LABEL_59;
  }
  if ( !v24[3] )
  {
    v52 = "scm_11d_elected_country_algo_fcc";
    goto LABEL_49;
  }
  v49 = *((unsigned __int16 *)v24 + 2);
  if ( wlan_reg_is_us(v24 + 6) )
  {
LABEL_24:
    v50 = 0;
    goto LABEL_25;
  }
  v54 = v49 > 2;
  if ( v24[3] < 2u )
  {
    if ( v49 <= 2 )
      goto LABEL_59;
    goto LABEL_24;
  }
  v50 = 0;
  v55 = 1;
  v56 = v23 + 604LL * v20 + 4;
LABEL_36:
  v57 = (unsigned __int16 *)(v56 + 6 * v55);
  if ( (unsigned __int16)v49 <= 2u )
    v49 = 2;
  else
    v49 = (unsigned __int16)v49;
  do
  {
    if ( v55 == 100 )
      goto LABEL_63;
    if ( wlan_reg_is_us((_BYTE *)v57 + 2) )
    {
      v50 = (unsigned __int8)v55;
      goto LABEL_25;
    }
    if ( *v57 > v49 )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Votes for Country %c%c : %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "scm_11d_elected_country_algo_fcc",
        *((unsigned __int8 *)v57 + 2),
        *((unsigned __int8 *)v57 + 3));
      v50 = (unsigned __int8)v55++;
      LOWORD(v49) = *v57;
      v54 = 1;
      if ( v55 >= v24[3] )
      {
LABEL_62:
        if ( v50 >= 0x64 )
          goto LABEL_63;
LABEL_25:
        v51 = "scm_11d_elected_country_algo_fcc";
        goto LABEL_57;
      }
      goto LABEL_36;
    }
    ++v55;
    v57 += 3;
  }
  while ( v55 < v24[3] );
  if ( v54 )
    goto LABEL_62;
LABEL_59:
  qdf_mem_set(v24 + 4, 0x258u, 0);
  result = (__int64)qdf_mem_set(v24, 3u, 0);
  v24[3] = 0;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
