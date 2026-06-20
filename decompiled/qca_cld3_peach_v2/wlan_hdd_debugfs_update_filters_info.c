__int64 __fastcall wlan_hdd_debugfs_update_filters_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
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
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 v26; // x19
  int v27; // w0
  int v28; // w8
  __int64 result; // x0
  __int64 v30; // x28
  __int64 v31; // x25
  __int64 v32; // x23
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w0
  int v43; // w0
  bool v44; // cc
  __int64 v45; // x25
  __int64 v46; // x0
  __int64 vdev_by_user; // x0
  __int64 v48; // x23
  int arp_offload_params; // w24
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w0
  __int64 v60; // x0
  __int64 v61; // x3
  __int64 v62; // x26
  __int64 v63; // x27
  unsigned __int64 v64; // x24
  __int64 v65; // x1
  int v66; // w0
  __int64 v67; // x8
  __int64 v68; // x26
  __int64 v69; // x27
  __int64 v70; // x0
  __int64 v71; // x23
  __int64 v72; // x24
  int ns_offload_params; // w25
  unsigned int *v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w0
  __int64 v84; // x22
  unsigned int v85; // w0
  __int64 v86; // x1
  unsigned int v87; // w24
  int v88; // w0
  unsigned __int64 v89; // x24
  __int64 v90; // x25
  const char *v91; // x6
  unsigned int v92; // w8
  const char *v93; // x8
  __int64 v94; // x8
  int v95; // w0
  __int64 v96; // x22
  unsigned __int8 *v97; // x8
  int v98; // w0
  const char *v99; // x2
  unsigned int v100; // w1
  int v101; // w0
  _QWORD v102[2]; // [xsp+60h] [xbp-2E0h] BYREF
  _QWORD v103[6]; // [xsp+70h] [xbp-2D0h] BYREF
  _QWORD s[84]; // [xsp+A0h] [xbp-2A0h] BYREF

  s[82] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_debugfs_update_filters_info");
  v16 = wlan_hdd_current_time_info_debugfs(a3, a4);
  v25 = a4 - v16;
  if ( a4 <= v16 )
    goto LABEL_63;
  if ( *(_DWORD *)(a2 + 40) )
  {
    v26 = v16;
    scnprintf(a3 + v16, v25, "Interface is not operating in STA mode\n");
    v28 = v27;
    result = v26;
    if ( v28 < 1 )
      goto LABEL_65;
    goto LABEL_10;
  }
  v30 = a2 + 49152;
  v31 = v16;
  v32 = a3 + v16;
  if ( hdd_cm_is_vdev_associated(*(_DWORD **)(v30 + 3680)) )
  {
    v33 = *(_QWORD *)a1;
    memset(s, 0, 194);
    if ( (ucfg_pmo_is_mc_addr_list_enabled(v33) & 1) == 0 )
    {
      v17 = scnprintf(v32, v25, "\nMC addr ini is disabled\n");
      goto LABEL_12;
    }
    if ( (unsigned int)ucfg_pmo_get_mc_addr_list(
                         *(_QWORD *)a1,
                         *(unsigned __int8 *)(*(_QWORD *)(v30 + 3680) + 8LL),
                         s,
                         v34,
                         v35,
                         v36,
                         v37,
                         v38,
                         v39,
                         v40,
                         v41) )
    {
      v17 = scnprintf(v32, v25, "\nMC addr list query is failed\n");
LABEL_12:
      v25 = v42 & (unsigned int)~(v42 >> 31);
      goto LABEL_13;
    }
    if ( !BYTE1(s[0]) )
    {
      v17 = scnprintf(v32, v25, "\nMC addr list is empty\n");
      goto LABEL_12;
    }
    v17 = scnprintf(v32, v25, "\nMC ADDR LIST DETAILS (mc_cnt = %u)\n", BYTE1(s[0]));
    if ( (int)v60 < 1 )
    {
      v25 = 0;
      goto LABEL_13;
    }
    v62 = (unsigned int)v60;
    if ( BYTE1(s[0]) )
    {
      v63 = 0;
      v64 = 0;
      while ( 1 )
      {
        v65 = v25 - v62;
        if ( v25 <= v62 )
          break;
        if ( v64 == 32 )
          goto LABEL_74;
        if ( (unsigned __int64)(v63 - 188) < 0xFFFFFFFFFFFFFF3DLL
          || (unsigned __int64)(v63 - 190) < 0xFFFFFFFFFFFFFF3ELL
          || (unsigned __int64)(v63 - 192) < 0xFFFFFFFFFFFFFF3DLL )
        {
          __break(1u);
LABEL_74:
          __break(0x5512u);
          return wlan_hdd_debugfs_update_roam_stats(v60, v65, (unsigned int)((int)((_DWORD)v65 << 22) >> 20), v61);
        }
        v17 = scnprintf(
                v32 + v62,
                v65,
                "%02x:%02x:%02x:**:**:%02x\n",
                *((unsigned __int8 *)s + v63 + 2),
                *((unsigned __int8 *)s + v63 + 3),
                *((unsigned __int8 *)s + v63 + 4),
                *((unsigned __int8 *)s + v63 + 7));
        if ( (int)v60 < 1 )
        {
          v25 = v62;
          goto LABEL_13;
        }
        ++v64;
        v62 += (unsigned int)v60;
        v63 += 6;
        if ( v64 >= BYTE1(s[0]) )
          goto LABEL_28;
      }
    }
    else
    {
LABEL_28:
      if ( v25 > v62 )
      {
        v17 = scnprintf(v32 + v62, v25 - v62, "mc_filter_applied = %u\n", LOBYTE(s[0]));
        if ( v66 < 1 )
          v25 = v62;
        else
          v25 = v62 + (unsigned int)v66;
LABEL_13:
        v45 = v25 + v31;
        if ( a4 <= v45 )
          goto LABEL_63;
        v46 = *(_QWORD *)(v30 + 3680);
        LODWORD(s[1]) = 0;
        s[0] = 0;
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(v46, 0x56u, (__int64)"wlan_hdd_arp_offload_info_debugfs");
        if ( vdev_by_user )
        {
          v48 = vdev_by_user;
          arp_offload_params = ucfg_pmo_get_arp_offload_params(vdev_by_user, s, v17, v18, v19, v20, v21, v22, v23, v24);
          _hdd_objmgr_put_vdev_by_user(
            v48,
            0x56u,
            (__int64)"wlan_hdd_arp_offload_info_debugfs",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58);
          if ( arp_offload_params )
            v17 = scnprintf(a3 + v45, a4 - v45, "\nARP OFFLOAD QUERY FAILED\n");
          else
            v17 = (s[1] & 0x1000000LL) != 0
                ? scnprintf(
                    a3 + v45,
                    a4 - v45,
                    "\nARP OFFLOAD: ENABLED (%u.%u.%u.%u)\n",
                    BYTE1(s[0]),
                    BYTE2(s[0]),
                    BYTE3(s[0]),
                    BYTE4(s[0]))
                : scnprintf(a3 + v45, a4 - v45, "\nARP OFFLOAD: DISABLED\n");
          v67 = v59 & (unsigned int)~(v59 >> 31);
        }
        else
        {
          v67 = 0;
        }
        v68 = v67 + v45;
        v69 = a4 - (v67 + v45);
        if ( a4 <= v67 + v45 )
          goto LABEL_63;
        memset(s, 0, 0x28Cu);
        v70 = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v30 + 3680), 0x56u, (__int64)"wlan_hdd_ns_offload_info_debugfs");
        if ( !v70 )
          goto LABEL_57;
        v71 = a3 + v68;
        v72 = v70;
        ns_offload_params = ucfg_pmo_get_ns_offload_params();
        _hdd_objmgr_put_vdev_by_user(
          v72,
          0x56u,
          (__int64)"wlan_hdd_ns_offload_info_debugfs",
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82);
        if ( ns_offload_params )
        {
          v17 = scnprintf(a3 + v68, v69, "\nNS OFFLOAD QUERY FAILED\n");
          v84 = v83 & (unsigned int)~(v83 >> 31);
          goto LABEL_58;
        }
        v17 = scnprintf(a3 + v68, v69, "\nNS OFFLOAD DETAILS\n");
        if ( (int)v85 < 1 )
        {
LABEL_57:
          v84 = 0;
          goto LABEL_58;
        }
        v84 = v85;
        v86 = v69 - v85;
        if ( v69 <= v85 )
          goto LABEL_68;
        v87 = v85;
        if ( (s[81] & 1) != 0 )
        {
          v17 = scnprintf(v71 + v85, v86, "NS offload enabled, %u ns addresses offloaded\n", HIDWORD(s[0]));
          if ( v88 >= 1 )
          {
            v84 = v88 + v87;
            if ( HIDWORD(s[0]) )
            {
              v89 = 0;
              v90 = 35;
              while ( 1 )
              {
                memset(v103, 0, 47);
                memset(v102, 0, 12);
                if ( v69 <= v84 )
                  break;
                scnprintf(
                  v103,
                  47,
                  "%02x%02x::%02x%02x::%02x%02x::%02x%02x::%02x%02x::%02x%02x::%02x%02x::%02x%02x",
                  LOBYTE(s[v90]),
                  BYTE1(s[v90]),
                  BYTE2(s[v90]),
                  BYTE3(s[v90]),
                  BYTE4(s[v90]),
                  BYTE5(s[v90]),
                  BYTE6(s[v90]),
                  HIBYTE(s[v90]),
                  LOBYTE(s[v90 + 1]),
                  BYTE1(s[v90 + 1]),
                  BYTE2(s[v90 + 1]),
                  BYTE3(s[v90 + 1]),
                  BYTE4(s[v90 + 1]),
                  BYTE5(s[v90 + 1]),
                  BYTE6(s[v90 + 1]),
                  HIBYTE(s[v90 + 1]));
                if ( v89 == 16 )
                  goto LABEL_74;
                v91 = "Invalid";
                v92 = *((_DWORD *)&s[73] + v89) - 1;
                if ( v92 <= 4 )
                  v91 = off_B2F468[v92];
                if ( *((_BYTE *)&s[69] + v89 + 7) == 1 )
                  v93 = "(ANY CAST)";
                else
                  v93 = "(UNI CAST)";
                v94 = *(_QWORD *)v93;
                ++v89;
                strcpy((char *)v102 + 7, "ST)");
                v102[0] = v94;
                v17 = scnprintf(
                        a3 + v68 + v84,
                        v69 - v84,
                        "%u. %s %s and scope is: %s\n",
                        v89,
                        (const char *)v103,
                        (const char *)v102,
                        v91);
                if ( v95 > 0 )
                {
                  v84 += (unsigned int)v95;
                  v90 += 2;
                  if ( v89 < HIDWORD(s[0]) )
                    continue;
                }
                goto LABEL_58;
              }
LABEL_68:
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: No sufficient buf_avail_len",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "wlan_hdd_ns_offload_info_debugfs");
              v84 = v69;
            }
          }
        }
        else
        {
          v17 = scnprintf(v71 + v85, v86, "NS offload is not enabled\n", v17);
          if ( v101 >= 1 )
            v84 = v101 + v87;
        }
LABEL_58:
        v96 = v84 + v68;
        if ( a4 > v96 )
        {
          if ( *(_DWORD *)(a1 + 3608) <= 2u )
            v97 = (unsigned __int8 *)(a1 + 3612);
          else
            v97 = (unsigned __int8 *)(v30 + 3112);
          v17 = scnprintf(a3 + v96, a4 - v96, "\nAPF OFFLOAD DETAILS, offload_applied: %u\n\n", *v97, v17);
          v99 = "%s: exit";
          a4 = v96 + (v98 & (unsigned int)~(v98 >> 31));
          v100 = 8;
          goto LABEL_64;
        }
LABEL_63:
        v99 = "%s: No sufficient buf_avail_len";
        v100 = 2;
LABEL_64:
        qdf_trace_msg(0x33u, v100, v99, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_debugfs_update_filters_info");
        result = a4;
        goto LABEL_65;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: No sufficient buf_avail_len",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_hdd_mc_addr_list_info_debugfs");
    goto LABEL_13;
  }
  scnprintf(v32, v25, "\nSTA is not connected\n");
  v28 = v43;
  v44 = v43 < 1;
  result = v31;
  if ( !v44 )
LABEL_10:
    result += (unsigned int)v28;
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
