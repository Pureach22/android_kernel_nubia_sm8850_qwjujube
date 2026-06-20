_WORD *__fastcall cm_roam_stats_print_scan_info(__int64 a1, __int64 a2, unsigned int a3, int a4, unsigned int a5)
{
  unsigned __int8 v7; // w22
  __int64 v9; // x19
  _WORD *result; // x0
  _WORD *v11; // x25
  char *v12; // x20
  __int64 v13; // x19
  __int64 v14; // x26
  unsigned __int16 v15; // w28
  unsigned __int16 v16; // w0
  size_t v17; // x1
  char *v18; // x0
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x23
  unsigned __int64 v29; // x8
  const char *v30; // x5
  __int64 v31; // x19
  unsigned int v32; // w25
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w24
  int v50; // w22
  __int64 v51; // x21
  __int64 v52; // x3
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  const char *v56; // x16
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // [xsp+0h] [xbp-C0h]
  __int64 v66; // [xsp+10h] [xbp-B0h]
  __int64 v67; // [xsp+18h] [xbp-A8h]
  __int64 v68; // [xsp+20h] [xbp-A0h]
  __int64 v69; // [xsp+28h] [xbp-98h]
  __int64 v70; // [xsp+30h] [xbp-90h]
  __int64 v71; // [xsp+38h] [xbp-88h]
  __int64 v72; // [xsp+40h] [xbp-80h]
  __int64 v73; // [xsp+48h] [xbp-78h]
  __int64 v74; // [xsp+58h] [xbp-68h]
  _WORD *v75; // [xsp+60h] [xbp-60h]
  char s[8]; // [xsp+68h] [xbp-58h] BYREF
  __int64 v77; // [xsp+70h] [xbp-50h]
  __int64 v78; // [xsp+78h] [xbp-48h]
  char v79[8]; // [xsp+80h] [xbp-40h] BYREF
  __int64 v80; // [xsp+88h] [xbp-38h]
  __int64 v81; // [xsp+90h] [xbp-30h]
  _QWORD v82[5]; // [xsp+98h] [xbp-28h] BYREF

  v7 = a3;
  v82[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int16 *)(a2 + 6);
  v77 = 0;
  v78 = 0;
  *(_QWORD *)s = 0;
  cm_roam_scan_info_event(a1, a2, a3);
  result = (_WORD *)_qdf_mem_malloc(0x12Cu, "cm_roam_stats_print_scan_info", 3782);
  if ( result )
  {
    v11 = result;
    if ( !*(_WORD *)(a2 + 2) )
    {
      *result = 123;
      v12 = (char *)result + 1;
      if ( (_DWORD)v9 )
      {
        v13 = 2 * v9;
        v75 = result;
        v14 = 0;
        v15 = 299;
        do
        {
          if ( v14 == 76 )
            __break(0x5512u);
          v16 = snprintf(v12, v15, "%d ", *(unsigned __int16 *)(a2 + 16 + v14));
          v14 += 2;
          v15 -= v16;
          v12 += v16;
        }
        while ( v13 != v14 );
        v11 = v75;
        v17 = v15;
      }
      else
      {
        v17 = 299;
      }
      snprintf(v12, v17, "}");
    }
    v18 = (char *)_qdf_mem_malloc(0x3Cu, "cm_roam_stats_print_scan_info", 3804);
    if ( v18 )
    {
      v19 = (__int64)v18;
      if ( a4 == 5 || a4 == 3 )
        snprintf(v18, 0x3Cu, "next_rssi_threshold: %d dBm", *(_DWORD *)(a2 + 12));
      mlme_get_converted_timestamp(a5, s);
      v28 = jiffies;
      if ( cm_roam_stats_print_scan_info___last_ticks - jiffies + 125 < 0 )
      {
        v29 = *(unsigned __int16 *)(a2 + 2);
        if ( v29 > 4 )
          v30 = "UNKNOWN";
        else
          v30 = off_9FDFE8[v29];
        qdf_trace_msg(
          0x68u,
          4u,
          "%s [ROAM_SCAN]: VDEV[%d] Scan_type: %s %s %s",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          s,
          v7,
          v30,
          v19,
          v11);
        cm_roam_stats_print_scan_info___last_ticks = v28;
      }
      v31 = (__int64)v11;
      v32 = *(unsigned __int8 *)(a2 + 4);
      v81 = 0;
      memset(v82, 0, 24);
      *(_QWORD *)v79 = 0;
      v80 = 0;
      qdf_trace_msg(
        0x68u,
        4u,
        "%62s%62s",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "==============================================================",
        "==============================================================");
      qdf_trace_msg(
        0x68u,
        4u,
        "%13s %16s %8s %4s %4s %5s/%3s %3s/%3s %7s %7s %6s %12s %20s",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "AP BSSID",
        "TSTAMP",
        "CH",
        "TY",
        "ETP",
        "RSSI",
        "SCR",
        "CU%",
        "SCR",
        "TOT_SCR",
        "BL_RSN",
        "BL_SRC",
        "BL_TSTAMP",
        "BL_TIMEOUT(ms)");
      qdf_trace_msg(
        0x68u,
        4u,
        "%62s%62s",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "==============================================================",
        "==============================================================");
      if ( v32 >= 9 )
        v49 = 9;
      else
        v49 = v32;
      if ( v32 )
      {
        v50 = 0;
        v51 = a2 + 92;
        do
        {
          mlme_get_converted_timestamp(*(_DWORD *)v51, (char *)v82);
          mlme_get_converted_timestamp(*(_DWORD *)(v51 + 48), v79);
          if ( v51 == -5 )
          {
            v54 = 0;
            v52 = 0;
            v53 = 0;
            v55 = 0;
          }
          else
          {
            v52 = *(unsigned __int8 *)(v51 + 5);
            v53 = *(unsigned __int8 *)(v51 + 6);
            v54 = *(unsigned __int8 *)(v51 + 7);
            v55 = *(unsigned __int8 *)(v51 + 10);
          }
          if ( *(_BYTE *)(v51 + 4) == 2 )
            v56 = "R_AP";
          else
            v56 = "P_AP";
          if ( !*(_BYTE *)(v51 + 4) )
            v56 = "C_AP";
          LODWORD(v74) = *(_DWORD *)(v51 + 52);
          LODWORD(v73) = *(_DWORD *)(v51 + 44);
          LODWORD(v72) = *(_DWORD *)(v51 + 40);
          LODWORD(v71) = *(_DWORD *)(v51 + 32);
          LODWORD(v70) = *(_DWORD *)(v51 + 20);
          LODWORD(v69) = *(_DWORD *)(v51 + 16);
          LODWORD(v68) = *(_DWORD *)(v51 + 28);
          LODWORD(v67) = *(_DWORD *)(v51 + 24);
          LODWORD(v66) = *(_DWORD *)(v51 + 36);
          LODWORD(v65) = *(unsigned __int16 *)(v51 + 12);
          qdf_trace_msg(
            0x68u,
            4u,
            "%02x:%02x:%02x:**:**:%02x %17s %4d %-4s %4d %3d/%-4d %2d/%-4d %5d %7d %7d %17s %9d",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v52,
            v53,
            v54,
            v55,
            v82,
            v65,
            v56,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v79,
            v74);
          cm_roam_candidate_info_event((unsigned int *)v51, v50++);
          v51 += 60;
        }
        while ( v49 > (unsigned __int16)v50 );
      }
      _qdf_mem_free(v31);
    }
    else
    {
      v19 = (__int64)v11;
    }
    result = (_WORD *)_qdf_mem_free(v19);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
