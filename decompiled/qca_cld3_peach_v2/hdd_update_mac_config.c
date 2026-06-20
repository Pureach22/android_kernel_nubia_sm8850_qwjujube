__int64 __fastcall hdd_update_mac_config(
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
  __int64 v9; // x8
  unsigned int v11; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x20
  size_t v30; // x0
  __int64 v31; // x21
  __int64 v32; // x24
  unsigned __int64 v33; // x27
  __int64 v34; // x23
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  char *v61; // x0
  char *v62; // x25
  int v63; // w8
  char *v64; // x0
  int v65; // t1
  char *v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w8
  char *v76; // x22
  int v77; // w8
  size_t v78; // x0
  _BYTE *v79; // x0
  _BYTE *v80; // x23
  const char *v81; // x23
  char **v82; // x8
  unsigned int v83; // w19
  unsigned int v84; // w21
  __int64 v85; // x8
  __int64 v86; // [xsp+0h] [xbp-110h]
  const void **v87; // [xsp+8h] [xbp-108h] BYREF
  int v88; // [xsp+10h] [xbp-100h] BYREF
  __int16 v89; // [xsp+14h] [xbp-FCh]
  __int64 v90; // [xsp+20h] [xbp-F0h] BYREF
  __int64 *v91; // [xsp+28h] [xbp-E8h]
  __int64 v92; // [xsp+30h] [xbp-E0h]
  __int64 v93; // [xsp+38h] [xbp-D8h]
  __int64 v94; // [xsp+40h] [xbp-D0h]
  __int64 v95; // [xsp+48h] [xbp-C8h]
  __int64 v96; // [xsp+50h] [xbp-C0h]
  __int64 v97; // [xsp+58h] [xbp-B8h]
  __int64 v98; // [xsp+60h] [xbp-B0h]
  __int64 v99; // [xsp+68h] [xbp-A8h]
  __int64 v100; // [xsp+70h] [xbp-A0h]
  __int64 v101; // [xsp+78h] [xbp-98h]
  __int64 v102; // [xsp+80h] [xbp-90h]
  __int64 v103; // [xsp+88h] [xbp-88h]
  __int64 v104; // [xsp+90h] [xbp-80h] BYREF
  __int64 v105; // [xsp+98h] [xbp-78h] BYREF
  __int64 v106; // [xsp+A0h] [xbp-70h]
  __int64 v107; // [xsp+A8h] [xbp-68h]
  __int64 v108; // [xsp+B0h] [xbp-60h]
  __int64 v109; // [xsp+B8h] [xbp-58h]
  __int64 v110; // [xsp+C0h] [xbp-50h]
  int v111; // [xsp+C8h] [xbp-48h]
  __int64 v112; // [xsp+D0h] [xbp-40h] BYREF
  __int64 v113; // [xsp+D8h] [xbp-38h]
  __int64 v114; // [xsp+E0h] [xbp-30h]
  __int64 v115; // [xsp+E8h] [xbp-28h]
  __int64 v116; // [xsp+F0h] [xbp-20h]
  __int16 v117; // [xsp+F8h] [xbp-18h]
  __int64 v118; // [xsp+100h] [xbp-10h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 104);
  v87 = nullptr;
  v111 = 0;
  LOBYTE(v9) = *(_BYTE *)(v9 + 180);
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  v104 = 0;
  v89 = 0;
  v88 = 0;
  if ( (v9 & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Reading MAC address from MAC file is not enabled.",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_update_mac_config");
    result = 16;
    goto LABEL_65;
  }
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = nullptr;
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: zte_wlan_mac_file = %s \n",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_update_mac_config",
    "wlan/qca_cld/peach_v2/wifimac.dat");
  v11 = request_firmware(&v87, "wlan/qca_cld/peach_v2/wifimac.dat", *(_QWORD *)(a1 + 96));
  if ( v11 || !v87 || !v87[1] || !*v87 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: request_firmware for ZTE mac address failed; status: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_update_mac_config",
      v11);
    if ( v87 )
      release_firmware(v87);
    v52 = firmware_request_nowarn(&v87, "wlan/qca_cld/peach_v2/wlan_mac.bin", *(_QWORD *)(a1 + 96));
    if ( !v52 )
    {
      if ( v87 && v87[1] && *v87 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: wlan_mac.bin size %zu",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "hdd_update_mac_config");
        v61 = (char *)_qdf_mem_malloc((size_t)*v87 + 1, "hdd_update_mac_config", 284);
        v29 = v61;
        if ( v61 )
        {
          qdf_mem_copy(v61, v87[1], *(unsigned int *)v87);
          v31 = 0;
          v62 = (char *)v29;
          *((_BYTE *)*v87 + (_QWORD)v29) = 0;
          while ( 1 )
          {
            while ( 1 )
            {
              v63 = (unsigned __int8)*v62;
              v64 = v62;
              if ( *v62 && (++v62, v63) )
              {
                while ( v63 != 10 && v63 != 13 )
                {
                  v65 = (unsigned __int8)*v62++;
                  v63 = v65;
                  if ( !v65 )
                    goto LABEL_36;
                }
                *(v62 - 1) = 0;
              }
              else
              {
LABEL_36:
                v62 = nullptr;
              }
              v66 = (char *)i_trim(v64);
              if ( *v66 )
              {
                v75 = (unsigned __int8)*v66;
                v76 = v66;
                if ( v75 != 35 )
                {
                  v77 = v75 - 69;
                  if ( !v77 )
                  {
                    v77 = (unsigned __int8)v66[1] - 78;
                    if ( v66[1] == 78 )
                      v77 = (unsigned __int8)v66[2] - 68;
                  }
                  if ( !v77 )
                    goto LABEL_58;
                  v78 = strlen(v66);
                  v79 = (_BYTE *)strnchr(v76, v78, 61);
                  if ( v79 )
                  {
                    v80 = v79;
                    *v79 = 0;
                    i_trim(v76);
                    if ( *v76 )
                    {
                      v81 = (const char *)i_trim(v80 + 1);
                      v30 = strlen(v81);
                      if ( v30 == 12 )
                        break;
                    }
                  }
                }
              }
              if ( !v62 )
                goto LABEL_58;
            }
            if ( (unsigned int)v31 > 6 )
            {
LABEL_67:
              __break(0x5512u);
              goto LABEL_68;
            }
            v82 = (char **)(&v90 + 2 * (unsigned int)v31);
            *v82 = v76;
            if ( ((16LL * (unsigned int)v31) | 8uLL) > 0x70 )
              goto LABEL_68;
            v82[1] = (char *)v81;
            if ( (_DWORD)v31 == 6 )
              break;
            v31 = (unsigned int)(v31 + 1);
            if ( !v62 )
              goto LABEL_58;
          }
          v31 = 7;
LABEL_58:
          if ( !(_DWORD)v31 || (int)v31 >= 8 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid number of Mac address provided, nMac = %d",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "hdd_update_mac_config",
              (unsigned int)v31);
            goto LABEL_53;
          }
          v30 = qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: %d Mac addresses provided",
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  "hdd_update_mac_config",
                  (unsigned int)v31);
          v117 = 0;
          v115 = 0;
          v116 = 0;
          v113 = 0;
          v114 = 0;
          v112 = 0;
          if ( (int)v31 >= 1 )
            goto LABEL_8;
LABEL_61:
          *(_DWORD *)(a1 + 3844) = v31;
          v84 = 7 - v31;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Populating remaining %d Mac addresses",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "hdd_update_mac_config",
            v84,
            v86);
          ((void (__fastcall *)(__int64, _QWORD))hdd_populate_random_mac_addr)(a1, v84);
          v85 = 3759;
          if ( !*(_DWORD *)(a1 + 3844) )
            v85 = 3801;
          qdf_mem_copy(&v88, (const void *)(a1 + v85), 6u);
          v83 = sme_set_custom_mac_addr(&v88);
        }
        else
        {
          v83 = 2;
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          1u,
          "%s: invalid firmware",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "hdd_update_mac_config");
        v29 = nullptr;
LABEL_53:
        v83 = 4;
      }
      goto LABEL_64;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: request_firmware failed; status:%d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "hdd_update_mac_config",
      v52);
    result = 16;
LABEL_65:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  qdf_trace_msg(
    0x33u,
    4u,
    "%s: wifimac.dat size is %zu",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "hdd_update_mac_config");
  v20 = (char *)_qdf_mem_malloc((size_t)*v87 + 1, "hdd_update_mac_config", 249);
  v29 = v20;
  if ( !v20 )
  {
    v83 = 2;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to malloc memory",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hdd_update_mac_config");
LABEL_64:
    _qdf_mem_free((__int64)v29);
    release_firmware(v87);
    result = v83;
    goto LABEL_65;
  }
  qdf_mem_copy(v20, v87[1], *(unsigned int *)v87);
  *((_BYTE *)*v87 + (_QWORD)v29) = 0;
  v30 = sscanf(
          v29,
          "wifiaddr: 0x%s 0x%s 0x%s 0x%s 0x%s 0x%s",
          &v104,
          (char *)&v104 + 2,
          (char *)&v104 + 4,
          (char *)&v104 + 6,
          &v105,
          (char *)&v105 + 2);
  v91 = &v104;
  v31 = 1;
  v117 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v112 = 0;
LABEL_8:
  v32 = 0;
  v86 = v31;
  v33 = 8;
  while ( v33 <= 0x70 )
  {
    if ( v32 == 42 )
      goto LABEL_67;
    v34 = *(__int64 *)((char *)&v90 + v33);
    if ( (hex2bin((char *)&v112 + v32, v34, 1) & 0x80000000) != 0
      || (hex2bin((char *)&v112 + v32 + 1, v34 + 2, 1) & 0x80000000) != 0
      || (hex2bin((char *)&v112 + v32 + 2, v34 + 4, 1) & 0x80000000) != 0
      || (hex2bin((char *)&v112 + v32 + 3, v34 + 6, 1) & 0x80000000) != 0
      || (hex2bin((char *)&v112 + v32 + 4, v34 + 8, 1) & 0x80000000) != 0
      || (unsigned int)hex2bin((char *)&v112 + v32 + 5, v34 + 10, 1)
      || !(*(_DWORD *)((char *)&v112 + v32) | *(unsigned __int16 *)((char *)&v112 + v32 + 4)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid MAC addresses provided",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "hdd_update_mac_config",
        v31);
      v83 = 16;
      goto LABEL_64;
    }
    v30 = (size_t)qdf_mem_copy((void *)(a1 + 3759 + v32), (char *)&v112 + v32, 6u);
    v32 += 6;
    v33 += 16LL;
    if ( 6LL * (unsigned int)v31 == v32 )
      goto LABEL_61;
  }
LABEL_68:
  __break(1u);
  return i_trim((char *)v30);
}
