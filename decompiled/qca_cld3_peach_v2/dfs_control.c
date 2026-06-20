__int64 __fastcall dfs_control(
        __int64 a1,
        int a2,
        unsigned int *a3,
        unsigned int a4,
        __int64 a5,
        _DWORD *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x8
  __int64 result; // x0
  bool v17; // zf
  const char *v20; // x2
  char v21; // w11
  char v22; // w11
  __int64 v27; // x19
  unsigned int *v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int *v54; // x8
  __int64 v55; // x22
  __int64 i; // x23
  unsigned int *v57; // x8
  int v58; // w9
  int v59; // w10
  unsigned int v61; // w9
  const char *v62; // x2
  _BOOL4 v63; // w9
  __int64 v64; // x4
  unsigned int v66; // w9
  int v68; // w9
  __int64 v69; // x10
  int v70; // w8
  __int64 v71; // x9
  int v72; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v75; // x19
  __int64 v76; // x8
  __int64 v82; // [xsp+0h] [xbp-90h]
  __int64 v83; // [xsp+8h] [xbp-88h]
  __int64 v84; // [xsp+10h] [xbp-80h]
  __int64 v85; // [xsp+18h] [xbp-78h]
  __int64 v86; // [xsp+20h] [xbp-70h]
  __int64 v87; // [xsp+28h] [xbp-68h]
  __int64 v88; // [xsp+30h] [xbp-60h]
  __int64 v89; // [xsp+38h] [xbp-58h]
  __int64 v90; // [xsp+40h] [xbp-50h]
  __int64 v91; // [xsp+48h] [xbp-48h]
  __int64 v92; // [xsp+50h] [xbp-40h]
  __int64 v93; // [xsp+58h] [xbp-38h]
  __int64 v94; // [xsp+60h] [xbp-30h] BYREF
  __int64 v95; // [xsp+68h] [xbp-28h]
  __int128 v96; // [xsp+70h] [xbp-20h]
  int v97; // [xsp+80h] [xbp-10h]
  __int64 v98; // [xsp+88h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97 = 0;
  v96 = 0u;
  v94 = 0;
  v95 = 0;
  if ( a1 )
  {
    v14 = a1 + 12288;
    switch ( a2 )
    {
      case 1:
        result = 4294967274LL;
        if ( a3 && a4 >= 4 )
        {
          result = 0;
          *(_DWORD *)(a1 + 160) = 1000 * *a3;
        }
        break;
      case 2:
        if ( a3 && a4 > 0x1F || (*(_BYTE *)(a1 + 1) & 2) == 0 )
          goto LABEL_56;
        qdf_trace_msg(
          0x27u,
          8u,
          "WLAN_DEBUG_DFS1 : %s: insize = %d, expected = %zu bytes, indata = %pK",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "dfs_control",
          a4,
          32,
          a3);
        result = 4294967274LL;
        break;
      case 3:
        result = 4294967274LL;
        if ( a5 && a6 && *a6 >= 0x20u )
        {
          *a6 = 32;
          qdf_mem_set(&v94, 0x24u, 0);
          v68 = HIDWORD(v94);
          v69 = v95;
          result = 0;
          *(_DWORD *)a5 = v94;
          *(_DWORD *)(a5 + 4) = v68;
          v70 = v96;
          v71 = *(_QWORD *)((char *)&v96 + 4);
          *(_QWORD *)(a5 + 8) = v69;
          *(_DWORD *)(a5 + 16) = v70;
          v72 = HIDWORD(v96);
          *(_QWORD *)(a5 + 20) = v71;
          *(_DWORD *)(a5 + 28) = v72;
        }
        break;
      case 4:
        result = 4294967274LL;
        if ( a5 && a6 && *a6 >= 4u )
        {
          v29 = (unsigned int *)a1;
          *a6 = 4;
          *(_DWORD *)a5 = *(_DWORD *)(a1 + 14960);
          qdf_trace_msg(
            0x27u,
            8u,
            "WLAN_DEBUG_DFS_ALWAYS : %s: #Phyerr=%d, #false detect=%d, #queued=%d",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "dfs_control",
            *(unsigned int *)(a1 + 14608),
            *(unsigned int *)(a1 + 14612),
            *(unsigned int *)(a1 + 14616));
          qdf_trace_msg(
            0x27u,
            4u,
            "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_phyerr_freq_min=%d, dfs_phyerr_freq_max=%d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "dfs_control",
            v29[3655],
            v29[3656]);
          qdf_trace_msg(
            0x27u,
            4u,
            "WLAN_DEBUG_DFS_ALWAYS : %s: Total radar events detected=%d, entries in the radar queue follows:",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "dfs_control",
            v29[3650]);
          v54 = v29;
          v55 = 0;
          for ( i = 0; i != 256; ++i )
          {
            if ( i >= (int)v54[3650] )
              break;
            if ( (*((_BYTE *)v54 + 1) & 1) != 0 )
            {
              v57 = &v54[v55];
              v58 = v57[73];
              if ( v58 >= 0 )
                v59 = v57[73];
              else
                v59 = -v58;
              LODWORD(v92) = *((char *)v57 + 313);
              LODWORD(v91) = *((unsigned __int8 *)v57 + 312);
              LODWORD(v93) = *((__int16 *)v57 + 157);
              LODWORD(v90) = v57[77];
              LODWORD(v89) = v57[76];
              LODWORD(v88) = v57[75];
              LODWORD(v87) = v57[74];
              LODWORD(v84) = v57[72];
              LODWORD(v83) = *((unsigned __int8 *)v57 + 284);
              LODWORD(v82) = v57[70];
              LODWORD(v85) = v58 / 1000;
              LODWORD(v86) = v59 % 1000;
              qdf_trace_msg(
                0x27u,
                8u,
                "WLAN_DEBUG_DFS : %s: ts=%llu diff_ts=%u rssi=%u dur=%u, is_chirp=%d, seg_id=%d, sidx=%d, freq_offset=%d."
                "%dMHz, peak_mag=%d, total_gain=%d, mb_gain=%d, relpwr_db=%d, delta_diff=%d, delta_peak=%d, psidx_diff=%d\n",
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                "dfs_control",
                *((_QWORD *)v57 + 33),
                v57[68],
                *((unsigned __int8 *)v57 + 276),
                *((unsigned __int8 *)v57 + 277),
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93);
              v54 = v29;
            }
            v55 += 14;
          }
          result = 0;
          v54[3650] = 0;
          *((_QWORD *)v54 + 1826) = 0;
          *((_QWORD *)v54 + 1827) = 0x7FFFFFFF00000000LL;
          v54[3656] = 0;
        }
        break;
      case 5:
        result = 4294967274LL;
        if ( a3 && a4 >= 4 )
        {
          result = 0;
          *(_DWORD *)(a1 + 14960) = *a3;
        }
        break;
      case 6:
        result = 4294967274LL;
        if ( a5 && a6 && *a6 >= 4u )
        {
          result = 0;
          *a6 = 4;
          *(_DWORD *)a5 = *(_DWORD *)(a1 + 88);
        }
        break;
      case 7:
      case 23:
      case 24:
      case 27:
        goto LABEL_7;
      case 8:
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v75 = a1;
          raw_spin_lock(a1 + 14968);
        }
        else
        {
          raw_spin_lock_bh(a1 + 14968);
          v75 = a1;
          *(_QWORD *)(a1 + 14976) |= 1uLL;
        }
        dfs_print_nol(v75);
        v76 = *(_QWORD *)(v75 + 14976);
        if ( (v76 & 1) != 0 )
        {
          *(_QWORD *)(v75 + 14976) = v76 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v75 + 14968);
        }
        else
        {
          raw_spin_unlock(v75 + 14968);
        }
        goto LABEL_7;
      case 9:
        v21 = *(_BYTE *)(a1 + 14852);
        *(_DWORD *)(a1 + 8) &= 0x5FFFFFFFu;
        *(_BYTE *)(a1 + 14852) = v21 | 4;
        qdf_trace_msg(
          0x27u,
          8u,
          "WLAN_DEBUG_DFS_ALWAYS : %s: enable detects, ignore_dfs %d",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "dfs_control",
          1);
        goto LABEL_7;
      case 10:
        v22 = *(_BYTE *)(a1 + 14852);
        v20 = "WLAN_DEBUG_DFS_ALWAYS : %s: enable detects, ignore_dfs %d";
        *(_DWORD *)(a1 + 8) |= 0xA0000000;
        *(_BYTE *)(a1 + 14852) = v22 & 0xFB;
        goto LABEL_64;
      case 11:
        v20 = "WLAN_DEBUG_DFS_ALWAYS : %s: TODO disable FFT val=0x%x";
        goto LABEL_64;
      case 12:
        v20 = "WLAN_DEBUG_DFS_ALWAYS : %s: TODO enable FFT val=0x%x";
LABEL_64:
        qdf_trace_msg(0x27u, 8u, v20, a7, a8, a9, a10, a11, a12, a13, a14, "dfs_control", 0);
        goto LABEL_7;
      case 13:
        result = 4294967274LL;
        if ( a3 && a4 >= 4 )
        {
          v27 = a1;
          *(_DWORD *)a1 = *a3 & 0x7FFFFFFF;
          qdf_trace_msg(
            0x27u,
            8u,
            "WLAN_DEBUG_DFS_ALWAYS : %s: debug level now = 0x%x",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "dfs_control");
          if ( (*(_BYTE *)(v27 + 1) & 8) != 0 )
          {
            result = 0;
            *(_DWORD *)(v27 + 14604) = 1;
          }
          else
          {
            utils_get_dfsdomain(*(_QWORD *)(v27 + 14936));
            result = 0;
            *(_DWORD *)(v27 + 14604) = 0;
          }
        }
        break;
      case 14:
        result = 4294967274LL;
        if ( !a5 || !a6 || *a6 < 0x268u )
          break;
        *a6 = 616;
        qdf_spin_lock_bh_17(a1 + 14968);
        dfs_get_nol(a1, a5 + 8, a5);
        qdf_spin_unlock_bh_22(a1 + 14968);
        qdf_spin_lock_bh_17(a1 + 14968);
        dfs_print_nol(a1);
        qdf_spin_unlock_bh_22(a1 + 14968);
        goto LABEL_7;
      case 15:
        result = 4294967274LL;
        if ( !a3 || a4 < 0x268 )
          break;
        dfs_set_nol(a1, a3 + 2, *a3);
        goto LABEL_7;
      case 16:
        result = 4294967274LL;
        if ( !a3 || a4 < 4 )
          break;
        v64 = *a3;
        v62 = "WLAN_DEBUG_DFS_ALWAYS : %s: false RSSI threshold now = 0x%x";
        *(_DWORD *)(a1 + 256) = v64;
        goto LABEL_91;
      case 17:
        result = 4294967274LL;
        if ( !a3 || a4 < 4 )
          break;
        v64 = *a3;
        v62 = "WLAN_DEBUG_DFS_ALWAYS : %s: peak_mag now = 0x%x";
        *(_DWORD *)(a1 + 260) = v64;
        goto LABEL_91;
      case 18:
        result = 4294967274LL;
        if ( !a3 || a4 < 4 )
          break;
        v61 = *a3;
        v62 = "WLAN_DEBUG_DFS_ALWAYS : %s: ignore cac = 0x%x";
        v63 = v61 != 0;
        v64 = v63 & 0x1FFFFFFF;
        *(_BYTE *)(v14 + 2564) = *(_BYTE *)(v14 + 2564) & 0xF7 | (8 * v63);
        goto LABEL_91;
      case 19:
        result = 4294967274LL;
        if ( !a3 || a4 < 4 )
          break;
        v66 = *a3;
        v62 = "WLAN_DEBUG_DFS_ALWAYS : %s: nol timeout = %d sec";
        if ( v66 )
          v64 = v66;
        else
          v64 = 1800;
        *(_DWORD *)(a1 + 14632) = v64;
        goto LABEL_91;
      case 20:
        result = 4294967274LL;
        if ( a5 && a6 && *a6 >= 4u )
        {
          result = 0;
          *a6 = 4;
          *(_DWORD *)a5 = *(_DWORD *)(a1 + 14856);
        }
        break;
      case 21:
        result = 4294967274LL;
        if ( !a3 || a4 < 4 )
          break;
        v64 = *a3;
        v62 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs timeout = %d";
        *(_DWORD *)(a1 + 14856) = v64;
LABEL_91:
        qdf_trace_msg(0x27u, 8u, v62, a7, a8, a9, a10, a11, a12, a13, a14, "dfs_control", v64);
        goto LABEL_7;
      case 22:
        dfs_print_nolhistory();
        goto LABEL_7;
      case 25:
        if ( *(_BYTE *)(a1 + 14954) != 1 || (unsigned int)utils_get_dfsdomain(*(_QWORD *)(a1 + 14936)) != 1 )
          goto LABEL_7;
        v17 = a4 <= 3 || a3 == nullptr;
        goto LABEL_12;
      case 26:
        result = 4294967274LL;
        if ( !a5 || !a6 || !*a6 )
          break;
        if ( *(_BYTE *)(v14 + 2666) != 1 )
          goto LABEL_7;
        result = 0;
        *a6 = 1;
        *(_BYTE *)a5 = 0;
        break;
      case 28:
        if ( a4 )
          v17 = a3 == nullptr;
        else
          v17 = 1;
LABEL_12:
        if ( v17 )
          result = 4294967274LL;
        else
          result = 0;
        break;
      case 29:
        *(_DWORD *)(a1 + 14628) = *a3;
        qdf_trace_msg(
          0x27u,
          8u,
          "WLAN_DEBUG_DFS_ALWAYS : %s: Set dfs pri multiplier to %d, dfsdomain %d",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "dfs_control");
        goto LABEL_7;
      default:
LABEL_56:
        result = 4294967274LL;
        break;
    }
  }
  else
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "dfs_control");
LABEL_7:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
