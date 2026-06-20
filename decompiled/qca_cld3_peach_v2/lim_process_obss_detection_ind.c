__int64 __fastcall lim_process_obss_detection_ind(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  int v16; // w8
  int v17; // w9
  int v18; // w10
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 session_by_vdev_id; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 *v36; // x24
  unsigned int v37; // w22
  unsigned int v38; // w25
  char v39; // w23
  __int64 v40; // x4
  const char *v41; // x2
  unsigned int v42; // w1
  __int64 result; // x0
  unsigned __int8 *v44; // x21
  int v45; // w26
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x21
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
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
  __int64 v79; // x4
  unsigned int v80; // w19
  __int64 v81; // [xsp+18h] [xbp-28h] BYREF
  __int64 v82; // [xsp+20h] [xbp-20h]
  __int64 v83; // [xsp+30h] [xbp-10h]
  __int64 v84; // [xsp+38h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a2;
  v13 = a2[1];
  v14 = a2[2];
  v15 = *((unsigned __int8 *)a2 + 12);
  v16 = *((unsigned __int8 *)a2 + 13);
  v17 = *((unsigned __int8 *)a2 + 14);
  v18 = *((unsigned __int8 *)a2 + 17);
  LODWORD(v83) = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: obss detect ind id %d, reason %d, msk 0x%x, %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_obss_detection_ind",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    0,
    0,
    0,
    v83,
    v84);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *a2, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !session_by_vdev_id )
  {
    v40 = *a2;
    v41 = "%s: Failed to get session for id %d";
LABEL_10:
    v42 = 2;
LABEL_11:
    qdf_trace_msg(0x35u, v42, v41, v28, v29, v30, v31, v32, v33, v34, v35, "lim_process_obss_detection_ind", v40);
LABEL_12:
    result = 4;
    goto LABEL_13;
  }
  if ( *(_DWORD *)(session_by_vdev_id + 88) != 1 )
  {
    v40 = *a2;
    v41 = "%s: session %d is not AP";
    goto LABEL_10;
  }
  v36 = (unsigned __int8 *)(session_by_vdev_id + 0x2000);
  if ( (*(_BYTE *)(session_by_vdev_id + 10006) & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Offload already disabled for session %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "lim_process_obss_detection_ind",
      *a2);
    result = 0;
    goto LABEL_13;
  }
  v37 = a2[1];
  if ( v37 )
  {
    v38 = a2[2];
    if ( v37 == 1 )
    {
      v39 = 1;
    }
    else
    {
      if ( v37 != 2 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid reason %d, session %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "lim_process_obss_detection_ind",
          v37,
          *a2);
        goto LABEL_12;
      }
      v39 = 0;
    }
    v44 = (unsigned __int8 *)session_by_vdev_id;
    v45 = *(_DWORD *)(session_by_vdev_id + 168);
    qdf_mem_set(&v81, 0x1Cu, 0);
    if ( (v38 & 1) != 0 )
    {
      if ( v37 != v36[1800] || v45 )
        goto LABEL_47;
      lim_enable11g_protection(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
      v36[1807] = v37;
    }
    if ( (v38 & 2) != 0 )
    {
      if ( v37 != v36[1801] || v45 )
        goto LABEL_47;
      lim_enable11g_protection(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
      v36[1808] = v37;
    }
    if ( (v38 & 4) != 0 )
    {
      if ( v37 != v36[1802] || v45 )
        goto LABEL_47;
      lim_enable_ht_protection_from11g(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
      v36[1809] = v37;
    }
    if ( (v38 & 8) != 0 )
    {
      if ( v37 != v36[1803] || v45 != 1 )
        goto LABEL_47;
      lim_update_11a_protection(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
      v36[1810] = v37;
    }
    if ( (v38 & 0x10) != 0 )
    {
      if ( v37 != v36[1804] || v45 )
        goto LABEL_47;
      lim_enable_ht_protection_from11g(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
      v36[1811] = v37;
    }
    if ( (v38 & 0x20) == 0 )
    {
LABEL_40:
      if ( (v38 & 0x40) == 0 )
      {
LABEL_43:
        if ( !*(_BYTE *)(a1 + 14881)
          && HIWORD(v82)
          && (sch_set_fixed_beacon_fields(a1, (__int64)v44),
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Beacon for PE session: %d got changed: 0x%x",
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                "lim_process_obss_detection_ind",
                v44[10],
                HIWORD(v82)),
              (unsigned int)lim_send_beacon_params(a1, (unsigned __int16 *)&v81, (__int64)v44)) )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to send beacon param, session %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "lim_process_obss_detection_ind",
            *a2);
          result = 5;
        }
        else
        {
          result = lim_obss_send_detection_cfg(a1, v44, 1, v28, v29, v30, v31, v32, v33, v34, v35);
          if ( (_DWORD)result )
          {
            v79 = *a2;
            v80 = result;
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to send obss detection cfg, session %d",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "lim_process_obss_detection_ind",
              v79);
            result = v80;
          }
        }
        goto LABEL_13;
      }
      if ( v37 == v36[1806] )
      {
        lim_enable_ht20_protection(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
        v36[1813] = v37;
        goto LABEL_43;
      }
      goto LABEL_47;
    }
    if ( v37 == v36[1805] && !v45 )
    {
      lim_enable_ht_protection_from11g(a1, v39, 1, (__int64)&v81, (__int64)v44, v28, v29, v30, v31, v32, v33, v34, v35);
      v36[1812] = v37;
      goto LABEL_40;
    }
LABEL_47:
    v40 = *a2;
    v41 = "%s: Wrong detection, session %d";
    v42 = 8;
    goto LABEL_11;
  }
  v54 = session_by_vdev_id;
  *(_BYTE *)(session_by_vdev_id + 10006) = 0;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: FW indicated obss offload disabled",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "lim_process_obss_detection_ind");
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Enabling host based detection, session %d",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "lim_process_obss_detection_ind",
    *a2);
  result = qdf_mc_timer_start(v54 + 8064, 0xFA0u);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: cannot start protection reset timer",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "lim_process_obss_detection_ind");
    result = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
