__int64 __fastcall cm_connect_info(__int64 result, char a2, const void *a3, unsigned __int8 *a4, unsigned int a5)
{
  __int64 v5; // x22
  __int64 v6; // x20
  unsigned __int8 *v11; // x19
  size_t v12; // x2
  __int64 v13; // x23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  char v23; // w9
  char v24; // w10
  unsigned int v25; // w9
  char v26; // w8
  __int64 v27; // x9
  __int64 cmpt_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  _DWORD *crypto_params; // x0
  int v38; // w10
  _DWORD *v39; // x22
  char v40; // w9
  char v41; // w8
  bool v42; // zf
  const char *v43; // x2
  unsigned int v44; // w9
  int v45; // w9
  unsigned int v46; // w21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
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
  const char *v71; // x8
  const char *v72; // x4
  const char *v73; // x5
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  const char *v82; // x3
  int v83; // w8
  const char *v84; // x4
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x4
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  const char *v111; // x4
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  unsigned __int8 *v128; // x21
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  char v137; // w9
  __int16 v138; // w10
  size_t v139; // x2
  __int64 v140; // [xsp+10h] [xbp-80h] BYREF
  size_t n[4]; // [xsp+18h] [xbp-78h] BYREF
  __int64 v142; // [xsp+38h] [xbp-58h] BYREF
  __int64 v143; // [xsp+40h] [xbp-50h]
  __int64 v144; // [xsp+48h] [xbp-48h]
  unsigned int v145; // [xsp+50h] [xbp-40h]
  _QWORD v146[4]; // [xsp+58h] [xbp-38h] BYREF
  __int64 v147; // [xsp+78h] [xbp-18h]
  char v148; // [xsp+80h] [xbp-10h]
  __int64 v149; // [xsp+88h] [xbp-8h]

  v149 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v140 = 0;
  if ( !a3 )
    goto LABEL_147;
  if ( !a4 )
    goto LABEL_147;
  v5 = *(_QWORD *)(result + 216);
  v6 = result;
  if ( !v5 )
    goto LABEL_147;
  result = *(_QWORD *)(v5 + 80);
  if ( !result )
    goto LABEL_147;
  v145 = 0;
  v143 = 0;
  v144 = 0;
  v142 = 0;
  memset(n, 0, sizeof(n));
  result = mlme_get_psoc_ext_obj_fl(result);
  if ( !result )
    goto LABEL_147;
  v11 = (unsigned __int8 *)result;
  qdf_mem_set(n, 0x3Cu, 0);
  qdf_mem_copy((char *)&v142 + 2, a3, 6u);
  if ( *a4 >= 0x20u )
    v12 = 32;
  else
    v12 = *a4;
  BYTE1(n[0]) = v12;
  qdf_mem_copy((char *)n + 2, a4 + 1, v12);
  cm_get_rssi_snr_by_bssid(v5, a3, n, nullptr);
  v13 = *(_QWORD *)(v6 + 40);
  LODWORD(v144) = 0;
  wlan_mlme_get_sta_ch_width(v6, (_DWORD *)&v140 + 1, (unsigned int *)&v140);
  v22 = v140;
  v23 = BYTE4(v140);
  if ( HIDWORD(v140) == 7 )
    v24 = 7;
  else
    v24 = -1;
  if ( HIDWORD(v140) >= 7 )
    v23 = v24;
  BYTE2(v143) = v23;
  if ( (_DWORD)v140 )
  {
    v25 = v140 - 11;
    if ( (unsigned int)v140 < 0xB )
    {
LABEL_16:
      v26 = byte_AEFE40[v22];
      goto LABEL_25;
    }
  }
  else
  {
    v22 = *(_DWORD *)(v13 + 28);
    LODWORD(v140) = v22;
    v25 = v22 - 11;
    if ( v22 < 0xB )
      goto LABEL_16;
  }
  if ( v25 >= 0xA )
  {
    if ( v22 - 21 >= 0xA )
    {
      if ( v22 - 31 >= 0xA )
        v26 = -1;
      else
        v26 = 12;
    }
    else
    {
      v26 = 10;
    }
  }
  else
  {
    v26 = 5;
  }
LABEL_25:
  v27 = *(unsigned int *)(v6 + 16);
  BYTE3(v143) = v26;
  if ( (unsigned int)v27 > 0xE )
  {
    BYTE4(v143) = -1;
    if ( !a5 )
      goto LABEL_30;
    goto LABEL_29;
  }
  BYTE4(v143) = byte_AEFD58[v27];
  if ( a5 )
LABEL_29:
    LOBYTE(v143) = wlan_reg_freq_to_chan(v5, a5, v14, v15, v16, v17, v18, v19, v20, v21);
LABEL_30:
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v6, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !cmpt_obj )
  {
    v43 = "%s: vdev component object is NULL";
LABEL_40:
    result = qdf_trace_msg(0x68u, 2u, v43, v29, v30, v31, v32, v33, v34, v35, v36, "cm_connect_info");
    goto LABEL_147;
  }
  BYTE1(v143) = *(_BYTE *)(*(_QWORD *)(cmpt_obj + 536) + 24007LL);
  crypto_params = (_DWORD *)wlan_crypto_vdev_get_crypto_params(v6);
  if ( !crypto_params )
  {
    v43 = "%s: crypto params is null";
    goto LABEL_40;
  }
  v38 = *crypto_params;
  v39 = crypto_params;
  v40 = 0;
  if ( *crypto_params )
  {
    v41 = a2;
    if ( (v38 & 3) == 0 )
    {
      if ( (v38 & 0x10) != 0 )
      {
        v40 = (crypto_params[1] & 0x18001) != 0;
      }
      else
      {
        if ( (v38 & 4) == 0 )
        {
          if ( (v38 & 0x6C8) != 0 )
          {
            v42 = (crypto_params[5] & 0x10300A1) == 0;
            v40 = 4;
            goto LABEL_49;
          }
          if ( (v38 & 0x20) != 0 )
          {
            v42 = (crypto_params[5] & 1) == 0;
            v40 = 2;
          }
          else
          {
            if ( (v38 & 0x100) == 0 )
            {
              v40 = 0;
              goto LABEL_51;
            }
            v42 = (crypto_params[5] & 0x2000) == 0;
            v40 = 6;
          }
LABEL_49:
          if ( v42 )
            ++v40;
          goto LABEL_51;
        }
        v40 = 1;
      }
    }
  }
  else
  {
    v41 = a2;
  }
LABEL_51:
  BYTE5(v143) = v40;
  v44 = crypto_params[1];
  if ( v44 )
  {
    if ( (v44 & 0x400) != 0 )
    {
      LOBYTE(v44) = 6;
    }
    else if ( (v44 & 0x200) != 0 )
    {
      LOBYTE(v44) = 5;
    }
    else if ( (v44 & 0x19CC) != 0 )
    {
      LOBYTE(v44) = 4;
    }
    else if ( (v44 & 2) != 0 )
    {
      LOBYTE(v44) = 3;
    }
    else if ( (v44 & 0x2010) != 0 )
    {
      LOBYTE(v44) = 7;
    }
    else if ( (v44 & 0x8001) != 0 )
    {
      LOBYTE(v44) = 1;
    }
    else
    {
      v44 = (v44 >> 15) & 2;
    }
  }
  BYTE6(v143) = v44;
  v45 = v11[2871];
  HIDWORD(v144) = v41 & 1;
  v145 = a5;
  if ( v45 )
    v46 = 2;
  else
    v46 = 1;
  qdf_trace_msg(0x68u, 8u, "+---------CONNECTION INFO START------------+", v29, v30, v31, v32, v33, v34, v35, v36);
  qdf_trace_msg(
    0x68u,
    8u,
    "VDEV-ID: %d self_mac:%02x:%02x:%02x:**:**:%02x",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    *(unsigned __int8 *)(v6 + 168),
    *(unsigned __int8 *)(v6 + 74),
    *(unsigned __int8 *)(v6 + 75),
    *(unsigned __int8 *)(v6 + 76),
    *(unsigned __int8 *)(v6 + 79));
  qdf_trace_msg(
    0x68u,
    8u,
    "ssid: %.*s bssid: %02x:%02x:%02x:**:**:%02x RSSI: %d dBm",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    BYTE1(n[0]),
    (char *)n + 2,
    BYTE2(v142),
    BYTE3(v142),
    BYTE4(v142),
    HIBYTE(v142),
    SLOBYTE(n[0]));
  v71 = "Unknown";
  if ( BYTE2(v143) >= 7u )
  {
    if ( BYTE2(v143) == 7 )
      v72 = "BW_320MHZ";
    else
      v72 = "Unknown";
  }
  else
  {
    v72 = off_AEFD68[BYTE2(v143)];
  }
  if ( BYTE3(v143) >= 0xCu )
  {
    if ( BYTE3(v143) == 13 )
      v71 = "DOT11_MODE_11BE_ONLY";
    if ( BYTE3(v143) == 12 )
      v73 = "DOT11_MODE_11BE";
    else
      v73 = v71;
  }
  else
  {
    v73 = off_AEFDA0[BYTE3(v143)];
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "Channel Freq: %d channel_bw: %s dot11Mode: %s",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v145,
    v72,
    v73);
  if ( BYTE5(v143) )
  {
    if ( BYTE5(v143) == 1 )
    {
      v82 = "Shared Key";
    }
    else
    {
      v83 = v39[5];
      if ( (v83 & 0x200000) != 0 )
      {
        v82 = "FT-FILS-SHA384";
      }
      else if ( (v83 & 0x100000) != 0 )
      {
        v82 = "FT-FILS-SHA256";
      }
      else if ( (v83 & 0x80000) != 0 )
      {
        v82 = "FILS-SHA384";
      }
      else if ( (v83 & 0x40000) != 0 )
      {
        v82 = "FILS-SHA256";
      }
      else if ( (v83 & 0x10000000) != 0 )
      {
        v82 = "FT-SAE-EXT-KEY";
      }
      else if ( (v83 & 0x800) != 0 )
      {
        v82 = "FT-SAE";
      }
      else if ( (v83 & 0x8000000) != 0 )
      {
        v82 = "SAE-EXT-KEY";
      }
      else if ( (v83 & 0x400) != 0 )
      {
        v82 = "SAE";
      }
      else if ( (v83 & 0x800000) != 0 )
      {
        v82 = "DPP";
      }
      else if ( (v83 & 0x8000) != 0 )
      {
        v82 = "OSEN";
      }
      else if ( (v83 & 0x400000) != 0 )
      {
        v82 = "OWE";
      }
      else if ( (v83 & 0x20) != 0 )
      {
        v82 = "FT-802.1x";
      }
      else if ( (v83 & 0x40) != 0 )
      {
        v82 = "FT-PSK";
      }
      else if ( (v83 & 1) != 0 )
      {
        v82 = "EAP 802.1x";
      }
      else if ( (v83 & 2) != 0 )
      {
        v82 = "WPA2-PSK";
      }
      else if ( (v83 & 0x4000) != 0 )
      {
        v82 = "RSN-CCKM";
      }
      else if ( (v83 & 0x100) != 0 )
      {
        v82 = "PSK-SHA256";
      }
      else if ( (v83 & 0x80) != 0 )
      {
        v82 = "EAP 802.1x-SHA256";
      }
      else if ( (v83 & 0x10000) != 0 )
      {
        v82 = "EAP Suite-B SHA256";
      }
      else if ( (v83 & 0x20000) != 0 )
      {
        v82 = "EAP Suite-B SHA384";
      }
      else if ( (v83 & 0x1000000) != 0 )
      {
        v82 = "FT-Suite-B SHA384";
      }
      else if ( (v83 & 0x10) != 0 )
      {
        v82 = "WPA-NONE";
      }
      else if ( (v83 & 0x2000) != 0 )
      {
        v82 = "WAPI-CERT";
      }
      else if ( (v83 & 0x1000) != 0 )
      {
        v82 = "WAPI-PSK";
      }
      else
      {
        v82 = "NONE";
      }
    }
  }
  else
  {
    v82 = "Open";
  }
  if ( BYTE6(v143) > 7uLL )
    v84 = "Unknown";
  else
    v84 = off_AEFE00[BYTE6(v143)];
  qdf_trace_msg(0x68u, 8u, "AKM: %s Encry-type: %s", v74, v75, v76, v77, v78, v79, v80, v81, v82, v84);
  v93 = wlan_vdev_mlme_get_cmpt_obj(v6, v85, v86, v87, v88, v89, v90, v91, v92);
  if ( v93 )
    v102 = *(unsigned __int8 *)(v93 + 23);
  else
    v102 = 0;
  qdf_trace_msg(0x68u, 8u, "DUT_NSS: %d | Intersected NSS:%d", v94, v95, v96, v97, v98, v99, v100, v101, v46, v102);
  if ( WORD2(v144) )
    v111 = "yes";
  else
    v111 = "no";
  qdf_trace_msg(
    0x68u,
    8u,
    "Qos enable: %d | Associated: %s",
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    v110,
    BYTE1(v143),
    v111);
  if ( (wlan_vdev_mlme_is_mlo_vdev(v6, v112, v113, v114, v115, v116, v117, v118, v119) & 1) != 0 )
  {
    v128 = *(unsigned __int8 **)(v6 + 184);
    if ( v128 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "self_mld_addr:%02x:%02x:%02x:**:**:%02x link_id:%d",
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        *(unsigned __int8 *)(v6 + 80),
        *(unsigned __int8 *)(v6 + 81),
        *(unsigned __int8 *)(v6 + 82),
        *(unsigned __int8 *)(v6 + 85),
        *(unsigned __int8 *)(v6 + 93));
      qdf_trace_msg(
        0x68u,
        8u,
        "peer_mld_mac:%02x:%02x:%02x:**:**:%02x",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        v128[792],
        v128[793],
        v128[794],
        v128[797]);
    }
  }
  qdf_trace_msg(0x68u, 8u, "+---------CONNECTION INFO END------------+", v120, v121, v122, v123, v124, v125, v126, v127);
  result = host_diag_event_report_payload(3158, 60, n);
  if ( (a2 & 1) != 0 )
  {
    v148 = 0;
    v147 = 0;
    memset(v146, 0, sizeof(v146));
    qdf_mem_set(v146, 0x29u, 0);
    v137 = BYTE1(v143);
    v138 = *(_WORD *)((char *)&v143 + 5);
    v139 = BYTE1(n[0]);
    LOBYTE(v146[0]) = 0;
    BYTE1(v147) = 0;
    v11[3529] = n[0];
    BYTE4(v147) = v137;
    *(_WORD *)((char *)&v147 + 5) = v138;
    qdf_mem_copy((char *)v146 + 1, (char *)n + 2, v139);
    HIBYTE(v147) = 0;
    qdf_mem_copy(v11 + 3546, v146, 0x29u);
    result = host_diag_event_report_payload(2739, 41, v146);
  }
LABEL_147:
  _ReadStatusReg(SP_EL0);
  return result;
}
