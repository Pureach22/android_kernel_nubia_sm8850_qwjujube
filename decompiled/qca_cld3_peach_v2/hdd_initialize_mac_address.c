__int64 __fastcall hdd_initialize_mac_address(__int64 a1)
{
  __int64 v2; // x21
  __int64 wlan_mac_address; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  char *v12; // x22
  unsigned __int8 *v13; // x23
  unsigned __int8 *v14; // x20
  unsigned int v15; // w9
  int v16; // w8
  unsigned __int64 v17; // x24
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w20
  __int64 v39; // x9
  __int64 wlan_derived_mac_address; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  char *v49; // x21
  unsigned int v50; // w8
  int v51; // w9
  unsigned int v52; // w8
  const char *v53; // x2
  unsigned __int64 v55; // x22
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  int v59; // w8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  int serial_number; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned __int64 v77; // x1
  int v78; // w8
  bool v79; // zf
  __int64 v80; // x8
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // [xsp+0h] [xbp-30h]
  _DWORD v90[3]; // [xsp+14h] [xbp-1Ch] BYREF
  unsigned int v91; // [xsp+20h] [xbp-10h] BYREF
  unsigned __int16 v92; // [xsp+24h] [xbp-Ch]
  __int64 v93; // [xsp+28h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 96);
  v90[0] = 0;
  v92 = 0;
  v91 = 0;
  wlan_mac_address = cnss_utils_get_wlan_mac_address(v2, v90);
  if ( !v90[0] || (v12 = (char *)wlan_mac_address) == nullptr )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: No mac configured from platform driver",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_platform_wlan_mac");
    v38 = -22;
    goto LABEL_25;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Resetting MAC address lists",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "hdd_free_mac_address_lists");
  v13 = (unsigned __int8 *)(a1 + 3759);
  qdf_mem_set((void *)(a1 + 3759), 0x2Au, 0);
  v14 = (unsigned __int8 *)(a1 + 3801);
  qdf_mem_set((void *)(a1 + 3801), 0x2Au, 0);
  v15 = v90[0];
  *(_QWORD *)(a1 + 3856) = 0;
  *(_QWORD *)(a1 + 3844) = 0;
  *(_QWORD *)(a1 + 3864) = 0;
  if ( v15 >= 8 )
    v90[0] = 7;
  qdf_mem_copy(&v91, v12, 6u);
  v16 = v90[0];
  if ( v90[0] )
  {
    v17 = 0;
    while ( v17 != 7 )
    {
      qdf_mem_copy(v13, v12, 6u);
      if ( v13 )
      {
        v18 = *v13;
        v19 = v13[1];
        v20 = v13[2];
        v21 = v13[5];
      }
      else
      {
        v20 = 0;
        v18 = 0;
        v19 = 0;
        v21 = 0;
      }
      LODWORD(v89) = v21;
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: provisioned MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_platform_wlan_mac",
        (unsigned int)v17,
        v18,
        v19,
        v20,
        v89);
      v16 = v90[0];
      ++v17;
      v12 += 6;
      v13 += 6;
      if ( v17 >= v90[0] )
        goto LABEL_13;
    }
LABEL_49:
    __break(0x5512u);
  }
LABEL_13:
  v39 = *(_QWORD *)(a1 + 104);
  *(_DWORD *)(a1 + 3844) = v16;
  if ( (*(_BYTE *)(v39 + 126) & 1) != 0 )
  {
    wlan_derived_mac_address = cnss_utils_get_wlan_derived_mac_address(v2, v90);
    v49 = (char *)wlan_derived_mac_address;
    if ( v90[0] && wlan_derived_mac_address )
    {
      v50 = 7 - *(_DWORD *)(a1 + 3844);
      if ( v90[0] > v50 )
      {
        v90[0] = 7 - *(_DWORD *)(a1 + 3844);
        if ( !v50 )
        {
LABEL_18:
          v51 = 0;
LABEL_19:
          v16 = *(_DWORD *)(a1 + 3844);
          *(_DWORD *)(a1 + 3848) = v51;
          goto LABEL_21;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: No derived address from platform driver",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hdd_platform_wlan_mac");
      if ( !v90[0] )
        goto LABEL_18;
    }
    v55 = 0;
    while ( v55 != 7 )
    {
      qdf_mem_copy(v14, v49, 6u);
      if ( v14 )
      {
        v56 = *v14;
        v57 = v14[1];
        v58 = v14[2];
        v59 = v14[5];
      }
      else
      {
        v58 = 0;
        v56 = 0;
        v57 = 0;
        v59 = 0;
      }
      LODWORD(v89) = v59;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: derived MAC Addr [%d] %02x:%02x:%02x:**:**:%02x",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "hdd_platform_wlan_mac",
        (unsigned int)v55,
        v56,
        v57,
        v58,
        v89);
      v51 = v90[0];
      ++v55;
      v49 += 6;
      v14 += 6;
      if ( v55 >= v90[0] )
        goto LABEL_19;
    }
    goto LABEL_49;
  }
  v51 = *(_DWORD *)(a1 + 3848);
LABEL_21:
  v52 = v16 + v51;
  v90[0] = v52;
  if ( v52 <= 6 )
    ((void (__fastcall *)(__int64, _QWORD))hdd_populate_random_mac_addr)(a1, 7 - v52);
  if ( !(unsigned int)sme_set_custom_mac_addr(&v91) )
  {
    v53 = "%s: using MAC address from platform driver";
    goto LABEL_32;
  }
  v38 = -11;
LABEL_25:
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 104) + 126LL) != 1 )
  {
    if ( (unsigned int)hdd_update_mac_config(a1, v30, v31, v32, v33, v34, v35, v36, v37) )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: using default MAC address",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_initialize_mac_address");
      if ( *(_DWORD *)(a1 + 3753) | *(unsigned __int16 *)(a1 + 3757) )
      {
        hdd_update_macaddr(
          (_DWORD *)a1,
          *(unsigned int *)(a1 + 3753) | ((unsigned __int64)*(unsigned __int16 *)(a1 + 3757) << 32),
          0);
      }
      else
      {
        serial_number = pld_socinfo_get_serial_number(*(_QWORD *)(a1 + 96));
        if ( serial_number )
        {
          v77 = bswap64(serial_number & 0xFFFFFF | 0xAF5000000LL) >> 16;
        }
        else
        {
          v92 = 0;
          v91 = 0;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: MAC failure from device serial no.",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "hdd_initialize_mac_address");
          get_random_bytes(&v91, 6);
          LOBYTE(v91) = 2;
          v77 = v91 | ((unsigned __int64)v92 << 32);
        }
        hdd_update_macaddr((_DWORD *)a1, v77, 1);
        v78 = *(_DWORD *)(a1 + 3844);
        v92 = 0;
        v79 = v78 == 0;
        v80 = 3759;
        v91 = 0;
        if ( v79 )
          v80 = 3801;
        qdf_mem_copy(&v91, (const void *)(a1 + v80), 6u);
        if ( (unsigned int)sme_set_custom_mac_addr(&v91) )
        {
          v38 = -11;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: MAC address out-of-sync, ret:%d",
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            "hdd_initialize_mac_address",
            4294967285LL);
          goto LABEL_34;
        }
      }
      goto LABEL_33;
    }
    v53 = "%s: using MAC address from wlan_mac.bin";
LABEL_32:
    qdf_trace_msg(0x33u, 4u, v53, v30, v31, v32, v33, v34, v35, v36, v37, "hdd_initialize_mac_address");
LABEL_33:
    v38 = 0;
    goto LABEL_34;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: getting MAC address from platform driver failed",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hdd_initialize_mac_address");
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return v38;
}
