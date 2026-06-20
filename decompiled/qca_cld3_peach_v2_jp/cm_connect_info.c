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
  unsigned int v24; // w9
  char v25; // w8
  __int64 v26; // x9
  __int64 cmpt_obj; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _DWORD *crypto_params; // x0
  int v37; // w10
  _DWORD *v38; // x22
  char v39; // w9
  char v40; // w8
  bool v41; // zf
  const char *v42; // x2
  unsigned int v43; // w9
  int v44; // w9
  unsigned int v45; // w21
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
  const char *v70; // x4
  const char *v71; // x5
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  const char *v80; // x3
  int v81; // w8
  const char *v82; // x4
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x4
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  const char *v109; // x4
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  char v118; // w9
  __int16 v119; // w10
  size_t v120; // x2
  __int64 v121; // [xsp+10h] [xbp-80h] BYREF
  size_t n[4]; // [xsp+18h] [xbp-78h] BYREF
  __int64 v123; // [xsp+38h] [xbp-58h] BYREF
  __int64 v124; // [xsp+40h] [xbp-50h]
  __int64 v125; // [xsp+48h] [xbp-48h]
  unsigned int v126; // [xsp+50h] [xbp-40h]
  _QWORD v127[4]; // [xsp+58h] [xbp-38h] BYREF
  __int64 v128; // [xsp+78h] [xbp-18h]
  char v129; // [xsp+80h] [xbp-10h]
  __int64 v130; // [xsp+88h] [xbp-8h]

  v130 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v121 = 0;
  if ( !a3 )
    goto LABEL_133;
  if ( !a4 )
    goto LABEL_133;
  v5 = *(_QWORD *)(result + 152);
  v6 = result;
  if ( !v5 )
    goto LABEL_133;
  result = *(_QWORD *)(v5 + 80);
  if ( !result )
    goto LABEL_133;
  v126 = 0;
  v124 = 0;
  v125 = 0;
  v123 = 0;
  memset(n, 0, sizeof(n));
  result = mlme_get_psoc_ext_obj_fl(result);
  if ( !result )
    goto LABEL_133;
  v11 = (unsigned __int8 *)result;
  qdf_mem_set(n, 0x3Cu, 0);
  qdf_mem_copy((char *)&v123 + 2, a3, 6u);
  if ( *a4 >= 0x20u )
    v12 = 32;
  else
    v12 = *a4;
  BYTE1(n[0]) = v12;
  qdf_mem_copy((char *)n + 2, a4 + 1, v12);
  cm_get_rssi_snr_by_bssid(v5, a3, n, nullptr);
  v13 = *(_QWORD *)(v6 + 40);
  LODWORD(v125) = 0;
  wlan_mlme_get_sta_ch_width(v6, (unsigned int *)&v121 + 1, (unsigned int *)&v121);
  v22 = v121;
  v23 = BYTE4(v121);
  if ( HIDWORD(v121) >= 7 )
    v23 = -1;
  BYTE2(v124) = v23;
  if ( (_DWORD)v121 )
  {
    v24 = v121 - 11;
    if ( (unsigned int)v121 < 0xB )
    {
LABEL_13:
      v25 = byte_9FDF38[v22];
      goto LABEL_20;
    }
  }
  else
  {
    v22 = *(_DWORD *)(v13 + 28);
    LODWORD(v121) = v22;
    v24 = v22 - 11;
    if ( v22 < 0xB )
      goto LABEL_13;
  }
  if ( v24 >= 0xA )
  {
    if ( v22 - 21 >= 0xA )
      v25 = -1;
    else
      v25 = 10;
  }
  else
  {
    v25 = 5;
  }
LABEL_20:
  v26 = *(unsigned int *)(v6 + 16);
  BYTE3(v124) = v25;
  if ( (unsigned int)v26 > 0xE )
  {
    BYTE4(v124) = -1;
    if ( !a5 )
      goto LABEL_25;
    goto LABEL_24;
  }
  BYTE4(v124) = byte_9FDE50[v26];
  if ( a5 )
LABEL_24:
    LOBYTE(v124) = wlan_reg_freq_to_chan(v5, a5, v14, v15, v16, v17, v18, v19, v20, v21);
LABEL_25:
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v6, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( !cmpt_obj )
  {
    v42 = "%s: vdev component object is NULL";
LABEL_35:
    result = qdf_trace_msg(0x68u, 2u, v42, v28, v29, v30, v31, v32, v33, v34, v35, "cm_connect_info");
    goto LABEL_133;
  }
  BYTE1(v124) = *(_BYTE *)(*(_QWORD *)(cmpt_obj + 520) + 24007LL);
  crypto_params = (_DWORD *)wlan_crypto_vdev_get_crypto_params(v6);
  if ( !crypto_params )
  {
    v42 = "%s: crypto params is null";
    goto LABEL_35;
  }
  v37 = *crypto_params;
  v38 = crypto_params;
  v39 = 0;
  if ( *crypto_params )
  {
    v40 = a2;
    if ( (v37 & 3) == 0 )
    {
      if ( (v37 & 0x10) != 0 )
      {
        v39 = (crypto_params[1] & 0x18001) != 0;
      }
      else
      {
        if ( (v37 & 4) == 0 )
        {
          if ( (v37 & 0x6C8) != 0 )
          {
            v41 = (crypto_params[5] & 0x10300A1) == 0;
            v39 = 4;
            goto LABEL_44;
          }
          if ( (v37 & 0x20) != 0 )
          {
            v41 = (crypto_params[5] & 1) == 0;
            v39 = 2;
          }
          else
          {
            if ( (v37 & 0x100) == 0 )
            {
              v39 = 0;
              goto LABEL_46;
            }
            v41 = (crypto_params[5] & 0x2000) == 0;
            v39 = 6;
          }
LABEL_44:
          if ( v41 )
            ++v39;
          goto LABEL_46;
        }
        v39 = 1;
      }
    }
  }
  else
  {
    v40 = a2;
  }
LABEL_46:
  BYTE5(v124) = v39;
  v43 = crypto_params[1];
  if ( v43 )
  {
    if ( (v43 & 0x400) != 0 )
    {
      LOBYTE(v43) = 6;
    }
    else if ( (v43 & 0x200) != 0 )
    {
      LOBYTE(v43) = 5;
    }
    else if ( (v43 & 0x19CC) != 0 )
    {
      LOBYTE(v43) = 4;
    }
    else if ( (v43 & 2) != 0 )
    {
      LOBYTE(v43) = 3;
    }
    else if ( (v43 & 0x2010) != 0 )
    {
      LOBYTE(v43) = 7;
    }
    else if ( (v43 & 0x8001) != 0 )
    {
      LOBYTE(v43) = 1;
    }
    else
    {
      v43 = (v43 >> 15) & 2;
    }
  }
  BYTE6(v124) = v43;
  v44 = v11[2667];
  HIDWORD(v125) = v40 & 1;
  v126 = a5;
  if ( v44 )
    v45 = 2;
  else
    v45 = 1;
  qdf_trace_msg(0x68u, 8u, "+---------CONNECTION INFO START------------+", v28, v29, v30, v31, v32, v33, v34, v35);
  qdf_trace_msg(
    0x68u,
    8u,
    "VDEV-ID: %d self_mac:%02x:%02x:%02x:**:**:%02x",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    *(unsigned __int8 *)(v6 + 104),
    *(unsigned __int8 *)(v6 + 74),
    *(unsigned __int8 *)(v6 + 75),
    *(unsigned __int8 *)(v6 + 76),
    *(unsigned __int8 *)(v6 + 79));
  qdf_trace_msg(
    0x68u,
    8u,
    "ssid: %.*s bssid: %02x:%02x:%02x:**:**:%02x RSSI: %d dBm",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    BYTE1(n[0]),
    (char *)n + 2,
    BYTE2(v123),
    BYTE3(v123),
    BYTE4(v123),
    HIBYTE(v123),
    SLOBYTE(n[0]));
  if ( BYTE2(v124) > 6uLL )
    v70 = "Unknown";
  else
    v70 = off_9FDE60[BYTE2(v124)];
  if ( BYTE3(v124) > 0xBuLL )
    v71 = "Unknown";
  else
    v71 = off_9FDE98[BYTE3(v124)];
  qdf_trace_msg(
    0x68u,
    8u,
    "Channel Freq: %d channel_bw: %s dot11Mode: %s",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v126,
    v70,
    v71);
  if ( BYTE5(v124) )
  {
    if ( BYTE5(v124) == 1 )
    {
      v80 = "Shared Key";
    }
    else
    {
      v81 = v38[5];
      if ( (v81 & 0x200000) != 0 )
      {
        v80 = "FT-FILS-SHA384";
      }
      else if ( (v81 & 0x100000) != 0 )
      {
        v80 = "FT-FILS-SHA256";
      }
      else if ( (v81 & 0x80000) != 0 )
      {
        v80 = "FILS-SHA384";
      }
      else if ( (v81 & 0x40000) != 0 )
      {
        v80 = "FILS-SHA256";
      }
      else if ( (v81 & 0x10000000) != 0 )
      {
        v80 = "FT-SAE-EXT-KEY";
      }
      else if ( (v81 & 0x800) != 0 )
      {
        v80 = "FT-SAE";
      }
      else if ( (v81 & 0x8000000) != 0 )
      {
        v80 = "SAE-EXT-KEY";
      }
      else if ( (v81 & 0x400) != 0 )
      {
        v80 = "SAE";
      }
      else if ( (v81 & 0x800000) != 0 )
      {
        v80 = "DPP";
      }
      else if ( (v81 & 0x8000) != 0 )
      {
        v80 = "OSEN";
      }
      else if ( (v81 & 0x400000) != 0 )
      {
        v80 = "OWE";
      }
      else if ( (v81 & 0x20) != 0 )
      {
        v80 = "FT-802.1x";
      }
      else if ( (v81 & 0x40) != 0 )
      {
        v80 = "FT-PSK";
      }
      else if ( (v81 & 1) != 0 )
      {
        v80 = "EAP 802.1x";
      }
      else if ( (v81 & 2) != 0 )
      {
        v80 = "WPA2-PSK";
      }
      else if ( (v81 & 0x4000) != 0 )
      {
        v80 = "RSN-CCKM";
      }
      else if ( (v81 & 0x100) != 0 )
      {
        v80 = "PSK-SHA256";
      }
      else if ( (v81 & 0x80) != 0 )
      {
        v80 = "EAP 802.1x-SHA256";
      }
      else if ( (v81 & 0x10000) != 0 )
      {
        v80 = "EAP Suite-B SHA256";
      }
      else if ( (v81 & 0x20000) != 0 )
      {
        v80 = "EAP Suite-B SHA384";
      }
      else if ( (v81 & 0x1000000) != 0 )
      {
        v80 = "FT-Suite-B SHA384";
      }
      else if ( (v81 & 0x10) != 0 )
      {
        v80 = "WPA-NONE";
      }
      else if ( (v81 & 0x2000) != 0 )
      {
        v80 = "WAPI-CERT";
      }
      else if ( (v81 & 0x1000) != 0 )
      {
        v80 = "WAPI-PSK";
      }
      else
      {
        v80 = "NONE";
      }
    }
  }
  else
  {
    v80 = "Open";
  }
  if ( BYTE6(v124) > 7uLL )
    v82 = "Unknown";
  else
    v82 = off_9FDEF8[BYTE6(v124)];
  qdf_trace_msg(0x68u, 8u, "AKM: %s Encry-type: %s", v72, v73, v74, v75, v76, v77, v78, v79, v80, v82);
  v91 = wlan_vdev_mlme_get_cmpt_obj(v6, v83, v84, v85, v86, v87, v88, v89, v90);
  if ( v91 )
    v100 = *(unsigned __int8 *)(v91 + 23);
  else
    v100 = 0;
  qdf_trace_msg(0x68u, 8u, "DUT_NSS: %d | Intersected NSS:%d", v92, v93, v94, v95, v96, v97, v98, v99, v45, v100);
  if ( WORD2(v125) )
    v109 = "yes";
  else
    v109 = "no";
  qdf_trace_msg(
    0x68u,
    8u,
    "Qos enable: %d | Associated: %s",
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    BYTE1(v124),
    v109);
  qdf_trace_msg(0x68u, 8u, "+---------CONNECTION INFO END------------+", v110, v111, v112, v113, v114, v115, v116, v117);
  result = host_diag_event_report_payload(3158, 60, n);
  if ( (a2 & 1) != 0 )
  {
    v129 = 0;
    v128 = 0;
    memset(v127, 0, sizeof(v127));
    qdf_mem_set(v127, 0x29u, 0);
    v118 = BYTE1(v124);
    v119 = *(_WORD *)((char *)&v124 + 5);
    v120 = BYTE1(n[0]);
    LOBYTE(v127[0]) = 0;
    BYTE1(v128) = 0;
    v11[3329] = n[0];
    BYTE4(v128) = v118;
    *(_WORD *)((char *)&v128 + 5) = v119;
    qdf_mem_copy((char *)v127 + 1, (char *)n + 2, v120);
    HIBYTE(v128) = 0;
    qdf_mem_copy(v11 + 3346, v127, 0x29u);
    result = host_diag_event_report_payload(2739, 41, v127);
  }
LABEL_133:
  _ReadStatusReg(SP_EL0);
  return result;
}
