__int64 __fastcall init_cmd_send_tlv(__int64 a1, __int64 a2)
{
  int v4; // w8
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x28
  __int64 v15; // x24
  __int64 v16; // x8
  __int64 **v17; // x0
  _DWORD *v18; // x22
  int v19; // w8
  char v20; // w8
  int v21; // w8
  unsigned int v22; // w8
  char v23; // w8
  int v24; // w8
  int v25; // w8
  int v26; // w9
  int v27; // w8
  unsigned int v28; // w8
  int v29; // w9
  int v30; // w9
  char v31; // w10
  int v32; // w11
  char v33; // w10
  unsigned int v34; // w10
  int v35; // w11
  int v36; // w10
  int v37; // w9
  int v38; // w9
  int v39; // w10
  int v40; // w9
  unsigned int v41; // w9
  int v42; // w9
  int v43; // w8
  unsigned int v44; // w8
  unsigned int v45; // w8
  unsigned int v46; // w8
  unsigned int v47; // w8
  int v48; // w9
  int v49; // w8
  int v50; // w9
  unsigned int v51; // w9
  __int64 v52; // x9
  __int64 (*v53)(void); // x9
  char v54; // w0
  unsigned int v55; // w19
  int v56; // w9
  unsigned int v57; // w9
  unsigned int v58; // w8
  _DWORD *v59; // x20
  unsigned int v60; // w8
  unsigned int v61; // w22
  const char *v62; // x2
  _DWORD *v63; // x19
  __int64 v64; // x10
  _QWORD *v65; // x9
  __int64 v66; // x10
  __int64 v67; // x9
  __int64 v68; // x6
  __int64 v69; // x7
  __int64 v70; // x4
  __int64 v71; // x5
  int v72; // w8
  int v73; // w11
  unsigned int v74; // w22
  int v75; // w8
  _DWORD *v76; // x20
  int v77; // w9
  __int64 v78; // x1
  __int64 (__fastcall *v79)(__int64, __int64); // x8
  unsigned int v80; // w8
  __int64 v81; // x1
  __int64 (__fastcall *v82)(__int64, __int64); // x8
  __int64 v83; // x1
  __int64 (__fastcall *v84)(__int64, __int64); // x8
  int v85; // w9
  int v86; // w9
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v112; // [xsp+0h] [xbp-40h]
  __int64 v113; // [xsp+8h] [xbp-38h]
  _QWORD v114[4]; // [xsp+20h] [xbp-20h] BYREF

  v114[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 24) == 11 )
    v4 = 0;
  else
    v4 = 16 * *(_DWORD *)(a2 + 28) + 20;
  v5 = wmi_buf_alloc_fl(a1, v4 + 1024, "init_cmd_send_tlv", 0x31FFu);
  if ( !v5 )
  {
    v55 = 16;
LABEL_108:
    _ReadStatusReg(SP_EL0);
    return v55;
  }
  v14 = *(_DWORD **)(v5 + 224);
  v15 = v5;
  *v14 = 4849692;
  v16 = **(_QWORD **)(a1 + 760);
  if ( !v16 || (v17 = *(__int64 ***)(v16 + 2808)) == nullptr )
  {
    qdf_trace_msg(0x31u, 2u, "%s: psoc handle is NULL", v6, v7, v8, v9, v10, v11, v12, v13, "wmi_copy_resource_config");
    goto LABEL_79;
  }
  v18 = *(_DWORD **)a2;
  v14[9] = **(_DWORD **)a2;
  v14[10] = v18[1];
  v14[11] = v18[3];
  v14[12] = v18[4];
  v14[13] = v18[5];
  v14[14] = v18[6];
  v14[15] = v18[7];
  v14[16] = v18[8];
  v14[17] = v18[9];
  v14[18] = v18[10];
  v14[19] = v18[11];
  v14[20] = v18[12];
  v14[21] = v18[13];
  v14[22] = v18[14];
  v14[23] = v18[15];
  v14[24] = v18[16];
  v14[25] = v18[17];
  v14[26] = v18[18];
  v14[27] = v18[19];
  v14[28] = v18[20];
  v14[29] = v18[21];
  v14[30] = v18[22];
  v14[31] = v18[23];
  v14[32] = v18[24];
  v14[33] = v18[25];
  v14[34] = v18[26];
  v14[35] = v18[27];
  v14[36] = v18[28];
  v14[37] = v18[29];
  v14[38] = v18[30];
  v14[39] = v18[45];
  v14[40] = v18[46];
  v14[41] = v18[47];
  v14[42] = v18[48];
  v14[43] = v18[49];
  v14[44] = v18[50];
  v14[45] = v18[51];
  v14[46] = v18[52];
  v14[47] = v18[53];
  v14[48] = v18[54];
  v14[49] = v18[55];
  v14[50] = v18[56];
  v14[51] = v18[57];
  v14[60] = v18[61];
  v14[61] = v18[62];
  v14[62] = v18[63];
  v14[63] = v18[64];
  v14[66] = v18[31];
  v14[70] = v18[58];
  v14[71] = v18[59];
  v14[72] = v18[68];
  v14[64] = v18[70];
  v14[78] = 16;
  v14[79] = v18[76];
  v14[80] = v18[77];
  v14[85] = v18[84];
  v14[86] = v18[88];
  v19 = v18[78];
  if ( v19 )
    v14[81] = v19;
  v14[82] = v18[79];
  v14[89] = v18[90];
  if ( *((_BYTE *)v18 + 373) == 1 )
    v14[77] |= 0x8000u;
  if ( *((_BYTE *)v18 + 374) == 1 )
    v14[76] |= 0x100000u;
  v14[90] = v18[91];
  v20 = *((_BYTE *)v18 + 168);
  if ( (v20 & 1) == 0 )
  {
    if ( (v18[42] & 2) == 0 )
      goto LABEL_15;
LABEL_67:
    v14[52] |= 0x200u;
    if ( (v18[42] & 4) == 0 )
      goto LABEL_17;
    goto LABEL_16;
  }
  v14[52] |= 0x40u;
  v20 = *((_BYTE *)v18 + 168);
  if ( (v20 & 2) != 0 )
    goto LABEL_67;
LABEL_15:
  if ( (v20 & 4) != 0 )
LABEL_16:
    v14[52] |= 0x400u;
LABEL_17:
  if ( *((_BYTE *)v18 + 260) == 1 )
    v14[52] |= 0x1000u;
  if ( v18[33] )
    v14[52] |= 0x80000000;
  if ( (v18[69] & 1) != 0 )
  {
    v21 = v14[52];
    v14[52] = v21 | 0x4000;
    if ( (~*((unsigned __int8 *)v18 + 276) & 6) != 0 )
    {
      v22 = v21 & 0xFFFC3FFF | 0xC000;
      v14[52] = v22;
      v14[52] = v22 & 0xFFFCFFFF | (((*((unsigned __int8 *)v18 + 276) >> 1) & 3) << 16);
    }
  }
  v23 = *((_BYTE *)v18 + 168);
  if ( (v23 & 8) != 0 )
  {
    v14[52] |= 0x80000u;
    v23 = *((_BYTE *)v18 + 168);
  }
  if ( (v23 & 0x10) != 0 )
    v14[52] |= 0x100000u;
  if ( *((_BYTE *)v18 + 277) == 1 )
    v14[52] |= 0x4000000u;
  v24 = v14[52];
  if ( *((_BYTE *)v18 + 278) == 1 )
  {
    v24 |= 0x1000000u;
    v14[52] = v24;
  }
  v25 = v24 | ((v18[42] & 0x20) << 22);
  v26 = v25 | 0x40000;
  v27 = v25 | 0x40080;
  v14[52] = v26;
  if ( !v18[43] )
    v27 = v26;
  v14[52] = v27 & 0xBFFFFFFF;
  v28 = v27 & 0xBFFFFFFF | ((v18[72] & 1) << 30);
  v14[52] = v28;
  if ( *((_BYTE *)v18 + 295) == 1 )
  {
    v28 |= 0x20000000u;
    v14[52] = v28;
  }
  v14[67] = v18[66];
  v14[68] = v18[67];
  v14[65] = *((unsigned __int8 *)v18 + 261);
  v14[53] = v18[35];
  if ( v18[71] )
  {
    v29 = v14[76];
    v14[76] = v29 & 0xFFFFFFF0;
    v14[76] = v29 & 0xFFFFFFF0 | v18[71] & 0xF;
  }
  if ( *((_BYTE *)v18 + 356) == 1 )
  {
    v30 = v14[76];
    v14[76] = v30 & 0xFFFFDFFF;
    v14[76] = v30 & 0xFFFFDFFF | ((v18[89] & 1) << 13);
  }
  v14[74] = 0;
  v31 = *(_DWORD *)((char *)v18 + 289);
  v14[74] = *(_DWORD *)((char *)v18 + 289) & 1;
  v32 = *(_DWORD *)((char *)v18 + 289) & 2 | v31 & 1;
  v14[74] = v32;
  v33 = *(_DWORD *)((char *)v18 + 289);
  v14[75] = 0;
  v14[74] = v33 & 4 | v32;
  v34 = *(_DWORD *)((char *)v18 + 289);
  v14[75] = (v34 >> 3) & 0xF;
  v35 = (*(_DWORD *)((char *)v18 + 289) >> 3) & 0xF0 | (v34 >> 3) & 0xF;
  v14[75] = v35;
  v36 = (*(_DWORD *)((char *)v18 + 289) >> 3) & 0xF00 | v35;
  v14[75] = v36;
  v37 = (*(_DWORD *)((char *)v18 + 289) >> 3) & 0xF000 | v36;
  v14[75] = v37;
  v38 = v37 | (*((unsigned __int8 *)v18 + 292) << 16);
  v39 = v14[77];
  v14[75] = v38;
  v40 = v38 | (*((unsigned __int8 *)v18 + 293) << 24);
  v14[77] = v39 & 0xFFFFFFFE;
  v14[75] = v40;
  v41 = v39 & 0xFFFEFFFE | *((unsigned __int8 *)v18 + 294) | 2;
  v14[77] = v41;
  v42 = v41 | (*((unsigned __int8 *)v18 + 375) << 16);
  v14[52] = v28 & 0xFF7FFFFF;
  v14[77] = v42;
  v14[52] = v28 & 0xFF7FFFFF | ((v18[80] & 1) << 23);
  if ( v18[81] )
    v14[76] |= 0x40u;
  if ( v18[82] )
    v14[76] |= 0x80u;
  if ( *((_BYTE *)v18 + 332) )
    v43 = v42 | 8;
  else
    v43 = v42;
  v14[77] = v43 & 0xFFFFFFEF;
  v44 = v43 & 0xFFFFDFEF | (16 * *((unsigned __int8 *)v18 + 296));
  v14[77] = v44;
  v45 = v44 & 0xFFFFFF7F | (*((unsigned __int8 *)v18 + 297) << 13);
  v14[77] = v45;
  v46 = v45 & 0xFFFFFE7F | (*((unsigned __int8 *)v18 + 344) << 7);
  v14[77] = v46;
  v47 = v46 & 0xFFFFFCFF | (*((unsigned __int8 *)v18 + 345) << 8);
  v14[77] = v47;
  v48 = v47 | (*((unsigned __int8 *)v18 + 346) << 9);
  v49 = v48 | 0x20;
  v14[77] = v48 | 0x20;
  if ( *((_BYTE *)v18 + 334) == 1 )
  {
    v49 = v48 | 0x60;
    v14[77] = v48 | 0x60;
  }
  if ( *((_BYTE *)v18 + 357) == 1 )
  {
    v49 |= 0x1000u;
    v14[77] = v49;
  }
  v50 = v14[76];
  v14[76] = v50 & 0xFFFFFFCF;
  v51 = v50 & 0xFFFFFFCF | (16 * (*((_BYTE *)v18 + 369) & 3));
  v14[76] = v51;
  if ( *((_BYTE *)v18 + 368) )
  {
    v51 |= 0x4000u;
    v14[76] = v51;
  }
  if ( *((_BYTE *)v18 + 370) == 1 )
  {
    v14[76] = v51 & 0xFFFDFFFF;
    v51 = v51 & 0xFFFDFFFF | ((*((_BYTE *)v18 + 370) & 1) << 17);
    v14[76] = v51;
  }
  if ( *((_BYTE *)v18 + 371) == 1 )
  {
    v14[76] = v51 & 0xFFFBFFFF;
    v14[76] = v51 & 0xFFFBFFFF | ((*((_BYTE *)v18 + 371) & 1) << 18);
  }
  if ( *v17 )
  {
    v52 = **v17;
    if ( v52 )
    {
      v53 = *(__int64 (**)(void))(v52 + 824);
      if ( v53 )
      {
        if ( *((_DWORD *)v53 - 1) != 944657148 )
          __break(0x8229u);
        v54 = v53();
        v49 = v14[77];
        if ( (v54 & 1) != 0 )
        {
          v49 |= 0x20000u;
          v14[77] = v49;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cdp_get_opt_dp_ctrl_refill_cap");
    v49 = v14[77];
  }
  if ( *((_BYTE *)v18 + 377) )
    v56 = 0x1000000;
  else
    v56 = 0x800000;
  v57 = v14[76] & 0xFE7FFFFF | v56;
  v14[76] = v57;
  v14[77] = v49 & 0xFFFFBFFF;
  v58 = v49 & 0xFFFFBFFF | ((v18[93] & 1) << 14);
  v14[77] = v58;
  if ( *((_BYTE *)v18 + 376) == 1 )
  {
    v57 |= 0x200000u;
    v14[76] = v57;
  }
  if ( v18[96] )
    v14[93] |= 1u;
  v14[77] = v58 & 0xFFEFFFFF;
  v14[77] = v58 & 0xFFEFFFFF | ((v18[97] & 1) << 20);
  if ( *((_BYTE *)v18 + 389) == 1 )
    v14[76] = v57 | 0x2000000;
LABEL_79:
  v59 = v14 + 96;
  v14[8] = 4915544;
  v60 = *(unsigned __int8 *)(a2 + 8);
  if ( *(_BYTE *)(a2 + 8) )
  {
    v61 = 0;
    while ( 1 )
    {
      v63 = &v59[5 * (unsigned __int16)v61];
      v64 = 32LL * (unsigned __int16)v61;
      *v63 = 4980752;
      v63[2] = *(_QWORD *)(*(_QWORD *)(a2 + 16) + v64 + 8);
      v63[3] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + v64 + 24);
      v63[1] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + v64 + 28);
      v65 = *(_QWORD **)(a1 + 760);
      if ( !v65[799] )
        break;
      v66 = v65[802];
      v67 = v65[800];
      if ( v66 )
      {
        if ( v67 )
          goto LABEL_89;
        v62 = "%s: WMI service ext bit map is not saved yet";
        goto LABEL_82;
      }
      if ( v67 )
      {
LABEL_89:
        if ( (*(_BYTE *)(v67 + 6) & 8) != 0 )
          v63[4] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 32LL * (unsigned __int16)v61 + 12);
        goto LABEL_83;
      }
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Service id %d but WMI ext service bitmap is NULL",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "is_service_enabled_tlv",
        179);
LABEL_83:
      qdf_trace_msg(
        0xA6u,
        8u,
        "chunk %d len %d requested ,ptr  0x%x ",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v61,
        (unsigned int)v63[3],
        (unsigned int)v63[2]);
      v60 = *(unsigned __int8 *)(a2 + 8);
      if ( v60 <= (unsigned __int16)++v61 )
        goto LABEL_92;
    }
    v62 = "%s: WMI service bit map is not saved yet";
LABEL_82:
    qdf_trace_msg(0x31u, 2u, v62, v6, v7, v8, v9, v10, v11, v12, v13, "is_service_enabled_tlv");
    goto LABEL_83;
  }
LABEL_92:
  v14[7] = v60;
  v68 = (unsigned int)v14[9];
  v69 = (unsigned int)v14[14];
  v70 = (unsigned int)v14[10];
  v71 = (unsigned int)v14[11];
  v73 = v14[39];
  v72 = v14[40];
  v74 = 20 * *(unsigned __int8 *)(a2 + 8) + 384;
  v14[95] = (4 * ((5 * *(unsigned __int8 *)(a2 + 8)) & 0x7FF)) | 0x120000;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: num peers: %d , num offload peers: %d, num vdevs: %d, num tids: %d, num tdls conn tb entries: %d, num tdls vdevs: %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "init_cmd_send_tlv",
    v70,
    v71,
    v68,
    v69,
    v72,
    v73);
  if ( *(_DWORD *)(a2 + 24) == 11 )
    goto LABEL_106;
  v75 = 20;
  v76 = &v59[5 * *(unsigned __int8 *)(a2 + 8)];
  *v76 = 33751052;
  v76[2] = *(_DWORD *)(a2 + 24);
  v77 = *(_DWORD *)(a2 + 28);
  v76[3] = v77;
  if ( !v77 )
  {
    v86 = 1179648;
    goto LABEL_105;
  }
  v76[5] = 38469644;
  v78 = *(unsigned int *)(a2 + 32);
  v79 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v79 - 1) != -2112860426 )
    __break(0x8228u);
  v76[6] = v79(a1, v78);
  v76[7] = *(_DWORD *)(a2 + 36);
  v76[8] = *(_DWORD *)(a2 + 40);
  v80 = *(_DWORD *)(a2 + 28);
  if ( v80 <= 1 )
    goto LABEL_103;
  v76[9] = 38469644;
  v81 = *(unsigned int *)(a2 + 44);
  v82 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v82 - 1) != -2112860426 )
    __break(0x8228u);
  v76[10] = v82(a1, v81);
  v76[11] = *(_DWORD *)(a2 + 48);
  v76[12] = *(_DWORD *)(a2 + 52);
  v80 = *(_DWORD *)(a2 + 28);
  if ( v80 < 3 )
    goto LABEL_103;
  v76[13] = 38469644;
  v83 = *(unsigned int *)(a2 + 56);
  v84 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v84 - 1) != -2112860426 )
    __break(0x8228u);
  v76[14] = v84(a1, v83);
  v76[15] = *(_DWORD *)(a2 + 60);
  v76[16] = *(_DWORD *)(a2 + 64);
  v80 = *(_DWORD *)(a2 + 28);
  if ( v80 <= 3 )
  {
LABEL_103:
    v85 = 16 * v80;
    v75 = 16 * v80 + 20;
    v86 = v85 | 0x120000;
LABEL_105:
    v74 += v75;
    v76[4] = v86;
LABEL_106:
    v114[0] = 0x66001000000LL;
    v114[1] = 0x4C4D5F414351LL;
    v114[2] = 0;
    wmi_cmp_and_set_abi_version(1, (__int64)&version_whitelist, (int *)v114, (int *)(a1 + 272), v14 + 1);
    LODWORD(v113) = v14[6];
    LODWORD(v112) = v14[5];
    qdf_trace_msg(
      0x38u,
      8u,
      "%s: INIT_CMD version: %d, %d, 0x%x, 0x%x, 0x%x, 0x%x",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "copy_fw_abi_version_tlv",
      HIBYTE(v14[1]),
      v14[1] & 0xFFFFFF,
      (unsigned int)v14[3],
      (unsigned int)v14[4],
      v112,
      v113);
    qdf_mem_copy((void *)(a1 + 296), v14 + 1, 0x18u);
    qdf_mtrace(49, 100, 1u, 0xFFu, 0);
    v55 = wmi_unified_cmd_send_fl(
            a1,
            v15,
            v74,
            1u,
            "init_cmd_send_tlv",
            0x323Au,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v102);
    if ( v55 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_unified_cmd_send WMI_INIT_CMDID returned Error %d",
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        "init_cmd_send_tlv",
        v55);
      wmi_buf_free();
    }
    goto LABEL_108;
  }
  v76[17] = 38469644;
  __break(0x5512u);
  return save_fw_version_in_service_ready_tlv();
}
