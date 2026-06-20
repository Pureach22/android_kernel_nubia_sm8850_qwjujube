__int64 __fastcall drv_cmd_get_dwell_time(
        int a1,
        __int64 *a2,
        char *s1,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v13; // x20
  int v16; // w20
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int8 v34; // w0
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
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  __int64 v60; // x20
  unsigned __int64 v61; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v63; // x9
  __int64 result; // x0
  unsigned int v65; // w21
  unsigned __int64 v66; // x9
  unsigned __int64 v72; // x8
  unsigned __int64 v73; // x8
  unsigned __int64 v75; // x9
  unsigned int active_6g_dwelltime; // w20
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned __int8 v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned __int8 v94; // w8
  int v95; // w0
  __int64 v96; // [xsp+0h] [xbp-30h] BYREF
  __int64 v97; // [xsp+8h] [xbp-28h] BYREF
  __int64 v98; // [xsp+10h] [xbp-20h]
  __int64 v99; // [xsp+18h] [xbp-18h]
  __int64 v100; // [xsp+20h] [xbp-10h]
  __int64 v101; // [xsp+28h] [xbp-8h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *a2;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  LODWORD(v96) = 0;
  if ( !s1 || !v13 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: argument passed for GETDWELLTIME is incorrect",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_get_dwell_time",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101);
LABEL_24:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to copy data to user buffer",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "drv_cmd_get_dwell_time",
      v96);
    result = 4294967282LL;
    goto LABEL_25;
  }
  if ( !strncmp(s1, "GETDWELLTIME ACTIVE MAX", 0x17u) )
  {
    wlan_scan_cfg_get_active_dwelltime(v13, &v96);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: active max dwelltime:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_get_dwell_time",
      (unsigned int)v96);
    scnprintf(&v97, 32, "GETDWELLTIME ACTIVE MAX %u\n", (unsigned int)v96);
    goto LABEL_15;
  }
  if ( !strncmp(s1, "GETDWELLTIME PASSIVE MAX", 0x18u) )
  {
    wlan_scan_cfg_get_passive_dwelltime(v13, &v96);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: passive dwelltime:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "hdd_get_dwell_time",
      (unsigned int)v96);
    scnprintf(&v97, 32, "GETDWELLTIME PASSIVE MAX %u\n", (unsigned int)v96);
    goto LABEL_15;
  }
  if ( !strncmp(s1, "GETDWELLTIME 2G MAX", 0x13u) )
  {
    wlan_scan_cfg_get_active_2g_dwelltime(v13, &v96);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: active 2g dwelltime:%d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "hdd_get_dwell_time",
      (unsigned int)v96);
    scnprintf(&v97, 32, "GETDWELLTIME 2G MAX %u\n", (unsigned int)v96);
    goto LABEL_15;
  }
  if ( !strncmp(s1, "GETDWELLTIME", 0xCu) )
  {
    wlan_scan_cfg_get_active_dwelltime(v13, &v96);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: active dwelltime:%d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "hdd_get_dwell_time",
      (unsigned int)v96);
    scnprintf(&v97, 32, "GETDWELLTIME %u\n", (unsigned int)v96);
LABEL_15:
    v59 = *(_DWORD *)(a13 + 12);
    if ( v59 > v34 )
      LOBYTE(v59) = v34 + 1;
    goto LABEL_17;
  }
  HIDWORD(v96) = 0;
  if ( !strncmp(s1, "GETDWELLTIME 6G MAX", 0x13u) )
  {
    active_6g_dwelltime = wlan_scan_cfg_get_active_6g_dwelltime(v13, (_DWORD *)&v96 + 1);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: active 6g dwelltime:%d",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "hdd_get_dwell_time_6g",
      HIDWORD(v96));
    if ( active_6g_dwelltime )
    {
LABEL_29:
      v17 = active_6g_dwelltime;
      v16 = 0;
      goto LABEL_32;
    }
    scnprintf(&v97, 32, "GETDWELLTIME 6G MAX %u\n", HIDWORD(v96));
  }
  else
  {
    if ( strncmp(s1, "GETDWELLTIME PASSIVE 6G MAX", 0x1Bu) )
    {
      v16 = 0;
      v17 = 4;
      goto LABEL_32;
    }
    active_6g_dwelltime = wlan_scan_cfg_get_passive_6g_dwelltime(v13, (_DWORD *)&v96 + 1);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: passive 6g dwelltime:%d",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "hdd_get_dwell_time_6g",
      HIDWORD(v96));
    if ( active_6g_dwelltime )
      goto LABEL_29;
    scnprintf(&v97, 32, "GETDWELLTIME PASSIVE 6G MAX %u\n", HIDWORD(v96));
  }
  v94 = v85;
  v17 = 0;
  v16 = v94;
LABEL_32:
  v95 = qdf_status_to_os_return(v17);
  v59 = *(_DWORD *)(a13 + 12);
  if ( v59 > v16 )
    LOBYTE(v59) = v16 + 1;
  if ( v95 )
    goto LABEL_24;
LABEL_17:
  v60 = (unsigned __int8)v59;
  if ( (unsigned __int8)v59 >= 0x21u )
  {
    _copy_overflow(32, (unsigned __int8)v59);
    goto LABEL_24;
  }
  v61 = *(_QWORD *)a13;
  _check_object_size(&v97, (unsigned __int8)v59, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v63 = v61, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v63 = v61 & ((__int64)(v61 << 8) >> 8);
  result = (unsigned int)v60;
  if ( 0x8000000000LL - v60 >= v63 )
  {
    v65 = v60;
    v66 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v72 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v72 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v72);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v66);
    v60 = _arch_copy_to_user(v61 & 0xFF7FFFFFFFFFFFFFLL, &v97, v60);
    result = v65;
    v73 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v75 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v75 - 4096);
    _WriteStatusReg(TTBR1_EL1, v75);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v73);
  }
  if ( v60 )
    goto LABEL_24;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
